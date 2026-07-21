class Solution {
public:
    void Addoperators(string num, vector<string> &answer, string ans , int ind, int n, long long value,long long prev,int target){
        if(ind>=n){
            if(value==target) answer.push_back(ans);
            return;
            
        }
        long long curr=0;
        for(int i=ind;i<num.size();i++){
            if(i>ind && num[ind]=='0') break;
            curr=curr*10 + (num[i]-'0');
            string str= num.substr(ind,i-ind+1);
            if(ind==0){
                Addoperators(num,answer,str,i+1,n,curr,curr,target);
            }
            else{
                Addoperators(num,answer,ans+'+'+str,i+1,n,value+curr,curr,target);
                Addoperators(num,answer,ans+'-'+str,i+1,n,value-curr,-curr,target);
                Addoperators(num,answer,ans+'*'+str,i+1,n,value-prev+prev*curr,curr*prev,target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        int n=num.size();
        Addoperators(num,answer,"",0,n,0,0,target);
        return answer;
    }
};