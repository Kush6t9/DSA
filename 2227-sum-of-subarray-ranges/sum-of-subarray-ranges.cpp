class Solution {
public:
    long long smallest(vector<int> &nums){
        stack<int> stk;
        long long ans=0;
        for(int i=0;i<=nums.size();i++){
            while(!stk.empty() && (i==nums.size() || nums[stk.top()]>nums[i])){
                int mid=stk.top();
                stk.pop();
                int l=stk.empty()? -1 : stk.top();
                int r=i;
                ans+=(mid-l)*(r-mid)*1LL*(nums[mid]);
            }
            stk.push(i);
        }
        return ans;
    }
    long long largest(vector<int> &nums){
        stack<int> stk;
        long long ans=0;
        for(int i=0;i<=nums.size();i++){
            while(!stk.empty() && (i==nums.size() || nums[stk.top()]<nums[i])){
                int mid=stk.top();
                stk.pop();
                int l=stk.empty()? -1:stk.top();
                int r=i;
                ans+=(mid-l)*(r-mid)*1LL*(nums[mid]);
            }
            stk.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return largest(nums)-smallest(nums);
    }   
};