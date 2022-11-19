#include <iostream>
#include "Stack.hpp"
#include <string>
#include <sstream>

bool isNum(std::string str)
{
    for (auto i : str)
    {
        if (!((i >= 48 && i <= 57) || (i == 46)))
            return false;
    }
    return true;
}

void evaluatePostfix(std::string exp)
{
    Stack<float> operandStack;
    std::string str;
    std::stringstream expStream(exp);
    float a, b, result;
    while (getline(expStream, str, ' '))
    {
        if (isNum(str))
        {
            operandStack.push(std::stof(str));
        }
        else if (str == "+")
        {
            if (!operandStack.isEmpty())
                a = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            if (!operandStack.isEmpty())
                b = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            result = b + a;
            operandStack.push(result);
        }
        else if (str == "-")
        {
            if (!operandStack.isEmpty())
                a = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            if (!operandStack.isEmpty())
                b = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            result = b - a;
            operandStack.push(result);
        }
        else if (str == "*")
        {
            if (!operandStack.isEmpty())
                a = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            if (!operandStack.isEmpty())
                b = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            result = b * a;
            operandStack.push(result);
        }
        else if (str == "/")
        {
            if (!operandStack.isEmpty())
                a = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            if (!operandStack.isEmpty())
                b = operandStack.pop();
            else
            {
                std::cout << "Invalid Expression\n";
                exit(1);
            }
            result = b / a;
            operandStack.push(result);
        }
        else
        {
            std::cout << "Invalid expression\n";
            exit(1);
        }
    }
    result = operandStack.pop();
    if (operandStack.isEmpty()) // after last pop stack should be empty
    {
        std::cout << "\nResult: " << result << "\n";
    }
    else
    {
        std::cout << "\nInvalid Expression\n";
    }
}

int main()
{
    std::string str;
    std::cout << "Enter postfix expression: ";
    getline(std::cin, str);
    evaluatePostfix(str);
    return 0;
}
