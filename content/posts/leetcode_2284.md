
+++
authors = ["Yasir"]
title = "Leetcode 2284: Sender With Largest Word Count"
date = "2018-07-28"
description = "Solution to Leetcode 2284"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sender-with-largest-word-count/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        unordered_map<string, int> cnt;
        string res;
        int max_cnt = 0;
        for(int i = 0; i < senders.size(); i++) {
            int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;
            int cur = cnt[senders[i]] += words;
            if((cur > max_cnt) || (cur == max_cnt && senders[i] > res)) {
                res = senders[i];
                max_cnt = cur;
            }
        }

        return res;
    }
};
{{< /highlight >}}

