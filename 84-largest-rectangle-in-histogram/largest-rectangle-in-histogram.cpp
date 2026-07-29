class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> stk;
        for(int i=0; i<=heights.size();i++){
            while(!stk.empty() && (i==heights.size() || heights[stk.top()]>heights[i])){
                int mid=stk.top();
                stk.pop();
                int l=stk.empty()? -1:stk.top();
                int r=i;
                int area=(r-l-1)*(heights[mid]);
                ans=max(ans,area);
            }
            stk.push(i);
        }
        return ans;
    }
};