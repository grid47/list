
+++
authors = ["grid47"]
title = "Leetcode 398: Random Pick Index"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 398: Random Pick Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Reservoir Sampling","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/398.webp"
youtube = "1rDRyxPcmvY"
youtube_upload_date="2020-03-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1rDRyxPcmvY/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/398.webp" 
    alt="A series of indices being selected randomly, with each chosen index softly glowing."
    caption="Solution to LeetCode 398: Random Pick Index Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array `nums` with potential duplicates, you need to randomly select an index `i` where `nums[i] == target`. If there are multiple indices with the same value, the selection should be made with equal probability for each valid index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers `nums` and a target integer. The target integer is guaranteed to exist in the array.
- **Example:** `Input: [4, 3, 2, 3, 5], target: 3`
- **Constraints:**
	- 1 <= nums.length <= 2 * 10^4
	- -2^31 <= nums[i] <= 2^31 - 1
	- At most 10^4 calls will be made to `pick`.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the randomly selected index where `nums[i] == target`. If there are multiple indices with the same value, the selection should be random.
- **Example:** `Output: 3`
- **Constraints:**
	- The function must return an index where `nums[i] == target`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to select a random index where the value matches the target. If there are multiple valid indices, ensure equal probability for all of them.

- Store the indices of all occurrences of each number in the array.
- When `pick(target)` is called, randomly select an index from the stored list of indices for that number.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` will contain at least one occurrence of the target number when `pick(target)` is called.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [4, 3, 2, 3, 5], target: 3`  \
  **Explanation:** In this case, there are two occurrences of the number 3 (at indices 1 and 3), and the function `pick(3)` can randomly return either 1 or 3 with equal probability.

- **Input:** `Input: [1, 1, 2, 2, 3, 3], target: 2`  \
  **Explanation:** There are two occurrences of the number 2 (at indices 2 and 3), and the function `pick(2)` can randomly return either 2 or 3 with equal probability.

{{< dots >}}
## Approach 🚀
The approach involves creating a map that stores the indices of each number in the array. When `pick(target)` is called, the list of indices for the target number is accessed and a random index is selected from the list.

### Initial Thoughts 💭
- The key challenge is to ensure that all indices of the target number are selected with equal probability.
- Using a hash map to store the indices of each number will allow for efficient lookup and random selection.
{{< dots >}}
### Edge Cases 🌐
- An empty array is not possible since the problem guarantees that `target` exists in `nums`.
- Ensure the solution handles arrays with up to 20,000 elements efficiently.
- Handle arrays where all elements are the same number, as the function should still select a random index from the array.
- Ensure that the random selection of indices is efficient and can handle up to 10^4 calls to `pick`.
{{< dots >}}
## Code 💻
```cpp
class Solution {
unordered_map<int, vector<int>> mp;
public:
Solution(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++)
    mp[nums[i]].push_back(i);
}

int pick(int target) { 
    int sz = mp[target].size();
    int res = mp[target][rand()%sz];
    return res;
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
```

The `Solution` class implements a way to pick a random index of a given `target` number in a vector `nums`. It stores indices of each number in an unordered map for efficient lookup and retrieval. The `pick` method randomly selects one of these indices for the given target.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	The class `Solution` is defined to solve the problem of randomly picking an index for a target number from a given list of numbers.

2. **Data Structure Initialization**
	```cpp
	unordered_map<int, vector<int>> mp;
	```
	An unordered map `mp` is declared, where the key is an integer (the target number) and the value is a vector of indices where the target appears in the list.

3. **Constructor**
	```cpp
	public:
	```
	The `public` access modifier is used to allow public access to the methods of the class.

4. **Constructor**
	```cpp
	Solution(vector<int>& nums) {
	```
	The constructor `Solution` initializes the object by accepting a vector of integers `nums` and populating the map `mp` with the indices of each number.

5. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	The size of the input vector `nums` is stored in the variable `n`.

6. **Map Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A loop is run to iterate over each element in the vector `nums`.

7. **Map Population**
	```cpp
	    mp[nums[i]].push_back(i);
	```
	For each number in `nums`, its index `i` is pushed into the vector corresponding to the number in the unordered map `mp`.

8. **Pick Method Definition**
	```cpp
	int pick(int target) { 
	```
	The `pick` method is defined to randomly select an index from the vector of indices corresponding to the `target` number.

9. **Size Calculation**
	```cpp
	    int sz = mp[target].size();
	```
	The size of the vector corresponding to the `target` in the map `mp` is calculated and stored in the variable `sz`.

10. **Random Index Selection**
	```cpp
	    int res = mp[target][rand()%sz];
	```
	A random index from the vector `mp[target]` is selected using the `rand()` function. The modulo operation ensures the index is within bounds of the vector size.

11. **Return Random Index**
	```cpp
	    return res;
	```
	The randomly selected index `res` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Both the initialization of the map and the `pick(target)` method have constant time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear, as we store a list of indices for each unique number in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/random-pick-index/description/)

---
{{< youtube 1rDRyxPcmvY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
