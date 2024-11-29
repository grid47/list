
+++
authors = ["grid47"]
title = "Leetcode 128: Longest Consecutive Sequence"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 128: Longest Consecutive Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/128.webp"
youtube = "P6RZZMu_maU"
youtube_upload_date="2020-06-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/P6RZZMu_maU/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/128.webp" 
    alt="A smooth, radiant path showing consecutive numbers, glowing brighter as the sequence length increases."
    caption="Solution to LeetCode 128: Longest Consecutive Sequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an unsorted array of integers, return the length of the longest consecutive elements sequence.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an unsorted array of integers.
- **Example:** `[1, 2, 4, 5, 6, 3]`
- **Constraints:**
	- 0 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the length of the longest consecutive sequence in the array.
- **Example:** `6`
- **Constraints:**
	- The output will be an integer representing the length of the longest consecutive sequence.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest consecutive sequence, we need to track elements and determine the sequence length efficiently.

- 1. Insert all elements into a set for constant time lookup.
- 2. For each element, check if it is the start of a new sequence by checking if the previous element (element - 1) is not in the set.
- 3. If it is the start of a sequence, continue checking for consecutive elements by incrementing the current element and counting the sequence length.
- 4. Track the maximum sequence length found.
{{< dots >}}
### Problem Assumptions ✅
- The input array may contain duplicate values which should not affect the length of the longest sequence.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 2, 4, 5, 6, 3]`  \
  **Explanation:** The sequence [1, 2, 3, 4, 5, 6] is the longest consecutive sequence in this array, having length 6.

- **Input:** `[10, 100, 5, 11, 6, 7]`  \
  **Explanation:** The longest consecutive sequence is [5, 6, 7, 10, 11] with length 5.

{{< dots >}}
## Approach 🚀
Use a set to store the elements for quick lookup and determine the longest consecutive sequence in linear time.

### Initial Thoughts 💭
- The problem asks for the longest consecutive sequence in an unsorted array.
- Using a set allows us to look up elements in constant time, making the solution more efficient.
- The solution involves inserting all elements into a set, then iterating through them and checking for consecutive sequences.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the longest consecutive sequence length is 0.
- The solution should handle inputs with up to 10^5 elements efficiently.
- If the input contains duplicates, they should be ignored since they do not affect the sequence length.
- The input array will contain between 0 and 10^5 elements, and the range of values will be between -10^9 and 10^9.
{{< dots >}}
## Code 💻
```cpp
int longestConsecutive(vector<int>& nums) {
    set<int> s;
    for(int x: nums)
        s.insert(x);
    if(s.empty()) return 0;
    int mx = 1;
    for(int i = 0; i < nums.size(); i++) {
        int y = nums[i];
        int c = 1;
        if(!s.count(y + 1))
        while(s.count(y - 1)) {
            c++;
            y = y -1;
            mx = max(mx, c);
        }
    }
    return mx;
}
```

This function finds the length of the longest consecutive elements sequence in an unsorted array, utilizing a set for efficient lookups.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestConsecutive(vector<int>& nums) {
	```
	Define the function `longestConsecutive` that takes a vector of integers `nums` as input.

2. **Set Initialization**
	```cpp
	    set<int> s;
	```
	Initialize an empty set `s` to store unique numbers from the input vector `nums`.

3. **Loop Iteration**
	```cpp
	    for(int x: nums)
	```
	Iterate through each element `x` in the input vector `nums`.

4. **Set Insertion**
	```cpp
	        s.insert(x);
	```
	Insert the current element `x` into the set `s`. This ensures all elements are unique.

5. **Empty Check**
	```cpp
	    if(s.empty()) return 0;
	```
	Check if the set is empty. If it is, return 0 as there are no elements to form a consecutive sequence.

6. **Variable Initialization**
	```cpp
	    int mx = 1;
	```
	Initialize the variable `mx` to 1 to keep track of the longest consecutive sequence found.

7. **Loop Iteration**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Iterate through each element of the `nums` vector again to find consecutive sequences.

8. **Element Assignment**
	```cpp
	        int y = nums[i];
	```
	Assign the current element `nums[i]` to the variable `y` for checking its consecutive sequence.

9. **Sequence Length Initialization**
	```cpp
	        int c = 1;
	```
	Initialize the counter `c` to 1 to count the current length of the consecutive sequence.

10. **Existence Check**
	```cpp
	        if(!s.count(y + 1))
	```
	Check if the next consecutive number `y + 1` does not exist in the set. If not, attempt to find the previous consecutive numbers.

11. **Loop for Consecutive Elements**
	```cpp
	        while(s.count(y - 1)) {
	```
	Enter a while loop to check if the previous consecutive number `y - 1` exists in the set.

12. **Counter Update**
	```cpp
	            c++;
	```
	Increment the counter `c` for each consecutive element found.

13. **Pointer Update**
	```cpp
	            y = y -1;
	```
	Update `y` to the previous consecutive element `y - 1`.

14. **Maximum Length Update**
	```cpp
	            mx = max(mx, c);
	```
	Update `mx` to the maximum length of consecutive sequence found so far.

15. **Return Statement**
	```cpp
	    return mx;
	```
	Return the maximum length of the longest consecutive sequence found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n), since we iterate through the array and each element is inserted and looked up in the set in constant time.
- **Worst Case:** O(n), as we always process each element once.

The time complexity is O(n) because we only process each element once and look up elements in constant time using the set.

### Space Complexity 💾
- **Best Case:** O(n), as we need a set to store the elements.
- **Worst Case:** O(n), since we store all elements in a set.

The space complexity is O(n), as we use a set to store the elements of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-consecutive-sequence/description/)

---
{{< youtube P6RZZMu_maU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
