#include "../printflib.h"

/*
 ******Author
 * Hileamlak M. Yitayew
 * hilea.buisness@gmail.com
 */


/**
 *smalloc - allocates a memory location and returns a pointer
 *@size: amount to be  allocated
 *Return: a generic pointer allocated or -1 on faliure
 */
void *smalloc(unsigned int size)
{
	char *pointer = malloc(size);
	void *_pointer = NULL;
	unsigned int i = 0;

	if (!pointer)
	{
		/*perr(NULL, NULL, "ERROR ALLOCATING MEMORY");*/
		exit(-1);
	}
	while (i < size)
	{
		pointer[i] = '\0';
		i += 1;
	}
	_pointer = (void *)pointer;
	return (_pointer);
}
/**
 *srealloc - rallocates a memory location and returns a pointer
 *(safe realloc)
 *@ptr: pointer to old mem location, must be null terminated
 *@size: new size
 *Return: a generic pointer reallocated memory or -1 on faliure
 */
void *srealloc(void *ptr, unsigned int size)
{
	char *_pointer = (char *)smalloc(size), *_ptr = (char *)ptr;
	void *pointer = NULL;
	int i = 0;

	if (!_ptr)
	{
		pointer = _pointer;
		return (pointer);
	}
	while (_ptr[i])
	{
		_pointer[i] = _ptr[i];
		i += 1;
	}
	_pointer[i] = '\0';
	pointer = (void *)_pointer;
	free(ptr);
	return (pointer);
}

