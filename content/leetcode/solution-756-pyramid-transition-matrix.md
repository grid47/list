
+++
authors = ["grid47"]
title = "Leetcode 756: Pyramid Transition Matrix"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 756: Pyramid Transition Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/756.webp"
youtube = "RMkh4P4h7ek"
youtube_upload_date="2019-11-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RMkh4P4h7ek/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/756.webp" 
    alt="A pyramid structure where transitions occur, with the valid transitions glowing softly as they are made."
    caption="Solution to LeetCode 756: Pyramid Transition Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are building a pyramid by stacking blocks, each represented by a color denoted by a letter. Each row above the bottom consists of one less block, centered on the row beneath. Only specific triangular patterns of blocks are allowed. A triangular pattern consists of three blocks: two at the bottom and one on top. Given the bottom row and allowed patterns, determine if it's possible to construct the pyramid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string representing the bottom row of blocks, and a list of strings representing the allowed triangular patterns.
- **Example:** `bottom = 'XYZ', allowed = ['XZZ', 'XYZ', 'ZYY', 'YYY']`
- **Constraints:**
	- 2 <= bottom.length <= 6
	- 0 <= allowed.length <= 216
	- allowed[i].length == 3
	- All input letters are from the set {'A', 'B', 'C', 'D', 'E', 'F'}
	- All patterns in 'allowed' are unique

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to build the pyramid following the allowed patterns, or false otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The solution must be efficient for large inputs

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to recursively check if we can build each level of the pyramid using the allowed triangular patterns.

- 1. Start with the bottom row of blocks.
- 2. Try to form each level of the pyramid by checking the allowed patterns for every adjacent pair of blocks.
- 3. If the level cannot be constructed using the allowed patterns, return false.
- 4. Repeat the process until the pyramid is complete or return false if any level cannot be built.
{{< dots >}}
### Problem Assumptions ✅
- There are no empty patterns in the allowed list.
- All patterns in the allowed list are valid and distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: bottom = 'XYZ', allowed = ['XZZ', 'XYZ', 'ZYY', 'YYY']`  \
  **Explanation:** Start with 'XYZ'. Use 'XYZ' to form 'ZY' on the next level, then form 'Y' on the top level. All patterns are valid, so the pyramid can be built.

- **Input:** `Example 2: bottom = 'AAA', allowed = ['AAB', 'ABB', 'AAB', 'BCC']`  \
  **Explanation:** Start with 'AAA'. There are no valid patterns to form a level from 'AA', so the pyramid cannot be built.

{{< dots >}}
## Approach 🚀
The approach is to use a recursive function to check if the pyramid can be constructed level by level, verifying the allowed triangular patterns for each pair of adjacent blocks in the current row.

### Initial Thoughts 💭
- We need to recursively reduce the problem from bottom to top, checking the allowed patterns for each adjacent pair of blocks.
- We can use a hash map to store the allowed patterns for efficient look-up during the recursive checks.
{{< dots >}}
### Edge Cases 🌐
- The allowed list may be empty, in which case it's impossible to form the pyramid.
- The solution must handle the upper limit of allowed patterns efficiently.
- No special cases for the input constraints.
- The solution must handle the bottom row's length ranging from 2 to 6 and up to 216 allowed patterns.
{{< dots >}}
## Code 💻
```cpp

unordered_set<string> invalid;

  bool pyramidTransition(string bottom, vector<string>& allowed) {
  invalid.clear();
unordered_map<string, vector<char>> m;
for(auto& s:allowed) m[s.substr(0, 2)].push_back(s.back());
return helper(bottom, m, 0, "");
  }

  bool helper(string bottom, unordered_map<string, vector<char>>& m, int start, string next){

if(bottom.size() == 1) return true;
else if(invalid.find(bottom) != invalid.end()) return false;
else if(start == (int)bottom.size() - 1) {
       bool res = helper(next, m, 0, "");
       if (!res) { invalid.insert(next); }
       return res;
   }
for(char c : m[bottom.substr(start, 2)])
  if(helper(bottom, m, start+1, next+c)) return true;

return false;
  }
