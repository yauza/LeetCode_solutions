#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

void printv(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int leastInterval(vector<char>& tasks, int n) {
    if(n == 0) return tasks.size();
    unordered_map<char, int> mp;
    int c = 0;
    for(auto t : tasks){
        mp[t]++;
        c = max(c, mp[t]);
    }

    int res = (c-1)*(n+1);

    for(auto i : mp){
        if(i.second == c) res++;
    }

    return max((int)tasks.size(), res);

}

int main(){
    vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'};
    vector<char> t1{'A','A','A','B','B','B'};
    int n = 2;
    cout << leastInterval(t1, n) << endl;

    return 0;
}



