#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

/*
vector<int> majorityElement1(vector<int>& nums){
    int ctr = 0, n = nums.size();
    vector<int> res;

    if(n == 0) return res;
    int x = -(n/3) + 1;
    int el = nums[0];
    ctr++;
    for(int i = 1; i < n; i++){
        if(nums[i] == el) ctr++;
        else{
            if(ctr == x){
                el = nums[i];
            }

        }
    }
}
*/



vector<int> majorityElement(vector<int>& nums){
    int el1 = -1, el2 = -1;
    int counter1 = 0, counter2 = 0;
    int n = nums.size();
    vector<int> res;

    if(n == 0) return res;

    for(int i = 0; i < n; i++){
        if(el1 == nums[i]) counter1++;
        else if(el2 == nums[i]) counter2++;
        else if(counter1 == 0){
            el1 = nums[i];
            counter1 = 1;
        }else if(counter2 == 0){
            el2 = nums[i];
            counter2 = 1;
        }else{
            counter1--;
            counter2--;
        }
    }

    int x = (n/3);
    counter1 = 0;
    counter2 = 0;

    for(int i = 0; i < n; i++){
        if(el1 == nums[i]) counter1++;
        else if(el2 == nums[i]) counter2++;
    }


    if(counter1 > x) res.push_back(el1);
    if(counter2 > x) res.push_back(el2);

    return res;
}



//to jest w ca³osci moje i dzia³a tylko przyk³ad na leetcode mi zle pokazal pzdr
vector<int> majorityElement1(vector<int>& nums) {
     int counter = 0, el, m = nums.size();
     vector<int> res;
     if(m == 0) return res;

     int x;
     if(m%3 == 0) x = -(m/3);
     else x = -(m+1/3);

     el = nums[0];
     counter++;
     for(int i = 1; i < nums.size(); ++i){
        if(nums[i] == el) counter++;
        else{
            counter--;
            if(counter <= x){
                el = nums[i];
            }
        }
        cout << counter << " " << nums[i] << endl;
     }

     cout << el << "     " << x << endl;
     int ctr = 0;
     for(auto i : nums){
        if(i == el) ctr++;
     }

     //if(counter >= x){
     if(ctr > (m/3)){
        //cout << "drugi if:  el: " << el << endl;
        res.push_back(el);
        int i = 0, n = nums.size();
        while(i < n){
            if(el == nums[i]){
                nums.erase(nums.begin() + i);
                n--;
                i--;
            }
            i++;
        }
        //cout << endl;
        //print(nums);
        //cout << endl;

        el = nums[0];
        counter = 1;
        //x = -(n/3);

        for(int i = 1; i < n; i++){
            if(el == nums[i]) counter++;
            else{
                counter--;
                if(counter <= 1){
                    el = nums[i];
                }
            }
        }


        if(counter >= 0){
            counter = 0;
            for(auto i : nums){
                if(i == el) counter++;
            }

            if(counter > (m/3)){
                res.push_back(el);
                return res;
            }else{
                return res;
            }

        }else{
            return res;
        }

     }else{
        return res;
     }

}

int main(){
    vector<int> res;
    vector<int> nums1{1,1,1,2,2,3,3,3};
    vector<int> nums2{3,2,3};
    vector<int> nums3{1,2,1,2,1,2,1,2,1,2,3,3,4,5,6,7,1,1,1,1};
    vector<int> nums4{1,2,3};
    vector<int> nums5{6,5,5};
    vector<int> nums6{1,1,1,2,2,2,2,2,2};
    res = majorityElement(nums1);
    cout << endl << endl << endl;
    for(auto i : res) cout << i << " ";
    return 0;
}
