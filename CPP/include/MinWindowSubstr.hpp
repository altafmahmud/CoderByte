// Min Window Substring
// Difficulty level: Medium
// Have the function MinWindowSubstring(strArr) take the array of strings stored in strArr, which will contain only two strings,
// the first parameter being the string N and the second parameter being a string K of some characters,
// and your goal is to determine the smallest substring of N that contains all the characters in K.
// For example: if strArr is ["aaabaaddae", "aed"] then the smallest substring of N that contains the characters a, e, and d is "dae"
// located at the end of the string.
// So for this example your program should return the string dae.

// Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest substring of N that contains all of the characters in K is "aabd"
// which is located at the beginning of the string. Both parameters will be strings ranging in length from 1 to 50 characters
// and all of K's characters will exist somewhere in the string N. Both strings will only contains lowercase alphabetic characters.

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, unsigned> K_counter;
std::unordered_map<char, unsigned> N_counter;

unsigned diffWithAllKChars(const std::string &subStr, const unsigned startAt)
{
    for (auto idx = startAt; idx < subStr.length(); ++idx)
    {
        auto ch = subStr.at(idx);
        auto itr = N_counter.find(ch);
        if (itr == N_counter.end())
        {
            N_counter.emplace(std::make_pair(ch, 1));
        }
        else
        {
            auto &count = itr->second;
            ++count;
        }
    }
    unsigned diff = 0;
    for (const auto &element : K_counter)
    {
        const auto &key = element.first;
        const auto &val = element.second;
        auto subStrItr = N_counter.find(key);
        if (subStrItr == N_counter.end())
        {
            diff += val;
            continue;
        }
        const auto subStrVal = subStrItr->second;
        if (subStrVal < val)
        {
            diff += (val - subStrVal);
        }
    }
    return diff;
}

unsigned discardLeadingCharsTo(const std::string &subStr)
{
    unsigned idx = 0;
    while (idx < subStr.length())
    {
        char ch = subStr[idx];
        auto K_itr = K_counter.find(ch);
        if (K_itr == K_counter.end())
        {
            ++idx;
            continue;
        }
        const auto K_count = K_itr->second;
        auto N_itr = N_counter.find(ch);
        auto &N_count = N_itr->second;
        if (N_count > K_count)
        {
            ++idx;
            --N_count;
        }
        else
        {
            break;
        }
    }
    return idx;
}

std::string MinWindowSubstring(const std::string strArr[], int arrLength)
{
    for (auto idx = 0; idx < strArr[1].length(); ++idx)
    {
        auto ch = strArr[1].at(idx);
        auto itr = K_counter.find(ch);
        if (itr == K_counter.end())
        {
            K_counter.emplace(std::make_pair(ch, 1));
        }
        else
        {
            auto &count = itr->second;
            ++count;
        }
    }
    std::string substr;
    size_t len = strArr[1].length();
    size_t prevLen = 0;
    unsigned diff = 0;
    while (len <= strArr[0].length())
    {
        substr = strArr[0].substr(0, len);
        diff = diffWithAllKChars(substr, prevLen);
        if (diff == 0)
        {
            break;
        }
        prevLen = len;
        len += diff;
    }
    if (diff > 0)
    {
        return "";
    }
    const auto startIdx = discardLeadingCharsTo(substr);
    if (startIdx > 0)
    {
        substr = substr.substr(startIdx);
    }
    return substr;
}