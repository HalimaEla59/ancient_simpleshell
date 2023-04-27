#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocate a memo block with malloc+free
 * @ptr: pointer to the previous memory allocated
 * @old_size: ptr size bytes
 * @new_size: size of new memo block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *dest;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	dest = malloc(new_size);
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		dest[i] = ptr[i];

	free(ptr);
	return (dest);
}
