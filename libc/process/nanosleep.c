#include <time.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {

	int result = syscall(__NR_nanosleep, req, rem);
	return result;
}
