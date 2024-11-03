
+++
authors = ["Crafted by Me"]
title = "Leetcode 519: Random Flip Matrix"
date = "2023-06-02"
description = "In-depth solution and explanation for Leetcode 519: Random Flip Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/random-flip-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    map<int, int> mp;
    int row, col, lmt;
public:
    Solution(int m, int n) {
        row = m;
        col = n;
        reset();
    }
    
    vector<int> flip() {
        int idx = rand()%lmt;
        lmt--;
        int x = mp.count(idx)? mp[idx] : idx;
        mp[idx] = mp.count(lmt)? mp[lmt]: lmt;
        return vector<int>{x/col, x%col};
    }
    
    void reset() {
        mp.clear();
        lmt = row*col;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/519.md" >}}
---


"| 520: Detect Capital |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

