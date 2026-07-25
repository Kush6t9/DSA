class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int ,int> hashmap;
        int n2=nums2.size();
        vector<int> ans;
        stack<int> stk;
        for(int i=n2-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=nums2[i]){
                stk.pop();
            }
            if(!stk.empty()) hashmap[nums2[i]]=stk.top();
            else hashmap[nums2[i]]=-1;
            stk.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(hashmap[nums1[i]]);
        }
        return ans;
    }
};