
+++
authors = ["grid47"]
title = "Leetcode 1600: Throne Inheritance"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1600: Throne Inheritance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/throne-inheritance/description/)

---
**Code:**

{{< highlight cpp >}}
class ThroneInheritance {
    unordered_map<string, bool> dead;   // Just to keep track of alive people
    unordered_map<string, vector<string>> family;  
    string root;
public:
    ThroneInheritance(string kingName) {
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);    // Appending at the end takes care of oldest to yongest 
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    void dfs(vector<string> &ans, string root) {
        if (!dead[root]) {           // Just check if dead before inserting into the order.
            ans.push_back(root);
        }
        for (string child: family[root]) {
            dfs(ans, child);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, root);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1600.md" >}}
---
{{< youtube VId-YNg9IG0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1601: Maximum Number of Achievable Transfer Requests](https://grid47.xyz/posts/leetcode-1601-maximum-number-of-achievable-transfer-requests-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}