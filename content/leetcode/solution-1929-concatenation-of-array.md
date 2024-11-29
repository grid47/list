
+++
authors = ["grid47"]
title = "Leetcode 1929: Concatenation of Array"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1929: Concatenation of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "68isPRHgcFQ"
youtube_upload_date="2023-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/68isPRHgcFQ/maxresdefault.webp"
comments = true
+++



---
You are given an integer array nums and are required to return a new array where nums is repeated twice in a row.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array nums of integers.
- **Example:** `nums = [3, 4, 5]`
- **Constraints:**
	- 1 <= n <= 1000
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the array where nums is concatenated with itself.
- **Example:** `[3, 4, 5, 3, 4, 5]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Concatenate the array nums with itself.

- Create a new array ans with a length twice as long as nums.
- Copy the elements of nums into the first half of ans.
- Copy the elements of nums into the second half of ans.
{{< dots >}}
### Problem Assumptions ✅
- nums contains positive integers.
- The result array will not exceed the constraints set by the problem.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 4, 5]`  \
  **Explanation:** The array ans is formed by concatenating nums with itself: [3, 4, 5, 3, 4, 5].

{{< dots >}}
## Approach 🚀
The problem can be solved by creating a new array with twice the length of nums, then copying the elements of nums twice.

### Initial Thoughts 💭
- The array needs to be expanded to twice its size.
- The solution can be efficiently achieved with a time complexity of O(n).
- Concatenation can be done in a single pass using a for loop or array operations.
{{< dots >}}
### Edge Cases 🌐
- If nums is empty, the output should also be an empty array.
- The solution should efficiently handle large arrays with the maximum length of 1000.
- Ensure that values in nums are handled properly when they are at the upper constraint of 1000.
- The time complexity of O(n) is sufficient to handle arrays with the maximum length.
{{< dots >}}
## Code 💻
```cpp
vector<int> getConcatenation(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        nums.push_back(nums[i]);
    }
    return nums;
}
```

This function takes a vector of integers, `nums`, and returns a new vector that is a concatenation of the original vector with itself.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Header**
	```cpp
	vector<int> getConcatenation(vector<int>& nums) {
	```
	Defines the function `getConcatenation`, which takes a vector `nums` by reference and returns a vector of integers.

2. **Variable Declaration**
	```cpp
	    int n=nums.size();
	```
	Calculates and stores the size of the input vector `nums` in the variable `n`.

3. **Loop Initialization**
	```cpp
	    for(int i=0;i<n;i++)
	```
	Starts a loop that iterates through each element of the vector `nums` using the index `i`.

4. **Array Modification**
	```cpp
	        nums.push_back(nums[i]);
	```
	Appends each element from the original vector `nums` to the end of the same vector, effectively duplicating its contents.

5. **Return Statement**
	```cpp
	    return nums;
	```
	Returns the modified vector `nums`, which now contains its original contents followed by a concatenation of those contents.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array nums, because we iterate through nums twice.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we create a new array of size 2n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/concatenation-of-array/description/)

---
{{< youtube 68isPRHgcFQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
