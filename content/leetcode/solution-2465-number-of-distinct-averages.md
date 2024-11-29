
+++
authors = ["grid47"]
title = "Leetcode 2465: Number of Distinct Averages"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2465: Number of Distinct Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2sWoLnBzuKw"
youtube_upload_date="2022-11-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2sWoLnBzuKw/maxresdefault.webp"
comments = true
+++



---
You are given an array of even length containing integers. In each step, repeatedly remove the smallest and the largest numbers from the array, calculate their average, and continue until the array is empty. The goal is to find how many distinct averages were calculated during this process.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers called 'nums', where the length of 'nums' is always even.
- **Example:** `nums = [3, 8, 1, 6, 5, 7]`
- **Constraints:**
	- 2 <= nums.length <= 100
	- nums.length is even.
	- 0 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct averages calculated as per the process described.
- **Example:** `For nums = [3, 8, 1, 6, 5, 7], the output is 3.`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the number of distinct averages by following the rule of removing the smallest and largest elements, calculating their average, and repeating until the list is empty.

- Sort the array to easily access the minimum and maximum values.
- Remove the smallest and largest values from the array, calculate their average, and store the average in a set to ensure uniqueness.
- Repeat the process until the array is empty.
- Return the size of the set containing distinct averages.
{{< dots >}}
### Problem Assumptions ✅
- The length of the array is always even, so there will always be an even number of elements to pair up.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [3, 8, 1, 6, 5, 7]`  \
  **Explanation:** In the first step, we remove 1 (min) and 8 (max), calculating their average 4.5. In the second step, we remove 3 (min) and 7 (max), calculating 5. Then, we remove 5 (min) and 6 (max), calculating 5.5. There are 3 distinct averages: 4.5, 5, and 5.5.

{{< dots >}}
## Approach 🚀
Sort the array and repeatedly remove the smallest and largest elements to compute the averages. Use a set to store the averages and return the size of the set.

### Initial Thoughts 💭
- Sorting the array simplifies accessing the minimum and maximum values.
- Using a set is crucial for ensuring uniqueness of averages.
{{< dots >}}
### Edge Cases 🌐
- The array will always have an even length and at least two elements.
- Ensure the solution can handle arrays of length up to 100.
- When all elements in the array are the same, all averages will be the same.
- The array will always have an even length.
{{< dots >}}
## Code 💻
```cpp
int distinctAverages(vector<int>& nums) {
    map<long, int> mp;
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while(i < j){
        int a = nums[j--];
        int b = nums[i++];
        long c = a + b;
        mp[c] = 1;
    }
    return mp.size();
}
```

This function calculates the number of distinct averages of pairs formed by summing the largest and smallest numbers in a sorted array. It uses a map to track unique sums and returns the map size as the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int distinctAverages(vector<int>& nums) {
	```
	Defines a function to calculate distinct averages from the input vector `nums`.

2. **Map Initialization**
	```cpp
	    map<long, int> mp;
	```
	Initializes a map to store unique sums of pairs.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input array in ascending order to easily pair smallest and largest numbers.

4. **Variable Initialization**
	```cpp
	    int i = 0, j = nums.size() - 1;
	```
	Initializes two pointers `i` and `j` to point to the smallest and largest elements in the array.

5. **Loop**
	```cpp
	    while(i < j){
	```
	Begins a loop to pair the smallest and largest elements until the pointers meet.

6. **Element Access**
	```cpp
	        int a = nums[j--];
	```
	Retrieves the largest element and decrements the pointer `j`.

7. **Element Access**
	```cpp
	        int b = nums[i++];
	```
	Retrieves the smallest element and increments the pointer `i`.

8. **Sum Calculation**
	```cpp
	        long c = a + b;
	```
	Calculates the sum of the smallest and largest elements.

9. **Map Insertion**
	```cpp
	        mp[c] = 1;
	```
	Stores the sum in the map, ensuring uniqueness.

10. **Result**
	```cpp
	    return mp.size();
	```
	Returns the number of unique sums stored in the map.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the array takes O(n log n) time, and the subsequent process of removing elements and calculating averages is O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the set of averages.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-distinct-averages/description/)

---
{{< youtube 2sWoLnBzuKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
