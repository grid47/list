
+++
authors = ["Crafted by Me"]
title = "Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool digitCount(string num) {
    int cnt[10] = {};
    for (auto n : num)
        ++cnt[n - '0'];
    for (int i = 0; i < num.size(); ++i)
        if (cnt[i] != num[i] - '0')
            return false;
    return true;
}
};
{{< /highlight >}}


---
{{< youtube kv0O7p0pRvI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2284: Sender With Largest Word Count](https://grid47.xyz/posts/leetcode_2284) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

