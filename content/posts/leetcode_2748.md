
+++
authors = ["Crafted by Me"]
title = "Leetcode 2748: Number of Beautiful Pairs"
date = "2016-04-24"
description = "Solution to Leetcode 2748"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-beautiful-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
int countBeautifulPairs(vector<int>& nums) {
    int cnt[10] = {}, res = 0;
    for(int i = 0; i < nums.size(); ++i) {
        for (int n = 1; n < 10; ++n)
            if (gcd(n, nums[i] % 10) == 1)
                res += cnt[n];
        while (nums[i] >= 10)
            nums[i] /= 10;
        ++cnt[nums[i]];
    }
    return res;
}
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

