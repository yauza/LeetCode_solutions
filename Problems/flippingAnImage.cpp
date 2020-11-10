#include <iostream>
#include <vector>

using namespace std;

void printv(vector<vector<int>> a){
    for(auto i : a){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

    for(int i = 0; i < A.size(); i++){
        int p = 0, q = A[i].size()-1;

        while(p <= q){
            swap(A[i][p], A[i][q]);

            if(A[i][p] == 1) A[i][p] = 0;
            else A[i][p] = 1;

            if(A[i][q] == 1 && p != q) A[i][q] = 0;
            else if(p != q) A[i][q] = 1;

            p++;
            q--;
        }
    }

    return A;
}

int main(){
    vector<vector<int>> a{{1}};
    printv(a);
    vector<vector<int>> b = flipAndInvertImage(a);
    printv(b);
    return 0;
}
