#include "main.h"

/**
 * fetchEnvVariable - Fetches the value of an env var
 * @var: The name of the env var
 *
 * Return: The value of the env var as a string.
 */
char *fetchEnvVariable(char *var)
{
    char *envVarCopy, *key, *value, *result;
    int i;

    for (i = 0; environ[i]; i++)
    {
        if (i == 2)
            continue;
        envVarCopy = duplicateString(environ[i]);
        key = strtok(envVarCopy, "=");
        if (stringCompare(key, var) == 0)
        {
            value = strtok(NULL, "\n");
            result = duplicateString(value);
            free(envVarCopy);
            return (result);
        }
        free(envVarCopy);
    }
    return (NULL);
}

/**
 * resolveCommandPath - Finds the absolute path for a command
 * @cmd: The command to resolve
 *
 * Return: The path to the command as a string, or NULL.
 */
char *resolveCommandPath(char *cmd)
{
    char *envPath, *commandFullPath, *pathToken;
    int i;
    struct stat fileStatus;

    for (i = 0; cmd[i]; i++)
    {
        if (cmd[i] == '/')
        {
            if (stat(cmd, &fileStatus) == 0)
                return (duplicateString(cmd));
            return (NULL);
        }
    }
    envPath = fetchEnvVariable("PATH");
    if (!envPath)
        return (NULL);
    pathToken = strtok(envPath, ":");
    while (pathToken)
    {
        commandFullPath = malloc(stringLength(pathToken) + stringLength(cmd) + 2);
        if (commandFullPath)
        {
            stringCopy(commandFullPath, pathToken);
            stringConcat(commandFullPath, "/");
            stringConcat(commandFullPath, cmd);
            if (stat(commandFullPath, &fileStatus) == 0)
            {
                free(envPath);
                return (commandFullPath);
            }
            free(commandFullPath);
        }
        pathToken = strtok(NULL, ":");
    }
    free(envPath);
    return (NULL);
}
