class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9),cols(9),blocks(9);
        
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')
                    continue;
                char element=board[i][j];
                
                if(rows[i].count(element) || cols[j].count(element)
                  || blocks[(i/3)*3+(j/3)].count(element))
                    return false;
                rows[i].insert(element);
                cols[j].insert(element);
                blocks[(i/3)*3+(j/3)].insert(element);
            }
        }
        
        return true;
    }
};