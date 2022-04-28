#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ofstream f1;
    int n,m=4;
    cin >> n;
    vector < vector <int> > a(n, vector <int> (m) );
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    f1.open("myfile.txt");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            f1 << a[i][j] << ' ';
        f1 << endl;
    }
    f1.close();
    return 0;
}
