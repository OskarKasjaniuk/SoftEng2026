#ifndef _SHAPE2D_H
#define _SHAPE2D_H


#include "IShape.h"
#include "ShapeParam.h"

template<class T>
class Shape2D : public IShape<T> {
  public:
    inline Shape2D(const ShapeParam<T> & param);

};
template<class T>
inline Shape2D<T>::Shape2D(const ShapeParam<T> & param) : IShape<T>(param) {
}

#endif
