#ifndef TOKEN_H
#define TOKEN_H

#define MASTER_KEYWORDS {"DO", "MAKE", "SET"}
#define EXTENSION_KEYWORDS {"WHEN", "WHILE", "ELSE", "ELSEWHEN", "CATCH", "STORE", "THEN"}
#define VAR_TYPES {"INT", "BOOL", "STRING", "FLOAT", "DOUBLE", "CHAR", "SHORT", "LONG", "BYTE", "VOID", "ARRAY", "FUNC", "UINT", "USHORT", "ULONG", "UBYTE", "STRUCT"}
#define SEPARATORS {';'}
#define OPERATORS {"+", "-", "*", "/", "%", "=", ">", "<", "!", "&", "|", "^", "~", "?", ":", ".", ",", "#", \
                    "+=", "-=", "*=", "/=", "%=", "++", "--", "==", "!=", ">=", "<=", "&&", "||", "<<", ">>"}
#define BRACKETS {"()", "{}", "[]"}

typedef enum {
    TOKEN_NULL = -1,
    TOKEN_COMMENT,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_MASTER_KEYWORD,
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_PARENTHESIS,
    TOKEN_EXT,
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
    OPERATOR_OR,
    OPERATOR_XOR,
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
} OperatorType;

typedef enum {
    M_NULL,
    FUNCTION_CALL,
    SET_VAR,
    MAKE_VAR
} MasterKeywordType;

typedef enum {
    D_NULL,
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
    E_NULL,
    EXT_WHEN,
    EXT_WHILE,
    EXT_ELSE,
    EXT_ELSEWHEN,
    EXT_CATCH,
    EXT_STORE,
    EXT_THEN
} ExtensionKeywordType;

typedef enum {
    NODE_NULL,
    NODE_FUNCTION_CALL,
    NODE_SET_VAR,
    NODE_MAKE_VAR
} NodeType;

typedef struct {
    int start, end;
    TokenType type;
    int carry;
} Token;

/**
 * @brief Get the type of a bracket
 * @param bracket The bracket to get the type of
*/
BracketType getBracketType (char bracket);

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

#endif