bool exist(char** board, int boardSize, int* boardColSize, char* word) {
        int len = strlen(word);

    bool search(int row, int col, int index) {
        if (index == len) return true;
        if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize[row]) return false;
        if (board[row][col] != word[index]) return false;

        char temp = board[row][col];
        board[row][col] = '#'; 

        bool found =
            search(row + 1, col, index + 1) ||
            search(row - 1, col, index + 1) ||
            search(row, col + 1, index + 1) ||
            search(row, col - 1, index + 1);

        board[row][col] = temp; // Backtrack
        return found;
    }

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; ++j) {


            bool found = false;


            bool dfs(int r, int c, int index) {
                if (index == len) return true;
                if (r < 0 || c < 0 || r >= boardSize || c >= boardColSize[r]) return false;
                if (board[r][c] != word[index]) return false;

                char temp = board[r][c];
                board[r][c] = '#';

                bool res = dfs(r + 1, c, index + 1) ||
                           dfs(r - 1, c, index + 1) ||
                           dfs(r, c + 1, index + 1) ||
                           dfs(r, c - 1, index + 1);

                board[r][c] = temp;
                return res;
            }
            if (dfs(i, j, 0)) return true;
        }
    }

    return false;

}
