#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

bool cmp(ll a, ll b) {
    return a < b;
}

int main() {
    ll n,a,b,count = 0;

    cin >> n >> a >> b;

    ll *arr = new ll[n];

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr,arr+n,cmp);

    // from a[b-1] to a[n-a] 
    for(ll i = arr[b-1]; i < arr[n-a];i++) {
        count++;
    }

    cout << count;

    return 0;
}