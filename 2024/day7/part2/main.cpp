#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool solveLine(long val, vector<long> &vec, long current, int index){
    if(index == vec.size())
        return val == current;
    return solveLine(val, vec, current + vec[index], index + 1) \
        || solveLine(val, vec, current * vec[index], index + 1) \
        || solveLine(val, vec, stol(to_string(current) + to_string(vec[index])), index + 1);
}


int main(){
    ifstream file("../data.txt");
    string line;
    unsigned long long res = 0;

    while(getline(file, line)){
        stringstream ss(line);
        string key;
        getline(ss, key, ':');
        cout << key << endl;
        long val = stol(key);
        getline(ss, key, ' ');
        vector<long> vec;
        while(getline(ss , key , ' ')){
            cout << key << " ";
            vec.push_back(stol(key));
        }
        cout << endl;
        if(solveLine(val, vec, vec[0], 1))
            res += val;
    }
    cout << res << endl;
}