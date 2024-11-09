
+++
authors = ["grid47"]
title = "Leetcode 2490: Circular Sentence"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2490: Circular Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-sentence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCircularSentence(string s) {
        
        int n = s.size();
        if((s[0]) != (s[n - 1]))
            return false;
        for(int i = 1; i < s.size() - 1; i++) {
            if(s[i] == ' ') {
                if((s[i - 1]) != (s[i + 1]))
                    return false;                
            }
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2490.md" >}}
---
{{< youtube 9Ty_eRjoDNM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2491: Divide Players Into Teams of Equal Skill](https://grid47.xyz/posts/leetcode-2491-divide-players-into-teams-of-equal-skill-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
