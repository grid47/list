
+++
authors = ["grid47"]
title = "Leetcode 423: Reconstruct Original Digits from English"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 423: Reconstruct Original Digits from English in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "cGgG0A__wNQ"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/423.webp"
+++



[`Problem Link`](https://leetcode.com/problems/reconstruct-original-digits-from-english/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/423.webp" 
    alt="A sequence of English words forming digits, with each word gently transforming into its corresponding digit."
    caption="Solution to LeetCode 423: Reconstruct Original Digits from English Problem"
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
    string originalDigits(string s) {
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> counts(26, 0);
        string result;
        for(auto ch : s){ counts[ch-'a']++;}
        for(int i = 0; i < 10; i++){
            int count = counts[distinct_char[i]-'a'];
            for(int j = 0; j < words[i].size(); j++)
                counts[words[i][j]-'a'] -= count;
            while(count--)
                result += to_string(nums[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/423.md" >}}
---
{{< youtube cGgG0A__wNQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #424: Longest Repeating Character Replacement](https://grid47.xyz/leetcode/solution-424-longest-repeating-character-replacement/) |
| --- |
