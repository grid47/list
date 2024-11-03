
+++
authors = ["Crafted by Me"]
title = "Leetcode 2380: Time Needed to Rearrange a Binary String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2380: Time Needed to Rearrange a Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0;
        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < s.size() - 1; i++) {
                if(s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    changed = true;
                    i++;
                }
            }
            seconds += changed;
        }
        return seconds;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2381: Shifting Letters II](https://grid47.xyz/posts/leetcode_2381) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

