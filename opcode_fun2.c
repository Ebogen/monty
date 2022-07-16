#include "monty.h"
/**
 * mod - a fucntion that computes the rest of the division
 *       of the second top element of the stack by the top
 *       element of the stack.
 * @stack: represents a pointer to a pointer to the beginning
 *         of the stack
 * @line_number: represnents the line number.
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int rem;
	stack_t *temp = *stack;
	int leng = dlistint_len(*stack);

	if (leng < 2)
	{
		err_mod1(line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		err_div2(line_number);
		exit(EXIT_FAILURE);
	}
	rem = (temp->next->n) % (temp->n);
	temp->next->n = rem;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}

/**
 * pchar - a function that prints the char at the top of
 *         the stack followed by a new line.
 *
 * @stack: represents a pointer to a pointer to the begining
 *         of the stack implementation list.
 * @line_number: represnt the line number.
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		err_pchar2(line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		err_pr1(line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - a function that prints the string starting at the
 *        top of the stack, followed by a new line.
 * @stack: A pointer to a pointer to the begining of the stack
 *         implementation list.
 * @line_number: represents the line number.
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;

	(void)line_number;

	while (traverse && traverse->n > 0 && traverse->n < 127)
	{
		printf("%c", traverse->n);
		traverse = traverse->next;
	}
	putchar('\n');
}

/**
 * rotl -  a function that rotates the stack to the top.
 * @stack: A pointer to a pointer to the begining of the stack
 *         implementation list.
 * @line_number: The line number.
 * Return: nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	add_dnodeint_end(stack, temp->n);
	free(temp);
}

/**
 * rotr -  a functiont that rotates the stack to the bottom.
 * @stack: A pointer to a pointer to the begining of the stack
 * implementation list.
 * @line_number: reperesents the line number.
 * Return: nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = get_dnodeint_at_index(*stack,  dlistint_len(*stack) - 1);
	add_dnodeint(stack, temp->n);
	delete_dnodeint_at_index(stack, dlistint_len(*stack) - 1);
}
