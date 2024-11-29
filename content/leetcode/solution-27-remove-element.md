
+++
authors = ["grid47"]
title = "Leetcode 27: Remove Element"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 27: Remove Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/27.webp"
youtube = "Pcd1ii9P9ZI"
youtube_upload_date="2021-09-13"
youtube_thumbnail="https://i.ytimg.com/vi/Pcd1ii9P9ZI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/27.webp" 
    alt="A soft, radiant element being gently pulled away from a sequence, leaving a streamlined flow."
    caption="Solution to LeetCode 27: Remove Element Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val. Modify the array nums such that the first k elements contain the elements which are not equal to val, and the remaining elements of nums are not important. Return k.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer val.
- **Example:** `For example, nums = [4, 1, 1, 4], val = 4.`
- **Constraints:**
	- 0 <= nums.length <= 100
	- 0 <= nums[i] <= 50
	- 0 <= val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer k, the number of elements in nums which are not equal to val. The first k elements in the array nums must be the elements that are not equal to val, and the order of these elements can be altered.
- **Example:** `For nums = [4, 1, 1, 4], val = 4, the output is 2, with nums = [1, 1, _, _].`
- **Constraints:**
	- The size of nums is at most 100.
	- The value of val is between 0 and 100.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to modify the array in-place such that all elements equal to val are removed, and return the number of remaining elements that are not equal to val.

- 1. Initialize an index pointer i to 0.
- 2. Traverse the array nums, and for each element not equal to val, place it in the position indicated by the index pointer i and increment i.
- 3. Return i as the number of elements not equal to val.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [4, 1, 1, 4], val = 4, the output is 2, with nums = [1, 1, _, _].`  \
  **Explanation:** We iterate over the array and shift the elements that are not equal to val to the front, resulting in the first two elements being [1, 1], and the rest of the array does not matter.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array and shifting elements that are not equal to val towards the front. This ensures that the first k elements contain the elements that are not equal to val.

### Initial Thoughts 💭
- We can modify the array in-place by maintaining an index pointer to place the non-val elements at the beginning.
- By iterating over the array and copying non-val elements to the front, we can avoid using extra space.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the output will be 0.
- Ensure the solution handles arrays with up to 100 elements efficiently.
- If all elements are equal to val, the output will be 0, and the array will be unchanged.
- The solution must modify the array in-place without allocating additional space.
{{< dots >}}
## Code 💻
```cpp
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    
    for(int node: nums)
        if(node != val)
        {
            nums[i] = node;
            i++;
        }
    
    return i;
}
```

This code removes all occurrences of a given value 'val' from a vector 'nums' and returns the new length of the vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int removeElement(vector<int>& nums, int val) {
	```
	This line declares a function named 'removeElement' that takes a vector of integers 'nums' and a target value 'val' as input and returns an integer representing the new length of the vector after removing the specified value.

2. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	This line initializes an integer variable 'i' to 0. This variable will be used as an index to keep track of the position to insert elements that are not equal to 'val'.

3. **Loop Iteration**
	```cpp
	    for(int node: nums)
	```
	This line starts a `for-each` loop to iterate through each element 'node' in the vector 'nums'.

4. **Conditional Check**
	```cpp
	        if(node != val)
	```
	This line checks if the current element 'node' is not equal to the target value 'val'.

5. **Array Manipulation**
	```cpp
	            nums[i] = node;
	```
	If the current element is not equal to 'val', it's copied to the position 'i' in the vector, effectively overwriting the previous element at that index.

6. **Index Update**
	```cpp
	            i++;
	```
	The index 'i' is incremented to point to the next position where a non-matching element should be placed.

7. **Return**
	```cpp
	    return i;
	```
	After the loop, the variable 'i' holds the new length of the vector, which is the number of elements that are not equal to 'val'. The function returns this value.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array, as we only iterate over the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as the array is modified in-place without using extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-element/description/)

---
{{< youtube Pcd1ii9P9ZI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
