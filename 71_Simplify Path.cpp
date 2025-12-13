/*

Leetcode Link : https://leetcode.com/problems/simplify-path/description/

*/

//*******************************************************************************************************
/*

# Intuition
By using stack.

# Approach

Parsing:
stringstream + getline splits the path by '/'.
Empty strings ("") and "."

Stack Logic:
".." pops the last directory (if any).
Other directory names get pushed

Building the Result:
You pop elements into vector<string> temp → directories are stored separately.
Reversing temp → directories are in correct order.
Join with '/' → produces canonical path.
Handles empty stack → returns "/" correctly.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n)
*/


/*****************************************C++**************************************************/
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string st;
        stack<string> s;
        vector<string> ans;

        while (getline(ss, st, '/'))
            ans.push_back(st);
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i]=="..")
            {
                 if(!s.empty())
                    s.pop();
            }
            else if(ans[i] == "." || ans[i]=="")
                continue;
            else
                s.push(ans[i]);
        }
        if(s.empty())
            return "/";

        vector<string> temp;
        while(!s.empty())
        {
            temp.push_back(s.top());
            s.pop();
        }
        reverse(temp.begin(), temp.end());
        string res;
        for(string &dir : temp)
            res+="/"+dir;
        return res;

        
    }
};