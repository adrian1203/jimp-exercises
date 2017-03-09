//
// Created by adrian on 07.03.17.
//

#include "SimpleForwardList.h"
struct ForwardList
{
    int value;
    ForwardList *next;

};

ForwardList* CreateNode(int value)
{
    ForwardList *tmp=new ForwardList;
    tmp->next=NULL;
    tmp->value=value;
    return tmp;

}
void DestroyList(ForwardList *list)
{
    list->next=NULL;
}