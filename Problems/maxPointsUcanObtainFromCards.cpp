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

int maxScore(vector<int>& cardPoints, int k) {
    int sum = 0, n = cardPoints.size(), curr = 0, res;
    //for(auto i : cardPoints) sum += i;

    for(int i = 0; i < k; i++) curr += cardPoints[i];
    res = curr;

    for(int i = 0; i < k; i++){
        curr -= cardPoints[k-i-1];
        curr += cardPoints[n-i-1];
        res = max(res, curr);
    }


    return res;
}

int main(){
    vector<int> c{1,2,3,4,5,6,1};
    vector<int> c1{1,10,100,1,1,1,1,70,2};
    vector<int> c2{1,79,80,1,1,1,200,1};
    vector<int> c3{96,90,41,82,39,74,64,50,30};
    int k = 3;
    cout << maxScore(c, 3) << endl;
    system("PAUSE");
    return 0;
}




