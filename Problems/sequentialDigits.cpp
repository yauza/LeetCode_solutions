#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int lenOfNum(int n){
    int ctr = 0;
    while(n > 0){
        ctr++;
        n /= 10;
    }
    return ctr;
}

void rec(int low, int high, int x, int n, int len, vector<int>& res){
    if(x >= low && x <= high && lenOfNum(x) == len){
        res.push_back(x);
        return;
    }

    if(lenOfNum(x) > len) return;
    x = x*10;
    x += n;
    cout << x << " ";
    if(n == 10) return;
    rec(low, high, x, n+1, len, res);
}

vector<int> sequentialDigitsRecursive(int low, int high){
    int p = lenOfNum(low);
    int q = lenOfNum(high);
    int x = 0;
    vector<int> res;
    while(p <= q){
        for(int i = 1; i < 9; ++i){
            rec(low, high, x, i, p, res);
        }
        p++;
    }
    return res;
}


vector<int> sequentialDigits(int low, int high) {  //nie teges
    vector<int> res;
    int p, q, num = 0, digit = 1, x = 0;
    p = lenOfNum(low);
    q = lenOfNum(high);
    num = p;
    int start = 1;
    while(num <= q){
        cout << "a";
        for(int i = 0; i < num && start < 9; ++i){
            x = x*10 + start;
            start++;
        }
        if(x >= low && x <= high){
            res.push_back(x);
            start -= num;
        }
        else if(x < low){
            start++;
            if(start >= 9){
                num++;
                start = 1;
            }
        }else if(x > high){
            num++;
        }
    }

}

void print(vector<int> arr){
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}


int main(){
    int l1 = 100, h1 = 300;
    vector<int> res = sequentialDigitsRecursive(l1, h1);
    cout << endl;
    print(res);

    int l2 = 1000, h2 = 13000;
    res = sequentialDigitsRecursive(l2, h2);
    cout << endl;
    print(res);

    int l3 = 12346, h3 = 100000;
    res = sequentialDigitsRecursive(l3, h3);
    print(res);

    return 0;
}
