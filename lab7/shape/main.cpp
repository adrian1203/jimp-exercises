//
// Created by Adrian on 2017-04-21.
//

#include "Shape.h"
#include <memory>
#include <iostream>
#include <list>
using namespace std;
int main(){
    list<Shade*> lista_incjalizacyjna{new Triangle, new Circle, new Square, new Circle, new Square, new Triangle};
    for (auto n:lista_incjalizacyjna){
        n->Draw();
        cout<<endl;
    }
}