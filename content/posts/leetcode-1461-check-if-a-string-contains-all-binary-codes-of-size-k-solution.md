
+++
authors = ["grid47"]
title = "Leetcode 1461: Check If a String Contains All Binary Codes of Size K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1461: Check If a String Contains All Binary Codes of Size K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Rolling Hash","Hash Function"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.size();
        set<int> cnt;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            if(i < k) {
                tmp = tmp * 2 + (s[i] == '0'? 0: 1);
                continue;
            }
            cnt.insert(tmp);
            tmp *= 2;
            tmp &= ((1 << k) - 1);            
            tmp += (s[i] == '0'? 0: 1);
        }
        cnt.insert(tmp);
        // cout << cnt.size() << " " << (1 << k);
        return cnt.size() == (1 << k);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1461.md" >}}
---
{{< youtube qU32rTy_kOM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1462: Course Schedule IV](https://grid47.xyz/posts/leetcode-1462-course-schedule-iv-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}