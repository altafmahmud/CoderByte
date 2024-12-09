
#include "MinWindowSubstr.hpp"
#include "BracketCombinations.hpp"

#include <algorithm>

int main()
{
    // MinWindowSubstring
    //std::string A[] = {"ahffaksfajeeubsne", "jefaa"};
    //std::string A[] = {"aaffhkksemckelloe", "fhea"};
    //std::string A[] = {"aabdccdbcacd", "aad"};
    std::string A[] = {"aaffsfsfasfasfasfasfasfacasfafe", "fafsf"};
    //std::string A[] = {"vvavereveaevafefaef", "vvev"};
    int arrLength = sizeof(A) / sizeof(*A);
    std::cout << MinWindowSubstring(A, arrLength);

    // Bracket combinations
    std::cout << "\n\n";
    std::cout << BracketCombinations(3) << '\n';
    
    return 0;
}
