#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int countPrimes(int n){

    bool primes[n+1];
    int temp;

    for(int i = 0; i < n; i++){
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;

    for(int j = 2; j <= sqrt(n); j++){
        if(primes[j] == true){
            for(int i = 2; i*j < n; i++){
                primes[i*j] = false;
            }
        }
    }
    int counter = 0;

    for(int i = 0; i < n; i++){
        if(primes[i] == true){
            cout << i << endl;
            counter++;
        }
    }
    return counter;
}


int main(){
    cout << countPrimes(7) << endl;

}
