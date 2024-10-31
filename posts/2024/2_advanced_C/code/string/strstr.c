#include <stdio.h>
#include <string.h>

void myRead(char *str) {                        // 将字符串读入到从str开始的一段内存中
    int i = 0;
    char c;     
    while ((c = getchar()) != '\n') {           // 检查读入的字符是否等于约定的字符串结尾字符，这里是'\n'
        str[i++] = c;
        if (i >= 99) {                          // 检查字符串长度是否超出了可接受的范围
            while ((c = getchar()) != '\n')
                ;                               // 空循环，清空输入缓存，防止影响下一次读入
            break;
        }
    }
    str[i] = '\0';                              // 注意字符串总是以'\0'作为结束
}

int main() {
    char str2[100], str1[100];
    puts("Please input the first string:");
    myRead(str1);
    puts("Please input the second string:");
    myRead(str2);
    char *res = strstr(str1, str2);
    if (res == NULL) {
        puts("Not Found.");
    } else {
        printf("Found at %d.\n", (int)(res - str1));
    }
    return 0;
}