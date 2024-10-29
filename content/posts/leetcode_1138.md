
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1138: Alphabet Board Path"
date = "2021-09-18"
description = "Solution to Leetcode 1138"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/alphabet-board-path/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int x = 0, y = 0;
        for(auto ch: target) {
            int x1 = (ch - 'a') %5, y1 = (ch - 'a') / 5;
            res +=  string(max(0, y-y1), 'U') +
                    string(max(0, x1-x), 'R') +
                    string(max(0, x-x1), 'L') +
                    string(max(0, y1-y), 'D') + '!';
            x = x1, y = y1;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

