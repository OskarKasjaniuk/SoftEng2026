#ifndef _SHAPEFACTORY_H
#define _SHAPEFACTORY_H

#include "IShape.h"
#include "ShapeParam.h"

// --- 2D ---
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Trapeze.h"
#include "Rhombus.h"
#include "Ellipse.h"
#include "Hexagon.h"

// --- 3D ---
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Pyramid.h"
#include "Ellipsoid.h"
#include "Torus.h"

template<class T>
class ShapeFactory {
  public:
    static inline IShape<T>* create(const ShapeParam<T> & param);

};
template<class T>
inline IShape<T>* ShapeFactory<T>::create(const ShapeParam<T> & param)
{
    switch (param.type)
    {
        // --- 2D ---
        case PT_CIRCLE:    return new Circle<T>(param);
        case PT_RECT:      return new Rectangle<T>(param);
        case PT_TRIANGLE:  return new Triangle<T>(param);
        case PT_TRAPEZE:   return new Trapeze<T>(param);
        case PT_RHOMBUS:   return new Rhombus<T>(param);
        case PT_ELLIPSE:   return new Ellipse<T>(param);
        case PT_HEXAGON:   return new Hexagon<T>(param);

        // --- 3D ---
        case PT_SPHERE:    return new Sphere<T>(param);
        case PT_CYLINDER:  return new Cylinder<T>(param);
        case PT_CONE:      return new Cone<T>(param);
        case PT_PYTAMID:   return new Pyramid<T>(param);
        case PT_ELLIPSOID: return new Ellipsoid<T>(param);
        case PT_TORUS:     return new Torus<T>(param);

        default: return nullptr;
    }
}

#endif
