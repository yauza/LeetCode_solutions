#include <iostream>
#include <vector>

using namespace std;

int maxDistToClosest(vector<int>& seats) {
    vector<int> busy;

    for(int i = 0; i < seats.size(); i++){
        if(seats[i] == 1) busy.push_back(i);
    }

    int dis = 0, j = 0;

    for(int i = 0; i < seats.size(); i++){
        //cout << busy[j] << endl;
        if(seats[i] == 1 && j < busy.size()-1){
            j++;
            continue;
        }else{
            if(j == 0 && busy[j] >= i){
                dis = max(dis, busy[j]-i);
                //cout << "busy: " << busy[j] << endl;
            }else if(j == 0 && busy[j] < i){
                dis = max(dis, i-busy[j]);
            }else if(busy[j] >= i){
                dis = max(dis, min(i-busy[j-1], busy[j]-i));
                //cout << "min: " << min(i-busy[j-1], busy[j]-i) << endl;
            }else{
                dis = max(dis, i-busy[j]);
            }
        }

    }

    return dis;
}

int main(){
    vector<int> seats{1,0,0,0,1,0,1};
    vector<int> seats1{1,0,0,0};
    vector<int> seats2{1,0};
    vector<int> seats3{0,1,1,1,0,0,1,0,0};
    cout << maxDistToClosest(seats3) << endl;

    return 0;
}
