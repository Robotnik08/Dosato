/**
 * @author Sebastiaan Heins
 * @file token.h
 * @brief Contains all the token types and their respective enums, as well as some helper functions and the token struct
 * @version 1.0
 * @date 05-10-2023
*/

#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

#define MASTER_KEYWORDS {"DO", "MAKE", "SET"}
#define EXTENSION_KEYWORDS {"WHEN", "WHILE", "ELSE", "CATCH", "INTO", "THEN", "FOR", "IF"}
#define EXTENSION_ACCEPTS {NEEDS_EXPRESSION, NEEDS_EXPRESSION, NEEDS_IF_OR_FUNCTION, NEEDS_FUNCTION, NEEDS_EXPRESSION, NEEDS_FUNCTION, NEEDS_EXPRESSION, NEEDS_EXPRESSION}
#define VAR_TYPES {"INT", "BOOL", "STRING", "FLOAT", "DOUBLE", "CHAR", "SHORT", "LONG", "BYTE", "VOID", "ARRAY", "FUNC", "UINT", "USHORT", "ULONG", "UBYTE", "STRUCT"}
#define SEPARATORS {';'}
#define OPERATORS {"+", "-", "*", "/", "%", "=", ">", "<", "!", "&", "^", "|", "~", "?", ":", ".", ",", "#",  \
                   "+=","-=","*=","/=","%=","++","--","==","!=",">=","<=","&&","||","<<",">>","&=","|=","^=", \
                   "**","^/","|>","<|","!-", "=>"}
// operator precedence is borrowed from C
#define OPERATOR_PRECEDENCE \
                  { 4,   4,   3,   3,   3,   14,  6,   6,   2,   8,   9,   10,  2,   13,  13,  1,   15,  1,   \
                    14,  14,  14,  14,  14,  2,   2,   7,   7,   6,   6,   11,  12,  5,   5,   14,  14,  14,  \
                    2,   2,   2,   2,   2,   15}

#define BRACKETS {"()", "{}", "[]"}

typedef enum {
    TOKEN_NULL = -2,
    TOKEN_COMMENT = 0,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_MASTER_KEYWORD,
    TOKEN_EXT,
    TOKEN_IDENTIFIER,
    TOKEN_PARENTHESIS,
    TOKEN_VAR_TYPE,
    TOKEN_SEPARATOR,
    TOKEN_END = -1
} TokenType;

typedef enum {
    BRACKET_NULL,
    BRACKET_ROUND = 1 << 13,
    BRACKET_SQUARE = 1 << 14,
    BRACKET_CURLY = 1 << 15,
} BracketType;

typedef enum {
    OPERATOR_NULL = -1,
    OPERATOR_ADD,
    OPERATOR_SUBTRACT,
    OPERATOR_MULTIPLY,
    OPERATOR_DIVIDE,
    OPERATOR_MODULO,
    OPERATOR_ASSIGN,
    OPERATOR_GREATER,
    OPERATOR_LESS,
    OPERATOR_NOT,
    OPERATOR_AND,
    OPERATOR_XOR,
    OPERATOR_OR,
    OPERATOR_NOT_BITWISE,
    OPERATOR_QUESTION,
    OPERATOR_COLON,
    OPERATOR_DOT,
    OPERATOR_COMMA,
    OPERATOR_HASH,
    OPERATOR_ADD_ASSIGN,
    OPERATOR_SUBTRACT_ASSIGN,
    OPERATOR_MULTIPLY_ASSIGN,
    OPERATOR_DIVIDE_ASSIGN,
    OPERATOR_MODULO_ASSIGN,
    OPERATOR_INCREMENT,
    OPERATOR_DECREMENT,
    OPERATOR_EQUAL,
    OPERATOR_NOT_EQUAL,
    OPERATOR_GREATER_EQUAL,
    OPERATOR_LESS_EQUAL,
    OPERATOR_AND_AND,
    OPERATOR_OR_OR,
    OPERATOR_SHIFT_LEFT,
    OPERATOR_SHIFT_RIGHT,
    OPERATOR_AND_ASSIGN,
    OPERATOR_OR_ASSIGN,
    OPERATOR_XOR_ASSIGN,
    OPERATOR_POWER,
    OPERATOR_ROOT,
    OPERATOR_MAX,
    OPERATOR_MIN,
    OPERATOR_ABSOLUTE,
    OPERATOR_AS
} OperatorType;

typedef enum {
    D_NULL = -1,
    TYPE_INT,
    TYPE_BOOL,
    TYPE_STRING,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_SHORT,
    TYPE_LONG,
    TYPE_BYTE,
    TYPE_VOID,
    TYPE_ARRAY,
    TYPE_FUNC,
    TYPE_UINT,
    TYPE_USHORT,
    TYPE_ULONG,
    TYPE_UBYTE,
    TYPE_STRUCT
} DataType;

typedef enum {
    MASTER_DO,
    MASTER_MAKE,
    MASTER_SET,

    M_NULL = -1
} MasterKeywordType;

typedef enum {
    EXT_WHEN,
    EXT_WHILE,
    EXT_ELSE,
    EXT_CATCH,
    EXT_STORE,
    EXT_THEN,
    EXT_FOR,
    EXT_IF,

    E_NULL = -1
} ExtensionKeywordType;

typedef struct {
    int start, end;
    TokenType type;
    int carry;
} Token;

typedef enum {
    NEEDS_NULL,
    NEEDS_BLOCK,
    NEEDS_EXPRESSION,
    NEEDS_FUNCTION,
    NEEDS_IF_OR_FUNCTION
} KeyWordFollowUpType;

/**
 * @brief Get the type of a bracket
 * @param bracket The bracket to get the type of
*/
BracketType getBracketType (char bracket);

/**
 * @brief Print all tokens in a token array
 * @param tokens The token array to print
*/
void printTokens (Token* tokens);

/**
 * @brief Check if an operator is an assignment operator
 * @param operator The operator to check
 * @return Whether or not the operator is an assignment operator
*/
int isAssignmentOperator (OperatorType operator);


BracketType getBracketType (char bracket) {
    switch (bracket) {
        case '(':
        case ')':
            return BRACKET_ROUND;
        case '[':
        case ']':
            return BRACKET_SQUARE;
        case '{':
        case '}':
            return BRACKET_CURLY;
        default:
            return BRACKET_NULL;
    }
}

void printTokens (Token* tokens) {
    if (tokens == NULL) {
        printf("No tokens.\n");
        return;
    }
    int i = 0;
    while (tokens[i].type != TOKEN_END) {
        printf("Token %d. start: %d, end: %d, type: %d, carry: %d\n",
               i, tokens[i].start, tokens[i].end, tokens[i].type, tokens[i].carry);
        i++;
    }
}

int isAssignmentOperator (OperatorType operator) {
    switch (operator) {
        case OPERATOR_ASSIGN:
        case OPERATOR_ADD_ASSIGN:
        case OPERATOR_SUBTRACT_ASSIGN:
        case OPERATOR_MULTIPLY_ASSIGN:
        case OPERATOR_DIVIDE_ASSIGN:
        case OPERATOR_MODULO_ASSIGN:
        case OPERATOR_AND_ASSIGN:
        case OPERATOR_OR_ASSIGN:
        case OPERATOR_XOR_ASSIGN:
            return 1;
        default:
            return 0;
    }
}

int checkIfOnly (Token* tokens, TokenType type, int start, int end) {
    if (end - start < 2) {
        return 0;
    }
    for (int i = start + 1; i < end; i++) {
        if (tokens[i].type != type) {
            return 0;
        }
    }
    return 1;
}

#endif