// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int left = 0 , right = 0 , len = strlen(s) ,maxlen = 0;
    int lastPos[256];
    memset(lastPos, -1 ,sizeof(lastPos));
    int curlen = 0;
    char ch;
    while (left < len && right < len)
    {
        ch = s[right];
        if (lastPos[(unsigned char)ch] < left) {
            lastPos[(unsigned char)ch] = right;
            curlen = right - left + 1;
            if (curlen > maxlen) {
                maxlen = curlen;
            }
            right++;
        }
        else {
                left = lastPos[(unsigned char)ch] + 1;
                lastPos[(unsigned char)ch] = right;
                curlen = right - left + 1;
                right++;
            }
    }
    return maxlen;
    
}