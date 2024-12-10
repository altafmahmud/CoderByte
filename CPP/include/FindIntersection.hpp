// Find Intersection
// Easy
// Have the function FindIntersection(strArr) read the array of strings stored in strArr which will contain 2 elements: the first element
// will represent a list of comma-separated numbers sorted in ascending order, the second element will represent a second list of
// comma-separated numbers (also sorted). Your goal is to return a comma-separated string containing the numbers that occur in elements
// of strArr in sorted order. If there is no intersection, return the string false.

// Examples
// Input: {"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"}
// Output: 1,4,13

// Input: {"1, 3, 9, 10, 17, 18", "1, 4, 9, 10"}
// Output: 1,9,10

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> tokenizeToNum(const std::string& str)
{
    std::vector<int> tokens;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, ','))
    {
        auto num = std::stoi(token);
        tokens.push_back(num);
    }
    tokens.shrink_to_fit();
    return tokens;
}

std::string FindIntersection(const std::string strArr[], int arrLength)
{
    // code goes here
    const auto& nums01 = tokenizeToNum(strArr[0]);
    const auto& nums02 = tokenizeToNum(strArr[1]);
    std::vector<int> res;
    std::set_intersection(nums01.begin(), nums01.end(), nums02.begin(), nums02.end(), std::back_inserter(res));
    if (res.empty())
    {
        return "false";
    }
    std::ostringstream oss;
    for (auto idx = 0; idx < res.size(); ++idx)
    {
        oss << res[idx];
        if (idx < res.size()-1)
        {
            oss << ',';
        }
    }
    return oss.str();
}
