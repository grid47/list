
+++
authors = ["Crafted by Me"]
title = "Leetcode 2784: Check if Array is Good"
date = "2017-03-20"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

