#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<limits.h>

using namespace std;

bool vis[1001];
int dis[1001];  //khoảng cách

//Hàm Bfs cơ bản chỉ duyệt và cập nhật kcach tới từng nước
void Bfs(vector<int> adj[]) {
    
    vis[1] = true;
    queue<int> q;
    dis[1] = 0;
    q.push(1);

    while(!q.empty()) {

        int temp = q.front();
        q.pop();

        for(auto it : adj[temp]) {

            if(!vis[it]) {

                vis[it] = true;
                dis[it] = dis[temp] + 1;    //kcach của nó = kcach của ba nó + 1;
                q.push(it);
            }
        }
    }
}

int main() {

    int n,m,u,v,q,gf;

    cin >> n;   //Nhập nước
    m = n - 1;  //suy ra edge

    vector<int> adj[1001];

    while(m--) {

        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> q;   //số gái
    vector<int> girls;

    while(q--) {
        
        cin >> gf;
        girls.push_back(gf);    //Nhập những nước có gái vào vector girls
    }

    memset(dis,INT_MAX,1001);
    memset(vis,false,1001);

    Bfs(adj);

    int girl_dis = dis[girls[0]];
    int girl_id = girls[0];

    for(int i = 1; i < girls.size(); i++) {

        if(dis[girls[i]] < girl_dis) {

            girl_dis = dis[girls[i]];
            girl_id = girls[i];
        }
    }

    cout << girl_id << endl;

    return 0;
}
