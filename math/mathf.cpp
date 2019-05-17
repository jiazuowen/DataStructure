#include "mathf.h"

namespace mathf
{

int Palindrome(const char* a, int a_len)
{
    if (a_len == 0) for (; *(a + a_len); ++a_len);
    const char* pa = a;
    const char* pb = a + a_len - 1;
    while (pb - pa >= 0)
    {
        if (*pa++ != *pb--) {
            return 0;
        }
    }
    return pa - a;
}

int abcwabc(const char* a, int a_len)
{
    if (a_len == 0) for (; *(a + a_len); ++a_len);
    if (a_len == 1) return 0;
    const char* pa = a;
    const char* pb = a + a_len / 2;
    const char* p = pb;
    while (p - a < a_len)
    {
        if (*pa == *p) {
            pa++;
            p++;
        } else {
            pa = a;
            pb++;
            p = pb;
        }
    }
    
    return pa - a;
}

}
