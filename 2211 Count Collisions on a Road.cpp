/*

Leetcode Link : https://leetcode.com/problems/count-collisions-on-a-road/description/

*/

/*****************************************C++**************************************************/
/*
    Approach: using simple for loops: Counting
    TC : O(n) 
    SC : O(1)
	
	Intuition :
	We define a vehicle that continuously moves outward (either left or right) without being blocked by a reversing or stationary vehicle in between as an "outward-moving vehicle."

	Left-moving outward vehicles and right-moving outward vehicles will not collide with each other. All other vehicles will collide exactly once.
*/

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        int l = 0, r = n-1;
		
		// Finding the last car position which going to left without any collision
        while(l<n && directions[l] == 'L')
            l++;

		// Finding the last car position which going to right without any collision
        while(r>=0 && directions[r] == 'R')
            r--;
	
		//Other Each moving car having 1 collion
        int res=0;
        for(int i=l; i<=r; i++)
        {
            if(directions[i]!='S')
                res++;
        }
        return res;
    
    }
};