```

This code defines a function that checks if a pyramid can be built from a given bottom row of stones and a set of allowed stone transitions. The helper function recursively attempts to build the pyramid, verifying each transition and checking for invalid configurations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Data Structures**
	```cpp
	unordered_set<string> invalid;
	```
	Creates an unordered set 'invalid' to keep track of previously visited bottom rows to avoid cycles or redundant checks.

2. **Function Start**
	```cpp
	  bool pyramidTransition(string bottom, vector<string>& allowed) {
	```
	Begins the definition of the 'pyramidTransition' function. The function checks if a pyramid can be built based on the given bottom row and allowed stone transitions.

3. **Clear Invalid Set**
	```cpp
	  invalid.clear();
	```
	Clears the 'invalid' set to ensure no old invalid configurations are present before checking the new pyramid bottom.

4. **Mapping Transitions**
	```cpp
	unordered_map<string, vector<char>> m;
	```
	Defines an unordered map 'm' where the key is a pair of stones and the value is a list of possible stones that can be placed above the pair.

5. **Transition Mapping**
	```cpp
	for(auto& s:allowed) m[s.substr(0, 2)].push_back(s.back());
	```
	Fills the map 'm' by iterating through the allowed transitions. For each transition, it maps the first two characters of the transition to the corresponding stone that can be placed above it.

6. **Recursion**
	```cpp
	return helper(bottom, m, 0, "");
	```
	Calls the helper function to start the process of attempting to build the pyramid, beginning from the bottom and using the transition map 'm'.

7. **Helper Function Start**
	```cpp
	  bool helper(string bottom, unordered_map<string, vector<char>>& m, int start, string next){
	```
	Starts the definition of the 'helper' function. This function handles the recursive process of trying to build the pyramid from the bottom upwards.

8. **Base Case - Single Stone**
	```cpp
	if(bottom.size() == 1) return true;
	```
	Base case of the recursion. If the bottom row has only one stone, the pyramid is successfully built.

9. **Cycle Check**
	```cpp
	else if(invalid.find(bottom) != invalid.end()) return false;
	```
	Checks if the current bottom row has been processed before. If it has, the function returns false to avoid infinite recursion or redundant calculations.

10. **Recursive Step**
	```cpp
	else if(start == (int)bottom.size() - 1) {
	```
	If the current start index is the last stone in the bottom row, the function will attempt to build the next layer above it.

11. **Recursive Call**
	```cpp
	       bool res = helper(next, m, 0, "");
	```
	Recursively calls the helper function with the newly formed next layer (the stones placed above the current bottom).

12. **Memoization**
	```cpp
	       if (!res) { invalid.insert(next); }
	```
	If the recursion fails, the next layer configuration is added to the 'invalid' set to avoid future redundant checks.

13. **Return Result**
	```cpp
	       return res;
	```
	Returns the result of the recursive call, indicating whether it was possible to build the pyramid from the current bottom layer.

14. **Character Iteration**
	```cpp
	for(char c : m[bottom.substr(start, 2)])
	```
	Iterates over all possible stone transitions that can be placed above the current two stones at the 'start' position of the bottom row.

15. **Recursive Call with New Stone**
	```cpp
	  if(helper(bottom, m, start+1, next+c)) return true;
	```
	Recursively attempts to build the pyramid by adding each possible stone transition to the 'next' layer, checking if a valid configuration can be formed.

16. **Return False**
	```cpp
	return false;
	```
	If no valid configuration is found after iterating through all possible stone transitions, the function returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The solution involves checking all possible pairs at each level, leading to a time complexity proportional to the size of the bottom row and the allowed patterns.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is proportional to the number of levels in the pyramid and the number of allowed patterns.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/pyramid-transition-matrix/description/)

---
{{< youtube RMkh4P4h7ek >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
