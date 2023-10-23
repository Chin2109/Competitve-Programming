#include<iostream>

using namespace std;

int main() {
    int n,k;

    cin >> n >> k;

    int *a = new int[n];
    int b[1001] = {0};

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0, count = 0, m = 0;

    for(r = 0; r < n; r++) {
        if(b[a[r]] == 0) {
            count++;
            b[a[r]]++;
        }

        while(count > k) {
            b[l]--;
            if(b[l] == 0) {
                count--;
            }
            l++;
        }

        //nếu = size thì sao
        

    }



    return 0;
    
    
}