#include "main.h"

/**
 * executeCommand - Executes a command
 * @commands: Array of command strings
 * @argv: Argument vector (array of strings)
 * @lineIndex: The index of the current line being executed
 *
 * Return: An integer status code.
 */
int executeCommand(char **commands, char **argv, int lineIndex)
{
    pid_t childProcess;
    int status;
    char *commandPath;

    commandPath = resolveCommandPath(commands[0]);
    if (!commandPath)
    {
        displayError(argv[0], commands[0], lineIndex);
        freeMemoryArray(commands);
        return (127);
    }
    childProcess = fork();
    if (childProcess == 0)
    {
        if (execve(commandPath, commands, environ) == -1)
        {
            free(commandPath);
            freeMemoryArray(commands);
        }
    }
    else
    {
        waitpid(childProcess, &status, 0);
        freeMemoryArray(commands);
        free(commandPath);
    }
    return (WEXITSTATUS(status));
}

/**
 * readInputLine - Reads a line of input from stdin
 *
 * Return: A string containing the input line.
 */
char *readInputLine(void)
{
    char *input = NULL;
    size_t bufSize = 0;
    ssize_t lineSize;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    lineSize = getline(&input, &bufSize, stdin);
    if (lineSize == -1)
    {
        free(input);
        return (NULL);
    }
    return (input);
}

/**
 * splitInputLine - Splits a line of input into separate tokens
 * @line: The input line to be split
 *
 * Return: An array of tokens (strings).
 */
char **splitInputLine(char *line)
{
    char *token = NULL, *lineCopy = NULL, **tokens = NULL;
    int tokenCount = 0, i = 0;

    if (!line)
        return (NULL);
    lineCopy = duplicateString(line);
    token = strtok(lineCopy, DELIMITERS);
    if (token == NULL)
    {
        free(line);
        free(lineCopy);
        return (NULL);
    }
    while (token)
    {
        tokenCount++;
        token = strtok(NULL, DELIMITERS);
    }
    free(lineCopy);
    tokens = malloc(sizeof(char *) * (tokenCount + 1));
    if (!tokens)
    {
        free(line);
        return (NULL);
    }
    token = strtok(line, DELIMITERS);
    while (token)
    {
        tokens[i] = duplicateString(token);
        token = strtok(NULL, DELIMITERS);
        i++;
    }
    free(line);
    tokens[i] = NULL;
    return (tokens);
}
