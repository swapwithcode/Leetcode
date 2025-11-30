/*

Leetcode Link : https://leetcode.com/problems/largest-rectangle-in-histogram/

*/


/*****************************************C++**************************************************/
/*
    Approach (Brute force) using simple for loops
    TC : O(n^2) 
    SC : O(1)
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        // used long long for calculate sum.
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        // If total sum already divisible by p, no subarray need to be removed.
        if(sum%p == 0)
            return 0;

        //Initializing minlen to the size fo the array.
        int minlen = n;
        
        // Try to removing every possible subarray
        for(int i =0; i<n; i++)
        {
            //Use avoid long long to avoid overflow 
            long long subsum = 0;
            for(int j = i; j<n; j++)
            {
                // calculating subarray sum.
                subsum+=nums[j];
                //checking after removing this subarray remaining divisible by p, if yes update the smallest subarray length.
                if((sum-subsum)%p==0)
                    minlen = min(minlen, (j-i+1));
            }
        }
        //if no valid subarray found, return -1.
        return minlen==n ? -1:minlen;
    }
};


/*****************************************C++**************************************************/
/*
    Approach (Expected Approch) using Stack
    TC : O(n) 
    SC : O(n)
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
		//Calculating total sum of array.
		//Finding the reminder (a+b)%p = (a%p +b%p)%p 
        for(int &num : nums)
        {
            sum = (sum + num) % p;
        }
        //target is the reminder of (total sum %p) 
        int target = sum % p;

		// if total sum is divisible by p than no need to remove anything return 0
        if(target == 0)
            return 0;
        
		// Declaring the unordered_map to store prev value with index.
        unordered_map<int, int> mp;
        int result = p;
        int curr = 0;
		
        mp[0] = -1;

        for(int j =0; j<n; j++)
        {
			// finding the cummulative sum of given array 
			// and getting remainder of it.
            curr = (curr + nums[j])%p;
			// sum(nums[j-i]) = nums[0...j] - nums[0...i]
			// target = curr - prev
			// prev = target - curr
			// +p is added to avoid negative reminder
            int remain = (curr - target+p)%p;

			
            if(mp.find(remain) !=mp.end())
            {
                result = min(result, j-mp[remain]);
            }
            mp[curr] = j;
        }
        return result == n ? -1:result;
    }
};