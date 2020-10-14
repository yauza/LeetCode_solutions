#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void printtab(vector<vector<int>> v){
    for(auto i : v){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void rec(vector<vector<int>>& grid, int x, int y, int& sum){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 1) return;
    cout << "x: " << x << " y: " << y << endl;
    if(x == grid.size()-1 && y == grid[0].size()-1) sum++;

    rec(grid, x+1, y, sum);
    rec(grid, x, y+1, sum);
}


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int sum = 0, x = 0, y = 0;
    rec(obstacleGrid, x, y, sum);
    return sum;
}


int uniquePathsWithObstaclesDP(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp = obstacleGrid;
    for(int i = 0; i < obstacleGrid.size(); i++){
        for(int j = 0; j < obstacleGrid[i].size(); j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i < obstacleGrid[0].size(); i++){
        if(obstacleGrid[0][i] != 1) dp[0][i] = dp[0][i-1];
        else dp[0][i] = 0;
    }

    for(int j = 1; j < obstacleGrid.size(); j++){
        if(obstacleGrid[j][0] != 1) dp[j][0] = dp[j-1][0];
        else dp[j][0] = 0;
    }

    for(int i = 1; i < obstacleGrid.size(); i++){
        for(int j = 1; j < obstacleGrid[i].size(); j++){
            if(obstacleGrid[i][j] != 1) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else dp[i][j] = 0;
        }
    }

    return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
}


int main(){
    vector<vector<int>> grid{{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> grid1{{0,0,0,0},{0,0,1,0},{1,0,1,0},{1,0,0,0}};

    cout << uniquePathsWithObstaclesDP(grid1) << endl;
    return 0;
}




