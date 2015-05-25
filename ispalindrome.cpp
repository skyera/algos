// 5/24/2015
//
// Valid Palindrome
//
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignorining cases.
// For example,
// "A man, a plan, a canal: Panama" is a plaindrome.
// "race a car" is not a palindrome.
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;


bool is_palindrome(const string &str)
{
    int start = 0;
    int end = str.size() - 1;

    while (start < end) {
        // find a char
        while (start < end && !isalnum(str[start])) {
            start++;
        } 

        while (start < end && !isalnum(str[end])) {
            end--;
        }
        
        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }
        
        start++;
        end--;
    }
    return true;
}

void test(const string &str, bool flag)
{
    cout << "test: " << str << endl;
    bool ispal = is_palindrome(str);
    bool ok = (ispal == flag);
    if (!ok) {
        cout << ispal << "\n";
    }
    assert(ok);
}

int main()
{
    test("A man, a plan, a canal: Panama", true);
    test("", true);
    return 0;
}
