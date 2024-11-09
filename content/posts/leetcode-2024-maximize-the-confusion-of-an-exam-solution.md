
+++
authors = ["grid47"]
title = "Leetcode 2024: Maximize the Confusion of an Exam"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2024: Maximize the Confusion of an Exam in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Binary Search","Sliding Window","Prefix Sum"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2024.md" >}}
---
{{< youtube XYJv2pySK44 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2027: Minimum Moves to Convert String](https://grid47.xyz/posts/leetcode-2027-minimum-moves-to-convert-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
