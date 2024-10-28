class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int row = click[0], col = click[1];
        if(board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            int cnt = 0;
            for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) continue;
                int x = row + i, y = col + j;
                if(x < 0 || y < 0 || x >= m || y >= n)    continue;
                if(board[x][y] == 'M' || board[x][y] == 'X') cnt++;
            }
            if (cnt > 0) board[row][col] = '0' + cnt;
            else {
                board[row][col] = 'B';
                for(int i = -1; i <= 1; i++)
                for(int j = -1; j <= 1; j++) {
                    if(i == 0 && j == 0) continue;
                    int x = row + i, y = col + j;
                    if(x < 0 || y < 0 || x >= m || y >= n)    continue;
                    vector<int> arr;
                    arr.push_back(x);
                    arr.push_back(y);

                    if(board[x][y] == 'E') updateBoard(board, arr);
                }
            }
        }
        return board;
    }
};