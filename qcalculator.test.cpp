#include <QtTest/QtTest>
#include "calculator.h"

#define CHECK_EXPRESION(exp) QCOMPARE(calculator::calculate(#exp), static_cast<double>(exp) )

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
    CHECK_EXPRESION(0 + 0);
    CHECK_EXPRESION(1 + 3);
    CHECK_EXPRESION(5 + 9 + 100 + 37 + 0);
    CHECK_EXPRESION(5.3 + 4.7 + 11.11 + 99.99 + 0.);
    CHECK_EXPRESION(1 + 1.1 + 1000 + 77.12345 + 0. + 0);
}

void QCalculatorTest::checkSubstraction()
{
    CHECK_EXPRESION(2 - 2);
    CHECK_EXPRESION(10 - 5);
    CHECK_EXPRESION(27 - 10 - 13 + 23 - 0 - 100);
    CHECK_EXPRESION(39.12 - 99 + 100 - 89.1234 - 0.);
    CHECK_EXPRESION(111.1 - 111.1 + 213 - 0 + 12 - 0. - 13.3333);
}

void QCalculatorTest::checkMultiplication()
{
    CHECK_EXPRESION(0 * 12);
    CHECK_EXPRESION(3 * 7 + 2 * 3);
    CHECK_EXPRESION(2 + 2 * 2.5 * 10 * 1 * 2 - 3);
    CHECK_EXPRESION(17.233 * 2 + 0.3 + 4 * 16.09);
}

void QCalculatorTest::checkDivision()
{
    CHECK_EXPRESION(0 / 12);
    CHECK_EXPRESION(145 / 5 - 87. / 3. / 11. / 2 );
    CHECK_EXPRESION(12.1 * 10 / 22.2 + 13 / 12.01 - 1 - 2 * 2.0 / 0.12);
    CHECK_EXPRESION(0.101 * 1000 / 101 - 1 * 22 / 22 - 3 + 0.23 / 12 / 22 + 2 * 3);
}

void QCalculatorTest::checkParenthesis()
{
    CHECK_EXPRESION((2 * 3) - (2 + 4) );
    CHECK_EXPRESION((2 + 2) * 2 - (17 - 10 * 3) );
    CHECK_EXPRESION((2.7 - 1.6) * (0.33 + 0.77) - (1 * 3 - 3. / 4) / (1) * (0.4 + 2 * 2) );
}

void QCalculatorTest::ckeckUnaryMinus()
{
    CHECK_EXPRESION(-0 + 0.);
    CHECK_EXPRESION(-3 + 5 * 2 / (-2) );
    CHECK_EXPRESION(-0.4 - (-2) * 3 * (10.01) );
}


QTEST_MAIN(QCalculatorTest)
#include "qcalculator.test.moc"
