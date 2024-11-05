
+++
authors = ["Crafted by Me"]
title = "Leetcode 2730: Find the Longest Semi-Repetitive Substring"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2730: Find the Longest Semi-Repetitive Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        vector<int> sem(10, 0);
        int cnt = 0;
        
        int j = 0, len = 1;        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                sem[s[i] - '0']++;
            }
            while(cnt > 1 && j < i) {
                if(s[j] == s[j + 1]) {
                    sem[s[j] - '0']--;
                    cnt--;
                }
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};
{{< /highlight >}}


---
{{< youtube x_tHB_M7a_g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2731: Movement of Robots](https://grid47.xyz/posts/leetcode_2731) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

