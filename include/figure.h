#pragma once

#include <memory>
#include <ostream>
#include <istream>
#include "point.h"

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <typename T>
class Figure {
public:
    virtual std::shared_ptr<Figure<T>> clone() const = 0;
    virtual Point getGeomitricCenter() const = 0;
    virtual operator double() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual ~Figure() = default;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& fig) {
    fig.print(os);
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Figure<T>& fig) {
    fig.read(is);
    return is;
}
