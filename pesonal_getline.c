#include "shell.h"

/*
 * pers0nal_getline(void) - reads a line of input from the standard input
 * Return: on success, apointer tothe allocated string is returned
 * On failure or end of input, NULL is returned
 */

char *pers0nal_getline(void)
{
	static ssize_t baitread;
	static size_t good;
	static char buffer[BUFFER_SIZE];
	size_t start, length, i;
	char *line;

	if (good >= baitread) /* Check if there is no more data in the buffer */
	{
		baitread = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (baitread <= 0) /* Check for end of input */
		{
			return (NULL);
		}
		good = 0; /* Reset the position in the buffer */
	}

	start = good;

	while (good < baitread && buffer[good] != '\n')
	{
		good++;
	}

	length = good - start;
	line = malloc(length + 1); /* Allocate memory for the line */
	if (line == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < length; i++)
	{
		line[i] = buffer[start + i];
	}

	line[length] = '\0';

	good++;

	return (line);
}
