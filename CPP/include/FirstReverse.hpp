// First Reverse
// Easy
// Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order.
// For example: if the input string is "Hello World and Coders" then your program should return the string sredoC dna dlroW olleH.
// Examples

// Input: "coderbyte"
// Output: etybredoc

// Input: "I Love Code"
// Output: edoC evoL I

#pragma once

#include <iostream>
#include <string>
#include <algorithm>

std::string FirstReverse(std::string str)
{
    // code goes here
    std::reverse(str.begin(), str.end());
    return str;
}