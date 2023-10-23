#include<iostream>
#include<queue>
#include<functional>
#include<vector>

using namespace std;

const int INF = 1e10;
const int maxn = 100001;
#define ll long long

int n;
int max_vertex = 0;

vector<pair<int,int>> adj[maxn];

void Get(int n) {

    int a,b,c;

    while(n--) {

        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
}

void Dijkstra(int s, vector<ll> &d) {

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;

    d[s] = 0;
    Q.push({0,s});

    while(!Q.empty()) {

        pair<int,int> top = Q.top();  Q.pop();

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

    cin >> n;
    Get(n);

    vector<ll> d(500,INF);

    int u;
    cin >> u;

    int q;
    cin >> q;

    Dijkstra(u,d);

    int z;
    while(q--) {
        
        cin >> z;
        
        if(d[z] == INF) cout << "NO PATH" << endl;

        else cout << d[z] << endl;
    }

    return 0;
}
