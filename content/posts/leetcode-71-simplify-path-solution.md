
+++
authors = ["grid47"]
title = "Leetcode 71: Simplify Path"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 71: Simplify Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/simplify-path/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/71.jpeg" 
    alt="A smooth, glowing path being simplified, with unnecessary elements fading away."
    caption="Solution to LeetCode 71: Simplify Path Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string simplifyPath(string path) {
        
        set<string> dot = {"..", ".", ""};
        
        string res = "", tmp;
        stringstream ss(path);
        
        stack<string> stk;
        
        while(getline(ss, tmp, '/')) {
            if(tmp == ".." && !stk.empty()) stk.pop();
            else if (!dot.count(tmp)) stk.push(tmp);
        }

        while(!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res == ""? "/": res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/71.md" >}}
---
{{< youtube 4e1gVeQ0AEs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #72: Edit Distance](https://grid47.xyz/posts/leetcode-72-edit-distance-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}