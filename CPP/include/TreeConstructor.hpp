// Tree Constructor
// Medium
// Have the function TreeConstructor(strArr) take the array of strings stored in strArr, which will contain pairs of integers in the following format: (i1,i2),
// where i1 represents a child node in a tree and the second integer i2 signifies that it is the parent of i1. For example: if strArr is ["(1,2)", "(2,4)", "(7,2)"],
// then this forms the following tree:

//         4
//        /
//       2
//      /\
//     1  7

// which you can see forms a proper binary tree. Your program should, in this case, return the string true because a valid binary tree can be formed.
// If a proper binary tree cannot be formed with the integer pairs, then return the string false. All of the integers within the tree will be unique,
// which means there can only be one node in the tree with the given integer value.

// Input: {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"}
// Output: true

// Input: {"(1,2)", "(3,2)", "(2,12)", "(5,2)"}
// Output: false

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::unordered_map<int, std::unordered_set<int>> parentSetMap;
typedef std::unordered_set<int> childrenSet;

std::string discardParenthesis(std::string &str)
{
    const auto pos1 = str.find('(');
    const auto pos2 = str.rfind(')');
    auto substr = str.substr(pos1+1, pos2-1);
    return substr;
}

std::vector<int> splitString(std::string &str)
{
    std::istringstream iss(str);
    std::string token;
    std::vector<int> tokens;
    while (std::getline(iss, token, ','))
    {
        auto num = std::stoi(token);
        tokens.push_back(num);
    }
    tokens.shrink_to_fit();
    return tokens;
}

std::string TreeConstructor(std::string strArr[], int arrLength)
{
    // code goes here
    std::string ret = "true";
    parentSetMap parents;
    childrenSet children;
    for (auto idx = 0; idx < arrLength; ++idx)
    {
        auto &str = strArr[idx];
        auto procStr = discardParenthesis(str);
        auto vec = splitString(procStr);
        const auto parent = vec[1];
        const auto child = vec[0];
        if (children.count(child) >= 1)
        {
            ret = "false";
            break;
        }
        children.insert(child);
        auto parent_itr = parents.find(parent);
        if (parent_itr == parents.end())
        {
            childrenSet cSet;
            cSet.insert(child);
            parents.emplace(std::make_pair(parent, cSet));
        }
        else
        {
            auto &s = parent_itr->second;
            if (s.size() > 1)
            {
                ret = "false";
                break;
            }
            s.insert(child);
        }
    }
    return ret;
}
