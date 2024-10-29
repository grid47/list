
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2288: Apply Discount to Prices"
date = "2018-07-26"
description = "Solution to Leetcode 2288"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

