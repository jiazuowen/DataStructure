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
    const char* pa = a;
    const char* pb = a + a_len / 2 + a_len % 2;
    while (pb - a < a_len)
    {
        if (*pa == *pb) {
            pa++;
            pb++;
        } else {
            pa = a;
            pb++;
        }
    }
    
    return pa - a;
}

}
