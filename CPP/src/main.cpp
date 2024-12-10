
#include "MinWindowSubstr.hpp"
#include "BracketCombinations.hpp"
#include "TreeConstructor.hpp"

#include <algorithm>

int main()
{
    {
        // MinWindowSubstring

        // std::string A[] = {"ahffaksfajeeubsne", "jefaa"};
        // std::string A[] = {"aaffhkksemckelloe", "fhea"};
        // std::string A[] = {"aabdccdbcacd", "aad"};
        std::string A[] = {"aaffsfsfasfasfasfasfasfacasfafe", "fafsf"};
        // std::string A[] = {"vvavereveaevafefaef", "vvev"};
        int arrLength = sizeof(A) / sizeof(*A);
        std::cout << MinWindowSubstring(A, arrLength);
    }

    {
        // Bracket combinations

        std::cout << "\n\n";
        const auto &ans = BracketCombinations(2);
        std::copy(ans.begin(), ans.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    }

    {
        // TreeConstructor
        
        std::cout << "\n";
        // std::string A[] = coderbyteInternalStdinFunction(stdin);
        // std::string A[] = {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"};
        // std::string A[] = {"(1,2)", "(3,2)", "(2,12)", "(5,2)"};
        std::string A[] = {"(2,3)", "(1,2)", "(4,9)", "(9,3)", "(12,9)", "(6,4)"};
        int arrLength = sizeof(A) / sizeof(*A);
        std::cout << TreeConstructor(A, arrLength);
    }

    return 0;
}
