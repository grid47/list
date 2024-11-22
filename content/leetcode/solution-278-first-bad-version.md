
+++
authors = ["grid47"]
title = "Leetcode 278: First Bad Version"
date = "2024-10-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 278: First Bad Version in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Interactive"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/278.webp"
youtube = "E15djRphPj0"
youtube_upload_date="2020-04-20"
youtube_thumbnail="https://i.ytimg.com/vi/E15djRphPj0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/278.webp" 
    alt="A series of versions, with the first bad one glowing brightly, indicating where the bad version starts."
    caption="Solution to LeetCode 278: First Bad Version Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        while(s < e) {
            int mid = s + (e - s) / 2;
            if(isBadVersion(mid))
                e = mid;
            else s = mid + 1;
        }
        return e;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

You're given an API called `isBadVersion(int version)` that checks whether a particular version of a software is bad. If the version is bad, it returns `true`, otherwise, it returns `false`. The task is to find the **first bad version** from a total of `n` versions, and you need to do this efficiently with the least number of API calls.

### 🧠 Approach

This problem is a classic example where **binary search** shines! Here's why binary search is a perfect fit:
1. **Ordered versions**: The versions are sequential, and once a bad version is found, all subsequent versions are also bad.
2. **Efficient narrowing**: We can halve the search space at each step, making it extremely efficient even for large values of `n`.

Binary search allows us to find the first bad version by progressively narrowing the search range until we zero in on the smallest bad version.

---

### 🔨 Step-by-Step Code Breakdown

Let's walk through the code step by step:

#### Step 1: Initialize Search Range
```cpp
int s = 1, e = n;
```
- `s` (start) and `e` (end) represent the search range for the versions. Initially, the range is from `1` to `n`.

#### Step 2: Start the Binary Search Loop
```cpp
while (s < e) {
```
- The loop runs as long as there’s more than one element left in the search range (`s < e`), ensuring we haven’t narrowed it down to the first bad version yet.

#### Step 3: Calculate the Midpoint
```cpp
int mid = s + (e - s) / 2;
```
- We calculate `mid` to avoid overflow (when `s` and `e` are large). This gives us the middle point in the current range.

#### Step 4: Check if `mid` is Bad
```cpp
if (isBadVersion(mid)) {
    e = mid;
} else {
    s = mid + 1;
}
```
- **Bad version found**: If `isBadVersion(mid)` returns `true`, it means the first bad version could be `mid` or any version before it. So, we update `e` to `mid` to continue searching on the left side.
- **Not a bad version**: If `mid` isn’t a bad version, the first bad version must be somewhere after `mid`, so we update `s` to `mid + 1`.

#### Step 5: Return the First Bad Version
```cpp
return e;
```
- By the time `s == e`, both will point to the first bad version, so we return `e` as the result.

---

### 📈 Complexity Analysis

#### Time Complexity:
- The time complexity is **O(log n)**. With each iteration of the loop, we halve the search space, making it logarithmic in terms of the number of versions, `n`.

#### Space Complexity:
- The space complexity is **O(1)**. We only use a constant amount of extra space to store the start (`s`), end (`e`), and middle (`mid`) points of the search range, which doesn't grow with the input size.

---

### 🏁 Conclusion

This binary search solution is highly efficient for finding the first bad version in a sequence of versions. By reducing the search space by half with each step, we can find the first bad version in logarithmic time — **O(log n)** — while using constant space.

#### Key Points:
- **Time-efficient**: Logarithmic time complexity ensures quick results, even with a large number of versions.
- **Space-efficient**: The algorithm only uses a small, constant amount of space.

This method minimizes API calls and guarantees an optimal solution for the problem. Whether you’re working with a few versions or billions of them, this approach is designed to scale seamlessly!

---

### 🎯 Takeaway

This problem is a great example of applying **binary search** to reduce the search space efficiently. Mastering binary search is a valuable skill that can be applied to many different types of problems in coding interviews and real-world scenarios. Keep practicing, and you’ll be a binary search pro in no time! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/first-bad-version/description/)

---
{{< youtube E15djRphPj0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
