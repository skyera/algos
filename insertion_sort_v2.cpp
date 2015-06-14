// Insertion sort
// 6/13/2015
//
#include <iostream>
#include <cassert>

using namespace std;

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            
            j--;
        }
    }
}

void test(int A[], int n, int B[])
{
    cout << "testing\n";
    insertion_sort(A, n);

    for (int i = 0; i < n; i++) {
        bool ok = (A[i] == B[i]);
        if (!ok) {
            cerr << i << ":" << A[i] << " " << B[i] << endl;
        }
        assert(ok);
    }
}

int main()
{
    int a[] = {5,2,4,6,1,3};
    int b[] = {1,2,3,4,5,6};

    test(a, 6, b);

    return 0;
}
