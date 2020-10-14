#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void printtab(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

bool sortByDigits(const int v1, const int v2){   //genialne!!!
    string s1 = (to_string(v1))+(to_string(v2));
    string s2 = (to_string(v2))+(to_string(v1));
    return s1 > s2;
}


string largestNumber(vector<int>& nums) {
    vector<string> str;
    string res;

    sort(nums.begin(),nums.end(), sortByDigits);
    if(nums[0] == 0){
        res = res + (to_string(nums[0]));
    }else{
        for(auto i : nums){
            res = res + (to_string(i));
        }
    }

    return res;
}

int main(){
    vector<int> nums{1011, 12, 9, 101};
    cout << largestNumber(nums) << endl;
    return 0;
}
