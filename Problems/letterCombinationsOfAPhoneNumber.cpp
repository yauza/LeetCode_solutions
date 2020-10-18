#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void printv(vector<string> v){
    for(auto i : v) cout << i << " ";
    cout << endl;
}

void rec(string digits, unordered_map<int,string> myMap, vector<string>& res, int ctr, string nr){
    if(ctr == digits.size()){
        res.push_back(nr);
        return;
    }
    cout << ctr << " ";
    string s = myMap[(digits[ctr]-'0')];
    cout << nr << endl;
    for(int i = 0; i < s.size(); i++){
        nr += s[i];
        rec(digits, myMap, res, ctr+1, nr);
        nr.pop_back();
    }
    cout << ctr << endl;
}


vector<string> letterCombinations(string digits) {
    if(digits.size() == 0) return {};
    unordered_map<int, string> myMap{{2,"abc"}, {3, "def"}, {4,"ghi"}, {5,"jkl"},
    {6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

    //for(auto el : myMap) cout << el.first << " " << el.second << "     ";

    vector<string> res;
    rec(digits, myMap, res, 0, "");
    printv(res);
    return res;
}


int main(){
    string digits = "23";
    vector<string> res = letterCombinations(digits);
    printv(res);
    system("PAUSE");
    return 0;
}
