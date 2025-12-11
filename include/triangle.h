#include "figure.h"

template <typename T>
class Triangle : public Figure<T> {
public:
    Triangle(T x1, T y1, T x2, T y2, T x3, T y3)
        : p1{x1, y1}, p2{x2, y2}, p3{x3, y3} {}

    std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Triangle<T>>(*this);
    }

    Point getGeomitricCenter() const override {
        T cx = (p1.x + p2.x + p3.x) / 3;
        T cy = (p1.y + p2.y + p3.y) / 3;
        return Point{cx, cy};
    }

    operator double() const override {
        return 0.5 * std::abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    }

    void print(std::ostream& os) const override {
        os << "Triangle with vertices: (" << p1.x << ", " << p1.y << "), (" 
           << p2.x << ", " << p2.y << "), (" << p3.x << ", " << p3.y << ")";
    }

    void read(std::istream& is) override {
        is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    }

private:
    Point p1, p2, p3;
};
