class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> hash;
        hash['a']=0;
        hash['b']=0;
        hash['c']=0;
        int i=0;
        int cnt=0;
        int n=s.size();
        for(int j=0;j<n;j++){
            hash[s[j]]++;
            while(hash['a']>0 && hash['b']>0 && hash['c']>0){
                cnt+=n-j;
                hash[s[i]]--;
                i++;
            }
        }
        return cnt;
    }
};