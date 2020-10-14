#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    if(coordinates.size() == 2) return true;

    double a, b, x1, y1, x2, y2;
    bool p = false;
    x1 = coordinates[0][0];
    y1 = coordinates[0][1];
    x2 = coordinates[1][0];
    y2 = coordinates[1][1];
    if(x1-x2 != 0){
        a = (y1-y2)/(x1-x2);
    }else p = true;
    b = y1 - x1*a;
    // y = ax + b
    // 1 = a + b
    // 2 = 2a + b

    for(int i = 2; i < coordinates.size(); i++){
        double x, y;
        x = coordinates[i][0];
        y = coordinates[i][1];
        if(!p && y != (a*x + b)) return false;
        else if(p && x1 != x) return false;
    }

    return true;
}

int main(){
    vector<vector<int>> coordinates{{1,2}, {2,3}, {3,5}, {4,5}};
    if(checkStraightLine(coordinates)) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;

    return 0;
}



