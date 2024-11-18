
+++
authors = ["grid47"]
title = "Leetcode 2288: Apply Discount to Prices"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2288: Apply Discount to Prices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-discount-to-prices/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        auto doit = [&](string word) {
            int n = word.size();
            if( n == 1 || word[0] != '$')
            return word;

            long long num = 0;
            for(int i = 1; i < word.size(); i++) {
                if(!isdigit(word[i])) return word;
                num = num * 10 + (word[i] - '0');
            }

            stringstream ss2;
            double discountPercentag = (100 - discount) / 100.00;
            ss2 << fixed << setprecision(2) << (discountPercentag * num);
            return "$" + ss2.str();

        };

        string res, word;
        stringstream ss(sentence);
        while(ss >> word) {
            res += doit(word) + " ";
        }
        res.pop_back();
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2288.md" >}}
---
{{< youtube 7W1Wzpfa1tg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2293: Min Max Game](https://grid47.xyz/leetcode/solution-2293-min-max-game/) |
| --- |
