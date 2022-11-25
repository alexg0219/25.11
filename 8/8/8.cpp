#include <iostream>
#include<fstream>
#include<vector>

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

	int k, n,summ=0,c=0;

	input >> n;
	input >> k;

	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
	{
		input >> a[i];
	}

	for (int i = 0; i != (n / k) + (n % k); i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			c++;
			if (c > n)
				break;
			else
				summ += a[i * k + (j - 1)] * (i + 1);
		}

	}

	output << summ << endl;

	input.close();
	output.close();
}
