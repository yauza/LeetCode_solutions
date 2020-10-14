
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;


void printv(vector<int> v){
    for(auto i : v){
        cout << i << "   ";
    }
    cout << endl;
}


int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
                if(v1[0] == v2[0]) return v1[1] > v2[1];
                return v1[0] < v2[0];
         });
    int res = intervals.size(), check = INT_MIN;
    for(int i = 0; i < intervals.size(); i++){
        if(check >= intervals[i][1]) res--;
        else check = intervals[i][1];
    }

    return res;
}


int main(){


    return 0;
}


