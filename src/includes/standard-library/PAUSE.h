#ifndef PAUSE_H
#define PAUSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ast.h"
#include "../parser.h"
#include "../lexer.h"
#include "../error.h"
#include "../function.h"
#include "../variable.h"
#include "../token.h"
#include "../scope.h"
#include "../process.h"

int pause (Process* process, const Variable* args, int argc);

int pause (Process* process, const Variable* args, int argc) {
    if (argc) {
        return ERROR_TOO_MANY_ARGUMENTS;
    }
    system("pause");
    return 0; // return code
}
#endif