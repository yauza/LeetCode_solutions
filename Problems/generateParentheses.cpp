#include <iostream>
#include <vector>

using namespace std;

void printv(vector<string> v){
    for(auto i : v) cout << i << " " << endl;
    cout << endl;
}

void rec(int n, int i, string s, vector<string>& res, int open, int close){
    if(i >= 2*n) {res.push_back(s); return;}
    if(open == 0) rec(n, i+1, s+"(", res, open+1, close);
    if(open == n) rec(n, i+1, s+")", res, open, close+1);
    if(open == close) rec(n, i+1, s+"(", res, open+1, close);
    if(open < n && open > close){
        rec(n, i+1, s+"(", res, open+1, close);
        rec(n, i+1, s+")", res, open, close+1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    rec(n, 0, "", res, 0, 0);
    vector<string> ans;
    for(int i = 0; i < res.size()/2; i++){
        ans.push_back(res[i]);
    }
    return ans;
}

int main(){
    vector<string> v = generateParenthesis(3);
    printv(v);
    return 0;
}
