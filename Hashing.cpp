#include <iostream>
#include <string>
using namespace std;

bool IsNumber(string s)
{
    for (char c : s)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}
int SelectDigits(string s)
{
    if (IsNumber(s) && s.length() > 4)
    {
        string to = s.substr(1, 1) + s.substr(4, 1);
        return stoi(to);
    }
    else
        return -1;
}
int ShiftFold(string s)
{
    if (IsNumber(s))
    {
        int result = 0;
        int left = s.size();
        for (int i = 0; i < s.size(); i += 3)
        {
            result += stoi(s.substr(i, min(left, 3)));
            left -= 3;
        }
        return result;
    }
    else
        return -1;
}
int BoundaryFold(string s)
{
    if (IsNumber(s))
    {
        int result = 0;
        int left = s.size();
        for (int i = 0; i < s.size(); i += 3)
        {
            string temp = s.substr(i, min(left, 3));
            string gen;
            for (int i = temp.size() - 1; i > -1; i--)
            {
                gen += temp.substr(i, 1);
            }
            result += stoi(gen);
            left -= 3;
        }
        return result;
    }
    else
        return -1;
}
int MidSquare(string s)
{
    if (IsNumber(s))
    {
        string temp = to_string(stoi(s) * stoi(s));
        for (int i = temp.size() - 1; temp.size() > 3; i--)
        {
            if (i % 2 == 0)
            {
                temp = temp.substr(1, temp.size() - 1);
            }
            else
                temp = temp.substr(0, temp.size() - 1);
        }
        return stoi(temp);
    }
    else
        return -1;
}
int Extraction(string s, int from, int length)
{
    if (IsNumber(s))
    {
        return stoi(s.substr(from, min(length, (int)s.size() - from)));
    }
    else
        return -1;
}
int RadixTransformation(string s)
{
    if(IsNumber(s))
    {
        int n = stoi(s);
        int remainder = 0;
        int octal = 0;
        int i = 1;
        while (n != 0)
        {
            remainder = n % 8;
            n /= 8;
            octal += remainder * i;
            i*=10;
        }
        return octal%1000;
    }
    else return -1;
}
int main()
{
    cout << SelectDigits("1561643518") << endl;
    cout << ShiftFold("321321321") << endl;
    cout << ShiftFold("11111") << endl;
    cout << BoundaryFold("123456") << endl;
    cout << BoundaryFold("1756") << endl;
    cout << MidSquare("3121") << endl;
    cout << Extraction("123456789",4,11) << endl;
    cout << RadixTransformation("1238") << endl;
    return 0;
}