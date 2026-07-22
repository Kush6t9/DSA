class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='['){
                stk.push(it);
            }
            else{
                if(stk.empty()) return false;
                char ch=stk.top();
                stk.pop();
                if(ch=='(' && it==')' ||
                   ch=='{' && it=='}' ||
                   ch=='[' && it==']')  continue;
                else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};