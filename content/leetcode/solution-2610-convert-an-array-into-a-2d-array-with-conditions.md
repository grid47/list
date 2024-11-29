
+++
authors = ["grid47"]
title = "Leetcode 2610: Convert an Array Into a 2D Array With Conditions"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2610: Convert an Array Into a 2D Array With Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9pl1QiaGgmI"
youtube_upload_date="2024-01-02"
youtube_thumbnail="https://i.ytimg.com/vi/9pl1QiaGgmI/maxresdefault.jpg"
comments = true
+++



---
Given an integer array, your task is to create a 2D array from the input array satisfying the following conditions:
1. The 2D array should contain all the elements of the input array.
2. Each row of the 2D array should contain distinct integers.
3. The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple valid answers, return any of them.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers nums. The array consists of integers, and some integers may appear more than once.
- **Example:** `nums = [3, 1, 2, 3, 1, 4, 2]`
- **Constraints:**
	- 1 <= nums.length <= 200
	- 1 <= nums[i] <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D array where each row contains distinct integers and all elements of the input array are used. The number of rows should be minimal.
- **Example:** `Output: [[3, 1, 2, 4], [3, 1], [2]]`
- **Constraints:**
	- The output should be a valid 2D array where each row contains distinct integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to arrange the elements of the input array into a minimal 2D array where each row contains distinct integers and all the elements of the input array are used.

- Count the frequency of each integer in the input array.
- Create a 2D array where each row contains distinct integers from the input array.
- Ensure that each row has as few elements as possible while still containing distinct integers.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains integers that may repeat.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 3, 4, 1, 2, 3, 1]`  \
  **Explanation:** We can create a 2D array like [[1, 3, 4, 2], [1, 3], [1]], where each row contains distinct integers, and all elements of the array are used.

- **Input:** `nums = [1, 2, 3, 4]`  \
  **Explanation:** Since all integers are distinct, we can simply place all of them in the first row, resulting in [[4, 3, 2, 1]].

{{< dots >}}
## Approach 🚀
To solve this problem, we need to group repeated numbers into rows and ensure that each row has distinct integers, while minimizing the number of rows.

### Initial Thoughts 💭
- We need to find the frequency of each integer in the input array and ensure that each integer appears in a different row for each repetition.
- A possible approach is to first calculate the frequency of each number in the array. Then, we can iterate through the array and add the number to different rows based on how many times it appears.
{{< dots >}}
### Edge Cases 🌐
- An empty array should return an empty 2D array.
- For larger input arrays, ensure the algorithm handles the size within the given constraints.
- Arrays with only distinct values will have a single row, containing all elements.
- Handle arrays with a mix of unique and repeated values efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> findMatrix(vector<int>& nums) {
    map<int, int> mp;
    int mx = 0;
    for(int x: nums) {
        mp[x]++;
        mx = max(mp[x], mx);
    }
    vector<vector<int>> grid(mx);
    for(auto it: mp) {
        for(int i = 0; i < it.second; i++) {
            grid[i].push_back(it.first);
        }
    }
    return grid;
}
```

This function takes a vector of integers and returns a 2D grid where each column contains occurrences of integers from the input vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> findMatrix(vector<int>& nums) {
	```
	Defines the function that takes a reference to a vector of integers and returns a 2D vector of integers.

2. **Variable Declaration**
	```cpp
	    map<int, int> mp;
	```
	Declares a map to store the frequency of each integer from the input vector.

3. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	Initializes the variable 'mx' to keep track of the maximum frequency of any number in the input vector.

4. **Loop - Iteration**
	```cpp
	    for(int x: nums) {
	```
	Starts a loop to iterate through each integer 'x' in the input vector.

5. **Map Update**
	```cpp
	        mp[x]++;
	```
	Increments the frequency count of the integer 'x' in the map.

6. **Maximum Frequency Update**
	```cpp
	        mx = max(mp[x], mx);
	```
	Updates the maximum frequency 'mx' if the frequency of the current integer 'x' is greater.

7. **Grid Initialization**
	```cpp
	    vector<vector<int>> grid(mx);
	```
	Initializes a 2D vector 'grid' with 'mx' rows to hold the elements grouped by their frequencies.

8. **Loop - Mapping Elements**
	```cpp
	    for(auto it: mp) {
	```
	Starts a loop to iterate through each key-value pair in the map 'mp'.

9. **Inner Loop - Frequency Processing**
	```cpp
	        for(int i = 0; i < it.second; i++) {
	```
	Starts an inner loop to iterate based on the frequency of the current element.

10. **Grid Update**
	```cpp
	            grid[i].push_back(it.first);
	```
	Adds the current integer (it.first) to the corresponding row in the 'grid'.

11. **Return Statement**
	```cpp
	    return grid;
	```
	Returns the 2D grid containing the elements grouped by their frequencies.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the input array as we iterate through the array to count the frequency and then create the 2D array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear as we store the frequency of the elements and the 2D array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/)

---
{{< youtube 9pl1QiaGgmI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
