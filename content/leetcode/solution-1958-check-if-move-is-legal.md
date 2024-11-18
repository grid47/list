
+++
authors = ["grid47"]
title = "Leetcode 1958: Check if Move is Legal"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1958: Check if Move is Legal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KxK33AcQZpQ"
youtube_upload_date="2021-08-07"
youtube_thumbnail="https://i.ytimg.com/vi/KxK33AcQZpQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/check-if-move-is-legal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char cur) {

        int m = board.size(), n = board[0].size();

        int dir[] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
        
        for(int d = 0; d < 9; d++) {
            for(int x = 1; ; x++) {
                int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
                if(i < 0 || j < 0 || i == 8 || j == 8|| board[i][j] == '.')
                    break;
                if(board[i][j] == cur) {
                    if(x > 1) return true;
                    
                    break;
                }
            }
        }

    
        return false;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1958.md" >}}
---
{{< youtube KxK33AcQZpQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1959: Minimum Total Space Wasted With K Resizing Operations](https://grid47.xyz/leetcode/solution-1959-minimum-total-space-wasted-with-k-resizing-operations/) |
| --- |
