#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, p, q;
    cin >> n >> m;
    cin >> p >> q;

    int* a = new int[n];
    int* b = new int[m];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }

    if(a[p-1] < b[m-q]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    

    delete[] a; 
    delete[] b;

    return 0;
}
