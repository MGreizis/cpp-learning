#include "Token.h"
#include <iostream>
#include <string>
#include <typeinfo>

/**
 * Constructor
 *
 * @param word The word to store in the token
 */
Token::Token(std::string word) : word(word), count(1) {};

/**
 * Returns the word stored in the token
 *
 * @return std::string The word stored in the token
 */
std::string Token::getWord() {
    return word;
}

/**
 * Returns the count of the token
 *
 * @return int The count of the token
 */
int Token::getCount() {
    return count;
}

/**
 * Increments the count of the token
 */
void Token::incrementCount() {
    count++;
}

/**
 * Compares the word of this token to the word of another token
 *
 * @param obj The other token to compare to
 * @return bool True if the words are equal, false otherwise
 */
bool Token::equals(const std::shared_ptr<Token> obj) {
    if (this == obj.get()) return true;
    if (obj == nullptr || typeid(*this) != typeid(*obj)) return false;
    return word == obj->word;
}

/**
 * Compares the word of this token to the word of another token
 *
 * @param otherToken The other token to compare to
 * @return int 0 if the words are equal, a positive number if this word is greater, a negative number if this word is less
 */
int Token::compareTo(Token otherToken) {
    return word.compare(otherToken.getWord());
}