#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    vector <pair<int,int>> vece;
    vector<int> q;
    string s;
    int countN = 0, countE = 0, cases = 0, p, c;

    while(true) {
        
        cin >> p >> c;
        cin.ignore();

        if(p == 0 && c == 0) {
            break;
        }
        else {
            cases += 1;
        }
        
        for(int i = 0; i < c; i++) {

            getline(cin,s);
            if(s[0] == 'N') {
                countN += 1; countE += 1;
            }
            else if (s[0] == 'E')
            {
                int x = stoi(s.substr(1));
                countE += 1;
                vece.push_back({countE,x});
            }
        }

        while(q.size() != countN) {
            for(int i = 1; i <= p; i++) {
                q.push_back(i);
            }
        }


        while(!vece.empty()) {
            
            int a = vece.front().first;
            int b = vece.back().second;

            for(a; a <= q.size(); a++) {
                if(q[a-1] == b) {
                    q.emplace(q.begin() + vece.front().first - 1, b);
                    q.erase(q.begin() + a-1);
                    vece.erase(vece.begin());
                    break;
                }
            }
        }
        
        cout << "Case " << cases << ":" << endl;
        for(auto it : q) {
            cout << it << endl;
        }

        vector<int>().swap(q);
        vector<pair<int,int>>().swap(vece);


        countN = 0; countE = 0;
        
    }

    return 0;
}