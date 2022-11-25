#include <iostream>
#include <fstream>
#include <string>

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

    string s,ns;
    
    input >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 58)
            ns = ns + char((s[i] - 48) - i - 1 + 96);
        else
            ns = ns + char((s[i] - 65 + 10) - i - 1 + 96);
    }

    output << ns;

    input.close();
    output.close();
}

