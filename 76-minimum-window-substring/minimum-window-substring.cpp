class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> shash;
        unordered_map<char,int> thash;
        for(int i=0;i<t.size();i++){
            thash[t[i]]++;
        } 
        int required=thash.size();
        int formed=0;
        int left=0;
        int start=0;
        int len=INT_MAX;
        for(int right=0;right<s.size();right++){
            shash[s[right]]++;
            if(thash.find(s[right])!=thash.end() && shash[s[right]]==thash[s[right]]){
                formed++;
            }
            while(formed==required){
                if(right-left+1<len){
                    len=right-left+1;
                    start=left;
                }
                shash[s[left]]--;
                if(thash.find(s[left])!=thash.end() && shash[s[left]]<thash[s[left]]){
                    formed--;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len); 
    }
};