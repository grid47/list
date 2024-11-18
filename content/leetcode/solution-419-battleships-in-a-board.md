
+++
authors = ["grid47"]
title = "Leetcode 419: Battleships in a Board"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 419: Battleships in a Board in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/419.webp"
youtube = "gKhvVHd8ihI"
youtube_upload_date="2020-07-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gKhvVHd8ihI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/battleships-in-a-board/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/419.webp" 
    alt="A board game where ships glow softly as they are placed on the grid, each ship highlighted as it is positioned."
    caption="Solution to LeetCode 419: Battleships in a Board Problem"
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
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return 0;
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
 cnt += (board[i][j] == 'X') && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'); 

        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/419.md" >}}
---
{{< youtube gKhvVHd8ihI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #421: Maximum XOR of Two Numbers in an Array](https://grid47.xyz/leetcode/solution-421-maximum-xor-of-two-numbers-in-an-array/) |
| --- |
