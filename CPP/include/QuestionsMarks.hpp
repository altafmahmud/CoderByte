// Questions Marks
// Easy
// Have the function QuestionsMarks(str) take the str string parameter, which will contain single digit numbers, letters, and question marks,
// and check if there are exactly 3 question marks between every pair of two numbers that add up to 10.
// If so, then your program should return the string true, otherwise it should return the string false. If there aren't any two numbers that add up to 10 in the string,
// then your program should return false as well.

// For example: if str is "arrb6???4xxbl5???eee5" then your program should return true because there are exactly 3 question marks between 6 and 4, and 3 question marks
// between 5 and 5 at the end of the string.

// Examples

// Input: "aa6?9"
// Output: false

// Input: "acc?7??sss?3rr1??????5"
// Output: true

#pragma once

#include <iostream>
#include <string>
#include <cctype>

std::string QuestionsMarks(const std::string &str)
{
    // code goes here
    std::string res("false");
    auto firstIdx = -1;
    auto secondIdx = -1;
    unsigned count = 0;
    for (auto idx = 0; idx < str.length(); ++idx)
    {
        const auto ch = str[idx];
        if (std::isdigit(ch))
        {
            if (firstIdx < 0)
            {
                firstIdx = idx;
                count = 0;
            }
            else if (secondIdx < 0)
            {
                secondIdx = idx;
                const auto sum = (str[firstIdx] - '0') + (str[secondIdx] - '0');
                if (sum == 10)
                {
                    if (count == 3)
                    {
                        res = "true";
                    }
                    else
                    {
                        res = "false";
                        break;
                    }
                }
                firstIdx = secondIdx;
                secondIdx = -1;
                count = 0;
            }
        }
        else if (ch == '?')
        {
            ++count;
        }
    }
    return res;
}