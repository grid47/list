
+++
authors = ["grid47"]
title = "Leetcode 2951: Find the Peaks"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2951: Find the Peaks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "zatlKoGhxCQ"
youtube_upload_date="2023-12-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zatlKoGhxCQ/maxresdefault.webp"
comments = true
+++



---
You are given a list called `mountain`, which contains integers. Your task is to find all the indices that represent peaks in the list. A peak is defined as an element that is strictly greater than its immediate left and right neighbors. The first and last elements of the list cannot be peaks. Return a list of indices that correspond to the peaks in the `mountain` array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 0-indexed list of integers, `mountain`, representing the array.
- **Example:** `mountain = [3, 2, 3, 4, 1]`
- **Constraints:**
	- 3 <= mountain.length <= 100
	- 1 <= mountain[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of indices corresponding to the peaks in the array.
- **Example:** `[2]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify indices where the corresponding value is greater than its neighbors.

- Loop through the list from index 1 to n-2.
- For each index, check if the value is greater than the previous and next values.
- If true, add the index to the result list.
{{< dots >}}
### Problem Assumptions ✅
- The input list will always contain at least 3 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mountain = [3, 2, 3, 4, 1]`  \
  **Explanation:** The peak is at index 2 because the value at index 2 (3) is greater than both its neighbors (2 and 4).

{{< dots >}}
## Approach 🚀
The approach to solve this problem involves checking each element (except the first and last) to see if it is greater than both its left and right neighbors.

### Initial Thoughts 💭
- The problem only requires checking elements that are not the first or last.
- To find the peak, I will iterate through the array from the second to the second-last element and compare each element with its neighbors.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the array has at least 3 elements.
- For larger arrays (up to 100 elements), ensure that the logic performs efficiently.
- If all elements are in increasing or decreasing order, the result should be an empty list.
- The array will always have at least 3 elements.
{{< dots >}}
## Code 💻
```cpp
vector<int> findPeaks(vector<int>& nums) {
    vector<int> res;
    for(int i = 1; i < nums.size() - 1; i++) {
        if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
            res.push_back(i);            
    }

    return res;
}
```

This function takes an array 'nums' and finds the indices where the elements are greater than their neighbors (a peak). It returns these indices as a vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findPeaks(vector<int>& nums) {
	```
	Defines the function 'findPeaks' that takes a reference to a vector 'nums' and returns a vector containing the indices of the peak elements.

2. **Result Vector Initialization**
	```cpp
	    vector<int> res;
	```
	Initializes an empty vector 'res' that will store the indices of the peak elements found in the array.

3. **Loop Initialization**
	```cpp
	    for(int i = 1; i < nums.size() - 1; i++) {
	```
	Starts a loop to iterate through the elements of 'nums', excluding the first and last elements, since they can't be peaks.

4. **Peak Condition**
	```cpp
	        if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
	```
	Checks if the current element 'nums[i]' is greater than both its left neighbor 'nums[i - 1]' and right neighbor 'nums[i + 1]', indicating that 'nums[i]' is a peak.

5. **Store Peak Index**
	```cpp
	            res.push_back(i);            
	```
	If the current element is a peak, its index 'i' is added to the 'res' vector.

6. **Return Result**
	```cpp
	    return res;
	```
	Returns the 'res' vector, which contains the indices of all the peak elements found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The best, average, and worst case time complexities are all O(n), where n is the length of the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the indices of peaks in a result list. In the best case, the list could be empty, so space complexity could be O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-peaks/description/)

---
{{< youtube zatlKoGhxCQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
