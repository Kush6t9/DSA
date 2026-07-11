class Solution {
public:
    void NQueens(vector<vector<string>> &board , vector<string> &ans, int ind , int n){
        if(ind==n){ 
            board.push_back(ans);
            return;
        }
        string temp(n,'Q');
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]=='Q'){
                    if(j-ind+i>=0) temp[j-ind+i]='.';
                    if(j+ind-i<n) temp[j+ind-i]='.';
                    temp[j]='.';
                }
            }
        }
        vector<int> temp1;
        for(int i=0;i<n;i++){
            if(temp[i]=='Q'){
                temp1.push_back(i);
            }
        }
        for(int i=0; i<temp1.size(); i++){
            string temp2(n,'.');
            temp2[temp1[i]]='Q';
            ans.push_back(temp2);
            NQueens(board,ans,ind+1,n);
            ans.pop_back();
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        vector<string> ans;
        NQueens(board,ans,0,n);
        return board;
    }
};