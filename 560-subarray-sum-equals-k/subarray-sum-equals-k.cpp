class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int sum=0;
        map <int,int> hash;
        hash[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(hash.find(sum-k)!=hash.end()){
                cnt+=hash[sum-k];
            }
            hash[sum]++;
        }
        return cnt;
    }
};