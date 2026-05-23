#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

///////////////////////////////////////////////////////////////////////////
/////////////////My string Utility lib ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////

namespace MyStringUtilityLib {
    std::vector<std::string> SplitString(std::string s, std::string Delimter) {
        std::vector<std::string> vString;
        std::string sWord;
        short pos;

        while ((pos = s.find(Delimter)) != std::string::npos) {
            sWord = s.substr(0, pos);

            if (sWord != "")
                vString.push_back(sWord);

            s.erase(0, pos + Delimter.length());
        }

        if (s != "")
            vString.push_back(s);

        return vString;
    }

    std::string RemovePunctuationFromString(std::string S1)
    {
        std::string s2 = "";

        for (char c : S1) {
            if (!std::ispunct(c))
                s2 += c;
        }

        return s2;
    }
    std::string ReplaceWordInStringUsingBultInFunction(std::string S1, std::string StringToReplace, std::string sReplaceTo) {
        short Pos = S1.find(StringToReplace);
        while (Pos != std::string::npos) {
            S1 = S1.replace(Pos, StringToReplace.length(), sReplaceTo);
            Pos = S1.find(StringToReplace);
        }
        return S1;
    }

    std::string ReverseWordsInString(std::string S1) {
        std::string S2 = "";
        std::vector<std::string> vString = SplitString(S1, " ");
        std::vector<std::string>::iterator iter = vString.end();

        while (iter != vString.begin()) {
            iter--;
            S2 += *iter + " ";
        }

        S2 = S2.substr(0, S2.length() - 1);
        return S2;
    }

    std::string JoinString(std::vector<std::string> vString, std::string Delim) {
        std::string S1 = "";
        for (std::string& s : vString) {
            S1 += s + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    std::string JoinString(std::string arrString[100], short Length, std::string Delim) {
        std::string S1 = "";
        for (short i = 0; i < Length; i++) {
            S1 += arrString[i] + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

    std::string TrimLeft(std::string s) {
        for (short i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                return s.substr(i, s.length() - i);
            }
        }
        return "";
    }

    std::string TrimRight(std::string s) {
        for (short i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }

    std::string Trim(std::string s) {
        return TrimRight(TrimLeft(s));
    }

    void PrintEachWordInString(std::string s) {
        std::string Delimter = " ";
        std::string sWord;
        short pos;

        while ((pos = s.find(Delimter)) != std::string::npos) {
            sWord = s.substr(0, pos);

            if (sWord != "")
                std::cout << sWord << std::endl;

            s.erase(0, pos + Delimter.length());
        }

        if (s != "")
            std::cout << s << std::endl;
    }

    short CountWords(std::string s) {
        short counter = 0;
        std::string Delimter = " ";
        std::string sWord;
        short pos;

        while ((pos = s.find(Delimter)) != std::string::npos) {
            sWord = s.substr(0, pos);

            if (sWord != "")
                counter++;

            s.erase(0, pos + Delimter.length());
        }

        if (s != "")
            counter++;

        return counter;
    }

   
    std::string UpperAllLetters(std::string s1) {
        for (size_t i = 0; i < s1.length(); i++) {
            s1[i] = std::toupper(s1[i]);
        }
        return s1;
    }

    std::string LowerAllLetters(std::string s1) {
        for (size_t i = 0; i < s1.length(); i++) {
            s1[i] = std::tolower(s1[i]);
        }
        return s1;
    }

    short CountLetter(const std::string& s, char Letter, bool MatchCase = true) {
        short counter = 0;

        for (short i = 0; i < s.length(); i++) {
            if (MatchCase) {
                if (s[i] == Letter)
                    counter++;
            }
            else {
                if (std::tolower(s[i]) == std::tolower(Letter))
                    counter++;
            }
        }

        return counter;
    }

    void PrintFirstLetterOfEachWord(std::string s1) {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ' && IsFirstLetter) {
                std::cout << s1[i] << " ";
            }

            IsFirstLetter = (s1[i] == ' ');
        }
    }

    bool IsVowel(char Ch1) {
        Ch1 = std::tolower(Ch1);
        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

    short CountVowels(std::string s) {
        short counter = 0;
        for (char e : s) {
            if (IsVowel(e))
                counter++;
        }
        return counter;
    }

    void PrintVowelsInString(std::string s) {
        std::cout << "\nVowels in the string are : ";
        for (char e : s) {
            if (IsVowel(e))
                std::cout << e << " ";
        }
    }

    std::string UpperEachLetterOfEachWord(std::string s1) {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ' && IsFirstLetter) {
                s1[i] = std::toupper(s1[i]);
            }

            IsFirstLetter = (s1[i] == ' ');
        }

        return s1;
    }

    std::string LowerEachLetterOfEachWord(std::string s1) {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ' && IsFirstLetter) {
                s1[i] = std::tolower(s1[i]);
            }

            IsFirstLetter = (s1[i] == ' ');
        }

        return s1;
    }

    char InvertLetterCase(char c) {
        return (std::isupper(c) ? std::tolower(c) : std::toupper(c));
    }

    std::string InverAllStringLettersCase(std::string& s) {
        for (short i = 0; i < s.length(); i++) {
            s[i] = InvertLetterCase(s[i]);
        }
        return s;
    }

    short GetCapitalLerttersCount(std::string S1) {
        short CapitalCount = 0;
        for (short i = 0; i < S1.length(); i++) {
            if (std::isupper(S1[i]))
                CapitalCount++;
        }
        return CapitalCount;
    }

    short GetSmallLerttersCount(std::string S1) {
        short SmallCount = 0;
        for (short i = 0; i < S1.length(); i++) {
            if (std::islower(S1[i]))
                SmallCount++;
        }
        return SmallCount;
    }

    enum enWhatToCount { SmallLetter = 0, CapitalLetter = 1, All = 3 };

    short CountCharacters(const std::string& s, enWhatToCount WhatToCount = enWhatToCount::All) {
        if (WhatToCount == enWhatToCount::All)
            return s.length();

        short Counter = 0;

        for (short i = 0; i < s.length(); i++) {
            if (WhatToCount == enWhatToCount::CapitalLetter && std::isupper(s[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetter && std::islower(s[i]))
                Counter++;
        }

        return Counter;
    }

    std::string ReplaceWordInStringUsingSplit(std::string S1, std::string StringToReplace, std::string sRepalceTo, bool MatchCase = true) {
        std::vector<std::string> vString = SplitString(S1, " ");

        for (std::string& s : vString) {
            if (MatchCase) {
                if (s == StringToReplace)
                    s = sRepalceTo;
            }
            else {
                if (LowerAllLetters(s) == LowerAllLetters(StringToReplace))
                    s = sRepalceTo;
            }
        }

        return JoinString(vString, " ");
    }
}