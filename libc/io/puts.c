#include <unistd.h>
#include <errno.h>

int puts(const char *string) {
	int chars = 0;

	while (*string != '\0') {
		if (write(1, string, 1) != 1) {
		return -1;
		}
		chars++;
		string++;
	}

	if (write(1, "\n", 1) != 1) {
		return -1;
	}
	chars++;

	return chars;
}

