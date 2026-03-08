#ifndef _SHAPE3D_H
#define _SHAPE3D_H


#include "IShape.h"
#include "ShapeParam.h"

template<class T>
class Shape3D : public IShape<T> {
  public:
    inline Shape3D(const ShapeParam<T> & param);

};
template<class T>
inline Shape3D<T>::Shape3D(const ShapeParam<T> & param) : IShape<T>(param) {
}

#endif
