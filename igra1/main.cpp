#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    int n,m=4;
    string path = "myfile2.txt";
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "Mistake" << endl;
    }
    fin >> n;
    vector < vector <int> > a(n, vector <int> (m) );
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            fin >> a[i][j];
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    fin.close();
    return 0;
}
