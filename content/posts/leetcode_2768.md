
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2768: Number of Black Blocks"
date = "2017-04-01"
description = "Solution to Leetcode 2768"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-black-blocks/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> cnt;
        vector<long long> res = {(n - 1L) * (m - 1), 0, 0, 0, 0};
        for (auto& c: coordinates)
            for (int i = c[0]; i < c[0] + 2; ++i)
                for (int j = c[1]; j < c[1] + 2; ++j)
                    if (0 < i && i < m && 0 < j && j < n) {
                        res[cnt[i * 100000L + j]]--;
                        cnt[i * 100000L + j]++;
                        res[cnt[i * 100000L + j]]++;
                    }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

