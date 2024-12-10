// Codeland Username Validation
// Easy
// Have the function CodelandUsernameValidation(str) take the str parameter being passed and determine if the string is a valid username according to the following rules:

// 1. The username is between 4 and 25 characters.
// 2. It must start with a letter.
// 3. It can only contain letters, numbers, and the underscore character.
// 4. It cannot end with an underscore character.

// If the username is valid then your program should return the string true, otherwise return the string false.

// Input: "aa_"
// Output: false

// Input: "u__hello_world123"
// Output: true

#pragma once

#include <iostream>
#include <string>
#include <algorithm>

std::string CodelandUsernameValidation(const std::string &str)
{
    // code goes here
    const auto len = str.length();
    if (len < 4 || len > 25)
    {
        return "false";
    }
    if (!std::isalpha(str[0]))
    {
        return "false";
    }
    if (!std::isalnum(str[len - 1]))
    {
        return "false";
    }
    const auto itr = std::find_if(str.begin(), str.end(), [](const char ch)
                                  { return !std::isalnum(ch) && (ch != '_'); });
    return (itr == str.end()) ? "true" : "false";
}
