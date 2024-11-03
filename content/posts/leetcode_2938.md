
+++
authors = ["Crafted by Me"]
title = "Leetcode 2938: Separate Black and White Balls"
date = "2016-10-17"
description = "In-depth solution and explanation for Leetcode 2938: Separate Black and White Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/separate-black-and-white-balls/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ++cnt;
            else
                res += cnt;
        }
        return res;        
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2939: Maximum Xor Product](https://grid47.xyz/posts/leetcode_2939) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

