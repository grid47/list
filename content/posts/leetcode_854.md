
+++
authors = ["Crafted by Me"]
title = "Leetcode 854: K-Similar Strings"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 854: K-Similar Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Breadth-First Search","Graph"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-similar-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<string> q;
        q.push(s1);
        int level = 0;
        
        unordered_set<string> seen;
        seen.insert(s1);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {

                string node = q.front(); q.pop();

                if(node == s2) return level;
                
                for(auto nbr : next(node, s2))
                    if(seen.find(nbr) == seen.end()) {
                        seen.insert(nbr);
                        q.push(nbr);
                    }

            }
            level++;
        }
        return level;
    }
    
    unordered_set<string> next(string a, string b) {
        int i = 0;
        for(; i < a.size(); i++)
            if(a[i] != b[i]) break;
        
        unordered_set<string> res;
        for(int j = i + 1; j < a.size(); j++)
            if(a[j] == b[i]) {
                swap(a[i], a[j]);
                res.insert(a);
                swap(a[i], a[j]);
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/854.md" >}}
---
{{< youtube GacKZ1-p3-0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #855: Exam Room](https://grid47.xyz/posts/leetcode_855) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

