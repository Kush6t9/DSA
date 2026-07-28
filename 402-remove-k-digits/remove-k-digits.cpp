class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char> stk;
        for(auto ch:num){
            while(!stk.empty() && k>0 && stk.top()-'0'>ch-'0'){
                k--;
                stk.pop();
            }
            stk.push(ch);
        }
        while(k>0){
            stk.pop();
            k--;
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        return ans.empty()? "0":ans;
    }
};