#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 300

/**
 * display_prompt - display a shell prompt
 *
 * This function is responsible for displaying the shell prompt, which is
 * typically "#cisfun$ ". It prompts the user to eneter a command in shell
 */
void display_prompt(void);


#endif /* SHELL_H */
