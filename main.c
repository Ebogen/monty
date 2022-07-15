#include "monty.h"

global_t globalv;

/**
 * free_globalv - this is a function that frees
 *                the global variables
 * Return: Here we return nothing
 */
void free_globalv(void)
{
	free_dlistint(globalv.head);
	free(globalv.buff);
	fclose(globalv.fdes);
}

/**
 * start_globalv - this is a function initializes
 *                 the global variables
 * @fdes: file descriptor
 * Return: no return
 */
void start_globalv(FILE *fdes)
{
	globalv.lifo = 1;
	globalv.curln = 1;
	globalv.secln = NULL;
	globalv.head = NULL;
	globalv.fdes = fdes;
	globalv.buff = NULL;
}

/**
 * check_input - this is a function that checks if the file
 *               exists and if the file can and can be opened
 * @argc: represents the argument count
 * @argv: represents the argument vector
 * Return: here we return the file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fdes;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fdes = fopen(argv[1], "r");

	if (fdes == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fdes);
}

/**
 * main -This function represents the Entry point
 * @argc: represents the argument count
 * @argv: represents the argument vector
 * Return: here we return 0 on success
 */
int main(int argc, char *argv[])
{
	void (*func)(stack_t **stack, unsigned int line_number);
	FILE *fdes;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fdes = check_input(argc, argv);
	start_globalv(fdes);
	nlines = getline(&globalv.buff, &size, fdes);
	while (nlines != -1)
	{
		lines[0] = _strtoky(globalv.buff, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			func = get_opcodes(lines[0]);
			if (!func)
			{
				dprintf(2, "L%u: ", globalv.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_globalv();
				exit(EXIT_FAILURE);
			}
			globalv.arg = _strtoky(NULL, " \t\n");
			func(&globalv.head, globalv.cont);
		}
		nlines = getline(&globalv.buff, &size, globalv);
		globalv.cont++;
	}

	free_globalv();

	return (0);
}
