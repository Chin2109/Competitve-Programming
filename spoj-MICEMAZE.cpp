#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

#define ll long long
const int INF = 1e10;
const int maxn = 1001;

vector<ll> d(maxn,INF);
vector<pair<int,int>> adj[maxn];

void Dijkstra(int e) {

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    
    d[e] = 0;
    Q.push({0,e});

    while(!Q.empty()) {

        pair<int,int> top = Q.top();    Q.pop();
        int u = top.second;
        int kc = top.first;

        if(kc > d[u]) continue;

        for(auto it : adj[u]) {

            int v = it.second;
            int w = it.first;

            if(d[u] + w < d[v]) {

                d[v] = d[u] + w;
                Q.push({d[v],v});
            }
        }
    }
}

int main() {

    int n,e,m,count = 0;
    ll t;
    cin >> n;
    cin >> e;
    cin >> t;
    cin >> m;

    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[b].push_back({c,a});
    }

    Dijkstra(e);

    for(ll i = 0; i < d.size(); i++) {
        if(d[i] <= t) count++;
    }

    cout << count;

    return 0;
} 

//vãi, maxn = 100 test sai, maxn = 1001 accepted=)))))