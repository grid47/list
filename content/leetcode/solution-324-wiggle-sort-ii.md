
+++
authors = ["grid47"]
title = "Leetcode 324: Wiggle Sort II"
date = "2024-10-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 324: Wiggle Sort II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Greedy","Sorting","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/324.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/324.webp" 
    alt="A sequence of numbers gently oscillating, with the elements arranged to form a wiggle pattern."
    caption="Solution to LeetCode 324: Wiggle Sort II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of integers. Your task is to reorder the array such that the elements alternate between smaller and larger numbers. The sequence should follow the pattern nums[0] < nums[1] > nums[2] < nums[3] > nums[4]....
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers.
- **Example:** `nums = [3, 5, 2, 1, 6, 4]`
- **Constraints:**
	- 1 <= nums.length <= 5 * 10^4
	- 0 <= nums[i] <= 5000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the reordered array where the elements alternate between smaller and larger numbers, following the pattern nums[0] < nums[1] > nums[2] < nums[3] > nums[4]....
- **Example:** `[3, 5, 2, 6, 1, 4]`
- **Constraints:**
	- The array should be reordered in place with the alternating pattern.

{{< dots >}}
### Core Logic 🔍
**Goal:** To reorder the given array such that the elements alternate between smaller and larger numbers.

- Sort the array first.
- Rearrange the elements in the array using a two-pointer technique to achieve the alternating pattern.
- Handle the case when the array length is odd or even while ensuring the alternating condition holds.
{{< dots >}}
### Problem Assumptions ✅
- The input array is always guaranteed to have a valid answer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 5, 2, 1, 6, 4]`  \
  **Explanation:** The reordered array follows the alternating pattern: 3 < 5 > 2 < 6 > 1 < 4.

- **Input:** `nums = [2, 1, 3, 2, 1, 4]`  \
  **Explanation:** The reordered array follows the alternating pattern: 1 < 3 > 1 < 4 > 2 < 2.

{{< dots >}}
## Approach 🚀
We can solve this problem efficiently using sorting followed by a two-pointer technique to reorder the array.

### Initial Thoughts 💭
- The alternating pattern can be easily achieved by first sorting the array.
- We need to rearrange the array in a way that satisfies the alternating condition.
- Sorting the array ensures that we can easily access the smallest and largest elements to form the alternating pattern.
{{< dots >}}
### Edge Cases 🌐
- The array is guaranteed to have at least one element, so an empty array case is not possible.
- The solution should be efficient enough to handle large inputs with up to 50,000 elements.
- If the array contains repeated elements, the alternating pattern should still hold.
- Ensure the solution runs in O(n) time after sorting the array.
{{< dots >}}
## Code 💻
```cpp
void wiggleSort(vector<int>& nums) {
    
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
    
    
}
```

This function sorts an array into a 'wiggle' pattern, where for every consecutive pair, the first is less than or equal to the second, and the second is greater than or equal to the third. It uses the 'nth_element' algorithm to find the median and applies a three-pointer technique to rearrange the elements accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void wiggleSort(vector<int>& nums) {
	```
	This is the declaration of the `wiggleSort` function, which takes a reference to a vector of integers (`nums`) and rearranges the elements in a wiggle pattern.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Here, the variable `n` is initialized to store the size of the `nums` vector.

3. **Median Calculation**
	```cpp
	    auto midptr = nums.begin() + n / 2;
	```
	The pointer `midptr` is set to the middle element of the `nums` vector, which will be used to find the median.

4. **Median Calculation**
	```cpp
	    nth_element(nums.begin(), midptr, nums.end());
	```
	The `nth_element` function rearranges the elements in the vector such that the element at the middle pointer (`midptr`) is the median of the array, with all smaller elements on the left and larger ones on the right.

5. **Variable Initialization**
	```cpp
	    int mid = *midptr;
	```
	The median value (`mid`) is assigned by dereferencing the `midptr` pointer.

6. **Macro Definition**
	```cpp
	    #define A(i) nums[(1 + 2 * i) % (n|1)]
	```
	This macro defines the function `A(i)` to access the elements in a rearranged order, ensuring that the elements are accessed in a zigzag manner, alternating between odd and even indices.

7. **Variable Initialization**
	```cpp
	    int i = 0, j = 0, k = n - 1;
	```
	Here, three variables (`i`, `j`, and `k`) are initialized to represent three pointers for the rearrangement process: `i` for the leftmost part, `j` for the current element, and `k` for the rightmost part.

8. **Loop Initialization**
	```cpp
	    while(j <= k) {
	```
	This while loop continues until the `j` pointer exceeds the `k` pointer, indicating that all elements have been rearranged.

9. **Conditional Logic**
	```cpp
	        if(A(j) < mid)
	```
	In this condition, if the current element pointed to by `j` is less than the median (`mid`), it means the element should be moved to the left part of the array.

10. **Swap Operation**
	```cpp
	            swap(A(j), A(k--));
	```
	Here, the element at `A(j)` is swapped with the element at `A(k)`, and the `k` pointer is decremented to move the right pointer inward.

11. **Conditional Logic**
	```cpp
	        else if(A(j) > mid)
	```
	If the current element at `A(j)` is greater than the median (`mid`), it should be placed in the right part of the array.

12. **Swap Operation**
	```cpp
	            swap(A(i++), A(j++));
	```
	In this case, the element at `A(i)` is swapped with the element at `A(j)`, and both pointers are incremented to move inward.

13. **Conditional Logic**
	```cpp
	        else j++;
	```
	If the current element at `A(j)` is equal to the median (`mid`), we simply increment the `j` pointer to continue checking the next element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage used for the sorted array. The in-place rearrangement takes O(1) additional space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/wiggle-sort-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
