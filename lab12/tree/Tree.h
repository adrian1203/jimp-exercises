//
// Created by Adrian on 2017-05-25.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H


#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;
namespace tree{


    template <class Element>
    class Tree{

        shared_ptr<Tree<Element>>  left;
        shared_ptr<Tree<Element>> right;
        Element value;
        size_t size=0;
    public:
        void Insert(const Element &e);
        bool Find(const Element &e);
        size_t Depth();
        size_t Size();
        Element Value();
        Tree(Element v);
        // size_t Dig(Tree* wsk);
        Tree();

        bool operator<(const Element &e);


    };

    template <class Element>
    Tree<Element>::Tree() {}

    template <class Element>
    bool Tree<Element>::operator<(const Element &e) {

        if (this->value<e)return true;
        else return false;

    }

    template <class Element> void Tree<Element>::Insert(const Element &e) {
        shared_ptr<Tree<Element>> wsk = make_shared<Tree<Element>>(*this);
        while (wsk != nullptr) {
            if (wsk->value<e) wsk = wsk->right;
            else wsk =wsk->left;
        }
        wsk->value=e;
        size++;



    }
    template <class Element> Tree<Element>::Tree(Element v) {
        this->value=v;
        size++;

    }
    template <class Element> bool Tree<Element>::Find(const Element &e){}
    template <class Element>  size_t Tree<Element>::Depth(){
        return 1;

    }
    template <class Element>  size_t Tree<Element>::Size(){

        return size;
    }
    template <class Element> Element Tree<Element>:: Value(){
        return value;
    }

    /*template <class Element> size_t Tree<Element>::Dig(Tree *wsk) {
        if (wsk!=NULL){
            Dig(wsk->left);
            Dig(wsk->right);
        }
    }*/


};
#endif //JIMP_EXERCISES_TREE_H

