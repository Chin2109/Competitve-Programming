#include<iostream>
#include<queue>

#define ll long long

using namespace std;

int main() {

    priority_queue<ll> pq;

    ll n;
    cin >> n;

    ll *a = new ll[n];

    for(ll i = 0; i < n; i++) {

        cin >> a[i];
        pq.push(a[i]);

        if(i < 2) cout << -1 << endl;

        else {
            ll a,b,c;

            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();

            c = pq.top();
            pq.pop();

            cout << a*b*c << endl;

            pq.push(a);
            pq.push(b);
            pq.push(c);
        }
    }

    return 0;
}