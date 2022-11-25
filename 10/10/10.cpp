#include <iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (!input)
	{
		cout << "error";
		return 0;
	}

	int k, n, summ, nsumm = 0;

	string s;
	input >> n;
	input >> k;

	summ = n + k;

	s = to_string(summ);

	for (int i = 0; i < s.length(); i++)
	{
		nsumm += (s[s.length() - i - 1] - 48) * pow(3, i);
	}

	output << nsumm;

	input.close();
	output.close();

}