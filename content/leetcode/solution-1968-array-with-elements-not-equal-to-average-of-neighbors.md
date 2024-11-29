
+++
authors = ["grid47"]
title = "Leetcode 1968: Array With Elements Not Equal to Average of Neighbors"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1968: Array With Elements Not Equal to Average of Neighbors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Wmb3YdVYfqM"
youtube_upload_date="2021-08-15"
youtube_thumbnail="https://i.ytimg.com/vi/Wmb3YdVYfqM/maxresdefault.jpg"
comments = true
+++



---
You are given an array `nums` containing distinct integers. You need to rearrange the elements of the array such that no element is equal to the average of its two adjacent elements. Specifically, for every index `i` (1 <= i < nums.length - 1), the condition `(nums[i-1] + nums[i+1]) / 2 != nums[i]` should hold. Your task is to return any valid rearrangement of `nums` that satisfies this condition.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array `nums` containing distinct integers.
- **Example:** `nums = [1, 2, 3, 4, 5]`
- **Constraints:**
	- 3 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^5
	- nums contains distinct integers

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a rearranged array where no element is the average of its neighbors.
- **Example:** `Output: [1, 2, 4, 5, 3]`
- **Constraints:**
	- The output should be a valid rearrangement of the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rearrange the array such that no element is the average of its adjacent elements.

- Step 1: Sort the input array.
- Step 2: Split the sorted array into two halves: one with smaller elements and the other with larger elements.
- Step 3: Interleave elements from the two halves to ensure that no element is the average of its neighbors.
{{< dots >}}
### Problem Assumptions ✅
- The input array always contains distinct integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3, 4, 5], Output: [1, 2, 4, 5, 3]`  \
  **Explanation:** In this example, we rearrange the elements such that no element is equal to the average of its neighbors. For instance, when i=2, nums[i]=4, and the average of its neighbors is (2+5)/2=3.5, which is not equal to nums[i].

- **Input:** `Input: nums = [6, 2, 0, 9, 7], Output: [9, 7, 6, 2, 0]`  \
  **Explanation:** After rearranging the array, we ensure that no element is the average of its neighbors. For example, when i=2, nums[i]=6, and the average of its neighbors is (7+2)/2=4.5, which is not equal to nums[i].

{{< dots >}}
## Approach 🚀
The solution involves sorting the array, splitting it into two parts, and interleaving elements from each part to achieve the desired rearrangement.

### Initial Thoughts 💭
- The key idea is to avoid placing an element in the middle of two elements where it could be the average of its neighbors.
- By splitting the array and interleaving the elements, we can ensure that no element is the average of its adjacent ones.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least three elements, as per the problem constraints.
- The solution should efficiently handle input arrays of up to 10^5 elements.
- The input contains distinct integers, so there will be no duplicates to handle.
- The array length will always be between 3 and 10^5, and elements are distinct.
{{< dots >}}
## Code 💻
```cpp
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;
    
    
    #define A(i) nums[(1 + 2 * i) % (n|1)]
    
    int i = 0, j = 0, k = n - 1;
    
    while(j <= k) {
        if(A(j) < mid)
            swap(A(j), A(k--));
        else if(A(j) > mid)
            swap(A(i++), A(j++));
        else j++;
    }
    return nums;
}
```

This function rearranges an array such that all elements less than the median are on one side and greater elements on the other.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> rearrangeArray(vector<int>& nums) {
	```
	The function `rearrangeArray` is defined, which takes a vector of integers `nums` and rearranges it around its median.

2. **Array Size Calculation**
	```cpp
	    int n = nums.size();
	```
	The size of the input vector `nums` is stored in the variable `n`.

3. **Pointer Calculation**
	```cpp
	    auto midptr = nums.begin() + n / 2;
	```
	A pointer `midptr` is initialized to the middle element of the array.

4. **Find Median Using nth_element**
	```cpp
	    nth_element(nums.begin(), midptr, nums.end());
	```
	The `nth_element` function is used to partition the array such that the element at `midptr` is the median of the array.

5. **Extract Median Value**
	```cpp
	    int mid = *midptr;
	```
	The median value is extracted from the pointer `midptr` and stored in the variable `mid`.

6. **Macro Definition**
	```cpp
	    #define A(i) nums[(1 + 2 * i) % (n|1)]
	```
	A macro `A(i)` is defined, which calculates the position of an element in the rearranged array using a circular indexing pattern.

7. **Variable Initialization**
	```cpp
	    int i = 0, j = 0, k = n - 1;
	```
	The variables `i`, `j`, and `k` are initialized. `i` and `j` are used to track the current positions in the array, while `k` tracks the rightmost position.

8. **Loop Start**
	```cpp
	    while(j <= k) {
	```
	A while loop starts, which continues until the `j` pointer exceeds `k`.

9. **Check Value Less Than Median**
	```cpp
	        if(A(j) < mid)
	```
	If the element at position `A(j)` is less than the median, the element is swapped with the element at position `A(k)`.

10. **Swap Less Than Median**
	```cpp
	            swap(A(j), A(k--));
	```
	The elements at positions `A(j)` and `A(k)` are swapped, and `k` is decremented.

11. **Check Value Greater Than Median**
	```cpp
	        else if(A(j) > mid)
	```
	If the element at position `A(j)` is greater than the median, the element is swapped with the element at position `A(i)`.

12. **Swap Greater Than Median**
	```cpp
	            swap(A(i++), A(j++));
	```
	The elements at positions `A(i)` and `A(j)` are swapped, and both `i` and `j` are incremented.

13. **Move to Next Element**
	```cpp
	        else j++;
	```
	If the element at position `A(j)` is equal to the median, `j` is incremented.

14. **Return Rearranged Array**
	```cpp
	    return nums;
	```
	The rearranged array `nums` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n). The rest of the steps (splitting and merging) take linear time, O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the input array and temporary variables during the sorting and merging process.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/)

---
{{< youtube Wmb3YdVYfqM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
