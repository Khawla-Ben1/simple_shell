#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector (array of strings)
 *
 * Return: Always returns 0.
 */
int main(int argc, char **argv)
{
	char *inputLine = NULL, **commands = NULL;
	int status = 0, lineIndex = 0;
	(void) argc;

	while (1)
	{
		inputLine = readInputLine();
		if (inputLine == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		lineIndex++;
		commands = splitInputLine(inputLine);
		if (!commands)
			continue;
		status = executeCommand(commands, argv, lineIndex);
	}
}
