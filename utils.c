#include "main.h"

/**
 * freeMemoryArray - Frees a 2D array of strings
 * @matrix: The array to be freed
 *
 * Return: Nothing.
 */
void freeMemoryArray(char **matrix)
{
	int index;

	if (!matrix)
		return;

	for (index = 0; matrix[index]; index++)
	{
		free(matrix[index]);
		matrix[index] = NULL;
	}
	free(matrix);
	matrix = NULL;
}

/**
 * displayError - Displays an error message
 * @program: Program name
 * @command: Command that caused the error
 * @lineNumber: Line index number
 *
 * Return: Nothing.
 */
void displayError(char *program, char *command, int lineNumber)
{
	char *lineNumStr, errorMsg[] = ": not found\n";

	lineNumStr = integerToString(lineNumber);
	write(STDERR_FILENO, program, stringLength(program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, lineNumStr, stringLength(lineNumStr));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, stringLength(command));
	write(STDERR_FILENO, errorMsg, stringLength(errorMsg));
	free(lineNumStr);
}

/**
 * integerToString - Converts an integer to a string
 * @num: The integer to convert
 *
 * Return: The converted string.
 */
char *integerToString(int num)
{
	char buffer[15];
	int index = 0;

	if (num == 0)
		buffer[index++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[index++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buffer[index] = '\0';
	reverseString(buffer, index);
	return (duplicateString(buffer));
}

/**
 * reverseString - Reverses a string
 * @str: The string to reverse
 * @length: The length of the string
 *
 * Return: Nothing.
 */
void reverseString(char *str, int length)
{
	char temp;
	int start = 0, end = length - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
