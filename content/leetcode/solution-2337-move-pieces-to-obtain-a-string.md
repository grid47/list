
+++
authors = ["grid47"]
title = "Leetcode 2337: Move Pieces to Obtain a String"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2337: Move Pieces to Obtain a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Tq2uKuSciOc"
youtube_upload_date="2022-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/Tq2uKuSciOc/maxresdefault.jpg"
comments = true
+++



---
You are given two strings `start` and `target`, each consisting of the characters `'L'`, `'R'`, and `'_'`. The goal is to check if it is possible to transform the string `start` into `target` by moving the 'L' and 'R' characters. 'L' can only move to the left and 'R' can only move to the right. A blank space can be occupied by either 'L' or 'R'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings, `start` and `target`, each of length `n`.
- **Example:** `start = '_L__R__R_', target = 'L______RR'`
- **Constraints:**
	- 1 <= n <= 10^5
	- start and target consist of the characters 'L', 'R', and '_'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it is possible to obtain the target string from the start string, otherwise return `false`.
- **Example:** `true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if it is possible to transform `start` into `target` by moving pieces according to the described rules.

- Initialize two queues to store the positions of the 'L' and 'R' pieces in `start` and `target`.
- Compare the characters in both queues to ensure they match.
- Ensure that the 'L' pieces in `start` do not move right in `target` and the 'R' pieces do not move left.
{{< dots >}}
### Problem Assumptions ✅
- The input strings are valid and consist only of 'L', 'R', and '_'.
- The strings are of equal length.
{{< dots >}}
## Examples 🧩
- **Input:** `start = '_L__R__R_', target = 'L______RR'`  \
  **Explanation:** The goal is to check if it's possible to transform the start string into the target string by moving 'L' and 'R' pieces according to the rules. This is possible, as described in the explanation.

{{< dots >}}
## Approach 🚀
The approach involves comparing the positions of the 'L' and 'R' characters in both strings and ensuring that no piece violates the movement restrictions.

### Initial Thoughts 💭
- The pieces can only move left or right, but the movement is restricted by their position relative to each other.
- We need to simulate the movements of the pieces and check if the positions match between the two strings under the given constraints.
{{< dots >}}
### Edge Cases 🌐
- Empty strings are not valid as per the constraints.
- Ensure that the solution handles input sizes up to 100,000 characters efficiently.
- If all characters are '_', the target string should be exactly the same as the start string.
- The strings should always have a length of at least 1 and no more than 100,000 characters.
{{< dots >}}
## Code 💻
```cpp
bool canChange(string start, string target) {
    queue<pair<int, int>> ss, ts;

    for(int i = 0; i < start.size(); i++)
    if(start[i] != '_') ss.push({start[i], i});

    for(int i = 0; i < target.size(); i++)
    if(target[i] != '_') ts.push({target[i], i});

    if(ss.size() != ts.size()) return false;

    while(!ss.empty()) {
        auto s = ss.front();
        auto t = ts.front();
        ss.pop();
        ts.pop();
        if(s.first != t.first) return false;

        if(s.first == 'L' && t.second > s.second)
        return false;
        if(t.first == 'R' && t.second < s.second)
        return false;
    }

    return true;
}
```

This is the complete implementation of the function 'canChange', which determines if it's possible to change the start string to the target string based on specific movement constraints for 'L' and 'R' characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Block**
	```cpp
	bool canChange(string start, string target) {
	```
	Define the function 'canChange' that takes two strings, 'start' and 'target', representing the initial and target states respectively.

2. **Variable Initialization**
	```cpp
	    queue<pair<int, int>> ss, ts;
	```
	Declare two queues, 'ss' and 'ts', to store the characters and their indices for the 'start' and 'target' strings.

3. **Loop**
	```cpp
	    for(int i = 0; i < start.size(); i++)
	```
	Loop through the characters of the 'start' string.

4. **Push Non-Underscore Characters**
	```cpp
	    if(start[i] != '_') ss.push({start[i], i});
	```
	Push each character from 'start' and its index into the queue 'ss', if the character is not an underscore.

5. **Loop**
	```cpp
	    for(int i = 0; i < target.size(); i++)
	```
	Loop through the characters of the 'target' string.

6. **Push Non-Underscore Characters**
	```cpp
	    if(target[i] != '_') ts.push({target[i], i});
	```
	Push each character from 'target' and its index into the queue 'ts', if the character is not an underscore.

7. **Check Queue Sizes**
	```cpp
	    if(ss.size() != ts.size()) return false;
	```
	Check if the sizes of the two queues are the same; if not, return false because the number of non-underscore characters doesn't match.

8. **Begin While Loop**
	```cpp
	    while(!ss.empty()) {
	```
	Start a while loop to process the elements in the queues.

9. **Pop from Queues**
	```cpp
	        auto s = ss.front();
	```
	Pop the front element from queue 'ss'.

10. **Pop from Queues**
	```cpp
	        auto t = ts.front();
	```
	Pop the front element from queue 'ts'.

11. **Remove from Queues**
	```cpp
	        ss.pop();
	```
	Remove the front element from queue 'ss'.

12. **Remove from Queues**
	```cpp
	        ts.pop();
	```
	Remove the front element from queue 'ts'.

13. **Check Character Equality**
	```cpp
	        if(s.first != t.first) return false;
	```
	Check if the characters from both queues are equal; if not, return false.

14. **Character Movement Conditions**
	```cpp
	        if(s.first == 'L' && t.second > s.second)
	```
	Check if a 'L' character in the 'start' string violates the movement condition, meaning it should not move to the right.

15. **Return False**
	```cpp
	        return false;
	```
	Return false if the movement condition is violated for 'L' characters.

16. **Character Movement Conditions**
	```cpp
	        if(t.first == 'R' && t.second < s.second)
	```
	Check if a 'R' character in the 'target' string violates the movement condition, meaning it should not move to the left.

17. **Return False**
	```cpp
	        return false;
	```
	Return false if the movement condition is violated for 'R' characters.

18. **Return True**
	```cpp
	    return true;
	```
	Return true if all conditions are met, indicating the transformation is possible.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we traverse each string once and perform constant-time operations for each character.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space used by the queues storing the positions of the 'L' and 'R' pieces.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/)

---
{{< youtube Tq2uKuSciOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
