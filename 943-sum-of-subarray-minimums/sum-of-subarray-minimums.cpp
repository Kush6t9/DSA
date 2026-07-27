class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> stk;
        long long total=0;
        int mod=1e9+7;
        for(int i=0;i<=arr.size();i++){
            while(!stk.empty() && (i==arr.size() || arr[stk.top()]>arr[i])){
                int mid=stk.top();
                stk.pop();
                int l=stk.empty()?-1:stk.top();
                int r=i;
                total=(total + (1LL*(mid-l)*(r-mid)*arr[mid]))%mod;
            }
            stk.push(i);
        }
        return total;
    }
};