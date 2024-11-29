
+++
authors = ["grid47"]
title = "Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0l2IwK_OHac"
youtube_upload_date="2023-10-29"
youtube_thumbnail="https://i.ytimg.com/vi/0l2IwK_OHac/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays `nums1` and `nums2`, both containing positive integers. Some elements in the arrays are zeros, which need to be replaced with strictly positive integers. The goal is to make the sums of both arrays equal by replacing the zeros in such a way that the resulting sums are the same. Return the minimum possible sum that can make the sums of both arrays equal, or return -1 if it is impossible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays of integers, `nums1` and `nums2`.
- **Example:** `nums1 = [5, 3, 0, 4, 0], nums2 = [10, 8, 0]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 10^5
	- 0 <= nums1[i], nums2[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible sum that can make the sums of both arrays equal, or -1 if it is impossible.
- **Example:** `Output: 16`
- **Constraints:**
	- The output must be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to calculate the sum of both arrays after replacing all zeros with positive integers in such a way that the sums become equal.

- Calculate the sum of both arrays, excluding the zeros.
- Count how many zeros exist in each array.
- If the sum of one array is larger than the other and there are no zeros to adjust, return -1.
- Distribute the necessary values to the zeros to make the sums equal, aiming to minimize the sum.
{{< dots >}}
### Problem Assumptions ✅
- Both arrays contain at least one element.
- The values in the arrays are positive integers, except for the zeros.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums1 = [5, 3, 0, 4, 0], nums2 = [10, 8, 0]`  \
  **Explanation:** We replace the zeros with positive integers in a way that minimizes the sum while making both arrays' sums equal. The result is 16.

{{< dots >}}
## Approach 🚀
We approach this problem by calculating the initial sums of both arrays and using the zeros to balance the sums while aiming to minimize the final sum.

### Initial Thoughts 💭
- We need to make the sums of both arrays equal by replacing the zeros with positive integers.
- The key is to balance the difference in the sums while minimizing the added values for zeros.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element in both arrays.
- The solution must efficiently handle up to 100,000 elements in each array.
- When one array has no zeros and the other has many, we must ensure the sum can still be balanced.
- We assume the constraints are within the given limits.
{{< dots >}}
## Code 💻
```cpp
long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
    for(int num: nums1) cnt1 += num == 0, sum1 += num;
    for(int num: nums2) cnt2 += num == 0, sum2 += num;

    if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
        cnt2 == 0 && cnt1 + sum1 > sum2)
            return -1;

    return max(sum1 + cnt1, sum2 + cnt2);

}
```

This function calculates the maximum sum by counting the zeroes in both arrays and summing the elements. If certain conditions are met, it returns -1, otherwise it returns the maximum sum considering the zero counts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long minSum(vector<int>& nums1, vector<int>& nums2) {
	```
	Defines the function 'minSum' that takes two vectors of integers, nums1 and nums2, and returns a long long value.

2. **Variable Initialization**
	```cpp
	    long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
	```
	Initializes variables 'cnt1' and 'cnt2' for counting zeros in nums1 and nums2, and 'sum1' and 'sum2' for summing the elements of nums1 and nums2.

3. **Loop through nums1**
	```cpp
	    for(int num: nums1) cnt1 += num == 0, sum1 += num;
	```
	Iterates over 'nums1', counting the zeros with 'cnt1' and summing the elements with 'sum1'.

4. **Loop through nums2**
	```cpp
	    for(int num: nums2) cnt2 += num == 0, sum2 += num;
	```
	Iterates over 'nums2', counting the zeros with 'cnt2' and summing the elements with 'sum2'.

5. **Condition Check**
	```cpp
	    if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
	```
	Checks if 'cnt1' is zero and if the sum of 'cnt2' and 'sum2' is greater than 'sum1', or if 'cnt2' is zero and if the sum of 'cnt1' and 'sum1' is greater than 'sum2'.

6. **Condition Check**
	```cpp
	        cnt2 == 0 && cnt1 + sum1 > sum2)
	```
	Continues the conditional check to verify the conditions between the elements and sums of both arrays.

7. **Return Statement**
	```cpp
	            return -1;
	```
	Returns -1 if the previous condition evaluates to true, indicating that the required condition is not met.

8. **Return Result**
	```cpp
	    return max(sum1 + cnt1, sum2 + cnt2);
	```
	Returns the maximum sum between the sums of nums1 with the count of zeroes and nums2 with the count of zeroes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where n and m are the lengths of nums1 and nums2.
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

We iterate through both arrays to calculate the sums and counts of zeros.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1), since the space used is constant.

We use a constant amount of space to track sums and counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/)

---
{{< youtube 0l2IwK_OHac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
