#ifndef STDLIB_H
#define STDLIB_H

#ifndef _LIBALLOC_H
#include <klibc/stdlib/liballoc.hpp>
#endif

#include <klibc/string>

void* operator new(size_t sz);
void* operator new[](size_t sz);
void operator delete(void* p);
void operator delete[](void* p);

void memcpy(void* dst, void* src, size_t sz);

string itoa(int n);
int atoi(string str);

string htoa(uint32_t n);
int htoi(string str);

#endif