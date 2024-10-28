
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1625: Lexicographically Smallest String After Applying Operations"
date = "2020-05-18"
description = "Solution to Leetcode 1625"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

