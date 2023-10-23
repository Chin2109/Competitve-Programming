#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void Delete(vector<int>& vec, int index) {
    vec.erase(vec.begin() + index);
}

int main() {
    stack<int> st;
    bool out = false;

    while(true) {
        int n;
        cin >> n; out = false;
        if(n == 0) break;

        vector<int> vec(n);

        for(int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        for(int l = 1; l < vec.size() ; l++) {
            if(vec[l] < vec[l-1]) {
                st.push(vec[l-1]);
                Delete(vec, l-1);
                l--;
            }
        }

        if(vec.size() == 1 && !st.empty()) {
            vec.push_back(st.top());
            st.pop();
        }

        else {

            for(int l = 1; l < vec.size(); l++) {
                while(!st.empty() && vec[l] - vec[l-1] > 1) {
                    vec.emplace(vec.begin() + l, st.top());
                    st.pop();
                    l++;
                }
            }
        }

        out = false;

        while(!st.empty()) {
            vec.push_back(st.top());
            st.pop();
        }

        for(int i = 1; i < vec.size(); i++) {
            if(vec[i] < vec[i-1]) {
                cout << "no" << endl;
                out = true;
                break;
            }
        }

        if(out == false) {
            cout << "yes" << endl;
        }
    }

    return 0;
}
