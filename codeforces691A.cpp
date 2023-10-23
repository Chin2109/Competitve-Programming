#include <iostream>

int n,minutes,bor = 0;
using namespace std;

int main() {
    cin >> n;
    int *a = new int[n+2];

    a[0] = 0;
    a[n+1] = 90;

    for(int i = 1; i < n+1; i++) {
        cin >> a[i];
    }

    for(int j = 0; j <= n+1; j++) {
        for(int k = a[j] + 1; k < a[j+1]; k++) {
            bor += 1;
            if(bor == 15) {
                minutes = a[j] + 15; break;
            }
        }

        if(a[j] >= 75) {
            minutes = 90; break;
        }
        
        if(bor == 15) break;
        bor = 0;
    }

    cout << minutes;

    delete []a;
    return 0;
}