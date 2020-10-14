
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;


void printv(vector<string> v){
    for(auto i : v){
        cout << i << "   ";
    }
    cout << endl;
}

bool compareTimes(string t1, string t2, string t3){
    if((t1[0] == t2[0] && t1[0] == t3[0]) && (t1[1] == t2[1] && t1[1] == t3[1])) return true;
    else{
        int s1 = ((t1[0]-'0')*10 + (t1[1]-'0'));
        int s2 = ((t1[3]-'0')*10 + (t1[4]-'0'));
        int s3 = ((t3[0]-'0')*10 + (t3[1]-'0')), s4 = ((t3[3]-'0')*10 + (t3[4]-'0'));
        cout << s1 << " " << s2 << "    " << s3 << " " << s4 << endl;
        if(s3 == 0 && s1 == 23) return false;

        if(s1 == s3-1){
            if(s2 >= s4) return true;
            else return false;
        }else return false;

    }


}

vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    vector<string> res;
    if(keyName.size() <= 2) return res;
    unordered_map<string, vector<string>> hashmap;
    //printv(keyTime);
    for(int i = 0; i < keyName.size(); i++){
        if(hashmap.find(keyName[i]) == hashmap.end()){
            hashmap[keyName[i]] = {keyTime[i]};
        }else{
            hashmap[keyName[i]].push_back(keyTime[i]);
        }
    }

    for(auto p : hashmap){
        if(p.second.size() >= 3){
            sort(p.second.begin(), p.second.end());
            printv(p.second);
            for(int i = 2; i < p.second.size(); i++){
                if(compareTimes(p.second[i-2], p.second[i-1], p.second[i])){
                        res.push_back(p.first);
                        break;
                }
            }
        }
    }



    sort(res.begin(), res.end());
    return res;
}


int main(){
    vector<string> keyName{"daniel","daniel","daniel","luis","luis","luis","luis"};
    vector<string> keyTime{"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    vector<string> kn1{"john","john","john"};
    vector<string> kt1{"23:58","23:59","00:01"};
    vector<string> kn2{"leslie","leslie","leslie","clare","clare","clare","clare"};
    vector<string> kt2{"18:00","18:51","19:30","19:49","13:00","13:20","14:00"};
    vector<string> kn3{"a","a","a","a","a","a","b","b","b","b","b"};
    vector<string> kt3{"23:27","03:14","12:57","13:35","13:18","21:58","22:39","10:49","19:37","14:14","10:41"};
    vector<string> res = alertNames(kn3,kt3);
    printv(res);


    return 0;
}

