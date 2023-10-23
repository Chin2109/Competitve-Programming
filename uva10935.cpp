#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int n,m,j;
    queue<int> q;
    vector<int> v;


    while(true) {
        cin >> n;
        if(n == 0) break;

        for(int i = 1; i <= n; i++) {
            q.push(i);
        }

        while(q.size() != 1) {
            m = q.front();
            v.push_back(m);
            q.pop();
            j = q.front();
            q.push(j);
            q.pop();
        }

        cout << "Discarded cards:";
        for(int i = 0; i < v.size(); i++) {
            if(i == v.size() - 1) {
                cout << " " << v[i];
            }
            else {
                cout << " " << v[i] << ",";
            }
        }
        v.clear();
        cout << endl;

        cout << "Remaining card: " << q.front() << endl;
        q.pop();
    }

    return 0;
}