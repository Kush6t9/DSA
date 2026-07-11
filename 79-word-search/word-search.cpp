class Solution {
public:
    bool WordSearch(vector<vector<char>>& board, string word,int ind,int ind1,int ind2){
        if(ind>=word.size()){
            return true;
        }
        if(ind1 < 0 || ind1 >= board.size() || ind2 < 0 || ind2 >= board[0].size() || board[ind1][ind2]!=word[ind]){
            return false;
        }
        char temp=board[ind1][ind2];
        board[ind1][ind2]='#';
        
        bool found= WordSearch(board,word,ind+1,ind1-1,ind2) ||
                    WordSearch(board,word,ind+1,ind1+1,ind2) ||
                    WordSearch(board,word,ind+1,ind1,ind2-1) ||
                    WordSearch(board,word,ind+1,ind1,ind2+1);
        
        board[ind1][ind2]=temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans=true;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(WordSearch(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};