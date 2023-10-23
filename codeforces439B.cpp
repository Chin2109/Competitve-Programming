#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

bool cmp(ll a, ll b) {
    return a < b;
}

int main() {
    ll n, x, sum = 0;
    cin >> n >> x;

    ll *a = new ll[n];

    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    sort(a,a+n,cmp);

    for(ll i = 0; i < n; i++) {
        if(x <= 1) {
            x = 1;
        }

        a[i] *= x;
        sum += a[i];
        x--;
    }

    cout << sum;

    return 0;

}