#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

    vector<int> res;
    for(int i = 0; i < asteroids.size(); i++){
        if(asteroids[i] > 0 || res.empty() || res.back() < 0) res.push_back(asteroids[i]);
        else if(asteroids[i]*(-1) >= res.back()){
                if(asteroids[i]*(-1) > res.back()) i--;
                res.pop_back();

        }
    }

    return res;
}

int main(){

    return 0;
}
