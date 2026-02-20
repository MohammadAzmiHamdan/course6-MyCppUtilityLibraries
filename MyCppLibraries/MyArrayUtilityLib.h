#pragma once
#include <iostream>
#include"MyRandomUtilityLib.h"
#include"MyMathUtilityLib.h"
#include"MyInputOutputLib.h"
///////////////////////////////////////////////////////////////////////////
///////////////////// My  My Array Utility  Library //////////////////////
/////////////////////////////////////////////////////////////////////////


/*ReadArray                 FindNumberPositionInArray
PrintArray                  IsNumberInArray
FillArrayWithRandomNumbers  AddArrayElement
MaxNumberInArray            InputUserNumbersInArray
MinNumberInArray            CopyOddNumbers
SumArray                    CopyPrimeNumbers
ArrayAverage                CopyDistinctNumbersToArray
CopyArray                   IsPalindromeArray
CopyOnlyPrimaryNumbers      OddCount
SumOf2Arrays                EvenCount
FillArrayWith1toN           PositiveCount
ShuffleArray                NegativeCount
CopyArrayInReverseOrder    FillArrayWithKeys
PrintStringArray            FillArrayWithRandomNumbersFromUser

*/

 namespace MyArrayUtilityLib{
    void ReadArray(int arr[100], int& arrLength)
    {
        std::cout << "\nEnter number of elements:\n";
        std::cin >> arrLength;  
        std::cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            std::cout << "Element [" << i + 1 << "] : "; 
            std::cin >> arr[i];                          
        }
        std::cout << std::endl; 
    }

    
    void PrintArray(int arr[100], int arrLength)
    {
       
        for (int i = 0; i < arrLength; i++)
            std::cout << arr[i] << " ";

        std::cout << "\n";  
    }

    void FillArrayWithRandomNumbersFromUser(int arr[100], int arrLength)
    {
        MyRandomUtilityLib::InitializeRandom();
        std::cout << "\nEnter number of elements:\n";
        std::cin >> arrLength; 
        for (int i = 0; i < arrLength; i++)
            arr[i] = MyRandomUtilityLib::RandomIntNumber(1, 100);
    }
    void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
    {
        MyRandomUtilityLib::InitializeRandom();
        
        for (int i = 0; i < arrLength; i++)
            arr[i] = MyRandomUtilityLib::RandomIntNumber(1, 100);
    }
    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;  
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max; 
    }
    int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = arr[0];  
        for (int i = 0; i < arrLength; i++)
        {
           
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min; 
    }
    int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;  

        
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }

        return Sum;  
    }
    float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }
    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }
    void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
    {
        int Counter = 0;  
        for (int i = 0; i < arrLength; i++)
        {
            if (MyMathUtilityLib::IsPrime(arrSource[i]) )
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;  
            }
        }

       
        arr2Lenght = Counter;
    }
    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];  
        }
    }

    void FillArrayWith1toN(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }
    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
           
            int index1 = MyRandomUtilityLib::RandomIntNumber(0, arrLength - 1);
            int index2 = MyRandomUtilityLib::RandomIntNumber(0, arrLength - 1);
            MyMathUtilityLib::Swap(arr[index1], arr[index2]);
        }
    }
    void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }
    void PrintStringArray(std::string arr[100], int arrLength)
    {
        std::cout << "\nArray elements:\n\n";
       
        for (int i = 0; i < arrLength; i++)
        {
            std::cout << "Array[" << i << "] : ";
            std::cout << arr[i] << "\n";
        }
        std::cout << "\n"; 
    }
    void FillArrayWithKeys(std::string arr[100], int arrLength)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = MyRandomUtilityLib::GenerateKey();
    }
    short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i; 
        }

        return -1;
    }
    bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }
    void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
                arr[arrLength++] = Number;
    }
    void InputUserNumbersInArray(int arr[100], int& arrLength)
    {
        bool AddMore = true;  
        
        do
        {
            AddArrayElement(MyInputOutputLib::ReadNumber(), arr, arrLength);

            std::cin >> AddMore; 

        } while (AddMore);  
    }
    void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arrSource[i] % 2 != 0)
            {
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }
    void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (MyMathUtilityLib::IsPrime(arrSource[i]))
            {
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }
    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
            {
                AddArrayElement(arrSource[i], arrDestination, DestinationLength);
            }
        }
    }
    bool IsPalindromeArray(int arr[100], int Length)
    {
        
        for (int i = 0; i < Length; i++)
        {
           
            if (arr[i] != arr[Length - i - 1])
            {
                return false;  
            }
        }

        return true;
    }
    int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;  
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
            {
                Counter++;  
            }
        }

        return Counter;  
    }
    int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;  

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
            {
                Counter++;
            }
        }
        return Counter;  
    }
    int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0; 

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
            {
                Counter++;  
            }
        }

        return Counter;  
    }
    int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0; 

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
            {
                Counter++;  
            }
        }

        return Counter;  
    }


}