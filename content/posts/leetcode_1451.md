
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1451: Rearrange Words in a Sentence"
date = "2020-11-10"
description = "Solution to Leetcode 1451"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-words-in-a-sentence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string arrangeWords(string txt) {
        
        int n = txt.size();
        vector<vector<int>> arr;
        map<int, string> mp;
        int prv = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(txt[i] == ' ' || i == n - 1) {
                string str;
                int len;
                if(i == n - 1) {
                    len = i + 1 - prv;
                } else {
                    len = i - prv;
                }
                str = txt.substr(prv, len);
                if(prv == 0) str[0] = str[0] - 'A' + 'a';
                cnt++;
                mp[cnt] = str;
                arr.push_back({len, cnt});
                prv = i + 1;
            }
        }
        sort(arr.begin(), arr.end());
        string res = "";
        for(int i = 0; i < arr.size(); i++) {
            res += mp[arr[i][1]];
            if(i != arr.size() - 1) res += ' ';
        }
        res[0] = res[0] - 'a' + 'A';
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

