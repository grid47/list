
+++
authors = ["Crafted by Me"]
title = "Leetcode 2024: Maximize the Confusion of an Exam"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2024: Maximize the Confusion of an Exam in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int ans = 1;
        int fidx = 0, tidx = 0, fcnt = 0, tcnt = 0;
        for(int i = 0; i < key.size(); i++) {
            if(key[i] == 'F') fcnt++;
            else tcnt++;
            while(fcnt > k) {
                if(key[tidx] == 'F') fcnt--;
                tidx++;
            }
            ans = max(ans, i - tidx + 1);
            while(tcnt > k) {
                if(key[fidx] == 'T') tcnt--;
                fidx++;
            }
            ans = max(ans, i - fidx + 1);            
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube XYJv2pySK44 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2025: Maximum Number of Ways to Partition an Array](https://grid47.xyz/posts/leetcode_2025) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

