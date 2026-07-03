class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
          // Get number of rows
        int rows = board.size();
        // Get number of columns
        int cols = board[0].size();

        // Loop through every cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start DFS if first letter matches
                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        // If no path found, return false
        return false;
     
    }
    bool solve(vector<vector<char>>&board,string word,int i,int j,int ind){
        if(ind == word.size())
    return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[ind]){
            return false;
        }
        char temp=board[i][j];
          board[i][j] = '#';

        // Explore all four directions
        bool found = solve(board, word, i + 1, j, ind + 1) ||
                   solve(board, word, i - 1, j, ind + 1) ||
                     solve(board, word, i, j + 1, ind + 1) ||
                     solve(board, word, i, j - 1, ind + 1);

        // Restore the character (backtracking)
        board[i][j] = temp;

        return found;
    }
};