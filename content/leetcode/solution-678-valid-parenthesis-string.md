
+++
authors = ["grid47"]
title = "Leetcode 678: Valid Parenthesis String"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 678: Valid Parenthesis String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/678.webp"
youtube = "QhPdNS143Qg"
youtube_upload_date="2022-01-29"
youtube_thumbnail="https://i.ytimg.com/vi/QhPdNS143Qg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/valid-parenthesis-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/678.webp" 
    alt="A string of parentheses being validated, with valid ones glowing softly and invalid ones fading away."
    caption="Solution to LeetCode 678: Valid Parenthesis String Problem"
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
    bool checkValidString(string s) {
        stack<int> stk, str;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*')
                str.push(i);
            else if(s[i] == '(')
                stk.push(i);
            else {
                if(!stk.empty())
                stk.pop();
                else if(!str.empty()) str.pop();
                else return false;
            }
        }
        while(!stk.empty() && !str.empty() && stk.top() < str.top()) {
            str.pop();
            stk.pop();
        }

        return stk.empty();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/678.md" >}}
---
{{< youtube QhPdNS143Qg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #684: Redundant Connection](https://grid47.xyz/leetcode/solution-684-redundant-connection/) |
| --- |