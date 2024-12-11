// Longest Word
// Easy
// Have the function LongestWord(sen) take the sen parameter being passed and return the longest word in the string. 
// If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty. 
// Words may also contain numbers, for example "Hello world123 567"

// Examples

// Input: "fun&!! time"
// Output: time

// Input: "I love dogs"
// Output: love

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

bool isWord(const std::string& str)
{
    const auto itr = std::find_if(str.begin(), str.end(), [] (const char ch) { return !std::isalnum(ch); });
    return itr == str.end();
}

std::string LongestWord(std::string sen)
{
    std::string longest;
    std::istringstream iss(sen);
    std::string token;
    unsigned len = 0;
    while (std::getline(iss, token, ' '))
    {
        if (!isWord(token))
        {
            continue;
        }
        if (token.length() > len)
        {
            longest = token;
            len = token.length();
        }
    }
    return longest;
}