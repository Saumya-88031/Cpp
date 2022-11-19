#include <iostream>
#include <string>
#include <algorithm>
#include "Stack.hpp"

class INT
{
private:
    std::string num;
    Stack<int> numStack;
    void fillStack()
    {
        for (int i = 0, n = num.size(); i < n; i++)
            numStack.push((int)num[i] - 48);
    }

public:
    INT()
    {
        this->num = "";
    }

    INT(const std::string &num)
    {
        this->num = num;
    }

    INT operator+(INT &obj)
    {
        this->fillStack();
        obj.fillStack();
        std::string stringResult;
        int a, b, result, carry = 0;
        while ((!numStack.isEmpty()) && (!obj.numStack.isEmpty()))
        {
            a = numStack.pop();
            b = obj.numStack.pop();
            result = a + b + carry;
            carry = result / 10;
            stringResult.push_back((char)((result % 10) + 48));
        }
        if (!numStack.isEmpty())
        {
            while(!numStack.isEmpty())
            {
                a = numStack.pop();
                result = a + carry;
                carry = result / 10;        
                stringResult.push_back((char)((result % 10) + 48));
            }
        } 
        else if (!obj.numStack.isEmpty())
        {
            while (!obj.numStack.isEmpty())
            {
                b = obj.numStack.pop();
                result = b + carry;
                carry = result / 10;
                stringResult.push_back((char)((result % 10) + 48));
            }
        }
        if (carry != 0)
        {
            stringResult.push_back((char)(carry + 48));
        }
        std::reverse(stringResult.begin(), stringResult.end());
        INT Result(stringResult);
        return Result;
    }

    friend std::ostream &operator<<(std::ostream &os, const INT &obj)
    {
        os << obj.num;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, INT &obj)
    {
        char ch;
        is.get(ch);
        obj.num = "";
        while(ch != '\n')
        {
            obj.num.push_back(ch);
            is.get(ch);
        }
        return is;
    }

    void display()
    {
        std::cout << num << "\n";
        numStack.display();
    }
};

int main()
{
    INT A;
    std::cout << "A: ";
    std::cin >> A;
    INT B;
    std::cout << "B: ";
    std::cin >> B;
    INT C = A+B;
    std::cout << C << "\n";
    return 0;
}
