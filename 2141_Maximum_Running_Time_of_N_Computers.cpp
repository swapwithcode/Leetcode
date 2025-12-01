/*

Leetcode Link : https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

*/

/*****************************************C++**************************************************/
/*
    Approach (Brute force) using simple for loops
    TC : O(n^2) 
    SC : O(1)
*/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);

        sort(batteries.begin(), batteries.end());

        // The maximum battery is greater than the avarge, so it can last forever.
        // Reduce the problem from size n to size n-1

        while(batteries.back() > sum /n)
        {
            sum-=batteries.back();
            batteries.pop_back();
            --n;
        }

        // If the maximum battery <= average running time, it won't be waste, and so
        // do smaller batteries
        return sum/n;
    }
};