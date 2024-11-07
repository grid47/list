
+++
authors = ["Crafted by Me"]
title = "Leetcode 640: Solve the Equation"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 640: Solve the Equation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/solve-the-equation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string solveEquation(string eqn) {
        int i = 0;
        int para = 0, xpara = 0;
        int flag = 1;
        while(i < eqn.size()) {
            int sgn = 1;
            int tmp = 0;
            if(eqn[i] == '=') {
                flag = -1;
                i++;
            } 
            if(eqn[i] == '-') {
                sgn = -1;
                i++;
            }
            if(eqn[i] == '+') {
                sgn = 1;
                i++;
            }
            if(isdigit(eqn[i])) {
                while(i < eqn.size() && isdigit(eqn[i])) {
                    tmp = tmp * 10 + eqn[i] - '0';
                    i++;
                }
                if(i < eqn.size() && eqn[i] == 'x') {
                    xpara += flag * sgn * tmp;
                    i++;
                }
                else para += flag * sgn * tmp;
            } else {
                xpara += flag * sgn;
                i++;
            }
        }

        string res;
        cout << para << '-'<< xpara;
        if(para == 0 && xpara == 0)
            res = "Infinite solutions";
        else if (xpara == 0)
            res = "No solution";
        else res = "x=" + to_string(para/xpara*-1);

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/640.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #641: Design Circular Deque](https://grid47.xyz/posts/leetcode_641) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
