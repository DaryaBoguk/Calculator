#include "functions.h"

template <typename T>
bool Programmer<T> ::negation() {
    return !number;
}
template <typename T>
bool Programmer<T> ::conjunction(bool x) {
    return (number && x);
}
template <typename T>
bool Programmer<T> ::disjunction(bool x) {
    return (number || x);
}

template <typename T>
T Programmer<T> ::bitwiseNot() {
    return ~number;
}

template <typename T>
T Programmer<T> ::bitwiseAnd(const T x) {
    return number && x;
}
template <typename T>
T Programmer<T> ::bitwiseOr(const T x) {
    return number | x;
}
template <typename T>
T Programmer<T> ::bitwiseExclusiveOr(const T x) {
    return number ^ x;
}
template <typename T>
T Programmer<T> ::bitwiseConjunctionNegation(const T x) {
    return bitwiseNot(bitwiseAnd(number, x));
}
template <typename T>
T Programmer<T> ::bitwiseDisjunctionNegation(const T x) {
    return bitwiseNot(bitwiseOr(number, x));
}
template <typename T>
T Programmer<T> ::leftShift(const T x, const int shift, const bool isLogic) {
    if (isLogic == true) {
        return x << shift;
    }
    T shift_x = 0;
    for (int i = 0; i < shift; i++) {
        shift_x += Engineer.pows(2, i);
    }
    return bitwiseOr(shift_x, x << shift);
}
template <typename T>
T Programmer<T> ::rightShift(const bool isLogic, const T x, const int shift) {
    if (isLogic == true) {
        return x >> shift;
    }
    T shift_x = Engineer.pows(2, 30);
    for (int i = 29; i > 30 - shift; i--) {
        shift_x += Engineer.pows(2, i);
    }
    return bitwiseOr(shift_x, x >> shift);
}
template<typename T>
bool Programmer<T> ::exclusiveOr(bool x) {
    return (number ^ x);
}

template<typename T>
bool Programmer<T>::conjunctionNegation(bool x) {
    return negation(true);
}

template<typename T>
bool Programmer<T>::disjunctionNegation(bool x) {
    return negation(disjunction(number, x));
}

template<typename T>
T Programmer<T>::unaryPlus() {
    return (number >= 0) ? number : (number * (-1));
}

template<typename T>
T Programmer<T>::unaryMinus() {
    return (number <= 0) ? number : (number * (-1));
}

std::string bin(std::string number)
{
    std::string number1 = "";
    int num = std::stoi(number);
    while (num > 0) {
        number1 += std::to_string(num % 2);
        num /= 2;
    }
    for (int i = 0; i < number1.size() / 2; i++) {
        std::swap(number1[i], number1[number1.size() - i - 1]);
    }
    return number1;
}

std::string binList(std::string number)
{
    std::string num1 = "";
    int length = pow(10, number.size());
    int num2 = std::stoi(number);
    for (int i = 0; i < 5; i++) {
        num2 *= 2;
        if (num2 >= length) {
            num2 -= length;
            num1 += "1"; }
        else {
            num1 += "0";
        }
    }
    return num1;
}

std::string binary(std::string n) {
    std::string n1 = "";
    std::string n2 = "";
    int counter = 0;
    for (auto i : n) {
        if (i != '.' && counter == 0) {
            n1 += i;
        }
        else if (i == '.') {
            counter++;
        }
        else {
            n2 += i;
        }
    };
    if (n2.empty()) {
        return bin(n1);
    }
    else {
        return bin(n1) + "." + binList(n2);
    }

}

template<typename T>
void Programmer<T>::Notation()
{
    switch (this->notation) {
    case (2):
        //return this->CalculateBinary;
    case (8):
        //return this->Calculate;
    case (10):
        return this->CalculateDecimal();
    case (16):;
        //return this->CalculateHex;
    }
}

std::string DecimalToBinary(std::string number) {
    double num = stod(number);
    std::vector<int> wholeNumbers;
    std::vector<int> fractionalNumbers;
    int wholePart = num;
    int counter = 0;
    while (wholePart > 0) {
        int temp;
        temp = wholePart % 2;
        wholePart /= 2;
        wholeNumbers.push_back(temp);
        counter++;
    }
    std::string newNumber = "";
    for (int i = counter - 1; i > 0; i--) {
        newNumber += std::to_string(wholeNumbers[i]);
    }
    number = newNumber;
    return number;
}

