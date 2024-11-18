
+++
authors = ["grid47"]
title = "Leetcode 2434: Using a Robot to Print the Lexicographically Smallest String"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2434: Using a Robot to Print the Lexicographically Smallest String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-8gRuQFSuX8"
youtube_upload_date="2022-10-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-8gRuQFSuX8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    char low(vector<int> &frq) {
        for(int i = 0; i < 26; i++)
            if(frq[i] != 0) return 'a'+i;
        return 'z';
    }
    
    string robotWithString(string s) {
        
        vector<int> frq(26, 0);
        for(char c: s)
            frq[c - 'a']++;
        
        stack<int> t;
        string ans = "";
        
        for(char c : s) {
            t.push(c);
            frq[c - 'a']--;
            while(!t.empty() && t.top() <= low(frq)) {
                ans += t.top();
                t.pop();
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2434.md" >}}
---
{{< youtube -8gRuQFSuX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2437: Number of Valid Clock Times](https://grid47.xyz/leetcode/solution-2437-number-of-valid-clock-times/) |
| --- |
