#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	char nb;
	int id = 0;
	string line;
	vector<int> vec;
	vector<int> compact;
	unsigned long long checkSum = 0;
	ifstream file("../data.txt");

	getline(file, line);

	for(int i=0; i < line.size(); i++){
		nb = line[i] - '0';
		for(int j=0; j < nb; j++){
			if(i % 2)
				vec.push_back(-1);
			else{
				vec.push_back(id);
				if(j == nb - 1)
					id++;
			}
		}
	}

	while (true) {
        int leftIdx = -1;
        for (int i = 0; i < (int)vec.size(); i++) {
            if (vec[i] == -1) {
                leftIdx = i;
                break;
            }
        }
        if (leftIdx == -1)
            break;

        int rightIdx = -1;
        for (int i = (int)vec.size() - 1; i >= 0; i--) {
            if (vec[i] != -1) {
                rightIdx = i;
                break;
            }
        }
        if (rightIdx == -1)
            break;

		if (rightIdx <= leftIdx)
			break;

        vec[leftIdx] = vec[rightIdx];
        vec[rightIdx] = -1;
    }

	for(auto it=vec.begin(); *it != -1; it++)
		compact.push_back(*it);

	for(int i=0; i < compact.size(); i++)
		checkSum += compact[i] * i;

	cout << checkSum << endl;
}