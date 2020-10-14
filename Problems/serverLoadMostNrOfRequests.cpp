
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;


void printv(vector<int> v){
    for(auto i : v){
        cout << i << "   ";
    }
    cout << endl;
}
//unifnished but close
vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> servers(k);
    vector<int> sLoad(k);
    for(auto i : servers) i = 0;
    vector<int> res;
    int curr = 0, s = 0, c = 0, sta = arrival[0];

    for(int i = 0; i < load.size(); i++){
        s = 0;
        while(s < k && servers[s] > 0){
            s++;
        }
        if(s >= servers.size()) break;
        else{
            servers[s] = load[i];
            sLoad[s]++;
        }
        printv(servers);
        for(int s = 0; s < k; s++){
            if(c < arrival.size() && servers[s] >= (arrival[c+1]-arrival[c])){
                servers[s] -= (arrival[c+1]-arrival[c]);
            }else if() servers[s] = 0;
        }
        c++;
        //printv(servers);
    }
    cout << "asdf";
    printv(sLoad);
    int m = INT_MIN;
    for(auto s : sLoad){
        m = max(s, m);
    }

    for(int s = 0; s < k; s++){
        if(sLoad[s] == m) res.push_back(s);
    }

    return res;
}


int main(){
    int k = 2;
    vector<int> arr{2,3,4,8};
    vector<int> load{3,2,4,3};
    vector<int> res;
    res = busiestServers(k, arr, load);
    cout << endl;
    printv(res);


    return 0;
}

