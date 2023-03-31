// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int result = syscall(__NR_fstat, fd, st);
	if(result < 0) {
		errno = -result;
		return -1;
	}
	return result;

}
