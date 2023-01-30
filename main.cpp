#include <iostream>
#include "vector.h"
#include <vector>

using namespace std;

class Student{

};
int main(int, char**) {
    
    Vector<int> v1;
    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    // v1.insert(v1.begin() + 4,15);
    // for (auto it = v1.begin();
    //      it != v1.end(); ++it)
    //     cout << ' ' << *it;
    // cout <<  v1.max_size() << endl;
    vector<long long> v;
    cout << v.max_size() << endl;
    cout << sizeof(int) << endl;
}
