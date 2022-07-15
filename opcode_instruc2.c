#include "monty.h"

/**
 * _queue - functiion that sets the format of the data
 *          to a queue (FIFO)
 * @doubly: represents the head of the linked list
 * @cline: represents the line number;
 * Return: nothing
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	globalv.lifo = 0;
}

/**
 * _stack - a function that sets the format fo the data
 *          to a stack (LIFO)
 * @doubly: represnts the head of the linked list
 * @cline: represents the line number;
 * Return: nothing
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	globalv.lifo = 1;
}

/**
 * _add - a function that adds the top two elements of the stack
 * @doubly: represnts the head of the linked list
 * @cline: represents the line number;
 * Return: nothing
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_globalv();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - This is a function that doesn't do anythinhg
 * @doubly: represents the head of the linked list
 * @cline: represents the line number;
 * Return: nothing
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - a function that subtracts the top element to the second
 *        top element of the stack
 * @doubly: represents head of the linked list
 * @cline: represents line number;
 * Return: nothing
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_globalv();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
