// 10.28.2016
#include <iostream>
using namespace std;

// remove duplicates from sorted array
class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int index1 = 0;
        int index2 = 1;

        while (index2 < n) {
            if (A[index2] == A[index1])
                ++index2;
            else if (index1 + 1 != index2)
                A[++index1] = A[index2++];
        }
        return index1 + 1;
    }
};


int main()
{
    Solution s;
    int A[3] = {1,1,2};
    int n = 3;

    int len = s.removeDuplicates(A, n);

    for (int i = 0; i < len; i++) 
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
