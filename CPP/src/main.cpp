
#include "MinWindowSubstr.hpp"
#include "BracketCombinations.hpp"
#include "TreeConstructor.hpp"
#include "CodelandUsernameValidation.hpp"
#include "BracketMatcher.hpp"
#include "FindIntersection.hpp"
#include "QuestionsMarks.hpp"
#include "FirstReverse.hpp"
#include "FirstFactorial.hpp"
#include "LongestWord.hpp"

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

    {
        // Codeland Username Validation

        std::cout << "\n\n";
        // keep this function call here
        // cout << CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
        std::cout << CodelandUsernameValidation("u__hello_world123");
        // std::cout << CodelandUsernameValidation("aa_");
    }

    {
        // Bracket Matcher

        std::cout << "\n\n";
        // std::cout << BracketMatcher("(coder)(byte))");
        // std::cout << BracketMatcher("(c(oder)) b(yte)");
        std::cout << BracketMatcher("");
    }

    {
        // Find Intersection

        std::cout << "\n\n";
        // std::string A[] = {"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"};
        std::string A[] = {"1, 3, 9, 10, 17, 18", "1, 4, 9, 10"};
        // std::string A[] = {"1, 2, 3, 4, 5, 6", "7, 8, 9, 10"};
        int arrLength = sizeof(A) / sizeof(*A);
        std::cout << FindIntersection(A, arrLength);
    }

    {
        // Questions Marks

        std::cout << "\n\n";
        std::cout << QuestionsMarks("arrb6???4xxbl5???eee5");
        std::cout << "\n";
        std::cout << QuestionsMarks("acc?7??sss?3rr1??????5");
        std::cout << "\n";
        std::cout << QuestionsMarks("5??aaaaaaaaaaaaaaaaaaa?5?5");
        std::cout << "\n";
        std::cout << QuestionsMarks("9???1???9??1???9");
        std::cout << "\n";
        std::cout << QuestionsMarks("aa6?9");
        std::cout << "\n";
        std::cout << QuestionsMarks("aa6???4");
    }

    {
        // First Reverse

        std::cout << "\n\n";
        std::cout << FirstReverse("coderbyte");
        std::cout << "\n";
        std::cout << FirstReverse("I Love Code");
    }

    {
        // First Factorial
        std::cout << "\n\n";
        std::cout << FirstFactorial(18);
    }

    {
        // Longest Word

        std::cout << "\n\n";
        std::cout << LongestWord("fun&!! time");
        std::cout << "\n";
        std::cout << LongestWord("I love dogs");
    }

    return 0;
}
