
+++
authors = ["Yasir"]
title = "Leetcode 341: Flatten Nested List Iterator"
date = "2023-11-21"
description = "Solution to Leetcode 341"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flatten-nested-list-iterator/description/)

---

**Code:**

{{< highlight html >}}
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

