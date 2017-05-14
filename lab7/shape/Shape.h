//
// Created by Adrian on 2017-04-21.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H

#include <iostream>
class Shade{
public:
    virtual void Draw(void) const =0;
};
class Triangle : public Shade{
public:
    void Draw(void) const override;
};
class Square : public Shade{
public:
    void Draw(void) const override;
};
class Circle : public Shade{
public:
    void Draw(void) const override;
};
#endif //JIMP_EXERCISES_SHAPE_H