
+++
authors = ["grid47"]
title = "Leetcode 1920: Build Array from Permutation"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1920: Build Array from Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "LoUAGs8fqB0"
youtube_upload_date="2021-07-04"
youtube_thumbnail="https://i.ytimg.com/vi/LoUAGs8fqB0/maxresdefault.jpg"
comments = true
+++



---
Given a zero-based permutation nums (0-indexed), build a new array ans of the same length where for each i, ans[i] = nums[nums[i]]. Return the array ans. A zero-based permutation means that the array consists of distinct integers from 0 to nums.length - 1 (inclusive).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums, which is a zero-based permutation of distinct integers from 0 to nums.length - 1.
- **Example:** `nums = [2, 0, 1, 4, 3]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 0 <= nums[i] < nums.length
	- The elements in nums are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the array ans, where each element is nums[nums[i]].
- **Example:** `[1, 2, 0, 3, 4]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** For each index i in the array nums, compute nums[nums[i]] and store it in the result array ans.

- Iterate over the array nums.
- For each index i, compute ans[i] = nums[nums[i]].
- Return the resulting array ans.
{{< dots >}}
### Problem Assumptions ✅
- The input array is a valid zero-based permutation of integers.
- The length of the array will not exceed 1000.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 0, 1, 4, 3]`  \
  **Explanation:** In the array nums = [2, 0, 1, 4, 3], the new array ans is computed as follows: ans[0] = nums[nums[0]] = nums[2] = 1, ans[1] = nums[nums[1]] = nums[0] = 2, ans[2] = nums[nums[2]] = nums[1] = 0, ans[3] = nums[nums[3]] = nums[4] = 3, ans[4] = nums[nums[4]] = nums[3] = 4. Thus, the final ans is [1, 2, 0, 3, 4].

{{< dots >}}
## Approach 🚀
We can simply iterate over the input array nums and use the given formula to compute the result for each index i.

### Initial Thoughts 💭
- The problem asks us to compute the value nums[nums[i]] for each index i.
- Since the array elements are distinct and within a specific range, we don't need additional data structures.
- This approach is straightforward and requires just one iteration through the array.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as per problem constraints.
- Ensure the solution efficiently handles inputs with the maximum size, i.e., nums.length = 1000.
- For the smallest array length (nums.length = 1), the result will be [nums[nums[0]]], which is just nums[0].
- The input array will always contain distinct integers from 0 to nums.length - 1.
{{< dots >}}
## Code 💻
```cpp
vector<int> buildArray(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i]=nums[nums[i]];
    }
    return ans;
}
```

This function builds an array where each element at index 'i' is replaced by the element at the index 'nums[i]' in the original array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> buildArray(vector<int>& nums) {
	```
	Defines the function 'buildArray' which takes a vector of integers 'nums' and returns a new vector where each element is replaced by another element indexed by its own value.

2. **Variable Initialization**
	```cpp
	    int n=nums.size();
	```
	Initializes the variable 'n' to store the size of the input vector 'nums'.

3. **Variable Initialization**
	```cpp
	    vector<int> ans(n);
	```
	Initializes a vector 'ans' of size 'n' to store the result.

4. **Loop Start**
	```cpp
	    for(int i=0;i<n;i++){
	```
	Begins a loop that iterates over each index of the input vector 'nums'.

5. **Array Assignment**
	```cpp
	        ans[i]=nums[nums[i]];
	```
	For each index 'i', assigns the value at 'nums[nums[i]]' to 'ans[i]', effectively building the new array by accessing the element indexed by 'nums[i]'.

6. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the newly constructed vector 'ans' that contains the elements at the indices specified by 'nums'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates over the array exactly once, which results in a time complexity of O(n), where n is the length of the input array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use an additional array of size n to store the result, so the space complexity is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/build-array-from-permutation/description/)

---
{{< youtube LoUAGs8fqB0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
