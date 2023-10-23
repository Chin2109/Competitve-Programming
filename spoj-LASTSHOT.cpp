#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int me = 10025;

int n,m;
int result, counter;
bool vis[me];
vector<int> adj[me];

void Dfs(int node) {

    vis[node] = true;
    counter++;

    for(auto it : adj[node]) {

        if(!vis[it]) Dfs(it);
    }
}

int main() {

    cin >> n >> m;

    while(m--) {

        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) {

        memset(vis,false,sizeof(vis));
        counter = 0;

        Dfs(i);
        result = max(result,counter);
    }

    cout << result;

    return 0;
}