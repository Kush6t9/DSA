class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                stk.push(asteroids[i]);
            }
            else{
                while(!stk.empty() && stk.top()>0 && stk.top()<-asteroids[i]){
                    stk.pop();
                }
                if(stk.empty() || stk.top()<0) stk.push(asteroids[i]);
                else if(!stk.empty() && stk.top()==-asteroids[i]) stk.pop();
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};