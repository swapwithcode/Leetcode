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
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();

        for(int i=0; i<n; i++)
        {
            int curr=heights[i];

            for(int j=i-1; j>=0 && heights[i]<=heights[j]; j--)
                curr += heights[i];

            for(int k=i+1; k<n && heights[i]<=heights[k]; k++)
                curr += heights[i];

            res = max(res, curr); 
        }
        return res;
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
    int largestRectangleArea(vector<int>& heights) {
        // Finding Size of the given array.
        int n = heights.size();
        // Declaring the array to store index of next minimum value. storing n as default if next minimum value is not present in array.
        vector<int> NextMin(n,n);
        // Declaring the array to store index of Previous minimum value. storing -1 as default if next minimum value is not present in array.
        vector<int> PrevMin(n,-1);
        // Declaring stack to take record of next an prev values.
        stack<int> sn;
        stack<int> sp;

        // Code to find next smaller for every element
        for(int i = 0; i<n; i++)
        {
            while(!sn.empty() && heights[i]<heights[sn.top()])
            {
                // Setting the index of the next smaller element
                // for the top of the stack
                NextMin[sn.top()] = i;
                sn.pop();
            }
            // Adding currunt value's index in stack.
            sn.push(i);
            
        }
        // code to find previous smaller for every element
        for(int i = 0; i<n; i++)
        {
            while(!sp.empty() && heights[i]<heights[sp.top()])
            {
                // Setting the index of the previous smaller element
                //  for the top of the stack
                sp.pop();
            }
            if(!sp.empty())
            {
                PrevMin[i] = sp.top(); 
            }
            // Adding currunt value's index in stack.
            sp.push(i);
        }
        int Max=0, ans =0;
        for(int i =0;i<n;i++)
        {
        //    cout<<" next= "<<NextMin[i];
        //   cout<<" Prev= "<<PrevMin[i];
        //    cout<<endl;
          int width = NextMin[i]-PrevMin[i]-1;
          ans = width*heights[i];
          Max = max(Max, ans);
        }
        return Max;

    }
};