#include<iostream>
#include<queue>
#define ll long long

using namespace std; 

int main() {
    ll n,b,t,d;

    cin >> n >> b;

    ll next_Free = 0;
    queue<ll> q; //khung chứa của sever và thêm 1 phần tử đang xử lí

    for(ll i = 0; i <= n - 1; i++) {
        cin >> t >> d;

        //Xuyên ko đến đây thì mọi thứ như lào
        while(!q.empty() && q.front() <= t) {
            q.pop();
        }


        //xét coai có quăng vô queue được hăm
        if(q.size() <= b) {
            next_Free = max(next_Free,t) + d;
            q.push(next_Free);
            cout << next_Free << endl;
        }
        else {
            cout << -1 << endl;
        }

    }

    return 0;
}