
+++
authors = ["grid47"]
title = "Leetcode 341: Flatten Nested List Iterator"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 341: Flatten Nested List Iterator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search","Design","Queue","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "4ILiBgLokM8"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/341.webp"
+++



[`Problem Link`](https://leetcode.com/problems/flatten-nested-list-iterator/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/341.webp" 
    alt="A nested list unfolding and flattening into a 1D array, with each item softly glowing as it appears."
    caption="Solution to LeetCode 341: Flatten Nested List Iterator Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/341.md" >}}
---
{{< youtube 4ILiBgLokM8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #342: Power of Four](https://grid47.xyz/leetcode/solution-342-power-of-four/) |
| --- |
