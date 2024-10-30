
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1600: Throne Inheritance"
date = "2020-06-14"
description = "Solution to Leetcode 1600"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/throne-inheritance/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

