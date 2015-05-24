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

    string new_str;

    int end_index = str_size - pat_size;
    for (int i = 0; i< end_index; i++) {
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
            new_str = str.substr(0, i) + replace_str + str.substr(i + pat_size);
            return new_str;

        }
    }

    // Not found, return original string
    return str;
}


int main()
{
    string str="abcdef";
    string pattern = "cd";
    string replace_str = "XY";
    
    // test case 1
    string new_str = replace_first_string(str, pattern, replace_str);
    bool ok = (new_str == "abXYef");
    assert(ok);
    
    // str is empty
    str = "";
    new_str = replace_first_string(str, pattern, replace_str);
    ok = (new_str == "");
    assert(ok);
    
    // str = "a";
    str = "a";
    new_str = replace_first_string(str, pattern, replace_str);
    ok = (str == "a");
    assert(ok);


    cout << "ok\n";
    return 0;
}
