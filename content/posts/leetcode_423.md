
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 423: Reconstruct Original Digits from English"
date = "2023-09-03"
description = "Solution to Leetcode 423"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reconstruct-original-digits-from-english/description/)

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
