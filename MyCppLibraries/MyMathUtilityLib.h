#pragma once
#include <cmath>

///////////////////////////////////////////////////////////////////////////
///////////////////// My     Math   Utility  Library /////////////////////
/////////////////////////////////////////////////////////////////////////

/*IsEven                     IsDivisible
IsOdd                        Swap
IsPrime                      MyABS
Factorial                    GetFractionPart
IsPerfect                    MyRound
ReverseNumber                MyFloor
SumDigits                    MyCeil
IsPalindrome                 MySqrt
*/

namespace MyMathUtilityLib
{
    
    bool IsEven(int Number)
    {
        return Number % 2 == 0;
    }

    bool IsOdd(int Number)
    {
        return Number % 2 != 0;
    }

    bool IsPrime(int Number)
    {
        if (Number <= 1)
            return false;

        

        for (int i = 2; i <= Number/2; i++)
        {
            if (Number % i == 0)
                return false;
        }

        return true;
    }
    int Factorial(int Number)
    {
        if (Number < 0)
            return -1; 

        int result = 1;
        for (int i = 1; i <= Number; i++)
        {
            result *= i;
        }

        return result;
    }
    bool IsPerfect(int Number)
    {
        if (Number <= 1)
            return false;

        int sum = 0;

        for (int i = 1; i <= Number / 2; i++)
        {
            if (Number % i == 0)
                sum += i;
        }

        return sum == Number;
    }
    int ReverseNumber(int Number)
    {
        int reversed = 0;

        while (Number != 0)
        {
            int digit = Number % 10;
            reversed = reversed * 10 + digit;
            Number /= 10;
        }

        return reversed;
    }
    int SumDigits(int Number)
    {
        int sum = 0;

        while (Number != 0)
        {
            sum += Number % 10;
            Number /= 10;
        }

        return sum;
    }
    bool IsPalindrome(int Number)
    {
        return Number == ReverseNumber(Number);
    }
    bool IsDivisible(int Number, int Divisor)
    {
        if (Divisor == 0)
            return false;

        return Number % Divisor == 0;
    }
    void Swap(int& A, int& B)
    {
        int Temp;    
        Temp = A;    
        A = B;       
        B = Temp;    
    }
    float MyABS(float Number)
    {
        
        if (Number > 0)
            return Number;
        else
            return Number * -1;  
    }
    float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }
    int MyRound(float Number)
    {
        int IntPart;  
        IntPart = int(Number);  

        
        float FractionsPart = GetFractionPart(Number);

        if (abs(FractionsPart) >= 0.5)
        {
            if (Number > 0)
                return ++IntPart;
            else
                return --IntPart;
        }
        else
        {
            return IntPart;
        }
    }
    int MyFloor(float Number)
    {
        if (Number > 0)
            return int(Number);
        else
            return int(Number) - 1;
    }
    int MyCeil(float Number)
    {
        if (abs(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
                return int(Number) + 1;  
            else
                return int(Number);  
        }
        else
            return Number;  
    }
    float MySqrt(float Number)
    {
        return pow(Number, 0.5); 
    }
}

