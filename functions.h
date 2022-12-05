//#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream> 
#include <string>
#include<vector>
using std::string;
bool notClearSt();
bool notClearEn();
double other1();

double sum(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double division(double a, double b);
double exps(double a);
double sqrt(double a);
double percent(double a, double b);
double pows(double a);
double reversenum(double a);
double mod(double a, double b);


class Standart {
    double number;
    char operation;
public:
    Standart() {};
    explicit Standart( double _number): number(_number) {};
    friend double other();
    void sum(double y);
    void sub(double y);
    void mult(double y);
    void division(double y);
    void exps();
    void sqrt();
    void percent(double y);
    void pows();
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
    double pows(double x);
    double sqrt(double x);
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

class Console {
    std::string foo;
public:
    friend double other();
    friend double other1();
    void Choose();
    void Standart1();
    //void Programmer();
    void Engineer1();
    //void Data();
    void ChooseCalculator();
};

std::string stringInput();
std::vector <std::string> separate(std::string n);

#endif //FUNCTIONS_H
