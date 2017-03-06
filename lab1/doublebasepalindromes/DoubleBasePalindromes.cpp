//
// Created by adrian on 04.03.17.
//

#include "DoubleBasePalindromes.h"
#include <cstdint>
uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    int i=0, tab[31], suma=0;

    for(i;i<=max_vaule_exculsive;i++)
    {
        int wynik=0, j=0, k=0, odwrotna=0;
        int liczba=i;
        while(liczba>0)
        {
            tab[j]=liczba%2;
            liczba/=2;
            j++;

        }
        if(tab[0])
        {
            for(k;k<j;k++)
            {
                if(tab[k]==tab[j-k-1])
                {
                    wynik+=1;
                }
            }

        }
        liczba=i;
        while(liczba)
        {
            odwrotna=odwrotna*10+liczba%10;
            liczba/=10;
        }
        if(odwrotna==i and wynik==j)
        {
            suma+=i;
        }
    }
    return suma;
}
