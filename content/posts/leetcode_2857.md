
+++
authors = ["Yasir"]
title = "Leetcode 2857: Count Pairs of Points With Distance k"
date = "2017-01-01"
description = "Solution to Leetcode 2857"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-pairs-of-points-with-distance-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int, int>> count;
        int res = 0;
        for (auto& c : coordinates) {
            for (int x = 0; x <= k; x++)
                if (count[c[0] ^ x].count(c[1] ^ (k - x)))
                    res += count[c[0] ^ x][c[1] ^ (k - x)];
            count[c[0]][c[1]]++;
        }
        return res;
    }
};
{{< /highlight >}}

