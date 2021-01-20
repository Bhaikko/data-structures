#include <iostream>
#include <algorithm>

struct Job
{
    int start;
    int end;
    int profit;
};

int nonConflict(Job jobs[], int n)
{
    for (int j = n; j >= 0; j--) {
        if (jobs[j].end <= jobs[n - 1].start) {
            return j;
        }
    }
    return -1;
}

int maxProfitRecursive(Job jobs[], int n)
{
    if (n == 1) {
        return jobs[n - 1].profit;
    }

    int lastJobIndex = nonConflict(jobs, n);
    int profit = jobs[n - 1].profit;
    
    if (lastJobIndex != -1) {
        profit += maxProfitRecursive(jobs, lastJobIndex + 1);
    }

    return std::max(profit, maxProfitRecursive(jobs, n - 1));
}

int maxProfitDP(Job jobs[], int n)
{
    int dp[n];
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int profit = jobs[i].profit;
        int lastJobIndex = nonConflict(jobs, i);
        if (lastJobIndex != -1) {
            profit += dp[lastJobIndex];
        }

        dp[i] = std::max(profit, dp[i - 1]);
    }

    return dp[n - 1];
}

int maxProfit(Job jobs[], int n)
{
    std::sort(jobs, jobs + n, [](Job a, Job b) -> bool {
        return a.end < b.end;
    });

    // return maxProfitRecursive(jobs, n);
    return maxProfitDP(jobs, n);
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	std::cout << "The optimal profit is " << maxProfit(arr, n) << std::endl; 
	return 0; 
}