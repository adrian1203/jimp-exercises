//
// Created by adrian on 07.03.17.
//

#include "SimpleForwardList.h"
struct ForwardList
{
    int value;
    ForwardList *next;

};
int main()
{
    ForwardList* Lista = new ForwardList;
    Lista=CreateNode(24);
    DestroyList(Lista);
}