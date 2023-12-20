#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 

using namespace std;

int main() {
	string line,name_file;
	cin >> name_file;
	ifstream in(name_file+".txt");
	ofstream out;
	out.open("file_result.gift");
	bool answer = false;
	if (in.is_open()) {
		while (getline(in, line)) {
			char first = line[0];
			char last = line[line.length()-1];
			if (first == '-') {
				line[0] = '~';
				out << line << endl;
			}
			else if (first == '+') {
				line[0] = '=';
				out << line << endl;
			}
			else if (last == '?'){
				line.append(" {");
				out << line << endl;
				answer = true;
			}
			else if ((last != '?') and (answer) and (first!='-') and (first!='+')) {
				out << "}" << endl;
				out << line << endl;
			}
			else {
				out << line << endl;
			}
		}
		out << "}" << endl;
	}
	out.close();
	in.close();
}