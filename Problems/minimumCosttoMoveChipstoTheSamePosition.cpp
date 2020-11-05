#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minCostToMoveChips(vector<int>& position) {
    int even = 0, odd = 0;

    for(auto p : position){
        if(p%2 == 0) even++;
        else odd++;
    }

    return min(even, odd);
}

int main(){
    vector<int> pos{2,2,2,3,3};
    cout << minCostToMoveChips(pos) << endl;
    return 0;
}


