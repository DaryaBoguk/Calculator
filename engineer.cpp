#include "functions.h"
#include"PolishNotation.h"
const double pi = 3.141592653;
const double EPSILON = 0.00001;



double Engineer::sum(double x, double b) {
    return x + b;
}
double Engineer::sub(double x, double b) {
    return x - b;
}
double Engineer::mult(double x, double b) {
    return x * b;
}
double Engineer::division(double x, double b) {
    return x / b;
}


double Engineer::cosRad(double x) {
    double answer = 1, elem = 1;
    int i = 1, sign = -1;
    while (elem >= EPSILON) {
        elem *= x * x / (i * (i + 1));
        answer += sign * elem;
        i += 2;
        sign *= -1;
    }
    return answer;

}

double Engineer::radical(double x, double b) {
    int multer = 1;
    for (; pows(multer, b) < x; multer++) {}
    double number_ = static_cast<double>(x) / pows(multer, b) - 1;
    if (number_ == 0.0) {
        return multer;
    }
    int denom = 1;
    double res = 1;
    double pseudo_mu = 1.0 / b;
    double mu = pseudo_mu;

    for (int i = 1; i < 40; i++)
    {
        res += (mu * number_) / factorial(denom);
        denom++;
        pseudo_mu -= 1;
        mu *= pseudo_mu;
        number_ *= number_;
    }
    res *= multer;
    return res;
}
double Engineer::cosDeg(double x) {
    x *= 0.017453;
    return cosRad(x);
}

double Engineer::sinRad(double x) {
    int sign = 1, i = 1;
    long double answer = x, elem = x;
    while (elem >= EPSILON)
    {
        sign *= -1;
        elem *= x * x / ((i + 1) * (i + 2));
        answer += sign * elem;
        i += 2;
    }
    return answer;
}

double Engineer::sinDeg(double x) {
    x *= 0.017453;
    return sinRad(x);
}

double Engineer::tanRad(double x) {
    return sinRad(x) / cosRad(x);
}

double Engineer::tanDeg(double x) {
    x *= 0.017453;
    return tanRad(x);
}

double Engineer::cotRad(double x) {
    return cosRad(x) / sinRad(x);
}

double Engineer::cotDeg(double x) {
    x *= 0.017453;
    return cotRad(x);
}

double Engineer::sec(double x) {
    return 1 / cosDeg(x);
}

double Engineer::csc(double x) {
    return 1 / sinDeg(x);
}

double Engineer::sh(double x) {
    int  i = 1;
    long double answer = x, elem = x;
    while (elem >= EPSILON)
    {
        elem *= x * x / ((i + 1) * (i + 2));
        answer += elem;
        i += 2;
    }
    return answer;
}

double Engineer::ch(double x) {
    double answer = 1, elem = 1;
    int i = 1;
    while (elem >= EPSILON) {
        elem *= x * x / (i * (i + 1));
        answer += elem;
        i += 2;
    }
    return answer;
}

double Engineer::th(double x) {
    return sh(x) / ch(x);
}

double Engineer::cth(double x) {
    return ch(x) / sh(x);
}

unsigned long long Engineer::factorial(unsigned long long x) {
    unsigned long long res = 1;
    for (int i = 1; i <= x; ++i) {
        res = res * i;
    }
    return res;
}

double mod(double a, double b) {
    double answer = a / b;
    int answer1 = static_cast<int>(answer);
    return a - b * answer1;
}
double Engineer::pows(double x, double a) {
    double b = x;
    for (int i = 1; i < a; i++)
        x *= b;
    return x;
}

double other1() {
    std::cout << "Input number:";
    double x;
    std::cin >> x;
    if (notClearEn()) {
        x = other1();
    }
    return x;
}

bool notClearEn() {
    bool isClear = false;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        isClear = true;
    }
    return isClear;
}
void Engineer::clean1() {
    number1 = other1();
}

std::string stringInput() {
    std::string expression;
    std::cout << "Input expression:";
    std::cin >> expression;
    if (expression == "exit") {
       exit(0);
    }
    return expression;
}

std::vector <std::string> separate(std::string x) {
    x += " ";
    std::vector <std::string> massiv;
    std::string son = "", sol = "";
    for (auto i : x) {
        if (('0' <= i && i <= '9') || i == '.') {
            son += i;
        }
        else if (((i >= 'a' && i <= 'z') && (i != 'r') && (i != 'd')) || (i == 'R') || (i == '!') || (i == 'e')) {
            if (!son.empty()) {
                massiv.push_back(son);
                son = "";
            };
            sol += i;
        }
        else {
            if (!sol.empty()) {
                massiv.push_back(sol);
                sol = "";
            };
            if (!son.empty()) {
                massiv.push_back(son);
                son = "";
            };
            if (i != ' ') {
                massiv.emplace_back(std::string(1, i));
            };
        }
    }
    return massiv;
}

