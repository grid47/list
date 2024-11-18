
+++
authors = ["grid47"]
title = "Leetcode 1115: Print FooBar Alternately"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1115: Print FooBar Alternately in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/print-foobar-alternately/description/)

---
**Code:**

{{< highlight cpp >}}
class FooBar {
private:
    int n;
    mutex mtx1, mtx2;
public:
    FooBar(int n) {
        mtx2.lock();
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mtx1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            mtx2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mtx2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            mtx1.unlock();
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1115.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1116: Print Zero Even Odd](https://grid47.xyz/leetcode/solution-1116-print-zero-even-odd/) |
| --- |
