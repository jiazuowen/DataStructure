#ifndef _MATH_H
#define _MATH_H

namespace mathf
{
    /**
     * 回文判断
     * 判断a和b是否是回文字符串
     * 返回 0 表示非回文
     * 返回 > 0 代表回文长度
    */
    int Palindrome(const char* a, int a_len = 0);

    /**
     * 首尾相同
     * 返回相同的长度
    */
    int abcwabc(const char* a, int a_len = 0);
}

#endif