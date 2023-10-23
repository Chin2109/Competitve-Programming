#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

ll b,e,n;

const int N = 1e5 + 10;

ll arr[N];

bool cmp(ll a, ll b) {
    return a < b;
}

ll before() {
    for(ll i = 2; i <= n; i++) {
        if(arr[i] < arr[i-1]) {
            return b = i - 1;
        }
    }

    return 1;
}

ll end() {
    for(int i = b + 1; i <= n; i++) {
        if(arr[i] > arr[i-1]) {
            return e = i - 1;
        }
    }

    return n;
}

int main() {
    cin >> n;

    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    b = before();
    e = end();

    sort(arr+b,arr+e+1,cmp);

    for(int i = 2; i <= n; i++) {
        if(arr[i] < arr[i-1]) {
            cout << "no";
            return 0;
        }
    }

    cout << "yes" << endl;
    cout << b << " " << e;

    return 0;

}

