#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream> 
#include <string>
#include<vector>


using std::string;
bool notClearSt();
bool notClearEn();
double other1();
std::string stringInput();
std::vector <std::string> separate(std::string n);
std::string binary(std::string number);
std::string binList(std::string number);
std::string binary(std::string n);
std::string DecimalToBinary(std::string number);
std::string BinaryToOctal(std::string _Number);


class Standart {
    double number;
    char operation;
public:
    Standart() {};
    explicit Standart(double _number) : number(_number) {};
    friend double other();
    void sum(double y);
    void sub(double y);
    void mult(double y);
    void division(double y);
    void exps();
    void sqrt();
    void percent(double y);
    void pows2();
    void reversenum();
    void clean();
    void standart();
};

class Engineer {
    std::string add;
    double number1;
    char operationEn;
public:
    friend double other1();
    Engineer() {};
    explicit Engineer(double _number1) : number1(_number1) {};
    unsigned long long factorial(unsigned long long x);
    double pows(double x, double a);
    double radical(double x, double b);
    double sum(double x, double b);
    double sub(double x, double b);
    double mult(double x, double b);
    double division(double x, double b);
    double cosRad(double x);
    double sinRad(double x);
    double tanRad(double x);
    double cotRad(double x);
    double cosDeg(double x);
    double sinDeg(double x);
    double tanDeg(double x);
    double cotDeg(double x);
    double sec(double x);
    double csc(double x);
    double sh(double x);
    double ch(double x);
    double th(double x);
    double cth(double x);
    double ln(double x);
    void clean1();
    long double stamples(std::vector <std::string>& number);
    void engineer();
};

template<typename T>
class Programmer
{
private:
    T number;
    char operation;
    T notation;
public:
    explicit Programmer(T _notation): notation(_notation) {};
    bool exclusiveOr(bool x);
    bool conjunctionNegation(bool x);
    bool disjunctionNegation(bool x);
    T rightShift(const bool isLogic, const T x, const int shift);
    T leftShift(const T x, const int shift, const bool isLogic);
    T bitwiseDisjunctionNegation(const T x);
    T bitwiseConjunctionNegation(const T x);
    T bitwiseExclusiveOr(const T x);
    T bitwiseOr(const T x);
    T bitwiseAnd(const T x);
    T bitwiseNot();
    bool disjunction(bool x);
    bool conjunction(bool x);
    bool negation();
    T unaryMinus();
    T unaryPlus();
    
    void Notation();
};

class Date {
    private:
        int day, mes, day1, mes1;
public:
    void difference();
};

class Console {
    std::string foo;
public:
    friend double other();
    friend double other1();
    void Choose();
    void Standart1();
    void Programmer1();
    void Engineer1();
    void Date1();
    void ChooseCalculator();
};


#endif //FUNCTIONS_H

