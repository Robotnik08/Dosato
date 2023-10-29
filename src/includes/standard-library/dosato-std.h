#ifndef DOSATO_STD_H
#define DOSATO_STD_H

#include "SAY.h"

#include "../ast.h"
#include "../parser.h"
#include "../lexer.h"
#include "../error.h"
#include "../function.h"
#include "../variable.h"
#include "../token.h"
#include "../scope.h"
#include "../process.h"

int standard_call (Process* process, const char* name, const Variable* args, int argc);

int standard_call (Process* process, const char* name, const Variable* args, int argc) {
    if (!strcmp(name, "SAY")) {
        return say(process, args, argc);
    }
    return ERROR_FUNCTION_NOT_FOUND;
}

#endif
