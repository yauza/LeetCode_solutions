#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2){
    return v1[0] < v2[0];
}

void printvec(vector< vector<int> > A);
void printres(vector<int> res);


vector<int> findRightInterval(vector< vector<int> >& intervals){
    vector<int> res(intervals.size());
    printres(res);
    if(intervals.size() == 1){
        res[0] = -1;
        return res;
    }

    vector< vector<int> > arr;
    arr = intervals;
    int n = intervals.size();
    for(int i = 0; i < n; i++){
        arr[i].push_back(i);
    }

    //printvec(arr);
    sort(arr.begin(), arr.end(), sortcol);
    //printvec(arr);
    bool endLoop = false;
    int val, temp;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n && !endLoop; j++){
            if(i != j){
                if(arr[i][1] <= arr[j][0]){
                    res[arr[i][2]] = arr[j][2];
                    endLoop = true;
                }
            }
        }
        if(!endLoop) res[arr[i][2]] = -1;
        endLoop = false;
    }

    return res;
}


void printvec(vector< vector<int> > A){
    for(int i = 0; i < A.size(); i++){
        cout << "[";
        for(int j = 0; j < A[i].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl << endl;
}

void printres(vector<int> res){
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
    }
}

int binarySearch(vector< vector<int> > arr, int x){
    int n = arr.size();
    int l = 0;
    int p = n-1;

    while(l <= p){
        int mid = (l+p)/2;
        if(arr[mid][0] == x) return mid;
        else if(arr[mid][0] > x) p = mid-1;
        else l = mid+1;

    return -1;
    }

}

vector<int> findRightIntervalFaster(vector< vector<int> >& intervals){
    vector<int> res(intervals.size());
    if(intervals.size() == 1){
        res[0] = -1;
        return res;
    }

    vector< vector<int> > arr;
    arr = intervals;
    int n = intervals.size();
    for(int i = 0; i < n; i++){
        arr[i].push_back(i);
    }

    printvec(arr);
    sort(arr.begin(), arr.end(), sortcol);
    printvec(arr);
    bool endLoop = false;
    int val, temp;

    for(int i = 0; i < n; i++){
        val = arr[arr[i][2]][1];
        cout << "a";
        temp = binarySearch(arr, val);
        cout << temp;

        if(temp == -1){
            auto tmp = upper_bound(arr[i].begin(), arr[i].end(), temp);
        }else{
            while(arr[temp-1][1] == val) temp--;
        }

        if(temp < n){
            res[arr[i][2]] = arr[temp][2];
        }else res[arr[i][2]] = -1;
    }

    return res;


}

int main(){
    int testCase1[3][2] = {{1, 4}, {2, 3}, {3, 4}};

    vector< vector<int> > v1 (3);
    v1[0] = {1, 4};
    v1[1] = {2, 3};
    v1[2] = {3, 4};

    vector< vector<int> > v2{{3,4}, {2,3}, {1,2}};
    vector< vector<int> > v3{{1,2}};
    vector<int> res;

    res = findRightIntervalFaster(v1);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    res = findRightIntervalFaster(v2);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    res = findRightIntervalFaster(v3);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

}

