//
// Created by Adrian on 2017-04-21.
//

#include "Shape.h"
#include <iostream>

using namespace std;

void Triangle::Draw() const {

    cout<<"    X"<<endl;
    cout<<"   X X"<<endl;
    cout<<"  X   X"<<endl;
    cout<<" X     X"<<endl;
    cout<<"X X X X X"<<endl;

}


void Square::Draw() const {

    cout<<"X X X X X X"<<endl;
    for(int i=0;i<4;i++){
        cout<<"X         X"<<endl;
    }
    cout<<"X X X X X X"<<endl;

}




void Circle::Draw() const {

    cout<<"      X"<<endl;
    cout<<"    X   X"<<endl;
    cout<<"  X       X"<<endl;
    cout<<" X         X"<<endl;
    cout<<"  X       X"<<endl;
    cout<<"    X   X"<<endl;
    cout<<"      X"<<endl;
    }

