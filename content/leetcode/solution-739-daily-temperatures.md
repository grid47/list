
+++
authors = ["grid47"]
title = "Leetcode 739: Daily Temperatures"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 739: Daily Temperatures in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/739.webp"
youtube = "_ZEvmycwXHs"
youtube_upload_date="2024-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/_ZEvmycwXHs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/daily-temperatures/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/739.webp" 
    alt="A series of temperatures with the next warmer day highlighted, glowing softly as it is identified."
    caption="Solution to LeetCode 739: Daily Temperatures Problem"
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
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> stk;
        vector<int> ans(temp.size(), 0);
        for(int i = 0; i < temp.size(); i++) {
            // cout << temp[i] << " " ;
            while(!stk.empty() && temp[i] > stk.top().first) {
                // cout << temp[i] << " " ;
                pair<int, int> x = stk.top();

                // cout << temp[i] << " " ;                
                stk.pop();
                
                // cout << temp[i] << " " << x.first << x.second; 
                ans[x.second] = i-x.second;
                // cout << temp[i] << " " ;
            }
            stk.push(make_pair(temp[i], i));
        }
        
        while(!stk.empty()) {
            auto x = stk.top();
            stk.pop();
            ans[x.second] = 0;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/739.md" >}}
---
{{< youtube _ZEvmycwXHs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #740: Delete and Earn](https://grid47.xyz/leetcode/solution-740-delete-and-earn/) |
| --- |
