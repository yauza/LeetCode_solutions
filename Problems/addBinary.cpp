#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


string addBinary(string a, string b){
    int i = a.size()-1, j = b.size()-1;
    string res = "";
    bool more = false;
    while(i >= 0 && j >= 0){
        //cout << a[i] << " " << b[j] << endl;
        if((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')){
            if(more){
                res = "0" + res;
                i--;
                j--;
            }else{
                res = "1" + res;
                i--;
                j--;
                more = false;
            }
        }
        if(a[i] == '0' && b[j] == '0'){
            if(more){
                res = "1" + res;
                i--;
                j--;
                more = false;
            }else{
                res = "0" + res;
                i--;
                j--;
            }
        }
        if(a[i] == '1' && b[j] == '1'){
            if(more){
                res = "1" + res;
                --i;
                --j;
            }else{
                res = "0" + res;
                --i;
                --j;
                more = true;
            }
        }
    }


    while(i >= 0){
        if(a[i] == '0'){
            if(more){
                res = "1" + res;
                --i;
                more = false;
            }else{
                res = "0" + res;
                --i;
            }
        }else{
            if(more){
                res = "0" + res;
                --i;
            }else{
                res = "1" + res;
                --i;
                more = false;
            }
        }
    }

    while(j >= 0){
        if(b[j] == '0'){
            if(more){
                res = "1" + res;
                --j;
                more = false;
            }else{
                res = "0" + res;
                --j;
            }
        }else{
            if(more){
                res = "0" + res;
                --j;
            }else{
                res = "1" + res;
                --j;
                more = false;
            }
        }
    }

    if(more){
        res = "1" + res;
    }

    return res;
}


int main(){
    string a = "0";
    string b = "0";
    cout << addBinary(a, b);

    return 0;
}

