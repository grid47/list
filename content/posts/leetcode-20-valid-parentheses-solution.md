
+++
authors = ["grid47"]
title = "Leetcode 20: Valid Parentheses"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 20: Valid Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-parentheses/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/20.webp" 
    alt="An elegant loop of parentheses, glowing and connected in a balanced, harmonious way."
    caption="Solution to LeetCode 20: Valid Parentheses Problem"
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
    bool isValid(string s) {
        stack<char> stk;
        for(char x: s) {
            if(x == '(' || x == '{' || x == '[') {
                stk.push(x);
            } else {
                     if(x == ')' && !stk.empty() && stk.top() == '(') stk.pop();
                else if(x == '}' && !stk.empty() && stk.top() == '{') stk.pop();
                else if(x == ']' && !stk.empty() && stk.top() == '[') stk.pop();                
                else return false;
            }
        }
        return stk.empty();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/20.md" >}}
---
{{< youtube WTzjTskDFMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #21: Merge Two Sorted Lists](https://grid47.xyz/posts/leetcode-21-merge-two-sorted-lists-solution/) |
| --- |
