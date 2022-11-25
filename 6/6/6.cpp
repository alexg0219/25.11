#include<iostream>
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

    int h, n, m, max, min, min1;
    input >> n >> m;
    vector <int> a(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            input >> h;
            if (i == 0 || a[j] < h) 
                a[j] = h;
            if (j == 0 || min > h) 
                min = h;
        }
        if (i == 0 || min > min1) 
            min1 = min;
    }
    max = a[0];
    for (int i = 1; i < m; i++)
        if (max > a[i]) max = a[i];
    output << min1 << " " << max;

    input.close();
    output.close();
}
