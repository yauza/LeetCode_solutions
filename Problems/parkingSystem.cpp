
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        bigP = big;
        medP = medium;
        smallP = small;
    }

    bool addCar(int carType) {
        if(carType == 1){
            if(bigP > 0){
                bigP--;
                return true;
            }else{
                return false;
            }
        }else if(carType == 2){
            if(medP > 0){
                medP--;
                return true;
            }else{
                return false;
            }
        }else{
            if(smallP > 0){
                smallP--;
                return true;
            }else{
                return false;
            }

        }
    }
private:
    int bigP;
    int medP;
    int smallP;
};



int main(){
    int big = 1, medium = 1, small = 0;
    vector<int> carType{1,2,3,1};
    ParkingSystem* obj = new ParkingSystem(big, medium, small);
    for(auto i : carType){
        bool param_1 = obj->addCar(i);
        if(param_1) cout << "TRUE" << endl;
        else cout << "False" << endl;
    }


    return 0;
}

