
+++
authors = ["grid47"]
title = "Leetcode 1079: Letter Tile Possibilities"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1079: Letter Tile Possibilities in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a string tiles containing uppercase English letters, where each letter represents a tile. You need to return the number of distinct non-empty sequences of letters that can be formed by selecting tiles from the string. A sequence can be formed by selecting tiles in any order and any number of times, but no tile can be used more than once in a sequence.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string tiles, consisting of uppercase English letters.
- **Example:** `Input: tiles = "ABAC"`
- **Constraints:**
	- 1 <= tiles.length <= 7
	- tiles consists of uppercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the number of distinct non-empty sequences that can be formed from the tiles.
- **Example:** `Output: 12`
- **Constraints:**
	- The number of possible distinct sequences should be computed.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the number of distinct non-empty sequences that can be formed from the given string of tiles.

- 1. Generate all possible non-empty subsequences of the input string.
- 2. Use a set to keep track of distinct sequences.
- 3. Ensure no tile is used more than once in any sequence.
- 4. Return the size of the set as the result.
{{< dots >}}
### Problem Assumptions ✅
- Each letter in the input string tiles can be used in any sequence, but no letter can be used more than once.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: tiles = "ABAC"`  \
  **Explanation:** The distinct sequences that can be formed are: "A", "B", "C", "AB", "AC", "BA", "BC", "AA", "ABAC", "ACA", "BCA", and "AAB". So, the output is 12.

- **Input:** `Input: tiles = "ABC"`  \
  **Explanation:** The distinct sequences that can be formed are: "A", "B", "C", "AB", "AC", "BC", and "ABC", resulting in 7 distinct sequences.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a backtracking approach to generate all possible subsequences of the given string and count the distinct ones. We use a set to ensure all subsequences are unique.

### Initial Thoughts 💭
- We can treat this as a combination problem where each letter can either be included or excluded from the subsequence.
- A set can be used to automatically handle duplicate subsequences.
- The solution will involve recursively generating subsequences and using a set to avoid counting duplicates.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return 0, as no sequences can be formed.
- The input string will not exceed 7 characters, so the solution should handle small inputs efficiently.
- If the input string consists of only one letter, the output should be 1, as there is only one possible sequence.
- The solution should work for inputs with repeated letters and handle small input sizes efficiently.
{{< dots >}}
## Code 💻
```cpp
int numTilePossibilities(string tiles) {
    set<string> ans;
    set<int> seen;

    gen(tiles, 0, "", ans, seen);
    return ans.size();
}

void gen(string tiles, int idx, string res, set<string> &ans, set<int> &vis ) {
    if(idx == tiles.size()) return;
    for(int i = 0; i < tiles.size(); i++) {
        if(!vis.count(i)) {
            vis.insert(i);
            ans.insert(res + tiles[i]);
gen(tiles, idx + 1, res + tiles[i], ans, vis);
            vis.erase(i);
        }
    }
}
```

This code defines two functions: `numTilePossibilities` calculates the number of possible distinct sequences that can be made from the tiles, and `gen` is a recursive helper function that generates these sequences.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numTilePossibilities(string tiles) {
	```
	This line defines the function `numTilePossibilities`, which takes a string `tiles` as input and returns an integer representing the number of distinct tile sequences that can be formed.

2. **Variable Initialization**
	```cpp
	    set<string> ans;
	```
	This initializes the set `ans`, which will store all distinct tile sequences generated.

3. **Set Initialization**
	```cpp
	    set<int> seen;
	```
	This initializes the set `seen`, which will keep track of which tiles have been used during the sequence generation to avoid duplicates.

4. **Call to gen Function**
	```cpp
	    gen(tiles, 0, "", ans, seen);
	```
	This calls the recursive function `gen`, passing the initial state of the variables: the tiles string, an index starting from 0, an empty string for the current sequence, the `ans` set to store results, and the `seen` set to track used tiles.

5. **Return Statement**
	```cpp
	    return ans.size();
	```
	This returns the size of the set `ans`, which contains all distinct sequences generated.

6. **Recursive Function Definition**
	```cpp
	void gen(string tiles, int idx, string res, set<string> &ans, set<int> &vis ) {
	```
	This line defines the recursive function `gen`, which takes the current state of the tiles, the index, the current sequence, the set of results `ans`, and the set of visited tiles `vis`.

7. **Base Case**
	```cpp
	    if(idx == tiles.size()) return;
	```
	This is the base case of the recursion. If the index `idx` reaches the size of `tiles`, the function returns without doing anything further.

8. **Loop Over Tiles**
	```cpp
	    for(int i = 0; i < tiles.size(); i++) {
	```
	This loop iterates over each tile in the `tiles` string.

9. **Check if Tile is Used**
	```cpp
	        if(!vis.count(i)) {
	```
	This checks if the tile at index `i` has already been used in the current sequence by checking the `vis` set.

10. **Mark Tile as Used**
	```cpp
	            vis.insert(i);
	```
	This marks the tile at index `i` as used by inserting it into the `vis` set.

11. **Add Sequence to Result Set**
	```cpp
	            ans.insert(res + tiles[i]);
	```
	This adds the new sequence, formed by appending the current tile to the current result string `res`, to the `ans` set.

12. **Recursive Call**
	```cpp
	gen(tiles, idx + 1, res + tiles[i], ans, vis);
	```
	This makes the recursive call to generate further sequences, incrementing the index `idx` and appending the current tile to the sequence.

13. **Unmark Tile as Used**
	```cpp
	            vis.erase(i);
	```
	This unmarks the tile at index `i` as used by removing it from the `vis` set, allowing it to be reused in other branches of the recursion.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n!)
- **Average Case:** O(n!)
- **Worst Case:** O(n!)

The time complexity is dominated by the need to generate all possible subsequences, where n is the length of the input string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(2^n)

The space complexity is O(2^n) due to the set storing all distinct subsequences. The worst case occurs when all subsequences are distinct.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/letter-tile-possibilities/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
