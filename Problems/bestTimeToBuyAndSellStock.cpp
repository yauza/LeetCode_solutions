#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
using namespace std;

void printtab(int prices[], int n){
    for(int i = 0; i < n; ++i){
        cout << prices[i] << " ";
    }
    cout << endl;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 0 || n == 1) return 0;
    int buy;
    buy = prices[0];
    int dp[n];
    dp[0] = 0;


    for(int i = 1; i < n; ++i){
        if(prices[i] < buy) buy = prices[i];
        dp[i] = max(dp[i-1], prices[i]-buy);
    }

    return dp[n-1];
}


int main(){
    /*
    srand(time(NULL));
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        a[i] = rand()%10;
        cout << a[i] << " ";
    }
    cout << endl;
    */
    vector<int> a1{7,1,5,3,6,4}; //5
    vector<int> a2{7,6,4,3,1};  //0
    cout << maxProfit(a1) << endl;

    return 0;
}
