
+++
authors = ["grid47"]
title = "Leetcode 1287: Element Appearing More Than 25% In Sorted Array"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1287: Element Appearing More Than 25% In Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "G74W8v2yVjY"
youtube_upload_date="2020-01-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/G74W8v2yVjY/maxresdefault.webp"
comments = true
+++



---
Given a sorted integer array, find and return the integer that occurs more than 25% of the time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array sorted in non-decreasing order.
- **Example:** `Input: arr = [1,2,2,6,6,6,6,7,10]`
- **Constraints:**
	- 1 <= arr.length <= 104
	- 0 <= arr[i] <= 105

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return the integer that appears more than 25% of the time in the array.
- **Example:** `Output: 6`
- **Constraints:**
	- It is guaranteed that exactly one integer will appear more than 25% of the time.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the element that appears more than 25% of the time in the array.

- Traverse through the array to count the frequency of each integer.
- Check if any integer appears more than one-fourth of the array length.
- Return the integer that satisfies the condition.
{{< dots >}}
### Problem Assumptions ✅
- The input array is already sorted in non-decreasing order.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [1,2,2,6,6,6,6,7,10]`  \
  **Explanation:** In this case, the integer '6' appears 4 times, which is more than 25% of the length of the array, so the function returns '6'.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to count the occurrences of each integer in the array and check if any integer appears more than 25% of the time.

### Initial Thoughts 💭
- Since the array is sorted, repeated elements will be adjacent to each other, making it easier to count occurrences.
- A hashmap or simple iteration through the array could be used to count the occurrences of each integer.
{{< dots >}}
### Edge Cases 🌐
- An empty array will never occur since the minimum length of the array is 1.
- The solution should efficiently handle arrays with lengths up to 10^4.
- In the case where all elements are the same, that element will automatically be the result.
- Since exactly one element appears more than 25% of the time, there are no corner cases where no element satisfies the condition.
{{< dots >}}
## Code 💻
```cpp
	int findSpecialInteger(vector<int>& arr) {
		unordered_map<int, int> m;
		for(int i = 0; i < arr.size(); i++){
			m[arr[i]]++;
		}
		for(auto i : m){
			if(i.second > arr.size() / 4){
				return i.first;
			}
		}
		return arr[0];
	}
```

This function finds the integer that appears more than 25% of the time in a sorted array using a frequency map and a linear scan.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
		int findSpecialInteger(vector<int>& arr) {
	```
	Defines a function to find the special integer that appears more than 25% of the time.

2. **Data Structure**
	```cpp
			unordered_map<int, int> m;
	```
	Declares an unordered map to store the frequency of each integer in the array.

3. **Loop Start**
	```cpp
			for(int i = 0; i < arr.size(); i++){
	```
	Iterates through the array to populate the frequency map.

4. **Increment Frequency**
	```cpp
				m[arr[i]]++;
	```
	Increments the count of the current integer in the frequency map.

5. **Check Frequencies**
	```cpp
			for(auto i : m){
	```
	Iterates through the frequency map to find the special integer.

6. **Condition Check**
	```cpp
				if(i.second > arr.size() / 4){
	```
	Checks if the current integer's frequency exceeds 25% of the array size.

7. **Return Value**
	```cpp
					return i.first;
	```
	Returns the integer if it satisfies the condition.

8. **Default Return**
	```cpp
			return arr[0];
	```
	Returns the first element as a default value if no special integer is found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - The best case is when the array is short and the element is immediately found.
- **Average Case:** O(n) - In the average case, we iterate through the entire array to count occurrences.
- **Worst Case:** O(n) - The worst case involves iterating through the entire array and counting all frequencies.

The time complexity is O(n) because we have to process each element in the array.

### Space Complexity 💾
- **Best Case:** O(1) - If only one unique element appears, the space required will be minimal.
- **Worst Case:** O(n) - The worst case occurs when all elements in the array are unique, so we store the frequency of all elements.

The space complexity is O(n) in the worst case because we need to store the frequency of each element in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/)

---
{{< youtube G74W8v2yVjY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
