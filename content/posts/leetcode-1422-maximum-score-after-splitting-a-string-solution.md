
+++
authors = ["grid47"]
title = "Leetcode 1422: Maximum Score After Splitting a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1422: Maximum Score After Splitting a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScore(string s) {
        int rightOnes = 0, leftZeroes = 0;
        for(char c: s)
            if(c=='1') rightOnes++;
        
        int score = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]=='0') leftZeroes++;
            else rightOnes--;
            score = max(score, leftZeroes + rightOnes);
        }
        return score;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1422.md" >}}
---
{{< youtube mc_eSStDrWw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1423: Maximum Points You Can Obtain from Cards](https://grid47.xyz/posts/leetcode-1423-maximum-points-you-can-obtain-from-cards-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}