#include <QtTest>
#include <..//objects//objects.h>
#include <..//objects//objects.cpp>

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_case1();

};

test::test()
{



}

test::~test()
{

}

void test::test_case1()
{
    Sedan sedan;
    QVERIFY(!sedan.drive(100));
    QCOMPARE(sedan.get_fuel(), 0.0);
    sedan.refuel();
    QCOMPARE(sedan.get_fuel(),1000.0);
    QVERIFY(sedan.drive(500));
    QCOMPARE(sedan.get_mileage(), 500);

    SUV suv;
    QVERIFY(!suv.drive(100));
    QCOMPARE(suv.get_fuel(), 0.0);
    suv.refuel();
    QCOMPARE(suv.get_fuel(),1000.0);
    QVERIFY(suv.drive(500));
    QCOMPARE(suv.get_mileage(), 500);

    Bicycle bicycle;
    QVERIFY(!bicycle.drive(100));
    QCOMPARE(bicycle.get_fuel(), 0.0);
    bicycle.refuel();
    QCOMPARE(bicycle.get_fuel(),1000.0);
    QVERIFY(bicycle.drive(500));
    QCOMPARE(bicycle.get_mileage(), 500);

    Bus bus;
    QVERIFY(!bus.drive(100));
    QCOMPARE(bus.get_fuel(), 0.0);
    bus.refuel();
    QCOMPARE(bus.get_fuel(),1000.0);
    QVERIFY(bus.drive(500));
    QCOMPARE(bus.get_mileage(), 500);

    Route route;
    route.add_point(0, 0, "1");
    route.add_point(100, 100, "2");
    Sedan test_sedan;
    route.run_to_route(&test_sedan);
    QCOMPARE(test_sedan.get_mileage(), 0);
    test_sedan.refuel();
    route.run_to_route(&test_sedan);
    QCOMPARE(test_sedan.get_mileage(), 50);





}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
