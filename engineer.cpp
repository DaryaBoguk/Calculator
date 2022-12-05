#include "functions.h"
const double pi = 3.141592653;
const double EPSILON = 0.000'000'001;

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

double Engineer::sqrt(double a) {
    double L = 0, R = a;
    double M = (L + R) / 2;
    while (R - L > EPSILON) {
        if (M * M <= a) {
            L = M;
        }
        else {
            R = M;
        }
        M = (L + R) / 2;
    }
    return M;
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
double Engineer::pows(double x) {
	double b = number1;
	for (int i = 1; i < x; i++)
		number1 *= b;
	return number1;
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
        else if (((i >= 'a' && i <= 'z') && (i != 'r') && (i != 'd')) || (i == 'R')) {
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
            res = pows( stod(number[i + 1]));
            transposition(number, i, res);
        }
        else if (number[i] == "Sqrt") {
            res = sqrt(stod(number[i + 1]));
            transposition(number, i, res);
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
    double result = stod(number[0]);
    return result;
}

void clearVector(std::vector<std::string>& number, double res, int index1, int index2) {
    number[index1 - 1] = std::to_string(res);
    number.erase(number.begin() + index1, number.begin() + index2);
}

void Engineer::engineer() {
    long double res = 0;
    while (true) {
        add = stringInput();
        if (add == "exit" || add == "Exit") {
            break;
        }
        std::vector<string> number = separate(add);
        std::vector<int> open;
        std::vector<int> close;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == "(") {
                open.push_back(i + 1);
            }
            else if (number[i] == ")") {
                close.push_back(i - 1);
            }
        }
        for (int j = open.size() - 1; j >= 0; j--) {
            int flag = 0;
            std::vector<std::string> count = {};
            for (int k = 0; k < close.size(); k++) {
                if (k + j == close.size() - 1) {
                    for (int f = open[j]; f <= close[k]; f++) {
                        flag++;
                        count.push_back(number[f]);
                    }
                    close[k + 1] -= flag;
                }
            }
            clearVector(number, stamples(count), open[j], close[close.size() - j - 1] + 2);
        }
        res = stamples(number);
        std::cout << "Result: " << res << std::endl;
    }
}