#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define DELIMITERS " \t\n"

extern char **environ;
char *fetchEnvVariable(char *var);
char *resolveCommandPath(char *cmd);

char *integerToString(int num);
void reverseString(char *str, int length);
void freeMemoryArray(char **matrix);
void displayError(char *program, char *command, int lineNumber);

char *readInputLine(void);
char **splitInputLine(char *line);
int executeCommand(char **cmd, char **argv, int index);

char *duplicateString(const char *original);
int stringCompare(char *str1, char *str2);
int stringLength(char *str);
char *stringConcat(char *dest, char *src);
char *stringCopy(char *dest, char *src);

#endif
