#include <QtTest/QtTest>
#include "calculator.h"


using calculator::calculate;

class QCalculatorTest: public QObject
{
    Q_OBJECT

private slots:
    void checkAddition();
    void checkSubstraction();
    void checkMultiplication();
    void checkDivision();
    void checkParenthesis();
    void ckeckUnaryMinus();
};


void QCalculatorTest::checkAddition()
{
    QCOMPARE(calculate("0 + 0"), static_cast<double>(0 + 0) );
    QCOMPARE(calculate("1 + 3"), static_cast<double>(1 + 3) );
    QCOMPARE(calculate("5 + 9 + 100 + 37 + 0"), static_cast<double>(5 + 9 + 100 + 37 + 0) );
    QCOMPARE(calculate("5.3 + 4.7 + 11.11 + 99.99 + 0."), static_cast<double>(5.3 + 4.7 + 11.11 + 99.99 + 0.) );
    QCOMPARE(calculate("1 + 1.1 + 1000 + 77.12345 + 0. + 0"), static_cast<double>(1 + 1.1 + 1000 + 77.12345 + 0. + 0) );
}

void QCalculatorTest::checkSubstraction()
{
    QCOMPARE(calculate("2 - 2"), static_cast<double>(2 - 2) );
    QCOMPARE(calculate("10 - 5"), static_cast<double>(10 - 5) );
    QCOMPARE(calculate("27 - 10 - 13 + 23 - 0 - 100"), static_cast<double>(27 - 10 - 13 + 23 - 0 - 100) );
    QCOMPARE(calculate("39.12 - 99 + 100 - 89.1234 - 0."), static_cast<double>(39.12 - 99 + 100 - 89.1234 - 0.) );
    QCOMPARE(calculate("111.1 - 111.1 + 213 - 0 + 12 - 0. - 13.3333"), static_cast<double>(111.1 - 111.1 + 213 - 0 + 0.12 - 0. - 13.3333 ) );
}

void QCalculatorTest::checkMultiplication()
{
    QCOMPARE(calculate("0 * 12"), static_cast<double>(0 * 12) );
    QCOMPARE(calculate("3 * 7"), static_cast<double>(3 * 7 + 2 * 3) );
    QCOMPARE(calculate("2 + 2 * 2.5 * 10 - 3"), static_cast<double>(2 + 2 * 2.5 * 10 * 1 * 2 - 3) );
    QCOMPARE(calculate("17.233 * 2 + 3 + 4 * 16.09"), static_cast<double>(17.233 * 2 + 0.3 + 4 * 16.09) );
}

void QCalculatorTest::checkDivision()
{
    QCOMPARE(calculate("0 / 12"), static_cast<double>(0 / 12) );
    QCOMPARE(calculate("145 / 5 - 87 / 3 / 11 / 1"), static_cast<double>(145 / 5 - 87 / 3 / 11 / 1) );
    QCOMPARE(calculate("12.1 * 10 / 22.2 + 13 / 12.01 - 1 - 2 * 2.0 / 0.12"), static_cast<double>(12.1 * 10 / 22.2 + 13 / 12.01 - 1 - 2 * 2.0 / 0.12) );
    QCOMPARE(calculate("0.101 * 1000 / 101 - 1 * 22 / 22 - 3 + 0.23 / 12 / 22 + 2 * 3"), static_cast<double>(0.101 * 1000 / 101 - 1 * 22 / 22 - 3 + 0.23 / 12 / 22 + 2 * 3 ) );
}

void QCalculatorTest::checkParenthesis()
{
    QCOMPARE(calculate("(2 * 3) - (2 + 4)"), static_cast<double>( (2 * 3) - (2 + 4) ) );
    QCOMPARE(calculate("(2 + 2) * 2 - (17 - 10 * 3)"), static_cast<double>( (2 + 2) * 2 - (17 - 10 * 3) ) );
    QCOMPARE(calculate("(2.7 - 1.6) * (0.33 + 0.77) - (1 * 3 - 3 / 4) / (1) * (0.4 + 2 * 2) )"), static_cast<double>( (2.7 - 1.6) * (0.33 + 0.77) - (1 * 3 - 3 / 4) / (1) * (0.4 + 2 * 2) ) );
}

void QCalculatorTest::ckeckUnaryMinus()
{
    QCOMPARE(calculate("-0 + 0."), static_cast<double>(-0 + 0.) );
    QCOMPARE(calculate("-3 + 5 * 2 / (-2)"), static_cast<double>(-3 + 5 * 2 / (-2) ) );
    QCOMPARE(calculate("-0.4 - (-2) * 3 * (10.01)"), static_cast<double>(-0.4 - (-2) * 3 * (10.01) ) );
}


QTEST_MAIN(QCalculatorTest)
#include "qcalculator.test.moc"
