#include <iostream>
#include <algorithm>

struct Activity
{
    int start;
    int end;
};


int activitySelection(Activity activities[], int size)
{
    std::sort(activities, activities + size, [](Activity first, Activity second) -> bool {
        return first.end <= second.end;
    });

    int selectedActivity = 0;
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (activities[i].start >= activities[selectedActivity].end) {    
            count++;
            selectedActivity = i;
        }
    }
    return count;
}

int main()
{
    int size = 6;

    Activity activities[6] = {
        {0, 6},
        {3, 4},
        {1, 2},
        {5, 9},
        {5, 7},
        {8, 9}
    };

    std::cout << activitySelection(activities, size) << std::endl;

    return 0;

}