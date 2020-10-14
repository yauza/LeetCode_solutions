#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum_gas = 0, sum_cost = 0;
    for(auto i : gas) sum_gas += i;
    for(auto i : cost) sum_cost += i;

    if(sum_cost > sum_gas) return -1;

    int start = 0, tank = 0;
    for(int i = 0; i < gas.size(); i++){
        tank += gas[i] - cost[i];

        if(tank < 0){
            start = i+1;
            tank = 0;
        }
    }

    return start;
}



int main(){
    vector<int> gas1{1,2,3,4,5};
    vector<int> cost1{3,4,5,1,2};
    vector<int> gas2{2,3,4};
    vector<int> cost2{3,4,3};
    vector<int> gas3{1,2,1};
    vector<int> cost3{1,2,1};

    cout << canCompleteCircuit(gas3,cost3);
    return 0;
}



