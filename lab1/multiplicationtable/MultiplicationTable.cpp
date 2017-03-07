//
// Created by adrian on 04.03.17.
//

#include "MultiplicationTable.h"
#include <iostream>
void MultiplicationTable(int tab[][10])
{
int i,j;
    for(i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            tab[i][j]=(i+1)*(j+1);
        }
    }
}
void PrintMultiplicationTable(int tab[][10])
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            std::cout<<tab[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}
