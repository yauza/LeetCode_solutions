#include <iostream>
#include <string>

using namespace std;

bool buddyStrings(string A, string B) {
    if(A.size() != B.size() || A.empty()) return false;

    if(A != B){
        int ctr = 0;
        char f ='a', s = 'a';
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[i]) continue;
            if(ctr > 2) return false;
            if(ctr == 0){
                f = A[i];
                s = B[i];
                ctr++;
                continue;
            }

            if(A[i] != s || B[i] != f) return false;
            ctr++;
        }

        return ctr == 2;
    }

    if(A.size() > 26) return true;
    vector<int> a(26,0);

    for(auto c : A){
        if(a[c-'a'] == 1) return true;
        a[c-'a']++;
    }

    return false;
}

// a a a b c a a
// a a a c a b a


int main(){

    return 0;
}
