//adaugare coloana pe o pozitie data
#include<iostream>
using namespace std;

void afisarematrice(int a[][10], int diml, int dimc)
{
    for (int i = 0; i < diml; i++)
    {
        for (int j = 0; j < dimc; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void adaugarecoloana(int a[][10], int diml, int& dimc, int* vector, int poz)
{
    for (int i = 0; i < diml; i++)
    {
        for (int j = dimc; j > poz; j--)
        {
            a[i][j] = a[i][j - 1];
        }
        a[i][poz] = vector[i];
    }
    dimc++;
}

int main()
{
    int a[10][10], diml = 4, vector[10], dimc = 4;


    for (int i = 0; i < diml; i++)
        for (int j = 0; j < dimc; j++)
            cin >> a[i][j];


    cout << "Vectorul pe care l adaugam in matrice este: ";
    for (int i = 0; i < diml; i++)
        cin >> vector[i];


    int poz = 3;
    adaugarecoloana(a, diml, dimc, vector, poz);

    afisarematrice(a, diml, dimc);

    return 0;
}