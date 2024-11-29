
+++
authors = ["grid47"]
title = "Leetcode 2731: Movement of Robots"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2731: Movement of Robots in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Brainteaser","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "L86PHNze5RM"
youtube_upload_date="2023-06-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/L86PHNze5RM/maxresdefault.webp"
comments = true
+++



---
A number of robots are standing on an infinite number line with their initial positions given in the array `nums`. Each robot will move based on a command string `s` where 'L' means left and 'R' means right. If two robots collide, they instantly reverse their directions. Your task is to calculate the sum of the distances between all pairs of robots `d` seconds after the command.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` representing the initial positions of robots, a string `s` representing the movement directions, and an integer `d` representing the number of seconds after the command.
- **Example:** ``nums = [2, 5, 8]`, `s = 'LLR'`, `d = 2``
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- -2 * 10^9 <= nums[i] <= 2 * 10^9
	- 0 <= d <= 10^9
	- nums.length == s.length
	- s consists of 'L' and 'R' only
	- nums[i] are unique

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of distances between all pairs of robots after `d` seconds. The result should be returned modulo 10^9 + 7.
- **Example:** `For `nums = [2, 5, 8]`, `s = 'LLR'`, and `d = 2`, the output is `24`.`
- **Constraints:**
	- The result should be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the sum of distances between all pairs of robots after moving for `d` seconds.

- For each robot, adjust its position based on its movement direction and the time `d`.
- Sort the final positions of the robots.
- For each pair of robots, calculate the absolute distance between them.
- Sum the distances and return the result modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input is always valid with no duplicates in the positions.
- The robots move in exactly one direction as specified by the string `s`.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** For `nums = [2, 5, 8]`, `s = 'LLR'`, and `d = 2`, the positions of the robots will be updated each second and we compute the sum of the distances after `d` seconds.

- **Input:** `Example 2`  \
  **Explanation:** For `nums = [1, 0]`, `s = 'RL'`, and `d = 1`, after one second, the robots are at positions `[2, -1]` and we calculate the distance between them.

{{< dots >}}
## Approach 🚀
We can first update the positions of the robots based on the time `d` and their respective directions, then calculate the sum of distances between all pairs of robots.

### Initial Thoughts 💭
- After `d` seconds, the positions of all robots will be determined.
- The sum of distances can be calculated using a sorted list of the final positions of robots.
- A direct calculation of the pairwise distances might be inefficient, so sorting the positions will help simplify the distance calculations.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the number of robots is always at least 2.
- For large inputs, we ensure the solution scales efficiently, especially with sorting and distance calculations.
- Handle cases where robots start at extreme positions or where `d = 0`.
- Ensure that the operations respect the constraints, especially the modulus for large numbers.
{{< dots >}}
## Code 💻
```cpp
int sumDistance(vector<int>& nums, string s, int d) {
    for(int i = 0; i < nums.size(); i++) {
        if(s[i] == 'L') nums[i] -= d;
        else nums[i] += d;
    }
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long ans = 0, dist = 0, mod = (int) 1e9 + 7;
    for(int i = 1; i < n; i++) {
        dist += ((long)nums[i] - nums[i - 1]) * (i);
        ans = (ans + dist) % mod;
    }
    return ans;
}
```

This function calculates the sum of the distances between elements in a vector `nums` based on a string `s` that determines whether to add or subtract a given value `d` to each element. The result is returned modulo (10^9 + 7).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumDistance(vector<int>& nums, string s, int d) {
	```
	The function `sumDistance` is defined, taking a vector of integers `nums`, a string `s`, and an integer `d` as parameters.

2. **Loop Start**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	A for-loop is started to iterate over all elements in the `nums` vector.

3. **Conditional Operation**
	```cpp
	        if(s[i] == 'L') nums[i] -= d;
	```
	If the character at index `i` in string `s` is 'L', the value at `nums[i]` is decreased by `d`.

4. **Conditional Operation**
	```cpp
	        else nums[i] += d;
	```
	Otherwise, if the character is not 'L', the value at `nums[i]` is increased by `d`.

5. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	The `nums` vector is sorted in ascending order.

6. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	The variable `n` is initialized to the size of the `nums` vector.

7. **Variable Initialization**
	```cpp
	    long long ans = 0, dist = 0, mod = (int) 1e9 + 7;
	```
	The variables `ans` (to store the final result), `dist` (to store intermediate distances), and `mod` (set to (10^9 + 7) for modulo operations) are initialized.

8. **Loop Start**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	A for-loop starts, iterating through the sorted `nums` vector from index 1 to `n-1`.

9. **Distance Calculation**
	```cpp
	        dist += ((long)nums[i] - nums[i - 1]) * (i);
	```
	The distance between the current and the previous element in the sorted vector is multiplied by the index `i`, and the result is added to `dist`.

10. **Result Update**
	```cpp
	        ans = (ans + dist) % mod;
	```
	The accumulated distance is added to the result `ans`, and the result is taken modulo `mod` to prevent overflow.

11. **Return Statement**
	```cpp
	    return ans;
	```
	The final result `ans` is returned, which is the sum of the distances modulo (10^9 + 7).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The most time-consuming step is sorting the positions, which is O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage needed for positions and other variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/movement-of-robots/description/)

---
{{< youtube L86PHNze5RM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
