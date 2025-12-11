#pragma once

#include <vector>
#include <memory> 
#include <iostream>
#include <stdexcept>
#include "figure.h"

template <typename T>
class Array {
public:
    Array() = default;  

    void PushItem(std::shared_ptr<Figure<T>> figure); 
    void PopItem();
    void DeleteFigure(size_t index);
    size_t getSize() const;
    std::shared_ptr<Figure<T>>& operator[](size_t index);
    void PrintFigures() const;
    double TotalArea() const;
    ~Array() = default;

private:
    std::vector<std::shared_ptr<Figure<T>>> figures; 
};

template <typename T>
void Array<T>::PushItem(std::shared_ptr<Figure<T>> figure) {
    figures.push_back(figure);
}

template <typename T>
void Array<T>::PopItem() {
    if (!figures.empty()) {
        figures.pop_back();
    }
}

template <typename T>
void Array<T>::DeleteFigure(size_t index) {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    figures.erase(figures.begin() + index);
}

template <typename T>
size_t Array<T>::getSize() const {
    return figures.size();
}

template <typename T>
std::shared_ptr<Figure<T>>& Array<T>::operator[](size_t index) {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}

template <typename T>
void Array<T>::PrintFigures() const {
    for (const auto& figure : figures) {
        std::cout << *figure << std::endl;
        std::cout << "Geometric center: (" 
                  << figure->getGeomitricCenter().x << ", " 
                  << figure->getGeomitricCenter().y << ")" << std::endl;
        std::cout << "Area: " << (double)(*figure) << std::endl;
    }
}

template <typename T>
double Array<T>::TotalArea() const {
    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += (double)(*figure);
    }
    return totalArea;
}
