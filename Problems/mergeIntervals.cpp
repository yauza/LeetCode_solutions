#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void printtab(vector<vector<int>> v){
    for(auto i : v){
        cout << "[" << i[0] << "," << i[1] << "]  ";
    }
    cout << endl;
}

bool sortByFirst(const vector<int>& v1, const vector<int>& v2){
    return v1[0] < v2[0];
}

vector<vector<int>> mergeI(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), sortByFirst);
    if(intervals.size() == 0) return 0;
    int i = 0, s, e;
    s = intervals[0][0];
    e = intervals[0][1];

    while(i < intervals.size()){
        if(intervals[i][0] <= e && intervals[i][1] >= e) e = intervals[i][1];
        else if(e < intervals[i][0]){
            res.push_back({s,e});
            s = intervals[i][0];
            e = intervals[i][1];
            i--;
        }
        i++;
    }
    res.push_back({s,e});

    return res;
}


int main(){
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{10,18}};
    printtab(mergeI(intervals));
    return 0;
}



