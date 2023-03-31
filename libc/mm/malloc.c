// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *result = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(result == MAP_FAILED) {
		return NULL;
	}
	return result;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
        void *result = malloc(nmemb * size);

        if(result == MAP_FAILED) {
                return NULL;
        }
        memset(result, 0, nmemb * size);
        return result;
}

void free(void *ptr)
{

	/* TODO: Implement free(). */
	if(ptr == NULL) {
		return;
	}
	size_t *p = (size_t *) ptr - 1;
	size_t size = *p;
	munmap(p, size);

}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	void *result = malloc(size);
	if (result == MAP_FAILED) {
		return NULL;
	}
	free(ptr);
	return result;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	if (ptr == NULL) {
		return NULL;
	}

	size_t total_size = nmemb * size;
	if (total_size == 0) {
		free(ptr);
		return NULL;
	}

	void *result = mremap(ptr, 0, total_size, MREMAP_MAYMOVE);
	if (result == MAP_FAILED) {
		return NULL;
	}
	return result;
}
