
+++
authors = ["grid47"]
title = "Leetcode 1718: Construct the Lexicographically Largest Valid Sequence"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1718: Construct the Lexicographically Largest Valid Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3kRBmhoA9b8"
youtube_upload_date="2021-01-09"
youtube_thumbnail="https://i.ytimg.com/vi/3kRBmhoA9b8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> constructDistancedSequence(int n) {
        this-> n = n;
        vector<int> ans(2 * n - 1, 0);
        
        vector<int> vis(n + 1, 0);
        
        bt(ans, vis, 0);
        
        return ans;
        
    }
    
    bool bt(vector<int> &ans, vector<int> &vis, int idx) {
        
        if(idx == ans.size()) return true;
        
        if(ans[idx] != 0) return bt(ans, vis, idx + 1);
        else {

            for(int i = n; i >= 1; i--) {

                if(vis[i]) continue;
                
                vis[i] = 1;
                ans[idx] = i;
                
                if(i == 1) {
                    if(bt(ans, vis, idx + 1)) return true;
                } else if (idx + i < ans.size() && ans[idx + i] == 0) {
                    ans[idx + i] = i;
                    if(bt(ans, vis, idx + 1)) return true;
                    ans[idx + i] = 0;                    
                }
                ans[idx] = 0;
                vis[i] = 0;
                
            }

        }
        return false;
        
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1718.md" >}}
---
{{< youtube 3kRBmhoA9b8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1720: Decode XORed Array](https://grid47.xyz/leetcode/solution-1720-decode-xored-array/) |
| --- |