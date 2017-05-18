//
// Created by Adrian on 2017-04-26.
//
#include <iostream>
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall() {
    throw BallException();
}

int main(){
    //najpier catch dla pochodnych później dla bazowej
    try{
        drawBall();
    }catch(BallException a){
        cout << "Blad podczas rysowania kuli" << endl;
    }catch(CircleException b){
        cout << "Blad podczas rysowania koła" << endl;
    }/*catch(...){
        cout<<"Innny";
    }*/

}
