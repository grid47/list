
+++
authors = ["grid47"]
title = "Leetcode 131: Palindrome Partitioning"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 131: Palindrome Partitioning in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/131.webp"
youtube = "7GlqVABgjJU"
youtube_upload_date="2020-11-23"
youtube_thumbnail="https://i.ytimg.com/vi/7GlqVABgjJU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/palindrome-partitioning/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/131.webp" 
    alt="A string being gently split into palindrome segments, with each partition glowing softly."
    caption="Solution to LeetCode 131: Palindrome Partitioning Problem"
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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        bt(ans, tmp, s, 0);
        return ans;
    }
    
    void bt(vector<vector<string>> &ans, vector<string> &tmp, string s, int idx) {
        if(idx == s.size()) {
            ans.push_back(tmp);
            return;
        }
        
        for(int i = idx; i < s.size(); i++) {
            if(isPal(s, idx, i)) {
              
                tmp.push_back(s.substr(idx, i - idx + 1));
                bt(ans, tmp, s, i + 1);
                tmp.pop_back();
            }
        }
    }
    
    bool isPal(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/131.md" >}}
---
{{< youtube 7GlqVABgjJU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #133: Clone Graph](https://grid47.xyz/leetcode/solution-133-clone-graph/) |
| --- |