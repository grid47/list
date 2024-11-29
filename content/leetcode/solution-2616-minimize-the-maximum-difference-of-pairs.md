
+++
authors = ["grid47"]
title = "Leetcode 2616: Minimize the Maximum Difference of Pairs"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2616: Minimize the Maximum Difference of Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lf1Pxg7IrzQ"
youtube_upload_date="2023-08-09"
youtube_thumbnail="https://i.ytimg.com/vi/lf1Pxg7IrzQ/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array `nums` and an integer `p`. Your task is to find `p` pairs of indices such that the maximum absolute difference between any of the pairs is minimized. Each index can be used in at most one pair. Return the minimized value of the maximum difference among all the pairs.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer `p`. The array `nums` contains integers, and `p` specifies the number of pairs to form.
- **Example:** `nums = [8, 3, 7, 1, 2, 9], p = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^9
	- 0 <= p <= (nums.length)/2

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible value of the maximum absolute difference between any of the formed pairs.
- **Example:** `Output: 2`
- **Constraints:**
	- The answer will be a non-negative integer representing the minimized maximum difference.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to select `p` pairs such that the maximum absolute difference between any pair is as small as possible.

- Step 1: Sort the array to allow easier pairing of close values.
- Step 2: Use binary search to minimize the maximum difference by testing different possible differences and adjusting accordingly.
- Step 3: For each candidate difference, count the number of valid pairs that can be formed and determine if it's feasible to achieve that difference.
- Step 4: Return the smallest possible maximum difference after the binary search concludes.
{{< dots >}}
### Problem Assumptions ✅
- All elements in `nums` are non-negative integers.
- The array `nums` can contain duplicate values, and the goal is to pair distinct indices that minimize the maximum difference.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [8, 3, 7, 1, 2, 9], p = 3`  \
  **Explanation:** After sorting the array as [1, 2, 3, 7, 8, 9], the best way to form 3 pairs is by selecting (1, 2), (3, 7), and (8, 9). The maximum difference is 2 (from the pair (7, 3)), which is the minimized maximum difference.

- **Input:** `nums = [10, 1, 2, 7, 1, 3], p = 2`  \
  **Explanation:** The array is sorted as [1, 1, 2, 3, 7, 10]. The two best pairs are (1, 1) and (2, 3), with the maximum difference being 1, which is the minimized maximum.

{{< dots >}}
## Approach 🚀
The approach uses sorting and binary search to find the minimized maximum difference efficiently. The binary search narrows down the possible maximum differences, while sorting simplifies pairing close elements.

### Initial Thoughts 💭
- Brute force approaches could be too slow, so we need to optimize the solution.
- By sorting the array and applying binary search, we can efficiently minimize the maximum difference while ensuring the correct number of valid pairs.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty, return 0.
- The solution should efficiently handle arrays up to 100,000 elements.
- If `p` is 0, the answer should be 0 since no pairs are formed.
- Ensure the algorithm runs in O(n log(maxDifference)) time where n is the size of the array and maxDifference is the range of values in `nums`.
{{< dots >}}
## Code 💻
```cpp
int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    
    int n = nums.size(), l = 0, r = nums[n - 1] - nums[0], ans = nums[n - 1] - nums[0];
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int k = p;
        for(int i = 1; i < n && k > 0; i++) {
            if(nums[i] - nums[i - 1] <= mid) {
                k--;
                i++;
            }
        }
        if(k == 0) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    
    return ans;
}
```

This code minimizes the maximum difference between pairs by applying binary search to the sorted input array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Initialization**
	```cpp
	int minimizeMax(vector<int>& nums, int p) {
	```
	Initialize the function minimizeMax, taking a vector of integers and an integer p as input.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the array nums to facilitate comparison of adjacent elements for minimizing the maximum difference.

3. **Variable Setup**
	```cpp
	    int n = nums.size(), l = 0, r = nums[n - 1] - nums[0], ans = nums[n - 1] - nums[0];
	```
	Set the initial values for binary search range (l, r) and the answer variable (ans).

4. **Binary Search**
	```cpp
	    while(l <= r) {
	```
	Start the binary search loop to narrow down the range for the minimum maximum difference.

5. **Middle Point Calculation**
	```cpp
	        int mid = l + (r - l) / 2;
	```
	Calculate the midpoint (mid) for the current search range to test the possible maximum difference.

6. **Remaining Pairs Setup**
	```cpp
	        int k = p;
	```
	Set the number of allowed pairs (k) to p, which is passed as an argument.

7. **Pair Evaluation**
	```cpp
	        for(int i = 1; i < n && k > 0; i++) {
	```
	Loop through the array to evaluate possible pairs based on the current maximum allowed difference.

8. **Pair Selection**
	```cpp
	            if(nums[i] - nums[i - 1] <= mid) {
	```
	Check if the current pair meets the condition of having a maximum difference less than or equal to mid.

9. **Decrement Allowed Pairs**
	```cpp
	                k--;
	```
	Decrement the number of remaining pairs after successfully selecting a pair.

10. **Skip Next Element**
	```cpp
	                i++;
	```
	Skip the next element in the array as it has been paired with the current element.

11. **Answer Update**
	```cpp
	        if(k == 0) {
	```
	If no more pairs can be made, update the answer with the current mid value.

12. **Binary Search Adjustment**
	```cpp
	            ans = mid;
	```
	Update the answer to the current mid value as it represents a potential minimum maximum difference.

13. **Search Range Update**
	```cpp
	            r = mid - 1;
	```
	Narrow the binary search range by adjusting the right boundary to mid - 1.

14. **Search Range Update**
	```cpp
	        } else l = mid + 1;
	```
	If no valid pairs are found, adjust the left boundary of the binary search range to mid + 1.

15. **Return Final Answer**
	```cpp
	    return ans;
	```
	Return the result, which is the minimized maximum difference between pairs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n), followed by a binary search for the maximum difference.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/)

---
{{< youtube lf1Pxg7IrzQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
