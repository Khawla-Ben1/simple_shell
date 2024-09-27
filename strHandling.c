#include "main.h"

/**
 * duplicateString - Duplicates a string
 * @original: The string to duplicate
 *
 * Return: The duplicated string.
 */
char *duplicateString(const char *original)
{
    char *copy;
    int i, size = 0;

    if (original == NULL)
        return (NULL);
    while (*original != '\0')
    {
        size++;
        original++;
    }
    original -= size;
    copy = malloc(sizeof(char) * (size + 1));
    if (copy == NULL)
        return (NULL);
    for (i = 0; i <= size; i++)
        copy[i] = original[i];
    return (copy);
}

/**
 * stringLength - Returns the length of a string
 * @str: The string to measure
 *
 * Return: The length of the string.
 */
int stringLength(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return (len);
}

/**
 * stringCompare - Compares two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: An integer representing the comparison.
 */
int stringCompare(char *str1, char *str2)
{
    int comparison;

    comparison = (int)*str1 - (int)*str2;
    while (*str1)
    {
        if (str1 != str2)
            break;
        str1++;
        str2++;
        comparison = (int)*str1 - (int)*str2;
    }
    return (comparison);
}

/**
 * stringCopy - Copies one string to another
 * @dest: Destination string
 * @src: Source string
 *
 * Return: The destination string.
 */
char *stringCopy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * stringConcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: The concatenated string.
 */
char *stringConcat(char *dest, char *src)
{
    char *ptr = dest;

    while (*ptr)
        ptr++;
    while (*src)
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return (dest);
}
