#ifndef STRING_H
#define STRING_H

#include <common/types.h>

size_t strlen(const char* str);
void strcpy(char* dest, const char* orig);
void strdisp(char* str, int n);
void strcat(char* dest, const char* orig);
void strcati(char* dest, const char* orig);
char strcmp(const char* a, const char* b);
char* strdup(const char* orig);
void strinv(char* str);

#endif
