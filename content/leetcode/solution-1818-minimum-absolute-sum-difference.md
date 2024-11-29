
+++
authors = ["grid47"]
title = "Leetcode 1818: Minimum Absolute Sum Difference"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1818: Minimum Absolute Sum Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PlenJ9Ny45s"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PlenJ9Ny45s/maxresdefault.webp"
comments = true
+++



---
You are given two positive integer arrays nums1 and nums2 of the same length n. You are allowed to change at most one element of nums1 to any other value from nums1 to minimize the total absolute sum difference between nums1 and nums2. Return the minimum absolute sum difference after making the replacement. Since the answer may be large, return it modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays nums1 and nums2, both of length n.
- **Example:** `nums1 = [3, 7, 6], nums2 = [4, 2, 6]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= nums1[i], nums2[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum absolute sum difference after making the replacement, modulo 10^9 + 7.
- **Example:** `Output: 2`
- **Constraints:**
	- The answer should be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the absolute sum difference by changing one element in nums1.

- Calculate the initial absolute sum difference between nums1 and nums2.
- Try replacing one element in nums1 and compute the new sum difference.
- Keep track of the maximum gain (reduction in sum) and compute the result.
{{< dots >}}
### Problem Assumptions ✅
- The arrays nums1 and nums2 are non-empty.
- You can only replace one element in nums1.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [3, 7, 6], nums2 = [4, 2, 6]`  \
  **Explanation:** By replacing one element of nums1 with another from nums1, we minimize the absolute sum difference.

{{< dots >}}
## Approach 🚀
We aim to minimize the absolute sum difference by trying different replacements in nums1 and comparing the results.

### Initial Thoughts 💭
- The initial absolute sum difference is computed for the given nums1 and nums2.
- For each element in nums1, we check the possible replacements to minimize the sum.
- Efficiently search for the best replacement by using binary search or sorted data structures.
{{< dots >}}
### Edge Cases 🌐
- n = 1, nums1 and nums2 are the smallest possible arrays.
- The arrays nums1 and nums2 have lengths near the upper limit, n = 10^5.
- All elements in nums1 and nums2 are identical, leading to an absolute sum difference of 0.
- The algorithm should work efficiently for large inputs within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size();
    set<int> sel(begin(nums1), end(nums1));

    long gain = 0, res = 0;
    for(int i = 0; i < n; i++) {
        long og = abs(nums1[i] - nums2[i]);
        res += og;
        if (gain < og) {
            auto num = sel.lower_bound(nums2[i]);
            if (num !=   end(sel)) gain = max(gain, og - abs(*num       - nums2[i]));
            if (num != begin(sel)) gain = max(gain, og - abs(*prev(num) - nums2[i]));
        }
    }

    return (res - gain) % 1000000007;
}
```

The function `minAbsoluteSumDiff` calculates the minimum absolute sum of differences between two arrays `nums1` and `nums2`, and tries to maximize the gain by minimizing the differences through element substitution. It returns the result modulo 1000000007.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
	```
	This is the function definition of `minAbsoluteSumDiff`, which takes two integer vectors `nums1` and `nums2` and returns the minimum possible sum of absolute differences between the two arrays, considering optimal substitutions.

2. **Variable Initialization**
	```cpp
	    int n = nums1.size();
	```
	The variable `n` stores the size of the input arrays `nums1` (and `nums2`), assuming both arrays are of the same size.

3. **Set Initialization**
	```cpp
	    set<int> sel(begin(nums1), end(nums1));
	```
	A set `sel` is initialized with the elements of `nums1` to allow efficient lookup of elements for calculating the minimum absolute difference.

4. **Variable Initialization**
	```cpp
	    long gain = 0, res = 0;
	```
	The variables `gain` and `res` are initialized to 0. `gain` will store the maximum gain that can be achieved by replacing an element, and `res` will accumulate the original sum of absolute differences.

5. **Loop Over Arrays**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates through each index `i` of the arrays `nums1` and `nums2`.

6. **Calculate Original Difference**
	```cpp
	        long og = abs(nums1[i] - nums2[i]);
	```
	The variable `og` stores the absolute difference between the elements `nums1[i]` and `nums2[i]` for the current index `i`.

7. **Accumulate Original Sum**
	```cpp
	        res += og;
	```
	The absolute difference `og` is added to the `res` variable, which accumulates the total sum of absolute differences between the two arrays.

8. **Gain Calculation**
	```cpp
	        if (gain < og) {
	```
	This conditional checks if the current difference `og` is greater than the previously calculated `gain`. If true, it attempts to minimize the difference by checking nearby elements.

9. **Set Lookup**
	```cpp
	            auto num = sel.lower_bound(nums2[i]);
	```
	The `lower_bound` function is used to find the smallest element in the set `sel` that is greater than or equal to `nums2[i]`. This helps in finding the best possible replacement to minimize the absolute difference.

10. **Gain Update**
	```cpp
	            if (num !=   end(sel)) gain = max(gain, og - abs(*num       - nums2[i]));
	```
	If a valid element `num` is found in the set `sel`, the potential gain is calculated as the difference between the original difference `og` and the new difference after replacing `nums1[i]` with `num`.

11. **Gain Update**
	```cpp
	            if (num != begin(sel)) gain = max(gain, og - abs(*prev(num) - nums2[i]));
	```
	This line checks if there is a valid element before `num` in the set `sel` and calculates the potential gain by considering that element as a replacement for `nums1[i]`.

12. **Return Result**
	```cpp
	    return (res - gain) % 1000000007;
	```
	The final result is returned as the total sum of absolute differences, reduced by the maximum gain, and taken modulo 1000000007.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The algorithm requires sorting or binary search, making the time complexity O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting or storing elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-absolute-sum-difference/description/)

---
{{< youtube PlenJ9Ny45s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
