#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n < 0) {
        cout << abs(n) * 2 - 1 << "\n";
    } else {
        cout << abs(n) * 2 << "\n";
    }
    return 0;
}