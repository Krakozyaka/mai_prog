#include <iostream>
#include <string>

using namespace std;

int var_calculation(string name, int variant) {
	return (char(name[0]) % variant);
}

int main()
{
	string name;
	int variant, res;
	cin >> name >> variant;
	res = var_calculation(name, variant);
	cout << res << endl;
	return 0;
}
