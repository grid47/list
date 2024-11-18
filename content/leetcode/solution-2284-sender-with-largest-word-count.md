
+++
authors = ["grid47"]
title = "Leetcode 2284: Sender With Largest Word Count"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2284: Sender With Largest Word Count in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "j5BlwSyz3F8"
youtube_upload_date="2022-05-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/j5BlwSyz3F8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/sender-with-largest-word-count/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2284.md" >}}
---
{{< youtube j5BlwSyz3F8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2287: Rearrange Characters to Make Target String](https://grid47.xyz/leetcode/solution-2287-rearrange-characters-to-make-target-string/) |
| --- |
