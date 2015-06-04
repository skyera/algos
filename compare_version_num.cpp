// 6/3/2015
// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
// Here is an example of version numbers ordering:
// 0.1 < 1.1 < 1.2 < 13.37
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>


using namespace std;


int compare_version(const string &a, const string &b)
{
    size_t a_dot_pos = a.find('.');
    if (a_dot_pos == string::npos) {
        return -2;
    }
    
    size_t b_dot_pos = b.find('.');
    if (b_dot_pos == string::npos) {
        return -2;
    }

    string a_major = a.substr(0, a_dot_pos);
    string a_minor = a.substr(a_dot_pos + 1);
    string b_major = b.substr(0, b_dot_pos);
    string b_minor = b.substr(b_dot_pos + 1);
    
    int a_major_num = atoi(a_major.c_str());
    int a_minor_num = atoi(a_minor.c_str());
    int b_major_num = atoi(b_major.c_str());
    int b_minor_num = atoi(b_minor.c_str());
    
    if (a_major_num < b_major_num) {
        return -1;
    } else if (a_major_num > b_major_num) {
        return 1;
    } else {
        // a major == b major
        if (a_minor_num < b_minor_num) {
            return -1;
        } else if (a_minor_num > b_minor_num) {
            return 1;
        } else {
            return 0;
        }
    }
}

void test(const string &a, const string &b, int out)
{
    cout << "test " << a << " " << b << endl;

    int code = compare_version(a, b);
    bool ok = (code == out);
    if (!ok) {
        cout << code << endl;
    }
    assert(ok);
}

int main()
{
    test("0.1", "1.1", -1);
    test("1.1", "1.2", -1);
    test("1.2", "1.1", 1);
    test("13.37", "2.1", 1);
    test("1.21", "1.21", 0);
    test("12", "21", -2);

    return 0;
}
