class Solution {
public:
    int Atmost(vector<int> nums,int goal){
        if (goal<0) return 0;
        int i=0;
        int sum=0;
        int cnt=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            cnt+=j-i+1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return Atmost(nums,goal) - Atmost(nums,goal-1);
    }
};