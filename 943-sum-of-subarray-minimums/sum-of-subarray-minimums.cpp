class Solution {
public:
    vector<int> nextsmallestelement(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[i]<=arr[stk.top()]){
                stk.pop();
            }
            if(stk.empty()) ans[i]=n;
            else ans[i]=stk.top();
            stk.push(i);
        }
        return ans;
    }
    vector<int> previossmallestelement(vector<int> arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }
            if(stk.empty()) ans[i]=-1;
            else ans[i]=stk.top();
            stk.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSE,PSEE;
        NSE=nextsmallestelement(arr);
        PSEE=previossmallestelement(arr);
        long long total=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            int nse=NSE[i]-i;
            int psee=i-PSEE[i];
            total=(total + (1LL * nse * psee * arr[i])%mod)%mod;
        }
        return total;
    }
};