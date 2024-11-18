
+++
authors = ["grid47"]
title = "Leetcode 1625: Lexicographically Smallest String After Applying Operations"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1625: Lexicographically Smallest String After Applying Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Depth-First Search","Breadth-First Search","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "S_WnsW5cdgI"
youtube_upload_date="2020-10-18"
youtube_thumbnail="https://i.ytimg.com/vi/S_WnsW5cdgI/maxresdefault.jpg"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1626: Best Team With No Conflicts](https://grid47.xyz/leetcode/solution-1626-best-team-with-no-conflicts/) |
| --- |
