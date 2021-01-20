#include <iostream>

#define N 4

bool isMorePreffered(int preferences[2 * N][N], int chosenWoman, int currentFreeMan, int currentEngagedMan) {
    for (int i = 0; i < N; i++) {
        if (preferences[chosenWoman][i] == currentEngagedMan) {
            return true;
        }
        if (preferences[chosenWoman][i] == currentFreeMan) {
            return false;
        }
    }
}

void stableMarriage(int preferences[2 * N][N])
{
    int partner[N];
    bool free[N];

    for (int i = 0; i < N; i++) {
        partner[i] = -1;
        free[i] = false;
    }

    int freeCount = N;
    
    while (freeCount > 0) {
        int currentFreeMan;
        for (int i = 0; i < N; i++) {
            if (!free[i]) {
                currentFreeMan = i;
                break;
            }
        }

        for (int i = 0; i < N && !free[currentFreeMan]; i++) {
            int chosenWoman = preferences[currentFreeMan][i];

            // condition to check is women is free
            if (partner[chosenWoman - N] == -1) {
                partner[chosenWoman - N] = currentFreeMan;
                free[currentFreeMan] = true;
                freeCount--;
            } else {
                int currentEngagedMan = partner[chosenWoman - N];
                if (!isMorePreffered(preferences, chosenWoman, currentFreeMan, currentEngagedMan)) {
                    partner[chosenWoman - N] = currentFreeMan;
                    free[currentFreeMan] = true;
                    free[currentEngagedMan] = false;
                }
            }
        }
    }

    std::cout << "Women\tMen" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << i + N << "\t" << partner[i] << std::endl;
    }
}

int main()
{
    int preferences[2 * N][N] = {
        {7, 5, 6, 4}, 
		{5, 4, 6, 7}, 
		{4, 5, 6, 7}, 
		{4, 5, 6, 7}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}
    };
    stableMarriage(preferences);

    return 0;
}