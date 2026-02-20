#pragma once
#include <iostream>
#include <cctype>
#include <limits>
#include <windows.h>
#include<cmath>
#include <vector>
#include <thread>
#include <chrono>
#include<string>
#include "MyMathUtilityLib.h"
///////////////////////////////////////////////////////////////////////////
///////////////////// My  Input  &   Output  Library /////////////////////
/////////////////////////////////////////////////////////////////////////

/*ReadNumberInRange         PrintHeader
ReadNumber                  PrintError
ReadPositiveNumber          PrintSuccess
ReadCharacter               PrintLineWithBorder
ReadYesNo                   PrintMenu
ReadEvenNumber              PrintTable
ReadOddNumber               PrintCountdown
ReadPrimeNumber             PrintProgressBar
ReadMenuChoice              AskAndPrint
Printl                      PrintYesNoResult
Print                       PrintColored
PrintNumber
SetColor
*/

namespace MyInputOutputLib {
   

    double ReadNumberInRange(double From, double To, const std::string& Message)
    {
        double Number = 0;
        do {
            std::cout << Message << std::endl;
            std::cin >> Number;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        } while (Number < From || Number > To);

        return Number;
    }
    int ReadNumber()
    {
        int Number;  // Variable to store the user's input.
        std::cout << "\nPlease enter a number? ";
        std::cin >> Number;  // Read the number from the user.
        return Number;  // Return the entered number.
    }
    int ReadPositiveNumber() {
        int num = 0;
        do {
            std::cout << "Please enter a positive number?\n";
            std::cin >> num;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        } while (num <= 0);

        return num;
    }

    char ReadCharacter(const std::string& Message, const std::string& charactersAllowed)
    {
        char Character;
        do {
            std::cout << Message << std::endl;
            std::cin >> Character;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        } while (charactersAllowed.find(Character) == std::string::npos);

        return Character;
    }

    bool ReadYesNo(const std::string& Message) {
        char Answer;
        while (true) {
            std::cout << Message << " (Y/N)? ";
            std::cin >> Answer;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

            Answer = std::tolower(Answer);

            if (Answer == 'y') return true;
            if (Answer == 'n') return false;
        }
    }

    int ReadEvenNumber(const std::string& Message) {
        int num;
        do {
            std::cout << Message << std::endl;
            std::cin >> num;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        } while (!MyMathUtilityLib::IsEven(num));

        return num;
    }

    int ReadOddNumber(const std::string& Message) {
        int num;
        do {
            std::cout << Message << std::endl;
            std::cin >> num;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        } while (!MyMathUtilityLib::IsOdd(num));

        return num;
    }

    int ReadPrimeNumber(const std::string& Message) {
        int num;
        do {
            std::cout << Message << std::endl;
            std::cin >> num;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        } while (!MyMathUtilityLib::IsPrime(num));

        return num;
    }

    int ReadMenuChoice(int NumberOfOptions) {
        int Choice;
        do {
            std::cout << "Enter your choice (1 - "
                << NumberOfOptions << "): ";
            std::cin >> Choice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }

        } while (Choice < 1 || Choice > NumberOfOptions);

        return Choice;
    }

    void Printl(const std::string& Message) {
        std::cout << Message << std::endl;
    }

    void Print(const std::string& Message) {
        std::cout << Message;
    }

    void PrintNumber(double Number) {
        std::cout << Number << std::endl;
    }

    void SetColor(int color) {
        // color = 0..15
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);




                     /*| ÑÞã | Çááæä        |
                   | --- | ------------ |
                   | 0   | ÃÓæÏ         |
                   | 1   | ÃÒÑÞ         |
                   | 2   | ÃÎÖÑ         |
                   | 3   | ÓãÇæí        |
                   | 4   | ÃÍãÑ         |
                   | 5   | ÃÑÌæÇäí      |
                   | 6   | ÃÕÝÑ/ÈÑÊÞÇáí |
                   | 7   | ÃÈíÖ         |
                   | 8   | ÑãÇÏí        |
                   | 9   | ÃÒÑÞ ÝÇÊÍ    |
                   | 10  | ÃÎÖÑ ÝÇÊÍ    |
                   | 11  | ÓãÇæí ÝÇÊÍ   |
                   | 12  | ÃÍãÑ ÝÇÊÍ    |
                   | 13  | æÑÏí         |
                   | 14  | ÃÕÝÑ ÝÇÊÍ    |
                   | 15  | ÃÈíÖ ÝÇÊÍ    |
                   */




    }
    void PrintHeader(const std::string& Title) {
        SetColor(2);
        std::cout << "==== " << Title << " ====" << std::endl;
        SetColor(7);
    }

    void PrintError(const std::string& Message) {
        SetColor(4);
        std::cout << "[ERROR] " << Message << std::endl;
        SetColor(7);
    }

    void PrintSuccess(const std::string& Message) {
        SetColor(2);
        std::cout << "[SUCCESS] " << Message << std::endl;
        SetColor(7);
    }
    void PrintLineWithBorder(const std::string& Text, char BorderChar = '*') {
        std::string border(Text.length() + 4, BorderChar);
        std::cout << border << std::endl;
        std::cout << BorderChar << " " << Text << " " << BorderChar << std::endl;
        std::cout << border << std::endl;
    }
    void PrintMenu(const std::vector<std::string>& Options) {
        for (size_t i = 0; i < Options.size(); i++) {
            std::cout << (i + 1) << ") " << Options[i] << std::endl;
        }
    }
    void PrintTable(const std::vector<std::vector<std::string>>& TableData) {
        for (const auto& row : TableData) {
            for (const auto& col : row) {
                std::cout << col << "\t";
            }
            std::cout << std::endl;
        }
    }
    void PrintCountdown(int Seconds, const std:: string& Message= "Go!        ") {
        for (int i = Seconds; i > 0; i--) {
            std::cout << i << "...\r" << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << Message<< std::endl;
    }
     
    void PrintProgressBar(int Percent) {
        int totalBars = 50;
        int filled = Percent * totalBars / 100;
        std::cout << "[";
        for (int i = 0; i < totalBars; i++) {
            if (i < filled) std::cout << "=";
            else std::cout << " ";
        }
        std::cout << "] " << Percent << "%" << std::flush;
        if (Percent == 100) std::cout << std::endl;
    }
    void AskAndPrint(const std::string& Message) {
        std::string input;
        std::cout << Message << ": ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, input);
        std::cout << "You entered: " << input << std::endl;
    }
    void PrintYesNoResult(bool Answer) {
        if (Answer) std::cout << "User answered YES" << std::endl;
        else std::cout << "User answered NO" << std::endl;
    }
    void PrintColored(const std::string& Message, int color) {
        SetColor(color);
        std::cout << Message << std::endl;
        SetColor(7); 
    }

}
