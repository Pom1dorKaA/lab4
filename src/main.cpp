#include <iostream>
#include <memory>
#include "array.h"
#include "square.h"
#include "triangle.h"
#include "rectangle.h"

int main() {
    Array<double> figures;

    auto tri = std::make_shared<Triangle<double>>(0, 0, 3, 0, 3, 4);
    figures.PushItem(tri);

    auto sq = std::make_shared<Square<double>>(1, 1, 4);
    figures.PushItem(sq);

    auto rect = std::make_shared<Rectangle<double>>(2, 2, 5, 3);
    figures.PushItem(rect);

    std::cout << "All figures:" << std::endl;
    figures.PrintFigures();

    std::cout << "Total area: " << figures.TotalArea() << std::endl;

    figures.DeleteFigure(0);

    std::cout << "After deletion:" << std::endl;
    figures.PrintFigures();

    return 0;
}
