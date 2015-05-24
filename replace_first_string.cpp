// 5/24/2015

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// replace the first occurence of a string pattern with another one
string replace_first_string(const string &str, 
                            const string &pattern, 
                            const string &replace_str)
{
    int str_size = str.size();
    int pat_size = pattern.size();
    int replace_str_size = replace_str.size();
    
    // str length is less than pattern, return str
    if (str_size < pat_size) {
        return str;
    }
    
    // no chars in pattern, just return str
    if (pat_size == 0) {
        return str;
    }


    int end_index = str_size - pat_size;
    for (int i = 0; i <= end_index; i++) {
        int k = i;
        // compare with every char in pattern
        bool found = true;
        for (int pat_index = 0; pat_index < pat_size; pat_index++, k++) {
            if (str[k] != pattern[pat_index]) {
                found = false;
                break;        
            }
        }

        // Found the pattern in string
        if (found) {
            cout << "found\n";
            string new_str = str.substr(0, i) + replace_str + str.substr(i + pat_size);
            return new_str;

        }
    }

    // Not found, return original string
    cout << "not found\n";
    return str;
}

void test(const string &str, const string &pat, 
          const string &rep, const string &output)
{
    cout << "testing str=" << str << " pat=" << pat << " "
         << "rep=" << rep << " out=" << output << "\n";
    string new_str = replace_first_string(str, pat, rep);
    bool ok = (new_str == output);
    if (!ok) {
        cout << "new_str=" << new_str << "\n";
    }
    assert(ok);
}

int main()
{
    string str="abcdef";
    string pattern = "cd";
    string replace_str = "XY";
    string output = "abXYef";

    // test case 1
    test(str, pattern, replace_str, output);
    
    // str is empty
    str = "";
    test(str, pattern, replace_str, str);
    
    str = "a";
    test(str, pattern, replace_str, str);

    str = "abcd";
    pattern = "bcd";
    replace_str = "XYZ";
    test(str, pattern, replace_str, "aXYZ");
    
    str = "ab";
    pattern = "a";
    replace_str = "X";
    test(str, pattern, replace_str, "Xb");
    
    test("ab", "b", "X", "aX");
    return 0;
}
