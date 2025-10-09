#include<iostream>
using namespace std;
void ordcrescvector(int* v,int dim)
{
	int i, j, aux;
	for (i = 0; i < dim - 1; i++)
	{
		for (j = i+1; j < dim; j++)
		{
			if (v[j] < v[i])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}
int main()
{ 
	int* v;
	int dim = 5;
	v = new int[10];
	for (int i = 0; i < dim; i++)
		cin >> v[i];
	cout << endl;
	cout << "Vectorul sortat este: ";
	ordcrescvector(v, dim);
	for (int i = 0;i<dim; i++)
		cout << v[i] << ' ';
	delete[] v;
}