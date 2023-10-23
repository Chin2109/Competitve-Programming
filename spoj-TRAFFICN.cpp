#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

#define MAX 10005
const int INF = 1e9 + 7;

vector<pair<int,int>> graphS[MAX], graphT[MAX];
vector<int> distS(MAX,INF), distT(MAX,INF);

void Dijkstra(int s, vector<int> &dist, vector<pair<int,int>> (&graph)[MAX]) {

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;

    dist[s] = 0;
    Q.push({0,s});

    while(!Q.empty()) {

        pair<int,int> top = Q.top();    Q.pop();
        int kc = top.first;
        int u = top.second;

        if(kc > dist[u]) continue;;

        for(auto it : graph[u]) {

            int w = it.first;
            int v = it.second;

            if(dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
                Q.push({dist[v],v});
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n, m, k, s, t, u, v, d;

    cin >> T;
    while(T--) {

        cin >> n >> m >> k >> s >> t;

        for(int i = 1; i <= n; i++) {
            graphS[i].clear();
            graphT[i].clear();
            distS[i] = INF;
            distT[i] = INF;
        }

        for(int i = 0; i < m; i++) {

            cin >> u >> v >> d;
            
            graphS[u].push_back({d,v});
            graphT[v].push_back({d,u});
        }

        Dijkstra(s,distS,graphS);
        Dijkstra(t,distT,graphT);
        int res = distS[t];

        for(int i = 0; i < k; i++) {

            cin >> u >> v >> d;

            int a = distS[u] + d + distT[v];
            int b = distS[v] + d + distT[u];
            res = min(res,min(a,b));
        }

        cout << (res != INF ? res : -1) << endl;
    }

    return 0;
}