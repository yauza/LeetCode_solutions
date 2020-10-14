#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int integerBreak(int n) {
    //7 -> 12   3*4 = 12
    //8 -> 18   3*3*2 = 18
    //9 -> 27   3*3*3 = 27
    //10 -> 36  3*3*4 = 36

    if(n == 2) return 1;
    else if(n == 3) return 2;
    else if(n == 4) return 4;

    int three = 0, res = 1;

    while(n-3 > 1){
        three++;
        n -= 3;
    }
    for(int i = 0; i < three; i++) res *= 3;

    return res*n;
}


int main(){
    cout << integerBreak(11) << endl;
    return 0;
}
