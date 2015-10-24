// 5/25/2015
// strstr
 
#include <stdio.h>
#include <string.h>
#include <assert.h>


char* mystrstr(const char *haystack, const char *needle)
{
    int hay_len;
    int needle_len;
    int i;
    int end_index;

    if (haystack == NULL || needle == NULL) return NULL;
    
    hay_len = strlen(haystack);
    needle_len = strlen(needle);

    if (hay_len < needle_len) return NULL;
    if (needle_len == 0) return NULL;

    end_index = hay_len - needle_len;
    for (i = 0; i <= end_index; i++) {
        int k = i;
        int j = 0;
        for(; j < needle_len; j++, k++) {
            if (haystack[k] != needle[j]) {
                break; 
            }
        }
        
        if (j == needle_len) {
            return (char *)(haystack + i);
        }
    }

    return NULL;
}

void test(const char *haystack, const char *needle, int pos)
{
    char *p;
    int index;

    p = mystrstr(haystack, needle);
    if (p == NULL) {
        index = -1;
    } else {
        index = p - haystack;
    }
    
    bool ok = (index == pos);
    assert(ok);
}

int main()
{
    test(NULL, NULL, -1);
    test("a", "x", -1);
    test("a", "a", 0);
    test("ab", "b", 1);
    test("abcd", "bc", 1);
    test("abc", "", -1);
    test("a", "xxx", -1);
    test("", "ab", -1);
    test("", "", -1);
    return 0;
}
