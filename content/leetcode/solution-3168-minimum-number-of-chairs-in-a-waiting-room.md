
+++
authors = ["grid47"]
title = "Leetcode 3168: Minimum Number of Chairs in a Waiting Room"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3168: Minimum Number of Chairs in a Waiting Room in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-VAEXKFWfXo"
youtube_upload_date="2024-06-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-VAEXKFWfXo/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` representing a sequence of events where each character is either 'E' (a person enters the waiting room) or 'L' (a person leaves the waiting room). The waiting room starts empty. Simulate the events and determine the minimum number of chairs required to ensure there is always a chair available for every person who enters the room.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` containing the characters 'E' and 'L'.
- **Example:** `Example 1:
Input: s = "LLLEEEE"
Output: 3`
- **Constraints:**
	- 1 <= s.length <= 50
	- s consists only of the characters 'E' and 'L'.
	- s represents a valid sequence of entries and exits.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of chairs required to accommodate all the people entering the waiting room.
- **Example:** `Example 1:
Input: s = "LLLEEEE"
Output: 3`
- **Constraints:**
	- The output will be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to track the number of people in the waiting room at any given time and determine the maximum number of chairs required at any point.

- Initialize a counter to track the number of people in the waiting room.
- Iterate over the events in the string `s`.
- For each 'E', increment the counter (a person enters).
- For each 'L', decrement the counter (a person leaves).
- Keep track of the maximum value of the counter during the iteration. This represents the maximum number of people in the room at once, which is the minimum number of chairs needed.
{{< dots >}}
### Problem Assumptions ✅
- The sequence of entries and exits is valid (no 'L' without an 'E' before it).
- The waiting room starts with 0 people and is initially empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `s = "LLLEEEE"`, at the start no one is in the room, then 3 people leave and 4 people enter, so the maximum number of people in the room at any time is 3. Therefore, the minimum number of chairs required is 3.

- **Input:** `Example 2:`  \
  **Explanation:** For `s = "ELELEEL"`, after each entry and exit, the number of people in the room fluctuates between 1 and 2. The maximum number of people in the room at any time is 2, so the minimum number of chairs needed is 2.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the string `s` to simulate each event. We track the number of people in the waiting room at any point and compute the maximum number of people in the room, which gives the number of chairs needed.

### Initial Thoughts 💭
- We need to track the current number of people in the room and update it as we process each event.
- The approach should efficiently handle the maximum input size (length up to 50). We will simply keep a counter and update it while tracking the maximum number of people in the room.
{{< dots >}}
### Edge Cases 🌐
- There will never be an empty string as input.
- The solution should handle strings with lengths up to 50 efficiently.
- Ensure the solution works with edge cases such as all people leaving immediately or all people entering.
- Ensure that the number of chairs is calculated accurately even with mixed events of entries and exits.
{{< dots >}}
## Code 💻
```cpp
int minimumChairs(string s) {
    int mx = 0, cnt = 0;
    for(char x: s) {
        cnt += (x == 'E'? 1: -1);
        mx = max(mx, cnt);
    }
    return mx;
}
```

This function 'minimumChairs' computes the minimum number of chairs required for a given string of events, where 'E' indicates a person enters and any other character indicates a person exits. The function tracks the maximum number of people present at any time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumChairs(string s) {
	```
	Defines the function 'minimumChairs' that accepts a string 's', representing a series of events, and returns the minimum number of chairs needed.

2. **Variable Initialization**
	```cpp
	    int mx = 0, cnt = 0;
	```
	Initializes two integer variables: 'mx' to store the maximum number of people present at any point, and 'cnt' to keep track of the current number of people inside.

3. **For Loop**
	```cpp
	    for(char x: s) {
	```
	Begins a for loop that iterates through each character 'x' in the string 's'.

4. **Condition Check**
	```cpp
	        cnt += (x == 'E'? 1: -1);
	```
	Checks if the character 'x' is 'E' (entry event), in which case it increments 'cnt' by 1. If 'x' is not 'E', it decrements 'cnt' by 1 (exit event).

5. **Max Update**
	```cpp
	        mx = max(mx, cnt);
	```
	Updates the value of 'mx' to be the maximum of 'mx' and the current 'cnt', ensuring it tracks the peak number of people inside.

6. **Return Statement**
	```cpp
	    return mx;
	```
	Returns the value of 'mx', which represents the maximum number of people inside at any point, i.e., the minimum number of chairs required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string `s`. We only need to iterate through the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are only using a constant amount of extra space for the counters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/)

---
{{< youtube -VAEXKFWfXo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
