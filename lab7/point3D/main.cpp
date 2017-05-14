//
// Created by Adrian on 2017-04-19.
//
#include <iostream>
#include "Point3D.h"
using namespace std;
using namespace geometry;

int main(){
    //zadanie 5
    //pierwszy wywoływane jest konstruktor klasy bazowej 2d
    //drugi wywoływany jest konstruktor klasy pochodnej 3d
    //w przypadku dekonstruktorów pierwszy wywoływany jest dla klasy pochodnej, później dla klasy bazowej
    Point3d  a(1,2,3);

    //zadanie 6
    //zwraca odległośc pomiędzy punktami  w 2d i wspołrzednymi x i y punktu 3d(ktory jest rzutowany na klase bazowa Point)
    Point3d point2d(1,2);
    Point3d point3d (4,1,3);
    cout<<"Distance:"<<point2d.Distance(point3d)<<endl;

    //zadanie 7
    //ponieważ klasa Point3D nie ma przeciążonego operatora <<
    //dlatego zostanie wywołany operator klazsy bazowej 2d
    Point3d p3d(1,2,3);
    cout << p3d << endl;

    return 0;
}