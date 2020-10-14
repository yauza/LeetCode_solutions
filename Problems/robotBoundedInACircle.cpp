#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;


bool isRobotBounded(string instructions) {
    vector< pair<int, int> > dir;
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(0,-1));
    dir.push_back(make_pair(1,0));

    int start[2] = {0,0};
    int curr = 0;
    for(int i = 0; i < instructions.size(); ++i){
        if(instructions[i] == 'G'){
            start[0] += dir[curr%4].first;
            start[1] += dir[curr%4].second;
            //cout << start[0] << start[1] << endl;
        }else if(instructions[i] == 'L'){
            curr += 1;
            if(curr > 3) curr = 0;
        }else{
            curr -= 1;
            if(curr < 0) curr = 3;
        }
        cout << start[0] << "." << start[1] << "  " << curr%4 << endl;

    }
    if(start[0] == 0 && start[1] == 0) return true;
    else if(curr%4 == 0) return false;
    else return true;
}


int main(){
    string instructions = "RRGRRGLLLRLGGLGLLGRLRLGLRLRRGLGGLLRRRLRLRLLGRGLGRRRGRLG"; //false
    string i2 = "RLLGLRRRRGGRRRGLLRRR";  //true
    if(isRobotBounded(instructions)) cout << "true";
    else cout << "false";
    if(isRobotBounded(i2)) cout << "true";
    else cout << "false";



    return 0;
}
