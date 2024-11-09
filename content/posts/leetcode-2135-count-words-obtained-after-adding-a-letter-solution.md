
+++
authors = ["grid47"]
title = "Leetcode 2135: Count Words Obtained After Adding a Letter"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2135: Count Words Obtained After Adding a Letter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& end) {
        set<int> bit;
        for(auto it: start) {
            int mask = 0;
            for(char x: it)
                mask |= 1 << (x - 'a');
            bit.insert(mask);
        }
        
        int cnt = 0;
        
        for(auto it: end) {
            int mask = 0;
            for(char x: it)
                mask |= 1 << (x - 'a');
            
            for(int i = 0; i < 26; i++) {
                if(((mask >> i) & 1) == 0) continue;
                int tmp = (mask ^ (1 << i));
                if(bit.count(tmp)) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2135.md" >}}
---
{{< youtube Ag3bur1amBs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2138: Divide a String Into Groups of Size k](https://grid47.xyz/posts/leetcode-2135-count-words-obtained-after-adding-a-letter-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
