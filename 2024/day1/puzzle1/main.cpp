#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
void print_vector(vector<int> vec){
	for(auto it1 = vec.begin(); it1 != vec.end(); it1++){
		cout << *it1 << endl;
	}
	cout << endl;
}

int main(int ac, char **av)
{
	if(ac != 2){
		cerr << "Usage: input file <string>" << endl;
		return 1;
	}

	ifstream file(av[1]);
	if(!file.is_open()){
		cerr << "Usage: file can't be opened" << endl;
		return 1;
	}
	
	string line;
	vector<int> row_1;
	vector<int> row_2;
	while(getline(file, line)){
		string token;
		stringstream ss(line);
		ss >> token;
		row_1.push_back(stoi(token));
		ss >> token;
		row_2.push_back(stoi(token));
	}
	file.close();

	sort(row_1.begin(), row_1.end());
	sort(row_2.begin(), row_2.end());

	auto sum = 0;
	for(int i=0; i < row_1.size(); i++){
		sum += abs(row_1[i] - row_2[i]);
	}

	cout << sum << endl;
}