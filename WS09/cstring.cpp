#include "cstring.h"

void sdds::strcpy(char* des, const char* src)
{
	while (*src != '\0') {
		*des = *src;
		src++;
		des++;
	}
	*des = '\0';
}

int sdds::strlen(const char* s)
{
	int length = 0;
	while (*s != '\0') {
		length++;
		s++;
	}
	return length;
}
