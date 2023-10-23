#include<iostream>
#include<vector>

using namespace std;

vector<int> vis;
vector<vector<int>> v;
bool circle;

void Dfs(int n) {

    vis[n] = 1;
    if(circle) return; //đảm bảo đệ quy có điểm dừng. dòng check cirlce ở dưới chỉ làm thoát đoạn đệ quy ở dưới thôi, nhưng nó sẽ tiếp tục truy ngược lên trên, do đó ta cần đặt thêm điều kiện đệ quy ở đây
    
    for(int i = 0; i < v[n].size(); i++) {

        if(vis[v[n][i]] == 1) { // 1: đã duyện qua trước suy ra vòng tròn
            circle = true;
            return;
        }

        else if (vis[v[n][i]] == 0) Dfs(v[n][i]); // 0: chưa duyệt nên duyệt
    }

    vis[n] = 2; // 2: ko có trỏ tới ai nên chuyện vòng tròn là vô ní
}

int main() {
    
    int t,n,m,u,e;
    
    cin >> t;

    while(t--) {

        cin >> n >> m;

        v.assign(n+1,vector<int> ()); //tạo ra n+1 phần tử (vì mún bắt đầu từ 1), mỗi phần tử là một vector số nguyên rỗng
        vis.assign(n+1,0);

        while(m--) {

            cin >> u >> e;
            v[u].push_back(e);
        }

        circle = false;

        for(int i = 0; i < n; i++) {

            if(vis[i] == 0) Dfs(i);
            if(circle) break;
        }

        if(circle) cout << "YES" << endl;
        else cout << "NO" << endl;

        vis.clear();
        v.clear();
    }

    return 0;
}