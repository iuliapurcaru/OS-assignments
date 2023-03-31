// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	long result = (long) syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if(result == 0) {
		return MAP_FAILED;
	}

	if (result < 0) {
		errno = -result;
		return (void *) -1;
	}
	return (void *) result;;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *result = (void *) syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if(result == MAP_FAILED) {
		return MAP_FAILED;
	}

	long int_result = (long)result;
	if(result == NULL) {
		errno = -int_result;
		return (void *) -1;
	}
	return (void *) result;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int result = syscall(__NR_munmap, addr, length);
	if (result < 0) {
		errno = -result;
		return -1;
	}
	return result;
}