void transposition(std::vector<std::string>& values, int& index, double res) {
    values[index - 1] = std::to_string(res);
    values.erase(values.begin() + index);
    res = 0;
    index -= 2;
}


int trigonometry(std::string word) {
    double res = 0;
    if (word == "sin") return 0;
    if (word == "cos") return 1;
    if (word == "tan") return 2;
    if (word == "cot") return 3;
    if (word == "sec") return 4;
    if (word == "csc") return 5;
    if (word == "sh") return 6;
    if (word == "ch") return 7;
    if (word == "th") return 8;
    if (word == "cth") return 9;
}

long double Engineer::stamples(std::vector <std::string>& number) {
    double res = 0;
    std::vector<int> n;
    for (int i = 1; i < number.size(); i += 2) {
        if (number[i] == "r") {
            switch (trigonometry(number[i - 1])) {
            case 0:
                res = sinRad(stod(number[i + 1]));
                break;
            case 1:
                res = cosRad(stod(number[i + 1]));
                break;
            case 2:
                res = tanRad(stod(number[i + 1]));
                break;
            case 3:
                res = cotRad(stod(number[i + 1]));
                break;
            case 4:
                res = sec(stod(number[i + 1]));
                break;
            case 5:
                res = csc(stod(number[i + 1]));
                break;
            case 6:
                res = sh(stod(number[i + 1]));
                break;
            case 7:
                res = ch(stod(number[i + 1]));
                break;
            case 8:
                res = th(stod(number[i + 1]));
                break;
            case 9:
                res = cth(stod(number[i + 1]));
                break;
            }
            transposition(number, i, res);
        }
        else if (number[i] == "d") {
            switch (trigonometry(number[i - 1])) {
            case 0:
                res = sinDeg(stod(number[i + 1]));
                break;
            case 1:
                res = cosDeg(stod(number[i + 1]));
                break;
            case 2:
                res = tanDeg(stod(number[i + 1]));
                break;
            case 3:
                res = cotDeg(stod(number[i + 1]));
                break;
            }
            transposition(number, i, res);
        }
        else if (number[i] == "^") {
            res = pows(stod(number[i - 1]), stod(number[i + 1]));
            transposition(number, i, res);
        }
        else if (number[i] == "R") {
            res = radical(stod(number[i - 1]), stod(number[i + 1]));
            transposition(number, i, res);
        }
        for (int i = 1; i < number.size(); i += 2) {
            if (number[i] == "!") {
                res = factorial(stod(number[i - 1]));
                transposition(number, i, res);
            }
        }

    }
    for (int i = 1; i < number.size(); i += 2) {
        if (number[i] == "*") {
            res = mult(stod(number[i - 1]), stod(number[i + 1]));
            transposition(number, i, res);
        }
        else if (number[i] == "/") {
            res = division(stod(number[i - 1]), stod(number[i + 1]));
            transposition(number, i, res);
        }
        else if (number[i] == "%") {
            res = mod(stod(number[i - 1]), stod(number[i + 1]));
            transposition(number, i, res);
        }

    }
    for (int i = 1; i < number.size(); i += 2) {
        if (number[i] == "+") {
            res = sum(stod(number[i - 1]), stod(number[i + 1]));
            transposition(number, i, res);
        }
        else if (number[i] == "-") {
            res = sub(stod(number[i - 1]), stod(number[i + 1]));
            transposition(number, i, res);
        }
    }
    long double result = stod(number[0]);
    return result;
}

void clearVector(std::vector<std::string>& number, double res, int index1, int index2) {
    number[index1 - 1] = std::to_string(res);
    number.erase(number.begin() + index1, number.begin() + index2);
}


void Engineer::engineer() {
    long double res = 0; int choose;
    while (true) {
        std::cout << "what expression you want?\n" << "long arifm - 1\n" << "another -2\n" << std::endl;
        std::cin >> choose;
        add = stringInput();
        switch (choose) {
        case 1: {
            std::string temp = PolishNotation::reverse_polish_notation(add);
            double a = PolishNotation::count_reverse_polish_notation(temp);
            std::cout << "Result: " << a << std::endl;
            break;
        }
        case 2: {
            std::vector<std::string> number = separate(add);
            res = stamples(number);
            std::cout << "Result: " << res << std::endl;
            break;
        }
        }
    }
}