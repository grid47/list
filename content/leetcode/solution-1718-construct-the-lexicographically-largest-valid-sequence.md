
+++
authors = ["grid47"]
title = "Leetcode 1718: Construct the Lexicographically Largest Valid Sequence"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1718: Construct the Lexicographically Largest Valid Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3kRBmhoA9b8"
youtube_upload_date="2021-01-09"
youtube_thumbnail="https://i.ytimg.com/vi/3kRBmhoA9b8/maxresdefault.jpg"
comments = true
+++



---
Given an integer `n`, find a sequence of length `2n - 1` that satisfies the following conditions:

1. The integer `1` occurs once in the sequence.
2. Each integer between `2` and `n` occurs twice in the sequence.
3. For every integer `i` between `2` and `n`, the distance between the two occurrences of `i` is exactly `i`.
4. The sequence should be lexicographically the largest possible sequence.

The sequence is considered lexicographically larger if, at the first position where the two sequences differ, the number in the first sequence is greater.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer `n`.
- **Example:** `Input: n = 4`
- **Constraints:**
	- 1 <= n <= 20

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically largest sequence that satisfies the conditions described.
- **Example:** `Output: [4, 1, 3, 2, 3, 4, 2]`
- **Constraints:**
	- The returned sequence will always be valid.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to construct a sequence that satisfies the given conditions while ensuring it is lexicographically the largest possible sequence.

- 1. Use backtracking to attempt filling the sequence while adhering to the constraints.
- 2. For each integer from `n` to `1`, try placing the number in the sequence and ensuring the required distance between its occurrences.
- 3. If a number can be placed, move to the next index and repeat the process. If the sequence is complete, return it.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that a valid sequence exists for any input `n`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3`  \
  **Explanation:** The lexicographically largest sequence that satisfies the conditions is `[3, 1, 2, 3, 2]`. It places the largest number (3) first, then places the smaller numbers (1 and 2) in the remaining positions, ensuring the distances are maintained.

- **Input:** `Input: n = 5`  \
  **Explanation:** The lexicographically largest sequence that satisfies the conditions is `[5, 3, 1, 4, 3, 5, 2, 4, 2]`. This sequence follows the same logic, ensuring the largest numbers come first while adhering to the distances.

{{< dots >}}
## Approach 🚀
The problem can be solved using a backtracking approach to construct the sequence by filling the positions while ensuring the required distances between numbers and maximizing lexicographical order.

### Initial Thoughts 💭
- This problem involves filling the sequence while adhering to a strict set of rules, including maintaining the required distances for each number.
- A backtracking approach seems suitable here, as it allows us to try placing each number while considering all possible positions in a systematic way.
{{< dots >}}
### Edge Cases 🌐
- The input will always be a positive integer `n`, so no handling for empty inputs is required.
- The solution should handle `n = 20` efficiently. Ensure that the backtracking process terminates quickly for large inputs.
- For `n = 1`, the sequence will just be `[1]`.
- The backtracking approach must handle the largest cases efficiently within the time constraints.
{{< dots >}}
## Code 💻
```cpp
int n;
vector<int> constructDistancedSequence(int n) {
    this-> n = n;
    vector<int> ans(2 * n - 1, 0);
    
    vector<int> vis(n + 1, 0);
    
    bt(ans, vis, 0);
    
    return ans;
    
}

bool bt(vector<int> &ans, vector<int> &vis, int idx) {
    
    if(idx == ans.size()) return true;
    
    if(ans[idx] != 0) return bt(ans, vis, idx + 1);
    else {

        for(int i = n; i >= 1; i--) {

            if(vis[i]) continue;
            
            vis[i] = 1;
            ans[idx] = i;
            
            if(i == 1) {
                if(bt(ans, vis, idx + 1)) return true;
            } else if (idx + i < ans.size() && ans[idx + i] == 0) {
                ans[idx + i] = i;
                if(bt(ans, vis, idx + 1)) return true;
                ans[idx + i] = 0;                    
            }
            ans[idx] = 0;
            vis[i] = 0;
            
        }

    }
    return false;
    
}

