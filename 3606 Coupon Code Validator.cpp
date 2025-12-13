class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string> gr;
        vector<string> el;
        vector<string> ph;
        vector<string> re;
        vector<string> ans;
        int n = code.size();

        for(int i=0; i<n; i++)
        {
            if(code[i].size()==0)
                continue;
            
            int flag = 0;
            for(int j=0; j<code[i].size(); j++)
            {
                if((code[i][j]>='0' && code[i][j]<='9') || (code[i][j]>='a' && code[i][j]<='z') || (code[i][j]>='A' && code[i][j]<='Z') || (code[i][j]=='_'))
                {
                    continue;
                }
                else
                {
                    flag =1;
                    break;
                }
            }
            if(flag == 0)
            {
                if(isActive[i])
                {
                    if(businessLine[i][0] == 'r')
                        re.push_back(code[i]);
                    else if(businessLine[i][0] == 'p')
                        ph.push_back(code[i]);
                    else if(businessLine[i][0] == 'g')
                        gr.push_back(code[i]);
                    else if(businessLine[i][0] == 'e')
                        el.push_back(code[i]);  
                }

            }
        }
        sort(re.begin(), re.end());
        sort(ph.begin(), ph.end());
        sort(gr.begin(), gr.end());
        sort(el.begin(), el.end());

        for(int i=0; i<el.size(); i++)
            ans.push_back(el[i]);
        for(int i=0; i<gr.size(); i++)
            ans.push_back(gr[i]);
        for(int i=0; i<ph.size(); i++)
            ans.push_back(ph[i]);
        for(int i=0; i<re.size(); i++)
            ans.push_back(re[i]);

        
        

        return ans;
        
    }
};