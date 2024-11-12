
+++
authors = ["grid47"]
title = "Leetcode 3121: Count the Number of Special Characters II"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3121: Count the Number of Special Characters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> ch(26, 0);
        for(char x: word) {
            if(isupper(x)) {
                if(ch[x - 'A'] == -1) continue;
                if(ch[x - 'A'] != 1 && ch[x - 'A'] != 2)  {
                  ch[x - 'A'] = -1;
                    continue;  
                }
                ch[x - 'A'] = 2;
            } else {
                if(ch[x - 'a'] == -1) continue;                
                if(ch[x - 'a'] == 2) {
                  ch[x - 'a'] = -1;
                    continue;  
                } 
                ch[x - 'a'] = 1;
            }
            // cout << x << " ";
            // for(int i = 0; i < 26; i++) {
            //     cout << ch[i] << " ";
            // }
            // cout << "\n";
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            // cout << ch[i] << " ";
            if(ch[i] == 2)
                cnt++;
        }
        return cnt;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3121.md" >}}
---
{{< youtube aIR3Iem0jQM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3122: Minimum Number of Operations to Satisfy Conditions](https://grid47.xyz/posts/leetcode-3122-minimum-number-of-operations-to-satisfy-conditions-solution/) |
| --- |
