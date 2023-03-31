// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while(*source != '\0') {
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	while(*source && len) {
		*destination = *source;
		destination++;
		source++;
		len--;
	}
	while(len) {
		*destination = '\0';
		destination++;
		len--;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	while(*destination) {
		destination++;
	}

	while(*source) {
		*destination++ = *source++;
	}
	*destination = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
        while(*destination) {
                destination++;
        }

        while(*source && len) {
                *destination++ = *source++;
		len--;
        }
       	*destination = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while(*str1 == *str2) {
		if(*str1 == '\0' || *str2 == '\0') {
			return 0;
		}

		str1++;
		str2++;
	}

	if(*str1 > *str2) {
		return 1;
	}

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while(len) {
		if(*str1 > *str2)
			return 1;
		if(*str1 < *str2)
			return -1;

		str1++;
		str2++;
		len--;
	}

	return 0;

}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while(*str) {
		if(*str == c)
		{
			return (char *) str;
		}
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	if(str == NULL) {
		return NULL;
	}

	char *p = NULL;
	while(*str) {
		if(*str == c) {
			p = (char *) str;
		}
		str++;
	}

	if(p != NULL) {
		return p;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if(needle == NULL) {
		return (char *) haystack;
	}

	while (*haystack) {
		const char *h = haystack;
		const char *n = needle;
		if(*haystack == *needle) {
			while (*h == *n && *n != '\0') {
				h++;
				n++;
			}
			if(*n == '\0') {
				return (char *) haystack;
			}
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if(*needle == '\0') {
		return (char *) haystack;
	}

	char *p = NULL;
	while(*haystack) {
		const char *h = haystack;
		const char *n = needle;
		if(*haystack == *needle) {
			while(*h == *n && *n != '\0') {
				h++;
				n++;
			}
			if(*n == '\0') {
				p = (char *) haystack;
			}
		}
		haystack++;
	}

	if(p != NULL) {
		return p;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	const char *s = source;
	char *d = destination;
	size_t i;
	for(i = 0; i < num; i++) {
    		d[i] = s[i];
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	const char *s = source;
	char *d = destination;
	size_t i;

	if(s < d) {
		for(i = num; i > 0; i--) {
			*(d+i-1) = *(s+i-1);
		}
	}
	else {
		for(i = 0; i < num; i++) {
			*(d+i) = *(s+i);
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	if(ptr1 == ptr2) {
		return 0;
	}

	const unsigned char* p1 = (const unsigned char*) ptr1;
	const unsigned char* p2 = (const unsigned char*) ptr2;
	while(num) {
		if(*p1 != *p2) {
                	if(*p1 < *p2)
                        	return -1;
                	if(*p1 > *p2)
                        	return 1;
		}
		num--;
		p1++;
		p2++;
	}


	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	unsigned char* s = (unsigned char*) source;
	unsigned char v = (unsigned char) value;
	while(num) {
		*s = v;
		s++;
		num--;
	}

	return source;
}
