//练习 9.52：使用 stack 处理括号的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从 stack 中 pop 对象，
//直到遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push 到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所代替。
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;

//将字符串形式的算数表达式拆分成数字和运算符号
void splitExpression(vector<string> &, string &);
//去除单个字符串首尾的空格
string &trimStr(string &);
//去除分割后算式每个部分首尾的空格
void trimContainer(vector<string> &);
//计算最简单的一个算术表达式（两个数字与一个运算符）
double calculateMin(string n1, string oper, string n2);
//计算一个不包含括号的，已经分割处理之后的四则运算表达式
double calculateSimple(stack<string> &);
//计算一个完整的包含括号的以一个字符串形式表示的算数表达式
double calculate(stack<string> &origin);

int main() {
    string str = "(1 - 2) * (3 + 4) / 5 - 6 * (7 + 8 - 6 + 2 + 4)";  //-91.4
    // string str = "(1 - 2) * (3 + 4) / 5 - 6 * 7 + 8 - 6 + 2 + 4";    //-35.4
    // string str = "1 - 2 * (3 + 4) / 5 - 6 * (7 + 8 - 6 + 2 + 4)";    //-91.8
    // string str = "1 - 2 * (3 + 4) / 5 - 6 * 7 + 8 - 6 + 2 + 4";      //-35.8

    // cout << "输入一行算数表达式（最多只能包含一层括号）" << endl;
    // std::getline(cin, str);
    cout << "输入的算数表达式为：" << endl;
    cout << str << endl;

    vector<string> containr;
    splitExpression(containr, str);
    trimContainer(containr);

    stack<string> stkContainer;
    auto beg = containr.crbegin();
    while (beg != containr.crend())
        stkContainer.push(*beg++);

    cout << "计算结果为：" << endl;
    cout << str << " = " << calculate(stkContainer) << endl;

    return 0;
}

void splitExpression(vector<string> &container, string &calcStr) {
    string::size_type pos = string::npos, prev = 0;
    string sub;
    while ((pos = calcStr.find_first_of("+-*/()", prev)) != string::npos && prev <= calcStr.size()) {
        sub = calcStr.substr(prev, pos - prev);
        if (sub.find_first_not_of(' ') != string::npos)
            container.push_back(sub);

        sub = calcStr.substr(pos, 1);
        if (sub.find_first_not_of(' ') != string::npos)
            container.push_back(sub);

        prev = pos + 1;
    }
    if (prev < calcStr.size())
        container.push_back(calcStr.substr(prev, calcStr.size() - prev));
}

string &trimStr(string &str) {
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);

    return str;
}

void trimContainer(vector<string> &container) {
    for (auto &s : container) {
        s = trimStr(s);
    }
}

double calculateMin(string n1, string oper, string n2) {
    double result = 0, n11 = std::stod(n1), n22 = std::stod(n2);

    if (oper == "+") {
        result = n11 + n22;
    } else if (oper == "-") {
        result = n11 - n22;
    } else if (oper == "*") {
        result = n11 * n22;
    } else if (oper == "/") {
        result = n11 / n22;
    }

    return result;
}

double calculateSimple(stack<string> &container) {
    double result = 0;
    while (!container.empty()) {
        if (container.size() == 1) {
            result = std::stod(container.top());
            container.pop();
        } else if (container.size() == 3) {
            string n1 = container.top();
            container.pop();

            string op = container.top();
            container.pop();

            string n2 = container.top();
            container.pop();

            result = calculateMin(n1, op, n2);
        } else {
            string n11 = container.top();
            container.pop();

            string op1 = container.top();
            container.pop();

            string n12 = container.top();
            container.pop();

            string op2 = container.top();
            double tmp = 0;
            if (op2 == "*" || op2 == "/") {
                container.pop();
                string n21 = container.top();
                container.pop();

                tmp = calculateMin(n12, op2, n21);
                container.push(std::to_string(tmp));
                container.push(op1);
                container.push(n11);
            } else {
                tmp = calculateMin(n11, op1, n12);
                container.push(std::to_string(tmp));
            }
        }
    }

    return result;
}

double calculate(stack<string> &origin) {
    stack<string> trans;

    if (origin.size() == 1) {
        return std::stod(origin.top());
    } else if (origin.size() == 3) {
        string n1 = origin.top();
        origin.pop();

        string op = origin.top();
        origin.pop();

        string n2 = origin.top();
        origin.pop();

        return calculateMin(n1, op, n2);
    }

    while (!origin.empty()) {
        while (!origin.empty() && origin.top() != "(") {
            trans.push(origin.top());
            origin.pop();
        }

        if (!origin.empty() && origin.top() == "(") {
            origin.pop();
            stack<string> tmpStk;

            while (origin.top() != ")") {
                tmpStk.push(origin.top());
                origin.pop();
            }
            origin.pop();

            stack<string> tmpStk2;
            while (!tmpStk.empty()) {
                tmpStk2.push(tmpStk.top());
                tmpStk.pop();
            }
            trans.push(std::to_string(calculateSimple(tmpStk2)));
        }
    }
    while (!trans.empty()) {
        origin.push(trans.top());
        trans.pop();
    }

    return calculateSimple(origin);
}
