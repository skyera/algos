// 10.28.2016
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        return removeDuplicates(A, A + n, A) - A;
    }

    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output)
    {
        while (first != last) {
            cout << "first:" <<  *first << endl;
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }

        return output;
    }
};

int main()
{
    Solution s;
    int A[3] = {1,1,2};
    int len = s.removeDuplicates(A, 3);

    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
