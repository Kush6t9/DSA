class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,x=0;
        int cnt=0;
        while(j<nums.size()){
            if(nums[j]==0 && x==k){
                while(nums[i]!=0){
                    i++;
                }
                i++;
            }
            else if(nums[j]==0){
                x++;
            }
            cnt=max(cnt,j-i+1);
            j++;
        }
        return cnt;
    }
};