```

This solution generates a distanced sequence for a given number `n` using backtracking. It aims to fill the sequence such that the number `i` appears at positions `idx` and `idx + i`. A recursive helper function (`bt`) is used to backtrack and try different configurations to complete the sequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	Declaring the integer variable `n`, which represents the size of the distanced sequence to be generated.

2. **Function Declaration**
	```cpp
	vector<int> constructDistancedSequence(int n) {
	```
	The function `constructDistancedSequence` is declared, taking an integer `n` as input, and returning a vector of integers representing the constructed sequence.

3. **Variable Assignment**
	```cpp
	    this-> n = n;
	```
	Assigning the input value of `n` to the member variable `n` of the current object.

4. **Vector Initialization**
	```cpp
	    vector<int> ans(2 * n - 1, 0);
	```
	Initializing a vector `ans` of size `2 * n - 1`, filled with zeros. This will hold the distanced sequence.

5. **Vector Initialization**
	```cpp
	    vector<int> vis(n + 1, 0);
	```
	Creating a vector `vis` to track which numbers have been used in the sequence, initialized with zeros.

6. **Backtracking Call**
	```cpp
	    bt(ans, vis, 0);
	```
	Calling the backtracking function `bt` to fill the sequence `ans` using the visitation array `vis`, starting from index `0`.

7. **Return Statement**
	```cpp
	    return ans;
	```
	Returning the constructed distanced sequence after it has been completed by the backtracking function.

8. **Backtracking Function Declaration**
	```cpp
	bool bt(vector<int> &ans, vector<int> &vis, int idx) {
	```
	Declaring the recursive backtracking function `bt`, which attempts to construct the sequence by filling the vector `ans` while ensuring each number `i` appears at positions `idx` and `idx + i`.

9. **Base Case Check**
	```cpp
	    if(idx == ans.size()) return true;
	```
	The base case of the recursion, returning `true` if the entire sequence has been filled correctly.

10. **Recursive Call**
	```cpp
	    if(ans[idx] != 0) return bt(ans, vis, idx + 1);
	```
	If the current index `idx` is already filled, the function moves on to the next index by recursively calling `bt`.

11. **Loop Through Numbers**
	```cpp
	        for(int i = n; i >= 1; i--) {
	```
	Iterating over the numbers from `n` down to `1`, trying to place each number `i` at index `idx` and `idx + i`.

12. **Skip Used Numbers**
	```cpp
	            if(vis[i]) continue;
	```
	Skipping the number `i` if it has already been used in the sequence (tracked by the `vis` array).

13. **Set Number Visited**
	```cpp
	            vis[i] = 1;
	```
	Marking the number `i` as used by setting the corresponding index in the `vis` array to `1`.

14. **Assign Value to Sequence**
	```cpp
	            ans[idx] = i;
	```
	Placing the number `i` at the current index `idx` in the sequence `ans`.

15. **Recursive Check for 1**
	```cpp
	            if(i == 1) {
	```
	If the number `i` is `1`, attempt to move to the next index and fill the sequence.

16. **Backtracking Call**
	```cpp
	                if(bt(ans, vis, idx + 1)) return true;
	```
	Recursively calling `bt` to check if the current assignment leads to a valid sequence.

17. **Check for Valid Pairing**
	```cpp
	            } else if (idx + i < ans.size() && ans[idx + i] == 0) {
	```
	If `i` is greater than `1`, checking if the position `idx + i` is available for placing `i`.

18. **Assign Value to Pairing Position**
	```cpp
	                ans[idx + i] = i;
	```
	Placing the number `i` at the position `idx + i` in the sequence `ans`.

19. **Backtracking Call for Pairing**
	```cpp
	                if(bt(ans, vis, idx + 1)) return true;
	```
	Recursively calling `bt` to check if the current assignment leads to a valid sequence.

20. **Undo Assignment**
	```cpp
	                ans[idx + i] = 0;
	```
	Undoing the assignment if the current choice does not lead to a valid sequence.

21. **Undo Assignment**
	```cpp
	            ans[idx] = 0;
	```
	Undoing the assignment of `i` at index `idx` if it does not lead to a valid sequence.

22. **Reset Visitation**
	```cpp
	            vis[i] = 0;
	```
	Resetting the visitation state for number `i` in the `vis` array.

23. **Final Return**
	```cpp
	    return false;
	```
	Returning `false` if no solution has been found after trying all possibilities.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), when the solution is found early in the backtracking process.
- **Average Case:** O(n!) in the worst case for larger values of `n` due to the backtracking approach.
- **Worst Case:** O(n!) due to the nature of the backtracking algorithm exploring all possible placements for each number.

The time complexity is dominated by the backtracking search for placing numbers in the sequence.

### Space Complexity 💾
- **Best Case:** O(n), if the solution is found early and requires minimal backtracking.
- **Worst Case:** O(n), as we only need to store the sequence of length `2n - 1` and a few additional variables for backtracking.

The space complexity is linear in terms of the size of the sequence.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/)

---
{{< youtube 3kRBmhoA9b8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
