//
// Created by Adrian on 2017-06-05.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <class T,class Y>
class  SequentialIdGenerator{
    Y value;
public:
    SequentialIdGenerator(Y iter);
    SequentialIdGenerator();
    int NextValue();
};
template <class T,class Y> SequentialIdGenerator<T,Y>::SequentialIdGenerator(Y iter) {
    //value= static_cast<int>(iter)-1;
    value=iter-1;

}
template <class T,class Y> SequentialIdGenerator<T,Y>::SequentialIdGenerator(){
    value=-1;
};
template <class T,class Y> int SequentialIdGenerator<T,Y>::NextValue() {
    int x;
    ++value;
    return value;

}
#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
