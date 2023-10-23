#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

vector<int>adj[1001];
int dist[1001];

void bfs(int s) {
    
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while(!q.empty()) {
        
        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {
            if(dist[it] == -1) {
                dist[it] = dist[node] + 6;
                q.push(it);
            }
        }

    }
}

int main() {
    int n,nodes,edges,u,v,s;

    cin >> n;

    for(int i = 0; i < n; i++) {
        
        cin >> nodes >> edges;

        for(int j = 0; j < nodes+1; j++) {
            adj[j].clear();
            dist[j] = -1;
        }

        for(int j = 0; j < edges; j++) {

            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        cin >> s;

        bfs(s);

        for(int z = 1; z <= nodes; z++) {
            if(z == s) {
                continue;
            }
            cout << dist[z] << " ";
        }

        cout << endl;

    }
        
    return 0;
}
