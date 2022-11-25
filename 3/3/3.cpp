#include <iostream>
#include <fstream>
#include <vector>

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

    int n, m, k, ii, jj;
    input >> n >> m >> k;
    vector<char> t;
    vector<vector<char> > a;

    for (int i = 0; i < n+2; i++) {
        t.clear();
        for (int j = 0; j < m+2; j++)
            t.push_back('.');
        a.push_back(t);
    }

    for (int i = 0; i < k; i++) {
        input >> ii >> jj;
        a[ii][jj] = '*';
    }
    for (int i = 1; i < a.size() - 1; i++) {
        for (int j = 1; j < a[i].size() - 1; j++) {
            int k = 0;
            if (a[i][j] != '*') {
                if (a[i - 1][j - 1] == '*')
                    k++;
                if (a[i - 1][j] == '*')
                    k++;
                if (a[i - 1][j + 1] == '*')
                    k++;
                if (a[i][j - 1] == '*')
                    k++;
                if (a[i][j] == '*')
                    k++;
                if (a[i][j + 1] == '*')
                    k++;
                if (a[i + 1][j - 1] == '*')
                    k++;
                if (a[i + 1][j] == '*')
                    k++;
                if (a[i + 1][j + 1] == '*')
                    k++;
                if (k != 0)
                    a[i][j] = 48 + k;
            }
        }
    }
    for (int i = 1; i < a.size() - 1; ++i) 
    {
        for (int j = 1; j < a[i].size() - 1; ++j)
            output << a[i][j];
        output << endl;
    }
}

