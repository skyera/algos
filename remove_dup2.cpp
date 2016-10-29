// 10.28.2016
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0) return 0;

        int index = 0;
        for (int i = 1; i < n; i++) 
            if (A[i] != A[index])
                A[++index] = A[i];
        return index + 1;
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
