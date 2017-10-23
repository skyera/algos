// compute the max difference
// EPI (65)
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int find_battery_capacity(const vector<int> &h) {
    int min_height = numeric_limits<int>::max();
    int capacity = 0;
    for (const int &height: h) {
        capacity = max(capacity, height - min_height);
        min_height = min(min_height, height);
    }

    return capacity;
}


int main()
{
    return 0;
}
