#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

#define MAX 10005
const int INF = 1e9 + 7;

vector<pair<int,int>> graph[MAX];
vector<int> dist(MAX,INF);
vector<string> cities;

int getIndex(string name) {

    for(int i = 0; i < cities.size(); i++) {

        if(name == cities[i]) return i;
    }

    return -1;
}

void Dijkstra(int s, int f) {

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;

    Q.push({0,s});
    dist[s] = 0;

    while(!Q.empty()) {

        pair<int,int> top = Q.top();    Q.pop();

        int kc = top.first;
        int u = top.second;

        if(u == f) break;

        if(kc > dist[u]) continue;

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

    int T,N,neigh,v,w,Q;
    string name,scity,fcity;
    
    cin >> T;
    while(T--) {

        cin >> N;
        for(int i = 1; i <= N; i++) {

            graph[i].clear();
        }
        cities.clear();

        for(int u = 1; u <= N; u++) {

            cin >> name >> neigh;
            cities.push_back(name);

            for(int i = 0; i < neigh; i++) {

                cin >> v >> w;
                graph[u].push_back({w,v});
            }
        }

        cin >> Q;
        for(int i = 0; i < Q; i++) {

            cin >> scity >> fcity;

            int s = getIndex(scity) + 1;
            int f = getIndex(fcity) + 1;

            dist = vector<int>(N+1,INF);
            Dijkstra(s,f);
            cout << dist[f] << endl;
        }
    }

    return 0;
}
