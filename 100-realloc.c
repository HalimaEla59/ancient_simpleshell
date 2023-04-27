#include "shell.h"

/**
 * _realloc - reallocate a memo block with malloc+free
 * @ptr: pointer to the previous memory allocated
 * @old_size: ptr size bytes
 * @new_size: size of new memo block
 * Return: NULL or new dest
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *dest;
	char *src;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	dest = malloc(new_size);
	src = ptr;
	if (dest == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			dest[i] = src[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			dest[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			dest[i] = src[i];
		free(ptr);
	}
	return (dest);
}
