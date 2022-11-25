#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n,answer;

    input >> n;

    answer = 3 * pow(2, n - 1);

    output << answer;

    input.close();
    output.close();
}
