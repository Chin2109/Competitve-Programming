#include<iostream>

using namespace std;

int main() {
    int cns[26] = {0}, cnt[26] = {0}; //tạo 26 ô số lần xuất hiện cho mỗi chuỗi;

    string s,t;

    cin >> s;
    cin >> t;

    for(int i = 0; i < s.length(); i++) { //đếm số lần xuất hiện của mỗi ký tự trong mỗi chuỗi
        cns[s[i] - 'a'] += 1; //vị trí của cns tăng 1, số trong ngoặc = ký tự trong chuỗi chuyển sang ascii - 97 (để ra 0 1 2... ứng với cns á)
    }

    for(int i = 0; i < t.length(); i++) {
        cnt[t[i] - 'a'] += 1;
    }

    //automaton: xóa, array: swap, need tree: hăm, both: cả high

    bool automaton = false, array = false, need_tree = false;

    for(int i = 0; i < 26; i++) {
        if(cns[i] < cnt[i]) {
            need_tree = true; 
            break;
        }
        if(cns[i] > cnt[i]) {
            automaton = true;
        }
    }

    int match = -1, old_match;

    for(int i = 0; i < t.length(); i++) {
        old_match = match;
        for(int j = match + 1; j < s.length(); j++) {
            if(t[i] == s[j]) {
                match = j; 
                break;
            }
        }
        if(match == old_match) { //nếu mà cập nhật được match thì luôn luôn match >= i;
            array = true;
            break;
        }
    }

    if(need_tree == true) {
        cout << "need tree"; return 0;
    } else if(array == true && automaton == true ) {
        cout << "both"; return 0;
    } else if(array == true) {
        cout << "array"; 
    } else if(automaton == true) {
        cout << "automaton"; 
    }

    return 0;

}