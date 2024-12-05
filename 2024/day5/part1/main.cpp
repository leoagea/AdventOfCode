#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ifstream file("../data.txt");

	string line;
	string mid = "\n";
	vector<pair<int, int>> rules;
	long long sum = 0;

	while(getline(file, line) && !line.empty()){
		int n1 = stoi(line.substr(0, line.find("|")));
		int n2 = stoi(line.substr(line.find("|") + 1));
		rules.push_back(pair<int, int>(n1, n2));
	}

	// for (auto &pair : rules){
	// 	cout << pair.first << "    " << pair.second << endl;
	// }

	while (getline(file,line)){
		vector<int> pages;
		stringstream ss(line);
		string token;
		
		while (getline(ss, token, ','))
			pages.push_back(stoi(token));

		unordered_map<int,int> indexOf;
		for (int i = 0; i < (int)pages.size(); i++) {
			indexOf[pages[i]] = i;
		}

		bool valid = true;
		for (auto &r : rules) {
			int X = r.first, Y = r.second;
			if (indexOf.find(X) != indexOf.end() && indexOf.find(Y) != indexOf.end()) {
				if (indexOf[X] >= indexOf[Y]) {
					valid = false;
					break;
				}
			}
		}

		if (valid) {
			int mid = (int)pages.size()/2;
			sum += pages[mid];
		}
	}
	cout << sum << "\n";
	return 0;

}