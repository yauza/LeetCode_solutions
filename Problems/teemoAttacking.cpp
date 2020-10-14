#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;



int findPoisonedDuration(vector<int>& timeSeries, int duration) {
     int res = 0;
     if(timeSeries.size() == 0) return res;
     for(int i = 1; i < timeSeries.size(); i++){
        if(timeSeries[i-1] + duration > timeSeries[i]){
            res += timeSeries[i] - timeSeries[i-1];
        }else{
            res += duration;
        }
     }
     res += duration;

     return res;
}




int main(){
    vector<int> timeSeries{1,4,5,7,12,15,63};
    int duration = 100;
    cout << findPoisonedDuration(timeSeries, duration) << endl;


    return 0;
}
