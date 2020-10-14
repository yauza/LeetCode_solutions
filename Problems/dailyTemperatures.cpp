#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

void printv(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> dailyTemperatures(vector<int>& T) {
    stack<pair<int,int>> s;
    int n = T.size();
    vector<int> res(n,0);

    for(int i = n-1; i >= 0; i--){

        while(!s.empty() && T[i] >= s.top().first) s.pop();

        if(s.empty()) res[i] = 0;
        else res[i] = s.top().second - i;

        s.push({T[i], i});
    }


    return res;
}

int main(){
    vector<int> nums{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(nums);
    printv(nums);
    printv(res);

    return 0;
}

