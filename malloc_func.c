#include "monty.h"
/**
 * _calloc - This is a function that concatenate two strings
 * @numelem: represents the number of elements
 * @size: represents the type of elements
 * Return: this returns nothing
 */
void *_calloc(unsigned int numelem, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (numelem == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(numelem * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (numelem * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * _realloc - This is a function that changes the size
 *            and copy the content
 * @ptr: this represnts the malloc pointer to reallocate
 * @old_size: this represents the old number of bytes
 * @new_size: this represents the new number of Bytes
 * Return: here we return nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
