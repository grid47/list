
+++
authors = ["grid47"]
title = "Leetcode 2210: Count Hills and Valleys in an Array"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2210: Count Hills and Valleys in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "I9ZXvpleMDk"
youtube_upload_date="2022-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/I9ZXvpleMDk/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array 'nums'. A number at index 'i' is part of a hill if its closest non-equal neighbors on both sides are smaller than the number at index 'i'. Similarly, an index 'i' is part of a valley if its closest non-equal neighbors on both sides are larger than the number at index 'i'. Adjacent indices 'i' and 'j' are part of the same hill or valley if the values at nums[i] and nums[j] are the same. An index must have non-equal neighbors on both sides to be part of a hill or valley. Your task is to count the total number of hills and valleys.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers.
- **Example:** `nums = [3, 5, 1, 4, 2]`
- **Constraints:**
	- 3 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of hills and valleys in the array.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify hills and valleys based on the given conditions.

- Iterate through the array and check for each element if it satisfies the hill or valley condition.
- For each element, compare it with the closest non-equal neighbors to determine if it forms a hill or valley.
- Count the number of hills and valleys.
{{< dots >}}
### Problem Assumptions ✅
- The input array has at least three elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 5, 1, 4, 2]`  \
  **Explanation:** In this example, index 1 is a hill (5 > 3 and 5 > 1), index 2 is a valley (1 < 5 and 1 < 4), and index 3 is a hill (4 > 1 and 4 > 2). Therefore, the total count of hills and valleys is 2.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the array and identifying hills and valleys based on the given conditions. A hill is a number that is greater than both its neighbors, and a valley is smaller than both its neighbors.

### Initial Thoughts 💭
- A hill is a local maximum, and a valley is a local minimum in the context of non-equal neighbors.
- We can iterate through the array and check for each element if it satisfies the hill or valley conditions.
{{< dots >}}
### Edge Cases 🌐
- The input array must have at least 3 elements.
- The solution should handle arrays of size up to 100 elements efficiently.
- Arrays where all elements are equal will not have any hills or valleys.
{{< dots >}}
## Code 💻
```cpp
int countHillValley(vector<int>& nums) {
  int res = 0;
    for(int j = 0, i = 1; i < nums.size() - 1; i++)
      if ((nums[j] < nums[i] && nums[i] > nums[i + 1]) ||
          (nums[j] > nums[i] && nums[i] < nums[i + 1])) {
            res++;
            j = i;
          }
    return res;
}
```

This function counts the number of 'hill' and 'valley' points in an array. A point is a hill if it is greater than its adjacent points, and a valley if it is smaller than its adjacent points.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countHillValley(vector<int>& nums) {
	```
	Function definition begins. This function takes a vector of integers as input and will return an integer value.

2. **Variable Initialization**
	```cpp
	  int res = 0;
	```
	Initialize the result variable `res` to 0. This will store the count of hill and valley points.

3. **Loop Setup**
	```cpp
	    for(int j = 0, i = 1; i < nums.size() - 1; i++)
	```
	Start a loop to iterate through the vector `nums`. The loop runs from index 1 to `size - 2` (excluding the first and last element). The variable `j` keeps track of the previous peak or valley.

4. **Condition Check**
	```cpp
	      if ((nums[j] < nums[i] && nums[i] > nums[i + 1]) ||
	```
	Check if the current point `i` is a 'hill'. A hill occurs when the current element is greater than both its neighbors.

5. **Condition Check**
	```cpp
	          (nums[j] > nums[i] && nums[i] < nums[i + 1])) {
	```
	Check if the current point `i` is a 'valley'. A valley occurs when the current element is smaller than both its neighbors.

6. **Increment Result**
	```cpp
	            res++;
	```
	If the current point is either a hill or valley, increment the result count.

7. **Update Previous Point**
	```cpp
	            j = i;
	```
	Update `j` to the current index `i` to track the new reference point for the next hill/valley check.

8. **Return Result**
	```cpp
	    return res;
	```
	Return the final count of hills and valleys found in the vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We need to loop through each element once, making the time complexity O(n), where n is the length of the input array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of extra space since we are only tracking the count of hills and valleys.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/)

---
{{< youtube I9ZXvpleMDk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
