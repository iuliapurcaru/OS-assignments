// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int result = syscall(__NR_stat, path, buf);
	if(result < 0) {
		errno = -result;
		return -1;
	}

	return result;
}
