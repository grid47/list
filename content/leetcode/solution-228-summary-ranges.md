
+++
authors = ["grid47"]
title = "Leetcode 228: Summary Ranges"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 228: Summary Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/228.webp"
youtube = "ZHJDwbfqoa8"
youtube_upload_date="2024-06-24"
youtube_thumbnail="https://i.ytimg.com/vi/ZHJDwbfqoa8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/228.webp" 
    alt="A range of numbers with each segment gently highlighted, showing the summarized range."
    caption="Solution to LeetCode 228: Summary Ranges Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted array of unique integers. Your task is to group consecutive numbers into ranges and return a sorted list of these ranges. A range [a,b] includes all integers from a to b (inclusive). Each range should be represented as 'a->b' if a != b or 'a' if a == b.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A sorted array of unique integers.
- **Example:** `Input: nums = [-3,-2,-1,1,2,5]`
- **Constraints:**
	- The array length is in the range [0, 20].
	- All values in the array are unique.
	- The values are sorted in ascending order.
	- Each integer lies in the range [-2^31, 2^31 - 1].

{{< dots >}}
### Output Specifications 📤
- **Output:** A sorted list of ranges that cover all the numbers in the array exactly, with each range formatted as 'a->b' or 'a'.
- **Example:** `Output: ['-3->-1','1->2','5']`
- **Constraints:**
	- Each number in the input array must be included in exactly one range.
	- Ranges must not include any integers outside the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify consecutive sequences of numbers and group them into ranges.

- Initialize a pointer to traverse the array.
- For each element, determine the start of a range.
- Continue iterating until the end of the current range is reached (next number is not consecutive).
- Add the range to the result list in the appropriate format ('a->b' or 'a').
- Repeat until all elements are processed.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-null and adheres to the constraints.
- Consecutive values are integers differing by exactly 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1,2,3,5,7,8,10]`  \
  **Explanation:** The ranges are: [1,3] -> '1->3', [5,5] -> '5', [7,8] -> '7->8', [10,10] -> '10'. Output: ['1->3','5','7->8','10'].

- **Input:** `Input: nums = [0,2,3,6]`  \
  **Explanation:** The ranges are: [0,0] -> '0', [2,3] -> '2->3', [6,6] -> '6'. Output: ['0','2->3','6'].

{{< dots >}}
## Approach 🚀
The solution involves iterating through the array to identify consecutive sequences and recording them as ranges. A two-pointer technique can be used to determine the start and end of each range.

### Initial Thoughts 💭
- Consecutive numbers can be identified when the difference between adjacent elements is 1.
- A range can be represented compactly as 'a->b' or just 'a' if it contains a single number.
- Iterate through the array while tracking the start of each range.
- When a non-consecutive number is encountered, finalize the current range.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should return an empty result.
- The largest possible array of size 20 with mixed consecutive and non-consecutive elements.
- An array with all consecutive numbers.
- An array where no two numbers are consecutive.
- Ensure no ranges extend beyond the given numbers.
{{< dots >}}
## Code 💻
```cpp
vector<string> summaryRanges(vector<int>& nums) {
    
    const int size_n = nums.size();
    vector<string> res;
    if ( 0 == size_n) return res;
    for (int i = 0; i < size_n;) {
        int start = i, end = i;
        while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
        if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else res.push_back(to_string(nums[start]));
        i = end+1;
    }
    return res;
    
}
```

This function takes a sorted array of integers and returns a summary of ranges where consecutive numbers appear, using the format 'start->end'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> summaryRanges(vector<int>& nums) {
	```
	Defines the function `summaryRanges` that takes a reference to a vector of integers and returns a vector of strings representing consecutive ranges.

2. **Variable Initialization**
	```cpp
	    const int size_n = nums.size();
	```
	Gets the size of the input vector `nums` and stores it in `size_n` for later use.

3. **Result Container**
	```cpp
	    vector<string> res;
	```
	Initializes an empty vector `res` to store the resulting summary ranges.

4. **Edge Case Check**
	```cpp
	    if ( 0 == size_n) return res;
	```
	Checks if the input vector is empty; if so, returns an empty result vector.

5. **Main Loop**
	```cpp
	    for (int i = 0; i < size_n;) {
	```
	Starts a loop to iterate over the elements of `nums`.

6. **Range Initialization**
	```cpp
	        int start = i, end = i;
	```
	Initializes two variables `start` and `end` to the current index `i`. These will track the beginning and end of a consecutive range.

7. **Range Expansion**
	```cpp
	        while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
	```
	Expands the `end` pointer to include consecutive numbers in the range.

8. **Range Formatting**
	```cpp
	        if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
	```
	If a range of consecutive numbers is found, adds the formatted range (e.g., 'start->end') to the result vector.

9. **Single Number Case**
	```cpp
	        else res.push_back(to_string(nums[start]));
	```
	If no range is found (i.e., the number is isolated), adds the number as a single element string to the result.

10. **Advance Index**
	```cpp
	        i = end+1;
	```
	Moves the index `i` to the next number after the current range.

11. **Return Result**
	```cpp
	    return res;
	```
	Returns the vector `res`, which contains the summary of ranges as strings.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each element is visited exactly once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

No additional space is required beyond the result list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/summary-ranges/description/)

---
{{< youtube ZHJDwbfqoa8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
