
+++
authors = ["Crafted by Me"]
title = "Leetcode 1138: Alphabet Board Path"
date = "2020-09-20"
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


---
{{< youtube rk-aB4rEOyU >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

