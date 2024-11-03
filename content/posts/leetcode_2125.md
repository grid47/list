
+++
authors = ["Crafted by Me"]
title = "Leetcode 2125: Number of Laser Beams in a Bank"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2125: Number of Laser Beams in a Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    public:
    int numberOfBeams(vector<string> bank) {

        int res = 0, m = bank.size(), n = bank[0].size();

        int cnt = 0, prv = 0;
        for (auto b : bank) 
        {
            cnt = 0;
            for(int i = 0; i < n; i++)
                if (b[i] == '1') cnt++;
            if(cnt > 0) {
                res += prv * cnt;
                prv = cnt;
            }
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube KLeKv59LAFY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2126: Destroying Asteroids](https://grid47.xyz/posts/leetcode_2126) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

