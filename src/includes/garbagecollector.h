/**
 * @author Sebastiaan Heins
 * @file garbagecollector.h
 * @brief Garbage collection for the interpreter
 * @version 0.1
 * @date 17-10-2023
*/

#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cleans up a scope removing all variables
 * @param scope The scope to clean
 * 
*/
void cleanScope (Scope* scope);

void cleanScope (Scope* scope) {
    if (scope->child != NULL) if (scope->child->body != NULL) {
        cleanScope(scope->child);
    }
    
    int length = getVariablesLength(scope->variables);
    for (int i = 0; i < length; i++) {
        destroyVariable(&scope->variables[i]);
    }
    free (scope->variables);

    length = getFunctionsLength(scope->functions);
    for (int i = 0; i < length; i++) {
        destroyFunction(&scope->functions[i]);
    }
    free (scope->functions);

    free (scope->child);
}

#endif