#include<iostream>
using namespace std;
int main()
{
	int a[10][10], i, j, poz, n, m;
	cin >> n >> m;
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	cout << endl;
	cin >> poz;
	for (i = poz; i < n; i++)
	{
		for (j = 1; j <= m; j++)
			a[i][j] = a[i + 1][j];
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}