
+++
authors = ["grid47"]
title = "Leetcode 2780: Minimum Index of a Valid Split"
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2780: Minimum Index of a Valid Split in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qhvhUTBnYd8"
youtube_upload_date="2023-07-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qhvhUTBnYd8/maxresdefault.webp"
comments = true
+++



---
Given a 0-indexed integer array nums of length n, an element x in nums is called dominant if freq(x) * 2 > n, where freq(x) is the number of occurrences of x in nums. It is guaranteed that nums contains exactly one dominant element. You can split nums into two non-empty subarrays at an index i such that the dominant element of the entire array is also the dominant element of both subarrays. Find the minimum index i where this condition holds, or return -1 if no such index exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array nums with a single dominant element.
- **Example:** `nums = [4, 5, 5, 5, 7, 5]`
- **Constraints:**
	- 1 <= nums.length <= 100,000
	- 1 <= nums[i] <= 1,000,000,000
	- nums contains exactly one dominant element.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum index where the array can be split such that both subarrays share the same dominant element. Return -1 if no valid split exists.
- **Example:** `Output: 3`
- **Constraints:**
	- Output is an integer.
	- If no split exists, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the smallest index i where nums can be split into two subarrays that both retain the dominant element.

- Count the frequency of each element to identify the dominant element in nums.
- Track the cumulative frequency of the dominant element as you iterate through nums.
- For each potential split point i, calculate the frequency of the dominant element in both subarrays.
- Check if the dominant element satisfies the dominance condition in both subarrays.
- Return the smallest index i that meets the criteria or -1 if no valid split exists.
{{< dots >}}
### Problem Assumptions ✅
- The array is not empty.
- There is exactly one dominant element in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 4, 4, 5, 6, 4]`  \
  **Explanation:** The dominant element is 4. The array can be split at index 2 into subarrays [4, 4, 4] and [5, 6, 4]. Both subarrays have the same dominant element, 4. Minimum valid split index is 2.

- **Input:** `nums = [2, 3, 3, 3, 4, 3, 3]`  \
  **Explanation:** The dominant element is 3. The array can be split at index 3 into subarrays [2, 3, 3, 3] and [4, 3, 3]. Both subarrays have the same dominant element, 3. Minimum valid split index is 3.

{{< dots >}}
## Approach 🚀
Utilize a frequency map to identify the dominant element, then iterate through the array to find the smallest valid split index based on the cumulative frequencies of the dominant element in the left and right subarrays.

### Initial Thoughts 💭
- A valid split requires that the dominant element satisfies the dominance condition in both subarrays.
- We need to track the cumulative frequency of the dominant element in the left and right subarrays dynamically.
- The problem can be solved efficiently with a single traversal of the array after determining the dominant element.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the array is guaranteed to have at least one element.
- Arrays with maximum length (100,000) and elements with large values.
- Arrays where all elements are the same.
- Arrays where the dominant element occurs at the beginning or the end.
- Ensure the algorithm handles large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimumIndex(vector<int>& nums) {
    map<int, int> mp;
    int n = nums.size();
    int dom = -1;
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
        if(2 * mp[nums[i]] > n) {
            dom = nums[i];
        }
    }
    
    int frq = mp[dom];
    
    int l = 0, r = frq;
    
    for(int i = 0; i < n - 1; i++) {
        if(nums[i] == dom) {
            l++;
            r--;
        }
        if(2 * l > (i + 1) && 2 * r > (n - (i + 1)))
            return i;
    }
    return -1;
}
```

The function `minimumIndex` calculates the minimum index where the frequency of a dominant number's occurrences in the array splits the array into two parts, with each part containing more than half the elements as the dominant number. The function uses a map to track frequencies and a two-pointer approach to find the suitable index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumIndex(vector<int>& nums) {
	```
	This line defines the function `minimumIndex` which takes a vector of integers `nums` and returns an integer representing the index where a specific condition holds for a dominant number.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	This line initializes a map `mp` to keep track of the frequency of each number in the array `nums`.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Here, `n` stores the size of the `nums` array, which will be used to determine the array's length for further operations.

4. **Variable Initialization**
	```cpp
	    int dom = -1;
	```
	The variable `dom` is initialized to -1 and will be used to store the dominant number if found during iteration.

5. **Looping**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This for-loop iterates over the entire `nums` array to calculate the frequency of each number and determine the dominant number.

6. **Frequency Update**
	```cpp
	        mp[nums[i]]++;
	```
	For each element `nums[i]`, the frequency in the map `mp` is incremented.

7. **Conditional Check**
	```cpp
	        if(2 * mp[nums[i]] > n) {
	```
	This condition checks if the frequency of the current number is greater than half of the total number of elements. If true, it updates `dom` to be the current number.

8. **Variable Assignment**
	```cpp
	            dom = nums[i];
	```
	The variable `dom` is assigned the current number `nums[i]` if the condition holds, meaning this number becomes the dominant number.

9. **Frequency Lookup**
	```cpp
	    int frq = mp[dom];
	```
	Here, the frequency of the dominant number `dom` is stored in the variable `frq` for later use.

10. **Variable Initialization**
	```cpp
	    int l = 0, r = frq;
	```
	The variables `l` and `r` are initialized to 0 and `frq`, respectively. They will represent the left and right boundaries around the dominant number.

11. **Looping**
	```cpp
	    for(int i = 0; i < n - 1; i++) {
	```
	This for-loop iterates over the `nums` array again, excluding the last element, to determine where the dominance splits the array.

12. **Conditional Check**
	```cpp
	        if(nums[i] == dom) {
	```
	This condition checks if the current element `nums[i]` is equal to the dominant number `dom`.

13. **Left Boundary Update**
	```cpp
	            l++;
	```
	If the current element is equal to `dom`, `l` is incremented, indicating an additional occurrence of the dominant number on the left side.

14. **Right Boundary Update**
	```cpp
	            r--;
	```
	If the current element is equal to `dom`, `r` is decremented, indicating a reduction in the remaining occurrences of the dominant number on the right side.

15. **Dominance Check**
	```cpp
	        if(2 * l > (i + 1) && 2 * r > (n - (i + 1)))
	```
	This condition checks if both sides of the array have more than half of the total elements as the dominant number. If true, the current index `i` is returned.

16. **Return Statement**
	```cpp
	            return i;
	```
	If the dominance condition is met, the function returns the current index `i`, which is the point where the dominance splits the array.

17. **Return Statement**
	```cpp
	    return -1;
	```
	If no suitable index is found where the array can be split with dominance, the function returns -1, indicating no solution.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves two passes over the array: one to calculate frequencies and another to check split validity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(u)

Space depends on the number of unique elements u in the array for the frequency map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-index-of-a-valid-split/description/)

---
{{< youtube qhvhUTBnYd8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
