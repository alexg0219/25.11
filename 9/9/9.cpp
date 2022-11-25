#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

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

    int n, m;
    string t;
    
    input >> n;
    
    vector<string> f;
    vector<string> mt;
    vector<string> a;
    
    for (int i = 0; i < n; i++) {
        input >> t;
        f.push_back(t);
    }
    
    input >> m;
    
    for (int i = 0; i < m; i++) 
    {
        input >> t;
        a.push_back(t);
    }
    
    if (n == 0 && m == 0) 
    {
        output << "Friends:" << endl;
        output << "Mutual Friends:" << endl;
        output << "Also Friend of:" << endl;
    }
    
    if (n == 0 && m) 
    {
        output << "Friends:" << endl;
        output << "Mutual Friends:" << endl;
        output << "Also Friend of: ";
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size() - 1; i++)
            output << a[i] << ", ";
        if (a.size())
            output << a[a.size() - 1] << endl;
    }
    
    if (n && m == 0) 
    {
        output << "Friends: ";
        sort(f.begin(), f.end());
        for (int i = 0; i < f.size() - 1; ++i)
            output << f[i] << ", ";
        if (f.size())
            output << f[f.size() - 1] << endl;
        output << "Mutual Friends:" << endl;
        output << "Also Friend of:" << endl;
    }
    
    if (f.size())
        sort(f.begin(), f.end());
    
    if (mt.size())
        sort(mt.begin(), mt.end());
    
    for (int i = 0; i < f.size(); i++) 
    {
        if (a.size() == 0)
            break;
        for (int j = 0; j < a.size(); j++) 
        {
            if (f[i] == a[j]) 
            {
                mt.push_back(a[j]);
                a.erase(a.begin() + j);
                j--;
                if (a.size() == 0)
                    break;
            }
        }
    }
    if (a.size())
        sort(a.begin(), a.end());
    output << "Friends: ";
    for (int i = 0; i < f.size() - 1; ++i)
        output << f[i] << ", ";
    if (f.size())
        output << f[f.size() - 1] << endl;
    output << "Mutual Friends: ";
    if (mt.size())
        for (int i = 0; i < mt.size() - 1; ++i)
            output << mt[i] << ", ";
    if (mt.size())
        output << mt[mt.size() - 1];
    output << endl;
    output << "Also Friend of: ";
    if (a.size() == 0) {
    }
    else {
        for (int i = 0; i < a.size() - 1; i++)
            output << a[i] << ", ";
        if (a.size() > 0)
            output << a[a.size() - 1] << endl;
    }

    input.close();
    output.close();
}

