class Solution {
public:
    int Atmost(vector<int>& nums, int k){
        unordered_map<int,int> hash;
        int i=0;
        int cnt=0;
        int x=0;
        for(int j=0;j<nums.size();j++){
            if(hash[nums[j]]==0){
                x++;
            }
            hash[nums[j]]++;
            while(x>k){
                if(hash[nums[i]]==1){
                    x--;
                }
                hash[nums[i]]--;
                i++;
            }
            cnt+=j-i+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Atmost(nums,k) - Atmost(nums,k-1);
    }
};