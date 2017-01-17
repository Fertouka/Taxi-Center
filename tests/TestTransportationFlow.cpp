//// fertoud 316295005 amitayi 203839030
//
//#include <iostream>
//#include "gtest/gtest.h"
//#include "Matrix.h"
//#include "TaxiCenter.h"
//#include "LuxuryCab.h"
//#include "TransportationFlow.h"
//
//using namespace std;
//
//class TestTransportationFlow : public::testing::Test {
//protected:
//    Point start;
//    Point end;
//    int width;
//    int height;
//    Matrix grid;
//    list<Driver*> employees;
//    list<Cab*> cabs;
//    TaxiCenter tc;
//    TransportationFlow tf;
//
//    virtual void SetUp() {
//        cout << "Setting Up" << endl;
//    }
//
//    virtual void TearDown() {
//        cout << "Tear Down" << endl;
//    }
//
////initializing the objects
//public:
//    TestTransportationFlow() : start(0, 0), end(2,2), width(3), height(3), grid(width, height),
//           employees(1,new Driver(30,40,'M',10,5)),
//           cabs(1, new LuxuryCab()), tc(&employees,&cabs), tf(grid, tc) {}
//};
////checking if the points are inside the limits of the grid
//TEST_F(TestTransportationFlow, testInputPoints) {
//    ASSERT_GE(start.getX(), 0);
//    ASSERT_LT(start.getX(), width);
//    ASSERT_GE(end.getX(), 0);
//    ASSERT_LT(end.getX(), width);
//    ASSERT_GE(start.getY(), 0);
//    ASSERT_LT(start.getY(), height);
//    ASSERT_GE(end.getY(), 0);
//    ASSERT_LT(end.getY(), height);
//}
////checking that the start point isn't the end point
//TEST_F(TestTransportationFlow, testStartNEend) {
//    ASSERT_FALSE(start == end);
//}
////checking if the matrix size is legal
//TEST_F(TestTransportationFlow, testWidthHeight) {
//    ASSERT_GE(width, 1);
//    ASSERT_GE(height, 1);
//}
