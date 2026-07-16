class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        unordered_map<char,int> hash;
        int cnt=0;
        while(j<s.size()){
            if(hash.find(s[j])!=hash.end()){
                i = max(i, hash[s[j]] + 1);
            }
            hash[s[j]]=j;
            cnt=max(cnt,j-i+1);
            j++;
        }
        return cnt;
    }
};