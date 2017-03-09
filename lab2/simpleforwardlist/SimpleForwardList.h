//
// Created by adrian on 07.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H
struct ForwardList
{
    int value;
    ForwardList *next;

};
ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);

#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
