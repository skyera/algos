// 6/3/2015
// Add binary
//Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string add_binary(const string &a_str, const string &b_str)
{
    int a_size = a_str.size();
    int b_size = b_str.size();
    int carry = 0; 
    string str;
    
    for (int a_index = a_size - 1, b_index = b_size - 1; a_index >= 0 || b_index >= 0; a_index--, b_index--) {

        // a char
        char a_ch = '0';
        
        if (a_index >= 0) {
            a_ch = a_str[a_index];
        }
        
        // b char
        char b_ch = '0';
        
        if (b_index >= 0) {
            b_ch = b_str[b_index];
        }
        
        // add 2 char/digits
        char ch;

        if (a_ch == '1' && b_ch == '1') {
            // 11
            if (carry == 0) {
                ch = '0';
            } else {
                ch = '1';
            }
            carry = 1;
        } else if ((a_ch == '1' && b_ch == '0') || (a_ch == '0'  && b_ch == '1')) {
            // 10 or 01
            if (carry == 0) {
                ch = '1';
                carry = 0;
            } else {
                ch = '0';
                carry = 1;
            }
        } else {
            // 00
            if (carry == 0) {
                ch = '0';
            } else {
                ch = '1';
            }
            carry = 0;
        }
        str = ch + str;
    }

    if (carry == 1) {
        str = "1" + str;
    }

    return str;
}

void test(const string &a, const string &b, const string &out)
{
    cout << "test " << a << " + " << b << " = " << out << "\n";
    string value = add_binary(a, b);
    bool ok = (value == out);

    if (!ok) {
        cout << "value:" << value << endl;
    }
    assert(ok);
}

int main()
{
    test("11", "1", "100");
    test("100", "010", "110");
    test("0", "", "0");
    test("234", "12", "xxx");

    return 0;
}
