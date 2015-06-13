// 6/12/2015
// Insertion sort
//
#include <iostream>
#include <cassert>

using namespace std;

void insertion_sort(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << ",";    
    }

    cout << endl;
    for (int i = 1; i < n; i++) {
        int key = a[i];

        // compare key with every item in sorted sequence
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > key) {
                a[j + 1] = a[j]; 
            } else {
                break;
            }
        }
        a[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ",";    
    }
    cout << endl;
}

void test(int A[], int n, int B[])
{
    cerr << "testing\n";
    insertion_sort(A, n);

    for (int i = 0; i < n; i++) {
        bool ok = (A[i] == B[i]);
        if (!ok) {
            cerr << "i = " << i << " A[i]=" << A[i] << " B[i]=" << B[i] << endl;
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
