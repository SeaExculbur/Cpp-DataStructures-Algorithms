#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool IsPalindrome(char *str, int left, int right) {
    if (str == NULL) return false;
    if (left > strlen(str) || left < 0) return false;
    if (right > strlen(str) || right < 0) return false;
    if (str[left] != str[right]) return false;
    if (left == right || left > right) return true;
    bool res = IsPalindrome(str , left+1 , right-1);
    if (res == true) return true;
    else return false;
}


int main() {
    char *s1 = "racecar";
    printf("\"%s\" → %s（预期 1）\n", s1,
           IsPalindrome(s1, 0, strlen(s1)-1) ? "true" : "false");

    char *s2 = "hello";
    printf("\"%s\" → %s（预期 0）\n", s2,
           IsPalindrome(s2, 0, strlen(s2)-1) ? "true" : "false");

    char *s3 = "abba";
    printf("\"%s\" → %s（预期 1）\n", s3,
           IsPalindrome(s3, 0, strlen(s3)-1) ? "true" : "false");

    char *s4 = "a";
    printf("\"%s\" → %s（预期 1）\n", s4,
           IsPalindrome(s4, 0, strlen(s4)-1) ? "true" : "false");

    char *s5 = "";
    printf("\"\" → %s（预期 1）\n",
           IsPalindrome(s5, 0, -1) ? "true" : "false");

    return 0;
}