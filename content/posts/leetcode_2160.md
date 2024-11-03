
+++
authors = ["Crafted by Me"]
title = "Leetcode 2160: Minimum Sum of Four Digit Number After Splitting Digits"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2160: Minimum Sum of Four Digit Number After Splitting Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution{
public:
    int minimumSum(int num){
        string s = to_string(num);
        sort(s.begin(), s.end());
        int res = (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2161: Partition Array According to Given Pivot](https://grid47.xyz/posts/leetcode_2161) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

