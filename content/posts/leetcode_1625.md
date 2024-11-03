
+++
authors = ["Crafted by Me"]
title = "Leetcode 1625: Lexicographically Smallest String After Applying Operations"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1625: Lexicographically Smallest String After Applying Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {

    string ans;
    int a, b;
    int n;
    unordered_set<string> seen;

    bool isVisited(string s) {
        return seen.find(s) != seen.end();
    }

    void visit(string s) {
        ans = min(ans, s);
        seen.insert(s);
    }    

    string rotate(string s, int x) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+x);
        reverse(s.begin()+x, s.end());
        return s;
    }

     string add(string s, int x) {
        for (int i=1; i<n; i += 2) {
            char &c = s[i];
            c = '0' + (c-'0'+x)%10;
        }
        return s;
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        ans = s;
        this->a = a;
        this->b = b;
        n = s.size();
        dfs(s);
        return ans;
    }
    void dfs(string s){
        if(isVisited(s)) return;
        visit(s);
        dfs(rotate(s, b));
        dfs(add(s, a));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1625.md" >}}
---
{{< youtube S_WnsW5cdgI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1626: Best Team With No Conflicts](https://grid47.xyz/posts/leetcode_1626) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

