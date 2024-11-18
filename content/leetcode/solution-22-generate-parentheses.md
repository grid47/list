
+++
authors = ["grid47"]
title = "Leetcode 22: Generate Parentheses"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 22: Generate Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/22.webp"
youtube = "7aSAbqCWhwE"
youtube_upload_date="2024-03-11"
youtube_thumbnail="https://i.ytimg.com/vi/7aSAbqCWhwE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/generate-parentheses/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/22.webp" 
    alt="A swirl of parentheses gently unfolding, forming balanced pairs that radiate a sense of calm."
    caption="Solution to LeetCode 22: Generate Parentheses Problem"
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
    
    void gen(string op, vector<string> &ans, int open, int closed, int n, int i) {
        if(i== 2*n) {
            ans.push_back(op);
            return;
        }
        
        if(open < n) {
            gen(op + "(", ans, open + 1, closed,n, i + 1);
        }
        if(open > closed) {
            gen(op + ")", ans, open, closed + 1,n, i + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen("", ans, 0, 0, n, 0);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/22.md" >}}
---
{{< youtube 7aSAbqCWhwE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #24: Swap Nodes in Pairs](https://grid47.xyz/leetcode/solution-24-swap-nodes-in-pairs/) |
| --- |
