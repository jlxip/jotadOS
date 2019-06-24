#include <libc/string.h>

void strinv(char* str) {
	size_t s_str = strlen(str);

	int iterations = (int)s_str/2;
	for(int i=0; i<iterations; i++) {
		char aux = str[i];
		str[i] = str[(s_str-i)-1];
		str[(s_str-i)-1] = aux;
	}
}
