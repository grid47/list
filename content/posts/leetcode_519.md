
+++
authors = ["Yasir"]
title = "Leetcode 519: Random Flip Matrix"
date = "2023-05-27"
description = "Solution to Leetcode 519"
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

{{< highlight html >}}
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

