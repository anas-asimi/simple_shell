#include "main.h"

/**
 * _realloc - _realloc.
 * Return: pointer.
 */
void *_realloc(void *ptr, size_t new_size)
{
	void *new_ptr;
	size_t copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return NULL;
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return NULL;

	if (ptr != NULL)
	{
		copy_size = new_size < sizeof(ptr) ? new_size : sizeof(ptr);
		_memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}

	return new_ptr;
}
