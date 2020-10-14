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

int bitwiseComplement(int N) {
    if(N == 0) return 1;
    string bin = "";
    int res = 0;
    while(N > 0){
        if(N%2 == 1) bin = "1" + bin;
        else bin = "0" + bin;
        N /= 2;
    }
    cout << bin << endl;
    for(int i = bin.size()-1; i >= 0; i--){
        if(bin[i] == '0') res += pow(2,(bin.size()-1)-i);
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    cout << bitwiseComplement(n) << endl;
    system("PAUSE");
    return 0;
}







