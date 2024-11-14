
+++
authors = ["grid47"]
title = "Leetcode 722: Remove Comments"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 722: Remove Comments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-comments/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/722.webp" 
    alt="A source code where comments are removed, with the comments fading out and the code glowing softly."
    caption="Solution to LeetCode 722: Remove Comments Problem"
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
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool is_mul = false;
        string res = "";
        for(int i = 0; i < source.size(); i++) {
            string str = source[i];
            res = is_mul? res:"";
            for(int j = 0; j < str.size() ; j++) {
                if(!is_mul) {
                    if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '/') {
                        break;
                    } else if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '*') {
                        is_mul = true;
                        j++;
                    } else {
                        res += str[j];
                    }
                } else {
                    if(j < str.size() - 1 && str[j] == '*' && str[j + 1] == '/') {
                        is_mul = false;
                        j++;
                    }
                }
            }

            if(!is_mul && res != "") ans.push_back(res);
        }
        return ans;
    }
};

//
/*
*/
/* */
// */ --- //
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/722.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #724: Find Pivot Index](https://grid47.xyz/posts/leetcode-724-find-pivot-index-solution/) |
| --- |
