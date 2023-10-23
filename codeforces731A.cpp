#include<iostream>
#include<string.h>
int a,b;

using namespace std;

int main() {
    string s;
    string t;
    string mid;
    cin >> s;
    cin >> t;

    int n = s.length();
    mid = s;

    for(int i = 0; i < n; i++) {
        while(mid[i] < 'z') {
            mid[i]++;
            if(mid < t) {
                cout << mid;
                return 0;
            }
        }
        if(mid[i] == 'z') {
            mid[i] = 'a';
        }
    }
  cout << "No such string";
    
    return 0;
}