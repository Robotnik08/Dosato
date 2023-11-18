#ifndef DOSATO_STD_H
#define DOSATO_STD_H

#include "SAY.h" // also includes SAYLN
#include "END.h"
#include "PAUSE.h"
#include "BREAK.h" // also includes CONTINUE and RETURN
#include "LISTEN.h"
#include "CLEAR.h"
#include "SYSTEM.h"

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
        return say(process, args, argc, 0);
    } else if (!strcmp(name, "SAYLN")) {
        return say(process, args, argc, 1);
    } else if (!strcmp(name, "END")) {
        return end(process, args, argc);
    } else if (!strcmp(name, "PAUSE")) {
        return pause(process, args, argc);
    } else if (!strcmp(name, "BREAK")) {
        return breakBlock(process, args, argc);
    } else if (!strcmp(name, "CONTINUE")) {
        return continueBlock(process, args, argc);
    } else if (!strcmp(name, "RETURN")) {
        return returnBlock(process, args, argc);
    } else if (!strcmp(name, "LISTEN")) {
        return listen(process, args, argc);
    } else if (!strcmp(name, "CLEAR")) {
        return clear(process, args, argc);
    } else if (!strcmp(name, "SYSTEM")) {
        return sys(process, args, argc);
    }
    return ERROR_FUNCTION_NOT_FOUND;
}

#endif
