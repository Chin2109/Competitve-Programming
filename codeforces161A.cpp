#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll n,m,x,y;

    cin >> n >> m >> x >> y;

    ll *a = new ll[100000];
    ll *b = new ll[100000];

    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    pair<ll,ll> *p = new pair<ll,ll>[100000];
    pair<ll,ll> *q = new pair<ll,ll>[100000];

    for(ll i = 0; i < n; i++) {
        p[i].first = a[i] - x;
        p[i].second = a[i] + y;
    }

    ll i = 0;
    

    for(ll j = 0; j < m; j++) {
        while(i < n) {
            if(b[j] >= p[i].first && b[j] <= p[i].second) {
                q[j].first = i + 1;
                q[j].second = j + 1;
                j++;
            }
            i++;
        }
    }

    ll count = 0;
    for(ll i = 0; i < m; i++) {
        if(q[i].first != 0 && q[i].second != 0) {
            count++;
        }
    }

    cout << count << endl;

    for(ll i = 0; i < m; i++) {
        if(q[i].first != 0 && q[i].second != 0) {
            cout << q[i].first << " " << q[i].second << endl;
        }    
    }

    return 0;
}