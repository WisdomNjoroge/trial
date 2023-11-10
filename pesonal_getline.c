#include "shell.h"

char *pers0nal_getline(void)
{
	static ssize_t baitread = 0;
	static size_t good = 0;
	static char buffer[BUFFER_SIZE];
	size_t start, length, i;
	char *line;

	if (good >= baitread)
	{
		baitread = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		
		if (baitread <= 0)
		{
			return (NULL);
		}
		good = 0;
	}

	start = good;
	
	while (good < baitread && buffer[good] != '\n')
	{
		good++;
	}

	length = good - start;
	line = malloc(length + 1);
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
