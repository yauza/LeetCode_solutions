#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int lastRemaining(int n){

    int first, last, nums;

    if(n%2 == 1){
        first = 2;
        last = n-1;
        nums = (n-1)/2;
    }else{
        first = 2;
        last = n;
        nums = n/2;
    }
    bool direction = false;
    int res;

    while(first != last){
        cout << first << " " << last << " " << direction << endl;
        int sum = first + last;

        if(first == last-2){
            if(direction) res = last;
            else res = first;

            break;
        }

        if(direction){
            if((sum/2)%2 == 0){
                first += 2;
            }else{
                last -= 2;
                first += 2;
            }
            direction = false;
        }else{
            if((sum/2)%2 == 0){
                last -= 2;
            }else{
                last -= 2;
                first += 2;
            }
            direction = true;
        }
    }

    return res;

}


int main(){
   int n;
   cin >> n;
    cout << lastRemaining(n) << endl;
}


