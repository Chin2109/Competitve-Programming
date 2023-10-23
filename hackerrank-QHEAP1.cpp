#include<iostream>
#include<functional>
#include<queue>

using namespace std;

int main() {

    int n,m;
    cin >> n;

    priority_queue<int,vector<int>,greater<int>> min_heap;

    while(n--) {

        cin >> m;
        if(m == 1) {

            int a;
            cin >> a;
            min_heap.push(a);
        }

        if(m == 2) {

            
        }

    }
}