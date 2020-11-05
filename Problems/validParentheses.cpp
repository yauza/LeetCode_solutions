#include <iostream>
#include <vector>
#include <stack>

using namespace std;


bool isValid(string s) {
    stack<char> st;

    for(char c : s){
        if(st.empty() || c == '(' || c == '{' || c == '[') st.push(c);
        if((c == ')' || c == '}' || c == ']') && !st.empty()){
            if(st.top() == '(' && c == ')') st.pop();
            else if(st.top() == '[' && c == ']') st.pop();
            else if(st.top() == '{' && c == '}') st.pop();
            else return false;
        }else if((c == ')' || c == '}' || c == ']') && st.empty()) return false;
    }

    return st.empty();
}


int main(){
    string s = "()[]{}";
    string s1 = "()";
    if(isValid1(s1)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

