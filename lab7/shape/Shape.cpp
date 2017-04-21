//
// Created by Adrian on 2017-04-21.
//

#include "Shape.h"
#include <iostream>

using namespace std;

void Triangle::Draw() const {
    int tmp1 = 0;
    for(int i = 0 ; i < 4 ; i++ ){
        for(int j = 0 ; j < 5 ; j++){
            if(i == 3 || abs(j-2) == tmp1){
                cout << "X";
            } else{
                cout << " ";
            }
        }
        tmp1++;
        cout << endl;
    }

}


void Square::Draw() const {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i % 6 == 0 || j % 6 == 0) {
                cout << "X";
            } else {
                cout << " ";
            }
        }
        cout << endl;

    }
}




void Circle::Draw() const {
    int tmp1 = 0;
    int tmp2 = 1;
    for(int i = 0 ; i < 9 ; i++ ){
        if(i == 4){ tmp2 = -1;}
        for(int j = 0 ; j < 9 ; j++){
            if( abs(j-4) == tmp1){
                cout << "X";
            } else{
                cout << " ";
            }
        }
        tmp1 += tmp2;
        cout << endl;
    }

}