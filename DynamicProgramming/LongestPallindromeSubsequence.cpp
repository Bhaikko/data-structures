#include <iostream>
#include <string>
#include <algorithm>

int LPS_recursive(std::string input, int start, int end)
{
    if (input.length() == 1 || start == end) {
        return 1;
    }

    if (input[start] == input[end]) {
        if (input.length() == 2) {
            return 2;
        } else {
            return LPS_recursive(input, start + 1, end - 1) + 2;
        }
    } else {
        return std::max(LPS_recursive(input, start + 1, end), LPS_recursive(input, start, end - 1));
    }
}

int LPS_dynamic(std::string input)
{
    int size = input.length();

    int dp[size][size];

    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }

    for (int i = 2; i <= size; i++) {
        for (int j = 0; j < size - i + 1; j++) {
            int k = i + j - 1;

            if (input[k] == input[j]) {
                if (i == 2) {
                    dp[j][k] = 2;
                } else {
                    dp[j][k] = dp[j + 1][k - 1] + 2;
                }
            } else {
                dp[j][k] = std::max(dp[j][k - 1], dp[j + 1][k]);
            }
        }
    }
    return dp[0][size - 1];
}

int main()
{
    std::string input = "racecar";
    // std::string input = "character";

    std::cout << LPS_recursive(input, 0, input.length() - 1) << std::endl;
    std::cout << LPS_dynamic(input) << std::endl;

    return 0;
}