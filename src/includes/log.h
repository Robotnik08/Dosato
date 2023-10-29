/**
 * @author Sebastiaan Heins
 * @file log.h
 * @brief The logging file, these functions are used to log errors and warnings in the dosato interpreter
 * @version 1.0
 * @date 05-10-2023
*/

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include "strtools.h"

typedef enum {
    ERROR,
    WARNING,
    GENERIC
} LogType;

typedef enum {
    ERROR_NULL,

    // Syntax Errors (generated by the parser)
    ERROR_SYNTAX,
    ERROR_TYPE_MISMATCH,
    ERROR_UNDEFINED,
    ERROR_RECURSION,
    ERROR_MEMORY,
    ERROR_FILE,
    ERROR_RUNTIME,
    ERROR_PARSER,
    ERROR_EXPECTED_MASTER,
    ERROR_EXPECTED_IDENTIFIER,
    ERROR_WRONG_BRACKET_ROUND,
    ERROR_WRONG_BRACKET_SQUARE,
    ERROR_WRONG_BRACKET_CURLY,
    ERROR_EXPECTED_ARGUMENTS,
    ERROR_EXPECTED_ARGUMENT,
    ERROR_EXPECTED_TYPE,
    ERROR_EXPECTED_ASSIGN_OPERATOR,
    ERROR_EXPECTED_COMMA,
    ERROR_EXPECTED_SEPERATOR,
    ERROR_EMPTY_BLOCK,
    ERROR_EXPECTED_EXTENSION,
    ERROR_EXPECTED_BLOCK,
    ERROR_EXPECTED_EXPRESSION,
    ERROR_INVALID_EXPRESSION,
    ERROR_OPERATOR_NOT_UNARY,
    ERROR_INVALID_FUNCTION_DECLARATION_ARGUMENT,

    // Runtime Errors (generated by the interpreter)
    ERROR_PROCESS_NOT_RUNNING,
    ERROR_INTERPRETER_INVALID_COMMAND,
    ERROR_SAY_ERROR,
    ERROR_FUNCTION_NOT_FOUND,
    ERROR_FUNCTION_ARG_NOT_CORRECT_AMOUNT,
    ERROR_INVALID_LITERAL,
    ERROR_INVALID_OPERATOR,
    ERROR_CANT_USE_TYPE_IN_ADDITION,
    ERROR_CANT_CONVERT_TO_STRING,
    ERROR_FLOATING_CANT_BE_UNSIGNED,
    ERROR_TYPE_NOT_SUBTRACTABLE,
    ERROR_CANT_USE_TYPE_IN_MULTIPLICATION,
    ERROR_CANT_USE_TYPE_IN_DIVISION,
    ERROR_CANT_USE_TYPE_IN_MODULO,
    ERROR_CANT_USE_TYPE_IN_BITWISE_EXPRESSION,

    ERROR_UNKNOWN

} ErrorType;

const char* ERROR_MESSAGES[] = {
    "No error Occured? (CODE NULL)", 

    // Syntax Errors (generated by the parser)
    "Syntax Error", 
    "Type Mismatch Error", 
    "Undefined Variable Error", 
    "Recursion Limit reached Error", 
    "Memory Error", 
    "File Error", 
    "Runtime Error", 
    "Parser Error",
    "Expected Master Keyword as first token (DO, SET, MAKE)",
    "Expected Identifier",
    "Bracket is incorrect, expected a round bracket ( )",
    "Bracket is incorrect, expected a square bracket [ ]",
    "Bracket is incorrect, expected a curly bracket { }",
    "Expected () after function call (arguments)",
    "Expected an argument",
    "Expected a type (INT, FLOAT, STRING, BOOL etc)",
    "Expected an assignment operator",
    "Expected a comma",
    "Expected a seperator (;)",
    "Empty Block, expected a statement",
    "Expected an extension (WHEN, WHILE, ELSE, etc)",
    "Expected a block { }",
    "Expected an expression",
    "Invalid Expression",
    "Operator is not unary (must be -, ! or ~)",
    "Invalid function declaration argument",

    // Runtime Errors (generated by the interpreter)
    "Interpreter can not interpret a process that is not running",
    "Interpreter can not interpret an invalid command (expected DO, SET or MAKE)",
    "SAY function returned an error",
    "The function name is not declared in the current scope",
    "The function was called with an incorrect amount of arguments",
    "The literal is invalid",
    "The operator is invalid",
    "The type can not be used in addition",
    "The type can not be converted to a string",
    "The type can not be unsigned or become unsigned (floating point types)",
    "The type can not be subtracted or get subtracted",
    "The type can not be used in multiplication",
    "The type can not be used in division",
    "The type can not be used in modulo",
    "The type can not be used in a bitwise expression",

    "Unknown Error"
};

/**
 * @brief Logs text to the console
 * @param type The type of log
 * @param contents The contents of the log
*/
void logText (const LogType type, const char* contents);

/**
 * @brief Prints an error message and quits the program with the error code
 * @param full_code The full code
 * @param pos The position of the error
 * @param type The type of error, also the error code
*/
void printError (const char* full_code, const int pos, const ErrorType type);

void logText (const LogType type, const char* contents) {
    switch (type) {
        case ERROR:
            printf("ERROR:\n");
            break;
        case WARNING:
            printf("WARNING:\n");
            break;
    }
    printf("%s", contents);
    if (type == ERROR) {
        exit(1);
    }
}
void printError (const char* full_code, const int pos, const ErrorType type) {
    printf("ERROR:\n");
    printf("E%i: %s\n", type, ERROR_MESSAGES[type]);
    printf("At line %i:%i\n", getLine(full_code, pos), getLineCol(full_code, pos));
    exit(type);
}

#endif