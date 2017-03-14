#include "GreatestProduct.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>


using namespace std;
int GreatestProduct(const vector<int> &numbers, int k)
{

    int *table1 = new int[k];
    int *table2 = new int[k];
    int *table3 = new int[k];
    int max = 0;
    int tmp, result1 = 1, result2 = 1, result3 = 1;
    int min = 0;
    for (int j = 0; j < k; j++) {
        table1[j] = INT_MIN;
        table2[j] = 0;
        table3[j] = INT_MAX;
    }


    for (int i = 0; i < numbers.size(); i++) {


        if (table1[0] < numbers[i]) table1[0] = numbers[i];
        if (table3[k - 1] > numbers[i]) table3[k - 1] = numbers[i];
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k - 1; l++) {
                if (table1[l] > table1[l + 1]) {
                    tmp = table1[l];
                    table1[l] = table1[l + 1];
                    table1[l + 1] = tmp;
                }
                if (table3[l] > table3[l + 1]) {
                    tmp = table3[l];
                    table3[l] = table3[l + 1];
                    table3[l + 1] = tmp;
                }

            }
        }
    }
    for (int j = 0; j < k; j++) {
        result1 = result1 * table1[j];
        result2 = result2 * table3[j];
    }


    for (int m = 0; m < (k / 2) * 2; m = m + 2) {
        if (table3[m] * table3[m + 1] >= table1[max] * table1[max + 1]) {
            tmp = table3[m] * table3[m + 1];
            max += 2;
        }
        for (int i = m + 2; i < k; ++i) {

            tmp = tmp * table1[i];


        }
        cout << tmp << endl;

        result3 = tmp;


    }


    for (int n = 0; n < k; n++) {
        if (table3[n] < 0) min++;

    }
    delete (table1);
    delete (table2);
    delete (table3);
    cout << result1 << endl;
    if (result1 > result3){
        return result1;
    } 

    return result3;
}