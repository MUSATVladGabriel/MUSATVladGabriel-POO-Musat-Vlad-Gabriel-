#include<iostream>
using namespace std;
double medienrint(int nrint[], int dim)
{
	int i;
		double s=0;
	double m;
	for (i = 0; i < dim; i++)
	{
		s = s + nrint[i];
	}
	m = s / dim;
	return m;
}
int main()
{
	int nrint[20], dim=4, i;
	for (i = 0; i < dim; i++)
		cin >> nrint[i];
	cout << endl;
	cout << "Media nr intregi este: ";
	cout<<medienrint(nrint, 4);


}
