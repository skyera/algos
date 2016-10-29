// 10.29.2016
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0) return 0;

        int index1 = 0;

        for (int index2 = 1; index2 < n; ++index2) {
            if (A[index2] != A[index1]) {
                if (index2 - index1 > 2) {
                    index1 += 2;
                    A[index1] = A[index2];
                }
            }
        }

        return index1 + 1;
    }
};


int main()
{
    Solution s;
    int A[6] = {1,1,1,2,2,3};

    int len = s.removeDuplicates(A, 6);
    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
