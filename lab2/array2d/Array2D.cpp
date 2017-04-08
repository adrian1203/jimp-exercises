//
// Created by adrian on 06.03.17.
//

#include "Array2D.h"
#include <iostream>
int **NewArray2D(int n_rows, int n_columns)
{
    if(n_rows<1 or n_columns<1)
    {
        return nullptr;
    }
    int suma=1;
    int **tab = new int *[n_rows];
    for ( int i = 0; i < n_rows; ++i )
    {
        tab[i] = new int [n_columns];
        for ( int j = 0; j < n_columns; ++j)
        {
            tab[i][j]=suma;
            suma+=1;
        }
    }
    return tab;
}
void Print(int **tablica, int wiersze, int kolumny)
{
    for(int i=0; i< wiersze;i++)
    {
        for(int j=0; j< kolumny;j++)
        {
            std::cout<<tablica[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

}
void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for (int i=0;i<n_rows;i++)
    {
        delete [] array[i];
    }
    delete [] array;
}
