#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 1e6 + 10; //nạp chồng toán tử

struct Point {
    int x,y;
    bool operator < (const Point &another) {
        return (x < another.x || (x == another.x && y < another.y));
    }
};

int main() {
    int a,b;

    vector<Point> points; 
    
    static bool countX[N];
    static bool countY[N];

    vector<int> x;
    vector<int> y;

    for(int i = 0; i < 8; i++) {
        cin >> a >> b;
        points.push_back({a,b});

        if(!countX[points[i].x]) {
            x.push_back(a);
            countX[points[i].x] = true;
        }

        if(!countY[points[i].y]) {
            y.push_back(b);
            countY[points[i].y] = true;
        }

    } 

    if(x.size() != 3 || y.size() != 3) {
        cout << "ugly";
        return 0;
    }

    sort(points.begin(),points.end());
    sort( x.begin(), x.end() );
    sort( y.begin(), y.end() );

    int index = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) {
                continue;
            }

            if(points[index].x == x.at(i) && points[index].y == y.at(j)) {
                index += 1;
            }

            else {
                cout << "ugly";
                return 0;
            }

        }
    }

    cout << "respectable";

    return 0;
}

