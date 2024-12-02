#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int isSafe(vector<int> vec){
	if(!is_sorted(vec.begin(), vec.end())){
		reverse(vec.begin(), vec.end());
		if(!is_sorted(vec.begin(), vec.end()))
			return 0;
	}
	for(int i=0 ; i < vec.size() - 1; i++){
		if(abs(vec[i] - vec[i + 1]) < 1 || abs(vec[i] - vec[i + 1]) > 3)
			return 0;
	}
	return 1;
}

int main(){

	ifstream file("data.txt");
	string line;
	vector<int> vec;
	unsigned long result = 0;
	while(getline(file, line)){
		istringstream ss(line);
		while(getline(ss, line, ' '))
			vec.push_back(stoi(line));
		for(auto value : vec)
			cout << "  " << value;
		cout << "  /  ";
		for(int i=0 ; i < vec.size(); i++){
			vector<int> tmp = vec;
			tmp.erase(tmp.begin() + i);
			if(isSafe(tmp)){
				cout << "1";
				result++;
				break;
			}
		}
		cout << endl;
		vec.clear();
	}
	cout << result << endl;
}