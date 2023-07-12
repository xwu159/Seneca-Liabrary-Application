#include "cstring.h"

namespace sdds {
	void strCpy(char* des, const char* src) {
		while (*src != '\0') {
			*des = *src;
			src++;
			des++;
		}
		*des = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len && src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		if (i < len) {
			des[i] = '\0';
		}
	}

	int strCmp(const char* s1, const char* s2) {
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}
}