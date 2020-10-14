#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


void rec(vector< vector<int> >& grid, int i, int j, int& counter, int& res){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == -1) return;

    if(grid[i][j] == 2){
        if(counter == 0) res++;
        return;
    }

    grid[i][j] = -1;
    counter--;

    rec(grid, i+1, j, counter, res);
    rec(grid, i-1, j, counter, res);
    rec(grid, i, j+1, counter, res);
    rec(grid, i, j-1, counter, res);

    grid[i][j] = 0;
    counter++;
}


int uniquePathsIII(vector< vector<int> >& grid){
    int counter = 1, res = 0;
    int startX, startY;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            if(grid[i][j] == 1){
                startX = i;
                startY = j;
            }
            if(grid[i][j] == 0) counter += 1;
        }
    }

    rec(grid, startX, startY, counter, res);
    return res;

}


int main(){
    vector< vector<int> > grid{{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    cout << uniquePathsIII(grid);

    return 0;
}
