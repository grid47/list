
+++
authors = ["grid47"]
title = "Leetcode 529: Minesweeper"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 529: Minesweeper in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/529.webp"
youtube = "zPmuqLKPbE8"
youtube_upload_date="2020-06-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zPmuqLKPbE8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minesweeper/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/529.webp" 
    alt="A glowing grid with mines and safe spots, where the player’s moves are highlighted to avoid mines."
    caption="Solution to LeetCode 529: Minesweeper Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
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
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/529.md" >}}
---
{{< youtube zPmuqLKPbE8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #530: Minimum Absolute Difference in BST](https://grid47.xyz/leetcode/solution-530-minimum-absolute-difference-in-bst/) |
| --- |