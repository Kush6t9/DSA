class Solution {
public:
    vector<vector<int>> NextRow(vector<vector<int>> &answer,int ind,int n){
        if(ind==n){
            return answer;
        }
        vector<int> ans;
        ans.emplace_back(1);
        for(int i=1;i<answer[ind-1].size();i++){
            ans.emplace_back(answer[ind-1][i-1] + answer[ind-1][i]);
        }
        ans.emplace_back(1);
        answer.emplace_back(ans);
        return NextRow(answer,ind+1,n);

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1){
            return ans;
        }
        NextRow(ans,1,numRows);
        return ans;
    }
};