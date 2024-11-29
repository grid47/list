
+++
authors = ["grid47"]
title = "Leetcode 2460: Apply Operations to an Array"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2460: Apply Operations to an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "SykhaokFEIM"
youtube_upload_date="2022-11-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SykhaokFEIM/maxresdefault.webp"
comments = true
+++



---
You are given an array of non-negative integers. You need to perform a series of operations on this array where, in each operation, you compare adjacent elements. If the elements are equal, you double the value of the first element and set the second element to zero. After performing these operations on all pairs, shift all the zeros to the end of the array. Return the resulting array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array nums containing non-negative integers.
- **Example:** `nums = [3, 3, 1, 1, 2, 0]`
- **Constraints:**
	- 2 <= nums.length <= 2000
	- 0 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the array after performing the operations and moving all zeros to the end.
- **Example:** `For nums = [3, 3, 1, 1, 2, 0], the output should be [6, 2, 1, 1, 0, 0].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to perform the operations as described and shift zeros to the end.

- 1. Iterate through the array and compare adjacent elements.
- 2. If elements are equal, double the first one and set the second to zero.
- 3. After all operations, shift all zeros in the array to the end.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that the operations will be valid and will not lead to any invalid state.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 3, 1, 1, 2, 0]`  \
  **Explanation:** The operations proceed as follows:
- For i = 0, nums[0] and nums[1] are equal, so we double nums[0] and set nums[1] to 0. The array becomes [6, 0, 1, 1, 2, 0].
- For i = 1, nums[1] and nums[2] are not equal, so no operation is performed.
- For i = 2, nums[2] and nums[3] are equal, so we double nums[2] and set nums[3] to 0. The array becomes [6, 0, 2, 0, 2, 0].
- Finally, we shift all the zeros to the end, resulting in [6, 2, 1, 1, 0, 0].

{{< dots >}}
## Approach 🚀
We will perform the operations sequentially and adjust the array. The approach works by iterating over the array, applying the operations on adjacent elements, and shifting the zeros at the end once the operations are complete.

### Initial Thoughts 💭
- We need to identify and apply operations only when adjacent elements are equal.
- We can apply the operation in a single pass over the array, followed by another pass to move the zeros to the end.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least two elements, so there will never be an empty array.
- The algorithm should work efficiently for arrays up to the maximum length of 2000.
- If no adjacent elements are equal, no operations will be performed.
- The solution should be able to handle large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<int> applyOperations(vector<int>& A) {
for (int i = 0, j = 0; i < size(A); ++i){
    if (i + 1 < size(A) and A[i] == A[i + 1]){
        A[i] *= 2;
        A[i + 1] = 0;
    }
    if (A[i]) swap(A[j++], A[i]);
}   
return A;
}
```

This function modifies an array by combining consecutive equal values into their double and shifting all non-zero values to the left.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> applyOperations(vector<int>& A) {
	```
	Defines the function to process the array and return the modified version.

2. **Loop Initialization**
	```cpp
	for (int i = 0, j = 0; i < size(A); ++i){
	```
	Initializes a loop to iterate through the array, with `i` as the current index and `j` to track the position of non-zero elements.

3. **Condition Check**
	```cpp
	    if (i + 1 < size(A) and A[i] == A[i + 1]){
	```
	Checks if the current element is equal to the next element to combine their values.

4. **Value Update**
	```cpp
	        A[i] *= 2;
	```
	Doubles the value of the current element when it matches the next element.

5. **Set Zero**
	```cpp
	        A[i + 1] = 0;
	```
	Sets the next element to zero after combining its value with the current element.

6. **Swap Non-Zero**
	```cpp
	    if (A[i]) swap(A[j++], A[i]);
	```
	Swaps non-zero elements to the left of the array, maintaining their relative order.

7. **Return Statement**
	```cpp
	return A;
	```
	Returns the modified array after processing.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array twice, once to apply the operations and once to shift the zeros.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we use only a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/apply-operations-to-an-array/description/)

---
{{< youtube SykhaokFEIM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
