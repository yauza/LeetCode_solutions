#include <iostream>
#include <string.h>


using namespace std;
string rec(int n, string res);

string countandsay(int n){
    if(n == 1) return "1";
    else{
        string a;
        return rec(n, a);
    }

}

string rec(int n, string res){
    if(n == 1){
        return "1";
    }

    res = rec(n-1, res) + res;
    return res;
}


int main(){
    cout << countandsay(4) << endl;

    return 0;
}
