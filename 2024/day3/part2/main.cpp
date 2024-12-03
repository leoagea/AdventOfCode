#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string s;
	fstream file("data.txt");

	unsigned long res = 0;
	bool enable = true;
	while(getline(file, s)){
		cout << s << endl;
		int i = 0;
		while(s[i]){
			i++;
			if(s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == '(' && s[i + 3] == ')'){
				i+=4;
				enable = true;
			}
			if(s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 'n' && s[i + 3] == '\'' && s[i + 4] == 't' && s[i + 5] == '(' && s[i + 6] == ')'){
				i+=7;
				enable = false;
			}
			if (s[i] == 'm' && s[i + 1] == 'u' && s[i + 2] == 'l' && s[i + 3] == '(' && enable){
				i += 4;
				int start = i;
				while(isdigit(s[i]))
					i++;
				int n1 = stoi(s.substr(start, i - start));
				if (s[i] != ',')
					continue;
				i++;
				start = i;
				while (isdigit(s[i]))
					i++;
				if (s[i] != ')')
					continue;
				int n2 = stoi(s.substr(start, i - start));
				cout << n1 << "   " << n2 << endl;
				res += n1 * n2;
			}
		}
	}
	cout << res << endl;
}