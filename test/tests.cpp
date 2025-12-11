#include <memory>
#include <sstream>
#include "array.h"
#include "square.h"
#include "triangle.h"
#include "rectangle.h"
#include <gtest/gtest.h>


TEST(RectangleTest, AreaAndCenter) {
	Rectangle<double> r(2.0, 3.0, 4.0, 5.0);
	EXPECT_DOUBLE_EQ(static_cast<double>(r), 20.0);
	Point c = r.getGeomitricCenter();
	EXPECT_DOUBLE_EQ(c.x, 2.0);
	EXPECT_DOUBLE_EQ(c.y, 3.0);
}

TEST(SquareTest, AreaAndCenter) {
	Square<double> s(1.0, 1.0, 3.0);
	EXPECT_DOUBLE_EQ(static_cast<double>(s), 9.0);
	Point c = s.getGeomitricCenter();
	EXPECT_DOUBLE_EQ(c.x, 1.0);
	EXPECT_DOUBLE_EQ(c.y, 1.0);
}

TEST(TriangleTest, AreaAndCenter) {
	Triangle<double> t(0.0, 0.0, 3.0, 0.0, 0.0, 4.0);
	EXPECT_DOUBLE_EQ(static_cast<double>(t), 6.0);
	Point c = t.getGeomitricCenter();
	EXPECT_DOUBLE_EQ(c.x, 1.0);
	EXPECT_DOUBLE_EQ(c.y, 4.0/3.0);
}

TEST(ClonePolymorphic, PreservesAreaAndCenter) {
	auto tri = std::make_shared<Triangle<double>>(0.0, 0.0, 3.0, 0.0, 0.0, 4.0);
	auto cloned = tri->clone();
	EXPECT_DOUBLE_EQ(static_cast<double>(*cloned), static_cast<double>(*tri));
	Point c1 = tri->getGeomitricCenter();
	Point c2 = cloned->getGeomitricCenter();
	EXPECT_DOUBLE_EQ(c1.x, c2.x);
	EXPECT_DOUBLE_EQ(c1.y, c2.y);
}

TEST(ArrayTest, PushPopDeleteAndTotal) {
	Array<double> arr;
	auto tri = std::make_shared<Triangle<double>>(0.0, 0.0, 3.0, 0.0, 0.0, 4.0);
	auto sq = std::make_shared<Square<double>>(1.0, 1.0, 2.0);
	auto rect = std::make_shared<Rectangle<double>>(2.0, 2.0, 5.0, 3.0);

	arr.PushItem(tri);
	arr.PushItem(sq);
	arr.PushItem(rect);

	EXPECT_EQ(arr.getSize(), 3u);

	double expected = static_cast<double>(*tri) + static_cast<double>(*sq) + static_cast<double>(*rect);
	EXPECT_DOUBLE_EQ(arr.TotalArea(), expected);

	arr.PopItem();
	EXPECT_EQ(arr.getSize(), 2u);
	EXPECT_DOUBLE_EQ(arr.TotalArea(), static_cast<double>(*tri) + static_cast<double>(*sq));

	EXPECT_DOUBLE_EQ(static_cast<double>(*arr[0]), static_cast<double>(*tri));

	EXPECT_THROW(arr.DeleteFigure(10), std::out_of_range);

	arr.DeleteFigure(0);
	EXPECT_EQ(arr.getSize(), 1u);
}

TEST(StreamReadTest, RectangleRead) {
	Rectangle<double> r(0.0, 0.0, 0.0, 0.0);
	std::istringstream iss("5 6 3 4");
	iss >> r;
	Point c = r.getGeomitricCenter();
	EXPECT_DOUBLE_EQ(c.x, 5.0);
	EXPECT_DOUBLE_EQ(c.y, 6.0);
	EXPECT_DOUBLE_EQ(static_cast<double>(r), 12.0);
}
