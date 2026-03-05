#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
///////////////////////////////////////////////////////////////////////////
///////////////////// My  Files Utility  Library /////////////////////////
/////////////////////////////////////////////////////////////////////////
void LoadDataFromFileToVector(std::string FileName, std::vector<std::string>& vFileContent) {
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::in);

    if (MyFile.is_open()) {
        std::string Line;
        while (std::getline(MyFile, Line)) {
            vFileContent.push_back(Line);
        }
        MyFile.close();
    }
}

void PrintFileContent(std::string FileName) {
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::in);

    if (MyFile.is_open()) {
        std::string Line;
        while (std::getline(MyFile, Line)) {
            std::cout << Line << std::endl;
        }
        MyFile.close();
    }
}
void SaveVectorToFile(std::string FileName, std::vector<std::string> vFileContent) {
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::out);

    if (MyFile.is_open()) {
        for (const std::string& Line : vFileContent) {
            if (Line != "") {
                MyFile << Line << std::endl;
            }
        }
        MyFile.close();
    }
}
void DeleteRecordFromFile(std::string FileName, std::string RecordName) {

    std::vector<std::string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);

    for (std::string& Record : vFileContent) {
        if (Record == RecordName) {
            Record = "";
        }
    }

    SaveVectorToFile(FileName, vFileContent);
}
void UpdateRecordInFile(std::string FileName, std::string Record, std::string UpdateTo) {

    std::vector<std::string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);

    for (std::string& Line : vFileContent) {
        if (Line == Record) {
            Line = UpdateTo;
        }
    }

    SaveVectorToFile(FileName, vFileContent);
}