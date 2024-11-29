
+++
authors = ["grid47"]
title = "Leetcode 2529: Maximum Count of Positive Integer and Negative Integer"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2529: Maximum Count of Positive Integer and Negative Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "4uhvXmOp5Do"
youtube_upload_date="2023-01-08"
youtube_thumbnail="https://i.ytimg.com/vi/4uhvXmOp5Do/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers sorted in non-decreasing order. Your task is to determine the maximum count between the number of positive integers and the number of negative integers in the array. Zero is not considered positive or negative.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers `nums` which is sorted in non-decreasing order.
- **Example:** `[-3, -2, -1, 1, 2, 3]`
- **Constraints:**
	- 1 <= nums.length <= 2000
	- -2000 <= nums[i] <= 2000
	- nums is sorted in non-decreasing order.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum of the count of positive integers and the count of negative integers in the array.
- **Example:** `3`
- **Constraints:**
	- The output will be a single integer representing the maximum count of positive or negative integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the count of positive and negative integers in the array and return the maximum of the two.

- Initialize counters for positive and negative integers.
- Iterate through the array and count the positive and negative integers.
- Return the maximum of the two counts.
{{< dots >}}
### Problem Assumptions ✅
- The input array is sorted in non-decreasing order.
- Zero (0) is neither positive nor negative.
{{< dots >}}
## Examples 🧩
- **Input:** `[-3, -2, -1, 1, 2, 3]`  \
  **Explanation:** In this example, there are 3 positive integers and 3 negative integers. The maximum count between them is 3.

- **Input:** `[-5, -3, -1, 0, 2, 4, 6]`  \
  **Explanation:** In this example, there are 3 positive integers and 3 negative integers. The maximum count between them is 4.

- **Input:** `[0, 2, 4, 8, 10]`  \
  **Explanation:** In this example, there are 5 positive integers and 0 negative integers. The maximum count between them is 5.

{{< dots >}}
## Approach 🚀
The solution involves counting the number of positive and negative integers in the array and returning the maximum of the two. The input is already sorted, which helps us efficiently determine the counts.

### Initial Thoughts 💭
- The array is sorted, which means the negative integers will be at the beginning and positive integers will be at the end.
- Counting positive and negative integers separately is the most straightforward approach.
- The problem could potentially be optimized further if we use binary search to quickly find the boundary between negative and positive numbers, reducing the time complexity.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least one element, as per the constraints.
- Ensure that the solution efficiently handles arrays of size up to 2000 elements.
- Arrays with zero values should be handled correctly, as zero is neither positive nor negative.
- The array is sorted, so you can exploit this property for more efficient solutions.
{{< dots >}}
## Code 💻
```cpp
int maximumCount(vector<int>& nums) {
    int pos = 0, neg = 0;
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] > 0) pos++;
        else if(nums[i] < 0) neg++;
    return max(pos, neg);
}
```

The 'maximumCount' function calculates and returns the larger of the count of positive or negative numbers in the given vector 'nums'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumCount(vector<int>& nums) {
	```
	This is the function definition for 'maximumCount', which takes a reference to a vector of integers 'nums' and returns an integer value.

2. **Variable Initialization**
	```cpp
	    int pos = 0, neg = 0;
	```
	Two integer variables, 'pos' and 'neg', are initialized to 0. 'pos' will track the count of positive numbers, and 'neg' will track the count of negative numbers.

3. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++)
	```
	This for loop iterates through each element in the 'nums' vector, with 'i' as the loop index.

4. **Conditional Statement**
	```cpp
	        if(nums[i] > 0) pos++;
	```
	If the current element is positive, the 'pos' counter is incremented.

5. **Conditional Statement**
	```cpp
	        else if(nums[i] < 0) neg++;
	```
	If the current element is negative, the 'neg' counter is incremented.

6. **Return Statement**
	```cpp
	    return max(pos, neg);
	```
	After completing the loop, the function returns the maximum of 'pos' and 'neg', which represents the greater count between positive and negative numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we need to count the number of positive and negative integers by iterating through the entire array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of space for the counters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/)

---
{{< youtube 4uhvXmOp5Do >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
