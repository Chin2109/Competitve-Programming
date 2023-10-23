#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main() {

    priority_queue<int> rest;

    priority_queue<int,vector<int>,greater<int>> top1_3;

    int nres = 0;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {

        int type,x;
        cin >> type;

        if(type == 1) {

            cin >> x;
            nres++;

            //decide xem sẽ điều chỉnh top1_3 nếu cần thiết, ngược lại đẩy x vào rest

            if(!top1_3.empty() &&  x > top1_3.top() ) {

                rest.push(top1_3.top()); //đẩy phần tử maxTop vào rest
                top1_3.pop(); //bỏ maxTop
                top1_3.push(x); //đẩy x vào Top
            }

            //nếu top 1_3 rỗng hoặc x nhỏ hơn thì đẩy vào rest để tạo top 1_3 ở đk sau
            else {
                rest.push(x);
            }

            if(nres % 3 == 0) {

                top1_3.push(rest.top());
                rest.pop();
            }
        }

        if(type == 2) {

            if(!top1_3.empty()) cout << top1_3.top() << endl;

            else cout << "No reviews yet" << endl;     
        }
    }

    return 0;
}
