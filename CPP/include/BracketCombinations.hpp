// Bracket combinations
// Difficulty level: Hard
// Have the function BracketCombinations(num) read num which will be an integer greater than or equal to zero,
// and return the number of valid combinations that can be formed with num pairs of parentheses. For example,
// if the input is 3, then the possible combinations of 3 pairs of parenthesis, namely: ()()(), are ()()(), ()(()), (())(), ((())), and (()()).
// There are 5 total combinations when the input is 3, so your program should return 5.
//
// Examples:
// Input: 3
// Output: 5

// Input: 2
// Output: 2

// The solution is taken from:
// https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

#pragma once

#include <iostream>
#include <string>

// function which generates all possible n pairs of balanced
void genParenthesisUtil(int n, int open, int close, unsigned &count)
{

    // if the count of both open and close parentheses
    // reaches n, it means we have generated a valid
    // parentheses.
    if (open == n && close == n)
    {
        ++count;
        return;
    }

    // At any index i in the generation of the string s, we
    // can put an open parentheses only if its count until
    // that time is less than n.
    if (open < n)
    {
        genParenthesisUtil(n, open + 1, close, count);
    }

    // At any index i in the generation of the string s, we
    // can put a closed parentheses only if its count until
    // that time is less than the count of open parentheses.
    if (close < open)
    {
        genParenthesisUtil(n, open, close + 1, count);
    }
}

unsigned BracketCombinations(unsigned num)
{
    if (num == 0)
    {
        return 1;
    }
    unsigned count = 0;
    genParenthesisUtil(num, 0, 0, count);
    return count;
}