#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct str {
    int x,y;
    int sz;
};

const int mx = 52;
bool vis[mx][mx];
char mat[mx][mx]; //map
bool border_area;
int conts = 0; //count the number of squares per lakes

void Dfs(int x, int y, int n, int m) {

    if(x < 1 || x > n || y < 1 || y > m) return;
    if(vis[x][y]) return;
    if(x == 1 || x == n || y == 1 || y == m) {
        border_area = true;
        return;
    }
    //already finished processing which cases need to be returned

    conts++;
    vis[x][y] = true;
    if(mat[x+1][y] == '.') Dfs(x+1,y,n,m);
    if(mat[x-1][y] == '.') Dfs(x-1,y,n,m);
    if(mat[x][y+1] == '.') Dfs(x,y+1,n,m);
    if(mat[x][y-1] == '.') Dfs(x,y-1,n,m);
}

void fill_up(int x, int y, int n, int m) {

    if(x < 1 || x > n || y < 1 || y > m) return;
    if(vis[x][y]) return; //in this function, the rule is đã thăm == đã filled;

    vis[x][y] = true;
    mat[x][y] = '*';

    if(mat[x+1][y] == '.') fill_up(x+1,y,n,m);
    if(mat[x-1][y] == '.') fill_up(x-1,y,n,m);
    if(mat[x][y+1] == '.') fill_up(x,y+1,n,m);
    if(mat[x][y-1] == '.') fill_up(x,y-1,n,m);
}

bool comp(str a, str b) { //it sorts elements in vector, which are struct type

    return(a.sz < b.sz);
}

int main() {

    int n,m,k;
    cin >> n >> m >> k; // k means the number of lakes in need

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            cin >> mat[i][j]; //get map
        }
    }

    vector<str> v; //vector contains each lake's data
    memset(vis,false,sizeof(vis));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(!vis[i][j] && mat[i][j] == '.') { //get how many lake to push in vector && this will make sure you analyse the water, not the land
                
                border_area = false;
                conts = 0;
                Dfs(i,j,n,m);

                if(!border_area) {  //after you call Dfs, you will gather các vũng nước, and you u just need to make sure that it is not the sea

                    str st;
                    st.x = i;
                    st.y = j;
                    st.sz = conts;
                    v.push_back(st);
                }
            }
        }
    }

    memset(vis,false,sizeof(vis));
    sort(v.begin(),v.end(),comp); //after sort, you will have the data of lakes which size increasing

    int siz = (int)v.size(); //để tránh tràn dữ liệu khi trả về số nguyên không dáu chứ hok phải ép kiểu đâu nha
    //có bao nhiêu hồ trong map

    siz -= k; //cập nhật lại lượng hồ cần bỏ để ra được k hồ theo yêu cầu

    //bỏ siz phần tử đầu tiên của vector (đã được sort tăng dần) ==> suy ra lượng ô cần bỏ là min
    int i = 0;
    int x,y;
    int cells = 0; //đếm số ô cần bỏ để lát in ra

    while(siz--) {

        x = v[i].x;
        y = v[i].y;
        cells += v[i].sz;
        fill_up(x,y,n,m);
        i++;
    }

    cout << cells << endl;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}