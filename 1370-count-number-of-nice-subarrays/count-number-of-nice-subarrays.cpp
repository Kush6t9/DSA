class Solution {
public:
    int Atmost(vector<int> nums,int k){
        int i=0;
        int cnt=0;
        int x=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2!=0){
                x++;
            }
            while(x>k){
                if(nums[i]%2!=0) x--;
                i++;
            }
            cnt+=j-i+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return Atmost(nums,k) - Atmost(nums,k-1);
    }
};