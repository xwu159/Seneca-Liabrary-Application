#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	int getInt(int min, int max);
	int getIntError(int min, int max, const char* message);
	int strlen(const char* s);
	void strcpy(char* des, const char* src);
}
#endif // SDDS_UTILS_H__