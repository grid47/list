
+++
authors = ["grid47"]
title = "Leetcode 2099: Find Subsequence of Length K With the Largest Sum"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2099: Find Subsequence of Length K With the Largest Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QXvaOym_Awk"
youtube_upload_date="2021-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QXvaOym_Awk/maxresdefault.webp"
comments = true
+++



---
You are given an integer array 'nums' and an integer 'k'. You need to find a subsequence of 'nums' of length 'k' such that the sum of its elements is maximized. A subsequence is a sequence that can be derived from another array by deleting some or no elements without changing the order of the remaining elements. Return any subsequence with the largest sum.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the array 'nums' and an integer 'k' representing the desired subsequence length.
- **Example:** `nums = [4, 1, 3, 2], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- -10^5 <= nums[i] <= 10^5
	- 1 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a subsequence of length 'k' with the largest sum.
- **Example:** `Output: [3, 4]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find a subsequence of length 'k' that has the largest possible sum of elements.

- Identify the 'k' largest elements in 'nums'.
- Keep their relative order from the original array.
- Return the subsequence formed by these elements.
{{< dots >}}
### Problem Assumptions ✅
- The input list is not empty.
- The value of 'k' is valid (1 <= k <= nums.length).
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [4, 1, 3, 2], k = 2`  \
  **Explanation:** The subsequence of length 2 with the largest sum is [3, 4], as it has the sum of 7.

- **Input:** `Example 2: nums = [2, -1, 5, 3], k = 2`  \
  **Explanation:** The subsequence with the largest sum is [5, 3], as it gives the highest sum of 8.

{{< dots >}}
## Approach 🚀
The approach to solve the problem involves selecting the largest 'k' elements and maintaining their order in the original array.

### Initial Thoughts 💭
- We need to ensure that we select the largest elements while maintaining the order of the original array.
- A simple solution would involve sorting, but we need to track the indices of the selected elements to maintain their original order.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases for empty inputs as the problem guarantees that nums has at least 'k' elements.
- The algorithm should handle arrays of length up to 1000 efficiently.
- Handle cases where all elements are negative or where the largest values are repeated.
- The values of 'k' and the elements in 'nums' are guaranteed to be within the specified constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> v(nums.begin(), nums.end());
    nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
    int cnt = count(v.begin(), v.begin() + k, v[k - 1]);
    
    vector<int> res;
    for(int i = 0; i < nums.size(); i++)
        if((nums[i] > v[k - 1]) ||
           (nums[i] == v[k - 1] && (cnt-- > 0)))
            res.push_back(nums[i]);
    
    return res;
}
```

This code defines a function to find the maximum subsequence of length k from an array of integers, where elements are selected based on their values and their occurrence in the original array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> maxSubsequence(vector<int>& nums, int k) {
	```
	This is the function signature for the maxSubsequence function, which takes an array 'nums' and an integer 'k' as parameters and returns a vector of integers.

2. **Initialization**
	```cpp
	    vector<int> v(nums.begin(), nums.end());
	```
	Creates a copy of the 'nums' vector to allow manipulation without affecting the original array.

3. **Sorting**
	```cpp
	    nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
	```
	Rearranges the elements in 'v' such that the element at position 'k-1' is the largest element, ensuring the top k elements are correctly ordered.

4. **Counting**
	```cpp
	    int cnt = count(v.begin(), v.begin() + k, v[k - 1]);
	```
	Counts how many times the k-th largest element appears in the first k elements of the vector 'v'. This count helps in handling ties during subsequence selection.

5. **Subsequence Construction**
	```cpp
	    vector<int> res;
	```
	Initializes an empty vector 'res' to store the final subsequence.

6. **Iterating Over Elements**
	```cpp
	    for(int i = 0; i < nums.size(); i++)
	```
	Starts a loop to iterate through all elements in the original 'nums' array to determine which elements belong in the subsequence.

7. **Condition Check 1**
	```cpp
	        if((nums[i] > v[k - 1]) ||
	```
	Checks if the current element in 'nums' is greater than the k-th largest element from 'v', ensuring the largest elements are selected.

8. **Condition Check 2**
	```cpp
	           (nums[i] == v[k - 1] && (cnt-- > 0)))
	```
	Handles cases where the current element equals the k-th largest element, ensuring that only the necessary number of such elements are selected.

9. **Subsequence Update**
	```cpp
	            res.push_back(nums[i]);
	```
	Adds the current element to the subsequence if it meets the selection criteria.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the resulting subsequence as the output of the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(n)

The space complexity is O(n) due to storing the indices of the elements and the subsequence.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/)

---
{{< youtube QXvaOym_Awk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
