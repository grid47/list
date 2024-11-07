
+++
authors = ["Crafted by Me"]
title = "Leetcode 1093: Statistics from a Large Sample"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1093: Statistics from a Large Sample in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/statistics-from-a-large-sample/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    double getKth(vector<int> &cnt, int k) {
        int x = 0;
        for(int i = 0; i < 256; i++) {
            x += cnt[i];
            if(x >= k) return i;
        }
        return 256;
    }
    
    vector<double> sampleStats(vector<int>& cnt) {
        double mn = 257, mx = -1, sum = 0, mode, frq = 0, median;
        int x = 0;
        for(int i = 0; i < 256; i++) {
            if(cnt[i] > 0) {
                mn = min(mn, (double)i);
                mx = i;
                sum += (double)cnt[i] * i;
                if(frq < cnt[i]) {
                    frq = cnt[i];
                    mode = i;
                }
                x += cnt[i];                 
            }
        }

        if(x % 2 == 0) {
            double a = getKth(cnt, x / 2);
            double b = getKth(cnt, x / 2 + 1);
            median = (a + b) / 2;
        } else median = getKth(cnt, x/ 2 + 1);
        
        return vector<double> {mn, mx, sum / x, median, mode };
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1093.md" >}}
---
{{< youtube 05WQZvhYcAg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1095: Find in Mountain Array](https://grid47.xyz/posts/leetcode_1095) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
