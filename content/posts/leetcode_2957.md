
+++
authors = ["Crafted by Me"]
title = "Leetcode 2957: Remove Adjacent Almost-Equal Characters"
date = "2016-09-28"
description = "In-depth solution and explanation for Leetcode 2957: Remove Adjacent Almost-Equal Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        int i = 1, cnt = 0;
        while(i < n) {
            if(s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) cnt++, i += 2;
            else i++;
        }
        return cnt;        
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2958: Length of Longest Subarray With at Most K Frequency](https://grid47.xyz/posts/leetcode_2958) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

