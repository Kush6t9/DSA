class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int i=0;
        int j=n-1;
        int leftmax=0;
        int rightmax=0;
        while(i<j){
            int lh=height[i];
            int rh=height[j];
            if(lh<=rh){
                if(lh>=leftmax){
                    leftmax=lh;
                }
                else{
                    ans+=leftmax-lh;
                }
                i++;
            }
            else{
                if(rh>=rightmax){
                    rightmax=rh;
                }
                else{
                    ans+=rightmax-rh;
                }
                j--;
            }
        }
        return ans;
    }
};