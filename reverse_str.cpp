// 7/30/2018
//
#include <assert.h>
#include <stdio.h>
#include <string.h>

char* reverse_str(char *str) {
    if (str == NULL) 
        return NULL;
    
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }

    return str;
}

void test(char *s1, char *s2) {
    char *p = reverse_str(s1);
    if (s2 != NULL) {
        printf("%s:%s\n", s1, p);
        int result = strcmp(p, s2);
        assert(result == 0);
    } else {
        assert(p == NULL);
    }
}

int main()
{
    char a1[] = "abc";
    char r1[] = "cba";

    test(a1, r1);

    char a2[] = "";
    char r2[] = "";
    test(a2, r2);

    char *p=NULL;
    test(p, NULL);

    char a3[] = "abcd";
    char r3[] = "dcba";
    test(a3, r3);

    return 0;
}
