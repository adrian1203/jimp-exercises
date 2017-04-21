//
// Created by Adrian on 2017-04-20.
//
#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main() {
    Kula k(0, 0, 0, 10);
    cout << "Pole kuli: " << k.Pole() << endl;
    cout << "Pole przekroju: " << k.Kolo::Pole() << endl;
    return 0;
}

