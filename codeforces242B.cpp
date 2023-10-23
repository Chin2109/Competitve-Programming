#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n,l = 1e9 + 1,r = 0,res;

    cin >> n;
    pair<int,int> *p = new pair<int,int>[n];

    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        l = min(p[i].first,l);
        r = max(p[i].second,r);
    }

    for(int i = 0; i < n; i++) {
        if(p[i].first == l && p[i].second == r) {
            res = i + 1;
            cout << res; return 0;
            break;
        }
    }

    cout << -1;

    return 0;

}