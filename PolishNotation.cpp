#include "PolishNotation.h"
#include"Stack.h"


#include <iostream>
#include <string>
#include <map>


using namespace std;

string PolishNotation::reverse_polish_notation(string expression) {

    map<string, int> priority;

    priority.insert(make_pair("u-", 3));
    priority.insert(make_pair("u+", 3));

    priority.insert(make_pair("*", 5));
    priority.insert(make_pair("/", 5));
    priority.insert(make_pair("%", 5));

    priority.insert(make_pair("+", 6));
    priority.insert(make_pair("-", 6));

    priority.insert(make_pair("<<", 7));
    priority.insert(make_pair(">>", 7));

    priority.insert(make_pair("<", 8));
    priority.insert(make_pair("<=", 8));
    priority.insert(make_pair(">", 8));
    priority.insert(make_pair(">=", 8));

    priority.insert(make_pair("==", 9));
    priority.insert(make_pair("!=", 9));

    priority.insert(make_pair("&", 10));

    priority.insert(make_pair("^", 11));

    priority.insert(make_pair("|", 12));

    priority.insert(make_pair("&&", 13));

    priority.insert(make_pair("||", 14));

    priority.insert(make_pair("(", 123));

    StackOnList<string> stack = StackOnList<string>();

    string rpn = ""; char last_non_space = '('; bool space_made = 1; string buffer = "";
    for (auto x : expression) {

        if (x >= '0' && x <= '9') {
            if (buffer != "") {
                while (!stack.IsEmpty() && priority[stack.Top()->value] <= priority[buffer]) {
                    rpn += stack.Pop() + ' ';
                }
                stack.Push(buffer);
                buffer = "";
            }
            rpn += x; space_made = 0;
        }
        else {

            if (!space_made) {
                rpn += ' '; space_made = 1;
            }

            if (x == ' ') {
                continue;
            }
            else if (x == '(') {

                if (buffer != "") {
                    while (!stack.IsEmpty() && priority[stack.Top()->value] <= priority[buffer]) {
                        rpn += stack.Pop() + ' ';
                    }
                    stack.Push(buffer);
                    buffer = "";
                }

                stack.Push("(");

            }
            else if (x == ')') {

                while (!stack.IsEmpty() && stack.Top()->value != "(") {
                    rpn += stack.Pop() + ' ';
                }

                if (stack.IsEmpty()) {
                    throw "Wrong balance of opening and closing brackets!\n";
                }

                stack.Pop();

            }
            else if (x == '+') {
                if ((last_non_space >= '0' && last_non_space <= '9') || last_non_space == ')') {
                    buffer += '+';
                }
                else {
                    buffer += "u+";
                }
            }
            else if (x == '-') {
                if ((last_non_space >= '0' && last_non_space <= '9') || last_non_space == ')') {
                    buffer += '-';
                }
                else {
                    buffer += "u-";
                }
            }
            else {
                buffer += x;
            }

        }

        last_non_space = x;

    }

    if (!space_made) {
        rpn += ' '; space_made = 1;
    }

    while (!stack.IsEmpty()) {

        if (stack.Top()->value == "(") {
            throw "Wrong balance of opening and closing brackets!\n";
        }
        rpn += stack.Pop() + ' ';

    }

    return rpn;

}

int PolishNotation::count_reverse_polish_notation(string rpn) {

    StackOnList<int> stack = StackOnList<int>();

    string buffer = "";
    for (auto x : rpn) {
        if (x != ' ') {
            buffer += x;
        }
        else {

            if (buffer[0] >= '0' && buffer[0] <= '9') {
                int tmp = stoi(buffer);
                stack.Push(tmp);
            }
            else if (buffer == "u+") {
                buffer = "";
                continue;
            }
            else if (buffer == "u-") {
                int arg = stack.Pop();
                arg *= (-1);
                stack.Push(arg);
            }
            else if (buffer == "*") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                stack.Push(arg1 * arg2);
            }
            else if (buffer == "/") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 / arg2);
            }
            else if (buffer == "%") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 % arg2);
            }
            else if (buffer == "+") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                stack.Push(arg1 + arg2);
            }
            else if (buffer == "-") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 - arg2);
            }
            else if (buffer == "<<") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 << arg2);
            }
            else if (buffer == ">>") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 >> arg2);
            }
            else if (buffer == "<") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 < arg2);
            }
            else if (buffer == "<=") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 <= arg2);
            }
            else if (buffer == ">") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 > arg2);
            }
            else if (buffer == ">=") {
                int arg2 = stack.Pop();
                int arg1 = stack.Pop();
                stack.Push(arg1 >= arg2);
            }
            else if (buffer == "==") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                if (arg1 == arg2) {
                    stack.Push(1);
                }
                else {
                    stack.Push(0);
                }
            }
            else if (buffer == "!=") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                if (arg1 != arg2) {
                    stack.Push(1);
                }
                else {
                    stack.Push(0);
                }
            }
            else if (buffer == "&") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                stack.Push(arg1 & arg2);
            }
            else if (buffer == "^") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                stack.Push(arg1 ^ arg2);
            }
            else if (buffer == "|") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                stack.Push(arg1 | arg2);
            }
            else if (buffer == "&&") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                if (arg1 != 0 && arg2 != 0) {
                    stack.Push(1);
                }
                else {
                    stack.Push(0);
                }
            }
            else if (buffer == "||") {
                int arg1 = stack.Pop();
                int arg2 = stack.Pop();
                if (arg1 != 0 || arg2 != 0) {
                    stack.Push(1);
                }
                else {
                    stack.Push(0);
                }
            }

            buffer = "";

        }
    }

    return stack.Pop();

}

