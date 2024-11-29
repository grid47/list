
+++
authors = ["grid47"]
title = "Leetcode 1887: Reduction Operations to Make the Array Elements Equal"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1887: Reduction Operations to Make the Array Elements Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1etc9Ip8Xm8"
youtube_upload_date="2021-06-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1etc9Ip8Xm8/maxresdefault.webp"
comments = true
+++



---
Given an integer array nums, the task is to perform operations until all elements in the array are the same. In each operation, identify the largest element in the array, find the next largest value strictly smaller than the current largest, and reduce the largest element to that value. The goal is to count how many operations are required to make all elements in the array equal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers nums, where each element nums[i] represents a value in the array.
- **Example:** `For example, given nums = [4, 1, 2]`
- **Constraints:**
	- The length of nums is between 1 and 50,000, inclusive.
	- Each element nums[i] is between 1 and 50,000, inclusive.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of operations required to make all elements in the array equal.
- **Example:** `For nums = [4, 1, 2], the output will be 3.`
- **Constraints:**
	- The output is an integer representing the number of operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the minimum number of operations required to make all elements in the array equal by reducing the largest elements in the array progressively.

- Sort the array in ascending order.
- Iterate through the sorted array and reduce the largest element to the next smaller element.
- Count the number of such operations until all elements become equal.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty, and the values are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 1, 2]`  \
  **Explanation:** It takes 3 operations to make all elements equal: 
1. largest = 4, nextLargest = 2, reduce nums[0] to 2, nums = [2, 1, 2]. 
2. largest = 2, nextLargest = 1, reduce nums[0] to 1, nums = [1, 1, 2]. 
3. largest = 2, nextLargest = 1, reduce nums[2] to 1, nums = [1, 1, 1].

- **Input:** `nums = [1, 1, 1]`  \
  **Explanation:** All elements are already equal, so no operations are needed. The output is 0.

- **Input:** `nums = [3, 3, 2, 2, 5]`  \
  **Explanation:** It takes 4 operations to make all elements equal: 
1. largest = 5, nextLargest = 3, reduce nums[4] to 3, nums = [3, 3, 2, 2, 3]. 
2. largest = 3, nextLargest = 2, reduce nums[0] to 2, nums = [2, 3, 2, 2, 3]. 
3. largest = 3, nextLargest = 2, reduce nums[1] to 2, nums = [2, 2, 2, 2, 3]. 
4. largest = 3, nextLargest = 2, reduce nums[4] to 2, nums = [2, 2, 2, 2, 2].

{{< dots >}}
## Approach 🚀
The solution involves sorting the array and performing operations to reduce the largest element until all elements are equal.

### Initial Thoughts 💭
- Sorting the array ensures that we always have easy access to the largest and next largest values.
- By iterating from the largest values downward, we can minimize the number of operations needed to make all elements the same.
{{< dots >}}
### Edge Cases 🌐
- The input array cannot be empty, as the problem guarantees at least one element.
- For larger inputs (e.g., nums.length = 50,000), the solution should handle them efficiently with O(n log n) time complexity.
- The array could contain repeated values or be already equal, in which case no operations would be required.
- Ensure that the solution works within the time and space limits for larger arrays.
{{< dots >}}
## Code 💻
```cpp
int reductionOperations(vector<int>& nums) {

    int ops = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = n - 2; i >= 0; i--) {
        
        if(nums[i] == nums[i + 1]) continue;
        ops += (n - 1 - i);
        
    }
    
    return ops;
}
```

This function implements a reduction operation on a vector of integers, sorting them and counting the number of operations needed to reduce adjacent duplicates.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int reductionOperations(vector<int>& nums) {
	```
	Function declaration, takes a vector of integers as input.

2. **Variable Initialization**
	```cpp
	    int ops = 0, n = nums.size();
	```
	Initialize variables: 'ops' for counting operations, 'n' for the size of the vector.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the input vector 'nums' in ascending order.

4. **For Loop**
	```cpp
	    for(int i = n - 2; i >= 0; i--) {
	```
	Iterate through the sorted vector from the second-to-last element to the first.

5. **Comparison**
	```cpp
	        if(nums[i] == nums[i + 1]) continue;
	```
	Skip duplicates by checking if the current element is equal to the next element.

6. **Operation Counting**
	```cpp
	        ops += (n - 1 - i);
	```
	Count the operations needed to reduce the current element.

7. **Return Statement**
	```cpp
	    return ops;
	```
	Return the total number of operations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The primary time complexity arises from sorting the array, which takes O(n log n), followed by a linear scan to count the operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting the array. The space complexity can be reduced if in-place sorting is used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/)

---
{{< youtube 1etc9Ip8Xm8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
