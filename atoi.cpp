// 5/25/2015
//

#include <iostream>
#include <string>
#include <cctype>
#include<cassert>
#include <climits>

using namespace std;

int myatoi(const string &str)
{
    int i = 0;
    int size = str.size();

    // skip white spaces
    while (i < size && isspace(str[i])) {
        i++;
    }
    
    // str does not contain digits
    if (i == size) {
        return 0;
    }
    
    // sign char?
    bool is_neg = false;
    char ch = str[i];
    if (ch == '-') {
        is_neg = true;
        i++;
    } else if (ch == '+') {
        i++;
    }

    if (i == size) return 0;
    
    double num = 0;
    while (i < size && isdigit(str[i])) {
        ch = str[i];
        num = num * 10 + (ch - '0');
        i++;
    }

    if (is_neg) {
        num = -num;
    }

    if (num >= INT_MAX) return INT_MAX;
    if (num <= INT_MIN) return INT_MIN;
    return num;

}

void test(const string &str, int value)
{
    cout << "test " << str << "\n";

    int val = myatoi(str);
    bool ok = (val == value);
    if (!ok) {
        cout << "val=" << val << "\n";
    }
    assert(ok);

}

int main()
{
    test("1", 1);
    test("x", 0);
    test("-", 0);
    test("-2", -2);
    test("923372036854775809", 2147483647);
    test("11111111111111923372036854775809", 2147483647);
}
