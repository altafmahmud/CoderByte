// Bracket Matcher
// Medium
// Have the function BracketMatcher(str) take the str parameter being passed and return 1 if the brackets are correctly matched and each one is accounted for.
// Otherwise return 0. For example: if str is "(hello (world))", then the output should be 1, but if str is "((hello (world))" the the output should be 0
// because the brackets do not correctly match up. Only "(" and ")" will be used as brackets. If str contains no brackets return 1.

// Input: "(coder)(byte))"
// Output: 0

// Input: "(c(oder)) b(yte)"
// Output: 1

#pragma once

#include <iostream>
#include <string>
#include <stack>

std::string BracketMatcher(const std::string &str)
{
    // code goes here
    std::string ret("1");
    std::stack<char> stck;
    for (const auto &ch : str)
    {
        if (ch == '(')
        {
            stck.push(ch);
        }
        else if (ch == ')')
        {
            if (stck.empty())
            {
                ret = "0";
                break;
            }
            const auto &top = stck.top();
            if (top != '(')
            {
                ret = "0";
                break;
            }
            stck.pop();
        }
    }
    ret = (ret != "0" && stck.empty()) ? "1" : "0";
    return ret;
}