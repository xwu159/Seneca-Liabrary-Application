#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H
namespace sdds {
	void strCpy(char* des, const char* src);

	void strnCpy(char* des, const char* src, int len);

	int strCmp(const char* s1, const char* s2);
}
#endif