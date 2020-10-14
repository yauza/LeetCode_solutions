#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector< vector<int> > v){
    for(auto i : v){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

bool sortByTh(const vector<int>& p1, const vector<int>& p2){
    return p1[2] < p2[2];
}

bool sortBySec(const vector<int>& p1, const vector<int>& p2){
    return p1[1] < p2[1];
}

bool carPooling(vector<vector<int>>& trips, int capacity) {

    vector< vector<int> > pickup = trips;
    vector< vector<int> > dropoff = trips;

    sort(pickup.begin(), pickup.end(), sortBySec);
    sort(dropoff.begin(), dropoff.end(), sortByTh);


    int ctr = 0, i = 0, j = 0;

    while(i < pickup.size()){
        if(pickup[i][1] < dropoff[j][2]){
            ctr += pickup[i][0];
            i++;
        }else if(pickup[i][1] >= dropoff[j][2]){
            ctr -= dropoff[j][0];
            j++;
        }

        if(ctr > capacity) return false;
    }

    return true;
}


int main(){
    vector< vector<int> > v1{{3,3,7},{2,1,5}};
    int c1 = 4;

    vector< vector<int> > v2{{3,2,7},{3,7,9},{8,3,9}};
    int c2 = 11;

    if(carPooling(v2, c2)) cout << "TRUE";
    else cout << "FALSE";

    return 0;
}
