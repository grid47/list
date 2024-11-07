
+++
authors = ["Crafted by Me"]
title = "Leetcode 2013: Detect Squares"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2013: Detect Squares in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/detect-squares/description/)

---
**Code:**

{{< highlight cpp >}}
class DetectSquares {
    int cnt[1001][1001] = {};
    vector<pair<int, int>> pts;
public:
    DetectSquares() {
       // cnt.resize(10001, vector<int>(10001));
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
        pts.emplace_back(point[0], point[1]);
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int ans = 0;
        for(auto [x3, y3] : pts) {
            if(abs(x3 - x1) == 0 || abs(x1 - x3) != abs(y1 - y3))
                continue;
            ans += cnt[x1][y3] * cnt[x3][y1];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2013.md" >}}
---
{{< youtube bahebearrDc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2016: Maximum Difference Between Increasing Elements](https://grid47.xyz/posts/leetcode_2016) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
