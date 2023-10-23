#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 100001;


void dfs(vector<int> v[], bool visited[], int root)
{
    visited[root] = true;
    for (int i = 0; i < v[root].size(); ++i)
    {
        int adj = v[root][i];
        if (!visited[adj])
        {
            dfs(v, visited, adj);
        }
    }
}

int no_of_connected_components(vector<int> v[], int n)
{
    bool visited[n] = {false};
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(v, visited, i);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> v[n];
        while (m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        printf("%d\n", no_of_connected_components(v, n));
    }
    
    return 0;
}