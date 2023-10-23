#include<iostream>

using namespace std;

int main() {
    int n,t;

    cin >> n >> t;

    int *a = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0, real_time = 0, max_book = 0;

    for(r = 0; r < n; r++) {
        real_time += a[r];

        while(real_time > t) {
            real_time -= a[l];
            l++;
        }

        max_book = max(max_book, r - l + 1);
    } 

    cout << max_book;

    return 0;
    
}