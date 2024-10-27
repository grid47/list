
+++
authors = ["Yasir"]
title = "Leetcode 2784: Check if Array is Good"
date = "2017-03-15"
description = "Solution to Leetcode 2784"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-is-good/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int cnt[201] = {}, n = nums.size() - 1;
        for (auto num : nums)
            ++cnt[num];
        return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; }) && cnt[n] == 2;
    }
};
{{< /highlight >}}

