// 5/25/2015
// convert an integer to string
//
#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

// convert an intger to a string 
string int_to_str(int x)
{
    bool is_neg = false;
   
    if (x < 0) {
        is_neg = true;
        x = -x;
    }    

    string s;

    do {
        char ch = x % 10 + '0';
        s += ch;
        x /= 10;
    } while (x > 0);

    reverse(s.begin(), s.end());
    
    if (is_neg) {
        s = "-" + s;
    }

    return s;
}

void test(int x, const string &out)
{
    string str = int_to_str(x);
    bool ok = (str == out);
    if (!ok) {
        cout << str << "\n";
    }
    assert(ok);
}

int main()
{
    test(0, "0");
    test(123, "123");
    test(-123, "-123");

    return 0;
}
