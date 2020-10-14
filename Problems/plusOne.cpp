#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    if(digits[n-1] != 9){
        digits[n-1] += 1;
        return digits;
    }else{
        int ctr = 0, i = n-1;
        while(i >= 0){
            if(digits[i] == 9) ctr++;
            i--;
        }

        if(ctr == n){
            for(int i = 0; i < n; ++i){
                digits[i] = 0;
            }
            digits.insert(digits.begin(), 1);
            return digits;
        }else{
            i = n-1;
            while(digits[i] == 9){
                digits[i] = 0;
                i--;
            }
            digits[i]++;
            return digits;
        }

    }
}


int main(){
    vector<int> d1{1,2,3};
    vector<int> d2{9,8,9};
    vector<int> d3{9,9,9};

    print(plusOne(d1));
    print(plusOne(d2));
    print(plusOne(d3));

    return 0;
}
