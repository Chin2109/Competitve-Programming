#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define ll long long

using namespace std;

ll arr[1001];
vector<ll> adj[1001];

ll Bfs(ll m) {

    ll nRes = 0;
    
    ll cat[1001]; //mèo liên tiếp
    memset(cat,0,sizeof(cat));
    bool vis[1001];
    memset(vis,false,sizeof(vis));

    queue<ll> q;

    vis[1] = true;

    if(arr[1] == true) {
        cat[1] = 1;
    }

    q.push(1);

    while(!q.empty()) {

        ll node = q.front();
        q.pop();

        for(ll &it : adj[node]) {

            if(vis[it]) {
                continue;
            }

            vis[it] = true;

            if(arr[it] == 0) { //ko phai meo
                cat[it] = 0;  // suy ra ko lien tiep
            }
            else {
                cat[it] = cat[node] + 1;
            }

            if(cat[it] <= m) {
                if(adj[it].size() == 1) {
                    nRes += 1;
                }
                else {
                    q.push(it);
                }
            }
        }
    }

    return nRes;
}

int main() {

    ll n,m,u,v;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for(ll i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << Bfs(m);
}