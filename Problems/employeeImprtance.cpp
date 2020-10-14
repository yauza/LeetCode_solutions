#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}


void dfs(vector<Employee*> employees, Employee* e, int& sum, unordered_map<int,Employee*> hashmap){

    sum += e->importance;
    cout << "sum: " << sum << endl;
    print(e->subordinates);
    for(auto i : e->subordinates){
        cout << i << endl;
        dfs(employees, hashmap[i], sum, hashmap);
    }

    return;
}


int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> hashmap;

    for(auto i : employees){
        hashmap[i->id] = i;
    }

    int res = 0;
    dfs(employees, hashmap[id], res, hashmap);
    return res;

}


int main(){
    int id1 = 1;
    vector<Employee*> employees;
    Employee* e1 = new Employee;
    e1->id = 1;
    e1->importance = 5;
    vector<int> s1{2,3};
    e1->subordinates = s1;

    Employee* e2 = new Employee;
    e2->id = 2;
    e2->importance = 3;
    vector<int> s2{};
    e2->subordinates = s2;

    Employee* e3 = new Employee;
    e3->id = 3;
    e3->importance = 3;
    vector<int> s3{};
    e3->subordinates = s3;

    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    cout << getImportance(employees, 1);
    return 0;
}




