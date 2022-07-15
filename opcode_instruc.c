#include "monty.h"

/**
 * _push - this is a function that pushes an element
 *         to the stack
 *
 * @doubly:this represents the head of the linked list
 * @cline: represents the line number
 * Return: this returns nothing
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!globalv.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_globalv();
		exit(EXIT_FAILURE);
	}

	for (j = 0; globalv.arg[j] != '\0'; j++)
	{
		if (!isdigit(globalv.arg[j]) && globalv.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_globalv();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(globalv.arg);

	if (globalv.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - a function that prints all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - a funtion that prints the value at the top
 *         of the stack
 * @doubly: represents the head of the linked list
 * @cline: represents the line number
 * Return: nothing
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_globalv();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - a function that removes the top element of the stack
 * @doubly: represnts the head of the linked list
 * @cline: represents the line number
 * Return: nothing
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_globalv();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - a function that swaps the top two elements of the stack
 * @doubly: represnts the head of the linked list
 * @cline: represents the line number
 * Return: nothing
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_globalv();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
