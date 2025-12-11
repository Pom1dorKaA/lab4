#include "figure.h"

template <typename T>
class Rectangle : public Figure<T> {
public:
    Rectangle(T x, T y, T width, T height)
        : center{x, y}, width(width), height(height) {}

    std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Rectangle<T>>(*this);
    }

    Point getGeomitricCenter() const override {
        return center;
    }

    operator double() const override {
        return width * height;
    }

    void print(std::ostream& os) const override {
        os << "Rectangle with center: (" << center.x << ", " << center.y << "), width: "
           << width << ", height: " << height;
    }

    void read(std::istream& is) override {
        is >> center.x >> center.y >> width >> height;
    }

private:
    Point center;
    T width;
    T height;
};
