
+++
authors = ["grid47"]
title = "Leetcode 2164: Sort Even and Odd Indices Independently"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2164: Sort Even and Odd Indices Independently in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "h7GOQPBZNv4"
youtube_upload_date="2022-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/h7GOQPBZNv4/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array 'nums'. Your task is to rearrange the elements of 'nums' by sorting the values at odd indices in non-increasing order and the values at even indices in non-decreasing order. Return the rearranged array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array 'nums'.
- **Example:** `nums = [5, 2, 8, 1]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the array 'nums' after rearranging it according to the given sorting rules.
- **Example:** `[2, 8, 5, 1]`
- **Constraints:**
	- The output must preserve the rearrangement order for odd and even indices as described.

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort elements at odd indices in non-increasing order and elements at even indices in non-decreasing order.

- Iterate through the array and sort the elements at even indices in non-decreasing order.
- Iterate through the array and sort the elements at odd indices in non-increasing order.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain between 1 and 100 elements.
- Elements are integers in the range 1 to 100.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [5, 2, 8, 1]`  \
  **Explanation:** First, the elements at odd indices [2, 1] are sorted in non-increasing order to become [8, 1]. Then, the elements at even indices [5, 8] are sorted in non-decreasing order to become [2, 5]. The final array is [2, 8, 5, 1].

- **Input:** `Example 2: nums = [9, 7]`  \
  **Explanation:** There is only one element at an odd index and one at an even index, so the array remains [7, 9].

{{< dots >}}
## Approach 🚀
The approach involves sorting elements at odd and even indices separately while preserving their relative order.

### Initial Thoughts 💭
- Sorting odd and even indices separately ensures that the required order is maintained.
- The solution involves simple sorting and iterating through the array.
{{< dots >}}
### Edge Cases 🌐
- The array must have at least one element.
- The solution should handle arrays with up to 100 elements.
- Arrays with all elements equal should still return the same array.
- The solution must handle arrays with lengths between 1 and 100 efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<int> sortEvenOdd(vector<int>& nums) {
    int minIndex;
// Here in this nested loop , we are sorting the elements at even indices in non-decreasing order.
    for(int i=0;i<nums.size();i+=2)
    {
        minIndex=i;
        for(int j=i+2;j<nums.size();j+=2)
        {
            if(nums[j]<nums[minIndex])
                minIndex=j;
        }
        swap(nums[i],nums[minIndex]);
    }
// Here , we are trying to sort the elements at odd indices in non-increasing order. 
    for(int i=1;i<nums.size();i+=2)
    {
        minIndex=i;
        for(int j=i+2;j<nums.size();j+=2)
        {
            if(nums[j]>nums[minIndex])
                minIndex=j;
        }
        swap(nums[i],nums[minIndex]);
    }
    
    return nums;
}
```

This function sorts elements at even indices in non-decreasing order and elements at odd indices in non-increasing order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> sortEvenOdd(vector<int>& nums) {
	```
	Defines the function that takes a vector of integers as input and returns a vector of integers.

2. **Variable Initialization**
	```cpp
	    int minIndex;
	```
	Initializes the variable 'minIndex' to store the index of the minimum element during the sorting process.

3. **For Loop**
	```cpp
	    for(int i=0;i<nums.size();i+=2)
	```
	Loop iterates through the elements at even indices in the vector 'nums'.

4. **Assignment**
	```cpp
	        minIndex=i;
	```
	Sets 'minIndex' to the current index to track the minimum element.

5. **Nested For Loop**
	```cpp
	        for(int j=i+2;j<nums.size();j+=2)
	```
	Nested loop iterates over the remaining even indices starting from the next index.

6. **Comparison**
	```cpp
	            if(nums[j]<nums[minIndex])
	```
	Compares the current element with the element at 'minIndex' to find the smallest element.

7. **Index Update**
	```cpp
	                minIndex=j;
	```
	Updates 'minIndex' to the new index if a smaller element is found.

8. **Swap**
	```cpp
	        swap(nums[i],nums[minIndex]);
	```
	Swaps the elements at index 'i' and 'minIndex' to place the smallest element at index 'i'.

9. **For Loop**
	```cpp
	    for(int i=1;i<nums.size();i+=2)
	```
	Loop iterates through the elements at odd indices in the vector 'nums'.

10. **Block Start**
	```cpp
	    {
	```
	Begins the block for the loop processing odd indices.

11. **Assignment**
	```cpp
	        minIndex=i;
	```
	Sets 'minIndex' to the current index to track the maximum element during the sorting process.

12. **Nested For Loop**
	```cpp
	        for(int j=i+2;j<nums.size();j+=2)
	```
	Nested loop iterates over the remaining odd indices starting from the next index.

13. **Comparison**
	```cpp
	            if(nums[j]>nums[minIndex])
	```
	Compares the current element with the element at 'minIndex' to find the largest element.

14. **Index Update**
	```cpp
	                minIndex=j;
	```
	Updates 'minIndex' to the new index if a larger element is found.

15. **Swap**
	```cpp
	        swap(nums[i],nums[minIndex]);
	```
	Swaps the elements at index 'i' and 'minIndex' to place the largest element at index 'i'.

16. **Return**
	```cpp
	    return nums;
	```
	Returns the sorted vector 'nums'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity for sorting each set of indices is O(n^2).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We use constant extra space apart from the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-even-and-odd-indices-independently/description/)

---
{{< youtube h7GOQPBZNv4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
