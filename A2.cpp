#include "A2.h"
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <cctype>
#include <list>
#include <regex>
#include <vector>
#include "SLL.h"
#include "Token.h"
#include "Node.h"

/**
 * Constructor
 */
A2::A2() : wordList() {};

/**
 * Processes the input word
 *
 * @param word The word to process
 */
int A2::main(int argc, char* argv[]) {
    A2* pA2 = new A2();
    pA2->processInput();
    pA2->printStatistics();
    return 0;
}

/**
 * Processes the input word
 *
 * @param word The word to process
 */
void A2::processInput() {
    std::string word;
    while (std::cin >> word) {
        processWord(word);
    }
}

/**
 * Process the given word by trimming, converting to lowercase, and removing
 * non-alphabetic characters. If the word is a stop word, increment the total
 * stop words. Otherwise, add the word to the word list.
 *
 * @param word The word to be processed
 */
void A2::processWord(std::string word) {
    word = trim(word);
    word = toLowerCase(word);
    word = std::regex_replace(word, std::regex("[^a-zA-Z]"), "");

    if (word.empty()) {
        return;
    }

    if (isStopWord(word)) {
        totalStopWords++;
    } else {
        std::shared_ptr<Token> token = std::make_shared<Token>(word);
        int index = wordList.indexOf(*token);

        if (index == -1) {
            wordList.addInOrder(*token);
        } else {
            wordList.get(index)->getData().incrementCount();
        }
    }

    totalWords++;
}

/**
 * Checks if the given word is a stop word
 * 
 * @param word the word to check
 * @return true if the word is a stop word, false otherwise
 */
bool A2::isStopWord(std::string word) {
    std::string stopWords[] = { "a", "about", "all", "am", "an", "and", "any", "are", "as", "at", "be", "been", "but",
        "by", "can", "cannot", "could", "did", "do", "does", "else", "for", "from", "get", "got", "had", "has",
        "have", "he", "her", "hers", "him", "his", "how", "i", "if", "in", "into", "is", "it", "its", "like",
        "more", "me", "my", "no", "now", "not", "of", "on", "one", "or", "our", "out", "said", "say", "says",
        "she", "so", "some", "than", "that", "the", "their", "them", "then", "there", "these", "they", "this",
        "to", "too", "us", "upon", "was", "we", "were", "what", "with", "when", "where", "which", "while", "who",
        "whom", "why", "will", "you", "your" };

    for (std::string stopWord : stopWords) {
        if (stopWord == word) {
            return true;
        }
    }

    return false;
}

/**
 * Print statistics including total words, unique words, stop words,
 * most frequent words, least frequent words, and all words.
 */
void A2::printStatistics() {
    wordList.sort();
    calculateTotalWords();

    std::cout << "Total Words: " << totalWords << "\n";
    std::cout << "Unique Words: " << wordList.size() << "\n";
    std::cout << "Total Stop Words: " << totalStopWords << "\n";

    std::cout << "\n10 Most Frequent";
    printTopWords(10);

    std::cout << "\n10 Least Frequent";
    printBottomWords(10);

    std::cout << "\nAll";
    printAllWords();
}

/**
 * Print the top n most frequent words
 *
 */
void A2::calculateTotalWords() {
    std::shared_ptr<Node<Token>> current = wordList.getHead();
    while (current != nullptr) {
        if (isStopWord(current->getData().getWord())) {
            totalStopWords += current->getData().getCount();
        }
        current->getNext();
    }
}

/**
 * Print the top n most frequent words along with their counts
 *
 * @param n The number of most frequent words to print
 */
void A2::printTopWords(int n) {
    std::shared_ptr<Node<Token>> current = wordList.getHead();
    std::vector<std::shared_ptr<Token>> topWordsList;

    for (int i = 0; std::min(n, wordList.size()); i++) {
        topWordsList.push_back(std::make_shared<Token>(current->getData()));
        current = current->getNext();
    }

    std::sort(topWordsList.begin(), topWordsList.end(), [](const std::shared_ptr<Token>& a, const std::shared_ptr<Token>& b) {
        if (a->getCount() != b->getCount()) {
            return a->getCount() > b->getCount();
        }
        return a->getWord() < b->getWord();
    });

    for (std::shared_ptr<Token> token : topWordsList) {
        std::cout << token->getWord() << " : " << token->getCount() << "\n";
    }
}

/**
 * Print the bottom n words along with their counts.
 *
 * @param n the number of bottom words to print
 * @return void
 */
void A2::printBottomWords(int n) {
    std::shared_ptr<Node<Token>> current = wordList.getHead();
    std::vector<std::shared_ptr<Token>> bottomWordsList;

    int size = wordList.size();
    for (int i = 0; i < std::min(n, size); i++) {
        bottomWordsList.push_back(std::make_shared<Token>(current->getData()));
        current = current->getNext();
    }

    std::sort(bottomWordsList.begin(), bottomWordsList.end(), [](const std::shared_ptr<Token>& a, const std::shared_ptr<Token>& b) {
        if (a->getCount() != b->getCount()) {
            return a->getCount() < b->getCount();
        }
        return a->getWord() < b->getWord();
    });

    for (std::shared_ptr<Token> token : bottomWordsList) {
        std::cout << token->getWord() << " : " << token->getCount() << "\n";
    }
}

/**
 * Print all words in the word list along with their counts
 *
 * @param None
 * @return None
 */
void A2::printAllWords() {
    std::shared_ptr<Node<Token>> current = wordList.getHead();
    while (current != nullptr) {
        Token token = current->getData();
        std::cout << token.getWord() << " : " << token.getCount() << "\n";
        current = current->getNext();
    }
}


/**
 * Trim function. Remove leading and trailing spaces
 *
 * @param str The string to trim
 */
std::string A2::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

/**
 * Convert string to lower case
 *
 * @param str The string to convert to lower case
 */
std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
    return str;
}