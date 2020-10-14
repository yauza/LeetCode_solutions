#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int myAtoi(string str) {
    int i = 0;
    long res = 0;
    bool positive = true;

    while(str[i] == ' ') i++;

    while(i < str.size()){
        if((int(str[i]) > 0 && int(str[i]) < 43) || int(str[i]) == 44 || (int(str[i]) > 45 && int(str[i]) < 48) || int(str[i]) > 57) return res;
        else if(int(str[i]) == 43 || int(str[i]) == 45){
            if(i+1 < str.size() && (int(str[i+1]) > 47 && int(str[i+1]) < 58) && (i == 0 || (i-1 >= 0 && int(str[i-1]) == ' '))){
                positive = (int(str[i]) == 43) ? true : false;
            }else return res;
        }
        else if(int(str[i]) > 47 && int(str[i]) < 58){
            if(positive){
                res = 10*res + (str[i] - '0');
                if(res >= INT_MAX) return INT_MAX;
            }else{
                res = 10*res - (str[i] - '0');
                if(res <= INT_MIN) return INT_MIN;
            }
        }
        i++;
    }

    return res;
}

int main(){
    string str = "-4";
    string str1 = "world 4234";
    cout << myAtoi(str) << endl;
    cout << myAtoi(str1) << endl;

    return 0;
}







