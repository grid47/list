
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
comments = true
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
You are managing a product development process where each version of the product is based on its previous version. However, you have a version that failed the quality check. Since all subsequent versions are based on the previous ones, they also fail the quality check. Your task is to find the first bad version that caused all subsequent versions to be bad. You are given an API `bool isBadVersion(version)` that returns `true` if the version is bad, and `false` otherwise. Your goal is to find the first bad version while minimizing the number of calls to the API.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer `n`, representing the total number of versions, and a function `isBadVersion(version)` that tells whether a version is bad or not.
- **Example:** `Input: n = 6, bad = 4`
- **Constraints:**
	- 1 <= bad <= n <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the first bad version number that causes all subsequent versions to be bad.
- **Example:** `Output: 4`
- **Constraints:**
	- The output should be the version number of the first bad version.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the first bad version by minimizing the number of calls to `isBadVersion`.

- Step 1: Use binary search to find the first bad version.
- Step 2: Initialize two pointers: start at 1 and end at n.
- Step 3: Compute the midpoint of the current range.
- Step 4: If the midpoint is a bad version, narrow the search range to the left half (end = mid). Otherwise, narrow the search range to the right half (start = mid + 1).
- Step 5: Repeat this process until the start pointer equals the end pointer, which will indicate the first bad version.
{{< dots >}}
### Problem Assumptions ✅
- The `isBadVersion` function is available and can be called.
- You need to minimize the number of calls to the `isBadVersion` API.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 6, bad = 4`  \
  **Explanation:** The versions are [1, 2, 3, 4, 5, 6]. The first bad version is 4. The binary search process calls `isBadVersion(3)` (false), then `isBadVersion(5)` (true), and finally `isBadVersion(4)` (true), thus returning 4.

- **Input:** `Input: n = 1, bad = 1`  \
  **Explanation:** Since there is only one version and it is bad, the function immediately returns 1.

{{< dots >}}
## Approach 🚀
The approach to solving the problem involves using binary search to minimize the number of calls to `isBadVersion` while locating the first bad version.

### Initial Thoughts 💭
- Binary search is an optimal approach for this problem as it allows us to narrow down the search space quickly, halving it with each check.
- We aim to minimize the number of API calls while ensuring correctness by consistently narrowing the search range.
{{< dots >}}
### Edge Cases 🌐
- No empty input cases are possible since the length of n is at least 1.
- For large values of n, ensure that the binary search approach is used to handle the input efficiently.
- If the first version is bad, the function should return 1 immediately.
- The number of versions, n, can be large, but the binary search will handle this efficiently in O(log n) time.
{{< dots >}}
## Code 💻
```cpp
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
```

This function uses binary search to find the first bad version in a series of versions. It returns the first bad version's number by repeatedly narrowing the search range.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int firstBadVersion(int n) {
	```
	Defines the function `firstBadVersion`, which takes an integer `n` representing the total number of versions and returns the number of the first bad version.

2. **Initialize Search Range**
	```cpp
	    int s = 1, e = n;
	```
	Initializes the search range with `s` as 1 (the first version) and `e` as `n` (the last version).

3. **Binary Search Loop**
	```cpp
	    while(s < e) {
	```
	Enters a loop that continues until the search range is narrowed down to a single version.

4. **Calculate Midpoint**
	```cpp
	        int mid = s + (e - s) / 2;
	```
	Calculates the midpoint `mid` of the current search range to check whether the bad version lies before or after it.

5. **Check Bad Version**
	```cpp
	        if(isBadVersion(mid))
	```
	Checks whether the version at the midpoint is bad by calling the `isBadVersion` function.

6. **Narrow Search Range Left**
	```cpp
	            e = mid;
	```
	If the midpoint version is bad, the search range is narrowed by setting the end of the range `e` to `mid`, excluding all versions after it.

7. **Narrow Search Range Right**
	```cpp
	        else s = mid + 1;
	```
	If the midpoint version is not bad, the search range is narrowed by setting the start of the range `s` to `mid + 1`, excluding the current `mid` version.

8. **Return First Bad Version**
	```cpp
	    return e;
	```
	Returns the first bad version found by the binary search.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) due to the binary search, where we halve the search space with each API call.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/first-bad-version/description/)

---
{{< youtube E15djRphPj0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
