#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "SLL.h"
#include "Token.h"
#include "Node.h"

// template <typename Token>
class A2 {
public:
    A2();
    int main(int argc, char* argv[]);
    
private:
    SLL<Token> wordList;
    int totalStopWords;
    int totalWords;
    void processInput();
    void processWord(std::string word);
    bool isStopWord(std::string word);
    void printStatistics();
    void calculateTotalWords();
    void printTopWords(int n);
    void printBottomWords(int n);
    void printAllWords();
    std::string trim(const std::string& str);
    std::string toLowerCase(std::string str);
};
