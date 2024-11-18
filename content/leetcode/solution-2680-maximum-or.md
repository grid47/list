
+++
authors = ["grid47"]
title = "Leetcode 2680: Maximum OR"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2680: Maximum OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XiaXIrEHFEY"
youtube_upload_date="2023-05-13"
youtube_thumbnail="https://i.ytimg.com/vi/XiaXIrEHFEY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-or/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        //prefix or
        //suffix or
        vector<long long>prefixor;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i == 0) prefixor.push_back((1LL * nums[i]));
            else prefixor.push_back(((1LL*prefixor.back()) | (1LL*nums[i])));
        }    

        vector<long long>suffixor;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i == (nums.size()-1))  suffixor.push_back((1LL * nums[i]));
            else suffixor.push_back(((1LL*suffixor.back()) | (1LL*nums[i])));
        }
        reverse(suffixor.begin(),suffixor.end());

        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        { 
            long long int left = 0;
            long long int self;
            long long int right = 0;
            if((i-1) >= 0)
            {
                left = prefixor[i-1];
            }
            self = (nums[i] * pow(2,k));
            if((i+1) <= nums.size()-1)
            {
                right = suffixor[i+1];
            }
            ans = max(ans , left | self | right);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2680.md" >}}
---
{{< youtube XiaXIrEHFEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2682: Find the Losers of the Circular Game](https://grid47.xyz/leetcode/solution-2682-find-the-losers-of-the-circular-game/) |
| --- |
