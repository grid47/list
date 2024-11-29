
+++
authors = ["grid47"]
title = "Leetcode 2766: Relocate Marbles"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2766: Relocate Marbles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "bH2EmMR5jpU"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/bH2EmMR5jpU/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array 'nums' representing the initial positions of marbles. You are also provided with two arrays, 'moveFrom' and 'moveTo', where each step moves marbles from one position to another. After performing all the moves, return the sorted list of unique positions that have at least one marble.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the following arrays: nums (the initial marble positions), moveFrom (the positions from which marbles are moved), and moveTo (the positions to which marbles are moved).
- **Example:** `nums = [4, 5, 6, 7], moveFrom = [4, 7, 5], moveTo = [6, 8, 7]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= moveFrom.length <= 10^5
	- moveFrom.length == moveTo.length
	- 1 <= nums[i], moveFrom[i], moveTo[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sorted list of unique positions where at least one marble exists after all moves are completed.
- **Example:** `For nums = [4, 5, 6, 7], moveFrom = [4, 7, 5], moveTo = [6, 8, 7], the output is [6, 7, 8].`
- **Constraints:**
	- The output is a list of unique positions sorted in ascending order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to track all the positions where marbles are placed after each move and return the sorted list of unique positions.

- Create a set to store all occupied positions initially using the nums array.
- For each move, transfer marbles from moveFrom[i] to moveTo[i], updating the set of occupied positions.
- Finally, sort and return the positions.
{{< dots >}}
### Problem Assumptions ✅
- There will always be at least one marble in the positions specified by moveFrom during the corresponding move.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [4, 5, 6, 7], moveFrom = [4, 7, 5], moveTo = [6, 8, 7]`  \
  **Explanation:** Initially, the marbles are at positions [4, 5, 6, 7]. After each move, the marbles are relocated as described in the example. The final occupied positions are [6, 7, 8].

- **Input:** `For nums = [2, 3, 3, 6], moveFrom = [3, 2], moveTo = [4, 5]`  \
  **Explanation:** Initially, the marbles are at positions [2, 3, 3, 6]. After each move, the marbles are relocated, and the final occupied positions are [4, 5, 6].

{{< dots >}}
## Approach 🚀
The solution involves tracking the marbles' positions using a set and performing the moves sequentially while updating the set of occupied positions.

### Initial Thoughts 💭
- Using a set allows us to efficiently track unique positions occupied by marbles.
- Since we only care about unique positions, a set data structure is ideal for this problem.
{{< dots >}}
### Edge Cases 🌐
- The problem constraints ensure that nums, moveFrom, and moveTo are never empty, so no need to handle empty inputs.
- Ensure the solution can handle up to 10^5 elements in nums, moveFrom, and moveTo.
- If all marbles end up in one position, the result will be a list with just that position.
- The solution must run efficiently with time complexity close to O(n log n) due to the sorting step at the end.
{{< dots >}}
## Code 💻
```cpp
vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
    map<int, int> mp;  
    for(auto n: nums) mp[n] = 1;
    for(int i = 0; i < moveFrom.size(); ++i){
        if(mp[moveFrom[i]] && moveFrom[i] != moveTo[i]) {
            mp[moveTo[i]] = 1;  mp[moveFrom[i]] = 0;
        }
    }
    vector<int> ans;
    for(auto m: mp) if(m.second) ans.push_back(m.first);
    return ans;
}
```

This function relocates marbles from one position to another according to the `moveFrom` and `moveTo` arrays and returns the final positions of the marbles in ascending order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
	```
	Defines the function `relocateMarbles`, which takes three vectors: `nums` (initial marble positions), `moveFrom` (positions to move from), and `moveTo` (positions to move to). It returns a vector with the final positions of the marbles.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;  
	```
	Initializes a map `mp` to track the marble positions, where the key is the position and the value is a flag indicating whether the position is occupied by a marble.

3. **Mark Initial Positions**
	```cpp
	    for(auto n: nums) mp[n] = 1;
	```
	Iterates through the `nums` vector to mark all the initial marble positions in the `mp` map by setting their corresponding values to 1.

4. **Iterate Over Moves**
	```cpp
	    for(int i = 0; i < moveFrom.size(); ++i){
	```
	Starts a loop to iterate through the `moveFrom` and `moveTo` vectors, processing each pair of positions to move a marble.

5. **Check Valid Move**
	```cpp
	        if(mp[moveFrom[i]] && moveFrom[i] != moveTo[i]) {
	```
	Checks if a marble exists at the position `moveFrom[i]` and if the move is not to the same position (i.e., the `moveFrom` and `moveTo` positions are different).

6. **Update Positions**
	```cpp
	            mp[moveTo[i]] = 1;  mp[moveFrom[i]] = 0;
	```
	If the move is valid, updates the `mp` map: sets the destination position `moveTo[i]` to 1 (marble is placed there) and sets the source position `moveFrom[i]` to 0 (marble is removed).

7. **Prepare Final Answer**
	```cpp
	    vector<int> ans;
	```
	Initializes an empty vector `ans` to store the final positions of the marbles after all moves.

8. **Collect Final Positions**
	```cpp
	    for(auto m: mp) if(m.second) ans.push_back(m.first);
	```
	Iterates through the `mp` map and adds the positions (keys) that have a marble (value is 1) to the `ans` vector.

9. **Return Final Positions**
	```cpp
	    return ans;
	```
	Returns the final list of positions of the marbles in the `ans` vector, which will be in ascending order due to the map's sorting of keys.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The worst case is determined by the sorting of unique positions at the end, where n is the number of unique positions.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is determined by the set storing the unique positions, which in the worst case can store all positions from nums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/relocate-marbles/description/)

---
{{< youtube bH2EmMR5jpU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
