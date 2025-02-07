#pragma once

#include <memory>
#include <string>

class Token {
public:
    Token(std::string word);
    std::string getWord();
    int getCount();
    void incrementCount();
    bool equals(const std::shared_ptr<Token> obj);
    int compareTo(Token otherToken);
    
private:
    std::string word;
    int count;
};
