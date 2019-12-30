#include <iostream>
#include <string>
#include <algorithm>

int editDistance(std::string first, std::string second)
{
    int rows = first.size();
    int cols = second.size();

    int dp[rows + 1][cols + 1];

    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (first[rows - i] == second[cols - j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(
                    dp[i - 1][j],
                    std::min(
                        dp[i][j - 1],
                        dp[i - 1][j - 1]
                    )
                ) + 1;
            }

        }
    }

    return dp[rows][cols];
}

int main()
{
    std::string first = "abc";
    std::string second = "dc";

    std::cout << editDistance(first, second) << std::endl;

    return 0;
}