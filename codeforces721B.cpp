#include <iostream>
#include <string>

using namespace std;

int main() {
    int n,t;
    string s, password;

    int count[101] = {0};

    cin >> n >> t;

    for(int i = 0; i < n; i++) {
        cin >> s;
        count[s.length()]++;
    }

    cin >> password;

    int best = 0, worst = 0;

    for(int i = 0; i < password.length(); i++) {
        best += count[i]; //best là tổng của những đứa đứng trước password
    }

    worst = best + count[password.length()] - 1; //-1 vì không tính trường hợp password

    //cập nhật tgian delay

    best += 5*(best/t);
    worst += 5*(worst/t);

    cout << best + 1 << " " << worst + 1;

    return 0;

}