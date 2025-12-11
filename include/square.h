#pragma once
#include "figure.h"

template <typename T>
class Square : public Figure<T> {
public:
    Square(T x, T y, T side)
        : center{x, y}, sideLength(side) {}

    std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Square<T>>(*this);
    }

    Point getGeomitricCenter() const override {
        return center;
    }

    operator double() const override {
        return sideLength * sideLength;
    }

    void print(std::ostream& os) const override {
        os << "Square with center: (" << center.x << ", " << center.y << "), side: " << sideLength;
    }

    void read(std::istream& is) override {
        is >> center.x >> center.y >> sideLength;
    }

private:
    Point center;
    T sideLength;
};
