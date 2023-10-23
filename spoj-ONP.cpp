#include<iostream>
#include<stack>
#include<vector>

using namespace std;

string str;

int main() {
    
    int tc;
    cin >> tc; //số biểu thức

    while(tc--) {
        cin >> str;

        stack<char> st;

        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') {
                st.push(str[i]);
            }

            else if (str[i] == ')')
            {
                char t = st.top();
                st.pop(); //pop cái dấu vs cái ngoặc mở
                st.pop();
                cout << t; 
            }

            else if (isalpha(str[i]))
            {
                cout << str[i];
            }

            else {
                st.push(str[i]);
            }
        }

        cout << endl;
    }

    return 0;
}