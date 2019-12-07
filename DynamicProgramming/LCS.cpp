#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

int LCS_recursive(std::string first, std::string second)
{
    if (first.length() == 0 || second.length() == 0) {
        return 0;
    }

    if (first[0] == second[0]) {
        return 1 + LCS_recursive(first.substr(1), second.substr(1));
    } else {
        return std::max(LCS_recursive(first, second.substr(1)), LCS_recursive(first.substr(1), second));
    }
}

void print_LCS(std::string array[][99], int  i, int j, std::string first)
{
    if (i == 0 || j == 0) {
        return;
    }

    if (array[i][j] == "diagonal") {
        print_LCS(array, i - 1, j - 1, first);
        std::cout << first[i];
    } else {
        if (array[i][j] == "up") {
            print_LCS(array, i - 1, j, first);
        } else if(array[i][j] == "side") {
            print_LCS(array, i, j - 1, first);
        }
    }
}

int LCS_dynamic(std::string first, std::string second) 
{
    int size1 = first.length();
    int size2 = second.length();
    int dp[size1 + 1][size2 + 1];
    std::string array[size1  + 1][99];

    for (int i = 0; i <= size1; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= size2; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                array[i][j] = "diagonal";
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    array[i][j] = "up";
                } else {
                    dp[i][j] = dp[i][j - 1];
                    array[i][j] = "side";
                }
            }
        }
    }

    print_LCS(array, size1, size2, first);
    std::cout << std::endl;

    return dp[size1 - 1][size2 - 1];
}


int main()
{
    std::string first = "abcdefghij";
    std::string second = "ecdgij";

    std::cout << LCS_recursive(first, second) << std::endl;
    std::cout << LCS_dynamic(first, second) << std::endl;

    return 0;
}
