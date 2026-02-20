#pragma once
#include <cstdlib>  
#include <ctime>  
#include <string>
#include <iostream>
///////////////////////////////////////////////////////////////////////////
///////////////////// My  Random Utility  Library ////////////////////////
/////////////////////////////////////////////////////////////////////////

/*InitializeRandom           GetRandomCharacter
RandomIntNumber              GenerateWord
RandomZeroOrOne              GenerateKey
RandomBool                   GenerateKeys
RollDice
*/


namespace MyRandomUtilityLib {
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        SpecialCharacter = 4
    };
    void InitializeRandom()
    {
        srand((unsigned)time(NULL));
    }

    int RandomIntNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    int RandomZeroOrOne()
    {
        return RandomIntNumber(0,1);
    }

   
    bool RandomBool()
    {
        return (bool)RandomIntNumber(0, 1);
    }
    int RollDice()
    {
        return RandomIntNumber(1, 6);
    }
    char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case SmallLetter:
            return char(RandomIntNumber(97, 122)); // a-z

        case CapitalLetter:
            return char(RandomIntNumber(65, 90)); // A-Z

        case Digit:
            return char(RandomIntNumber(48, 57)); // 0-9

        case SpecialCharacter:
            return char(RandomIntNumber(33, 47)); // —„Ê“ Œ«’…

        default:
            return 'A'; // «Õ Ì«ÿ
        }
    }

    std::string GenerateWord(enCharType type, int Length)
    {
        std::string word = "";
        for (int i = 0; i < Length; i++)
        {
            word += GetRandomCharacter(type); // ›‰ﬂ‘‰ «·—«‰œÊ„ Õ—›
        }
        return word;
    }
    std::string GenerateKey()
    {
        std::string Key = "";  
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

        return Key;
    }

    
    void GenerateKeys(short NumberOfKeys)
    {
        
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            
            std::cout << "Key [" << i << "] : ";
            std::cout << GenerateKey() << std::endl;
        }
    }






}
