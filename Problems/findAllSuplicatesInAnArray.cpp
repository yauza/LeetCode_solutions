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

vector<int> findDuplicates(vector<int>& nums) {//soooo smart
    vector<int> res;

    for(int i = 0; i < nums.size(); i++){
        int j = abs(nums[i])-1;
        if(nums[j] < 0) res.push_back(j+1);
        nums[j] = -nums[j];
    }
    printv(nums);

    return res;
}

int main(){
    vector<int> c{4,3,2,7,8,2,3,1};
    vector<int> res = findDuplicates(c);
    printv(res);
    system("PAUSE");
    return 0;
}





