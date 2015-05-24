#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// replace all patterns(substring) in a string with a new substring
string replace_all_str(const string &str, const string &pattern,
                       const string &replace)
{
    int str_size = str.size();
    int pat_size = pattern.size();
    int rep_size = replace.size();

    if (pat_size == 0) {
        return str;
    }

    if (str_size < pat_size) {
        return str;
    }

    if (rep_size == 0) {
        return "";
    }

    int end_index = str_size - pat_size;
    string new_str;
    for (int i = 0; i <= end_index;) {
        int k = i;
        bool found = true;
        for (int pat_index = 0; pat_index < pat_size; pat_index++, k++) {
            if (str[k] != pattern[pat_index]) {
                found = false;
                break;
            }
        }
        if (found) {
            new_str += replace;
            i += pat_size;
        } else {
            if (i == end_index) {
                new_str += str.substr(end_index);
                break;
            } else {
                new_str.append(1, str[i]); 
                i++;
            }
        }
    }
    return new_str;
}


void test(const string &str, const string &pat, const string &rep, const string &output)
{
    cout << "testing: str=" << str << " pat=" << pat 
         << " rep=" << rep << " output=" << output << endl;
    string new_str = replace_all_str(str, pat, rep);
    bool ok = (new_str == output);
    if (!ok) {
        cout << "new_str:" << new_str << "\n";
    }
    if (ok) {
        cout << "pass\n";
    } else {
        cout << "fail\n";
    }
    assert(ok);
}

int main()
{
    test("abcd", "cd", "XY", "abXY");
    test("abcdabef", "ab", "X", "XcdXef");
    test("abcd", "x", "y", "abcd");
    test("abba", "a", "XY", "XYbbXY");
    test("a", "a", "xxx", "xxx");
    test("abc", "b", "X", "aXc");
    test("aba", "a", "X", "XbX");
    return 0;
}
