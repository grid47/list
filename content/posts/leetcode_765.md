
+++
authors = ["Crafted by Me"]
title = "Leetcode 765: Couples Holding Hands"
date = "2022-09-29"
description = "Solution to Leetcode 765"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/couples-holding-hands/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0, n = row.size();
        
        vector<int> pos(n, 0);
        vector<int> ptn(n, 0);
        
        for(int i = 0; i < n; i++) {
            pos[row[i]] = i;
            ptn[i] = (i % 2 == 0) ? i + 1 : i - 1;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = ptn[pos[ptn[row[i]]]]; j != i; j = ptn[pos[ptn[row[i]]]]) {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                res++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/765.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

