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

    int n, m, x, s, k = 0;
    input >> n >> m;
    vector<int> t;
    vector<vector<int> > a;
    vector<int> na(m);
    vector<int> na1(n);

    for (int i = 0; i < n; i++) {
        t.clear();
        for (int j = 0; j < m; j++)
        {
            input >> x;
            t.push_back(x);
        }
        a.push_back(t);
    }

    for (int i = 0; i < m; i++) {
        s = a[i][0];
        for (int j = 1; j < n; j++)
            if (s > a[i][j])
                s = a[i][j];
        na[i] = s;
    }
    for (int i = 0; i < n; i++) {
        s = a[0][i];
        for (int j = 1; j < m; j++)
            if (s < a[j][i])
                s = a[j][i];
        na1[i] = s;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (na[i] == na1[j])
                k++;
    output << k;

    input.close();
    output.close();
}
