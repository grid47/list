
+++
authors = ["grid47"]
title = "Leetcode 2131: Longest Palindrome by Concatenating Two Letter Words"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2131: Longest Palindrome by Concatenating Two Letter Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kBMf-m5we-8"
youtube_upload_date="2022-01-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kBMf-m5we-8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int unpaired = 0;
        unordered_map<string, int> mp;

        for(string w: words) {
            if(w[0] == w[1]) {
                if(mp[w] > 0) {
                    unpaired--;
                    ans += 4;
                    mp[w]--;
                } else {
                    unpaired++;
                    mp[w]++;
                }
            } else {
                string rev = w;
                reverse(rev.begin(), rev.end());
                if(mp[rev] > 0) {
                    ans += 4;
                    mp[rev]--;
                } else mp[w]++;
            }
        }


        if (unpaired > 0) ans += 2;
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2131.md" >}}
---
{{< youtube kBMf-m5we-8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2133: Check if Every Row and Column Contains All Numbers](https://grid47.xyz/leetcode/solution-2133-check-if-every-row-and-column-contains-all-numbers/) |
| --- |
