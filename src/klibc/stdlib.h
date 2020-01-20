#ifndef STDLIB_H
#define STDLIB_H

#ifndef _LIBALLOC_H
#include <klibc/stdlib/liballoc.h>
#endif

void* operator new(size_t sz);
void* operator new[](size_t sz);
void operator delete(void* p);
void operator delete[](void* p);

#ifndef _STRING_H
#include <klibc/string.h>
#endif

char* itoa(int n);
int atoi(char* str);

char* htoa(uint32_t n);
int htoi(char* str);

#endif
