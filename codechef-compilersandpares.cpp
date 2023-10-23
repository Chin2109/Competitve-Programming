#include<iostream>
#define ll long long

using namespace std;

int main() {
    ll n, answer = 0;
    cin >> n;

    ll count = 0;

    string s;

    for(ll i = 0; i < n; i++) {
        count = 0;
        answer = 0;
        
        cin >> s;

        for(ll l = 0; l < s.size(); l++) {
            
            if(s[l] == '<') {
                count += 1;
            }
            else if (count == 0)
            {
                break;
            }
            else {
                count--;
            }

            if(count == 0) {
                answer = l + 1;
            }
            
        }

        cout << answer << endl;
    }

    return 0;

}