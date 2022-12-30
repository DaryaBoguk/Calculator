#include "functions.h"

const double EPSILON = 0.00000001;


double exps(double x) {
    double res = 1;
    double currentTerm = x;
    int n = 1;
    while (currentTerm > EPSILON) {
        res += currentTerm;
        ++n;
        currentTerm *= x / n;
    }
    return res;
}

void Standart::sum(double y) {
    number += y;
    std::cout << "Result: " << number << '\n';
}
void Standart::sub(double y) {
    number -= y;
    std::cout << "Result: " << number << '\n';
}
void Standart::mult(double y) {
    number *= y;
    std::cout << "Result: " << number << '\n';
}
void Standart::division(double y) {
    number /= y;
    std::cout << "Result: " << number << '\n';
}

void Standart::sqrt() {
    double L = 0, R = number;
    double M = (L + R) / 2;
    while (R - L > EPSILON) {
        if (M * M <= number) {
            L = M;
        }
        else {
            R = M;
        }
        M = (L + R) / 2;
    }
    number = M;
    std::cout << "Result: " << number << '\n';
}

void Standart::pows2()
{
    number *= number;
    std::cout << "Result: " << number << '\n';
}

void Standart::exps() {
    double res = 1;
    double currentTerm = number;
    int n = 1;
    while (currentTerm > EPSILON) {
        res += currentTerm;
        ++n;
        currentTerm *= number / n;
    }
    number = res;
    std::cout << "Result: " << number << '\n';
}

void Standart::reversenum() {
    number = 1 / number;
    std::cout << "Result: " << number << '\n';
}

void Standart::percent(double y) {
    number = number * y / 100;
    std::cout << "Result: " << number << '\n';
}

double other() {
    std::cout << "Input number:";
    double y;
    std::cin >> y;
    if (notClearSt()) {
        y = other();
    }
    return y;
}

bool notClearSt() {
    bool isClear = false;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        isClear = true;
    }
    return isClear;
}
void Standart::clean() {
    number = other();
}

void Standart::standart() {
    long double res = 0;
    while (true) {
        std::cout << "Operation: ";
        std::cin >> operation;
        if (operation == 'e' || operation == 'E') {
            break;
        }
        switch (operation) {
        case'+': sum(other());
            break;
        case'-': sub(other());
            break;
        case'*': mult(other());
            break;
        case'/': division(other());
            break;
        case'%': percent(other());
            break;
        case'^': pows2();
            break;
        case',': exps();
            break;
        case's': sqrt();
            break;
        case'~': reversenum();
            break;
        case'C': clean();
            break;
        }
    }
}