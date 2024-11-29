
+++
authors = ["grid47"]
title = "Leetcode 2024: Maximize the Confusion of an Exam"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2024: Maximize the Confusion of an Exam in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XYJv2pySK44"
youtube_upload_date="2021-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XYJv2pySK44/maxresdefault.webp"
comments = true
+++



---
You are given a string `answerKey` where each character represents a question's answer (either 'T' for True or 'F' for False), and an integer `k`. You are allowed to change at most `k` answers. Your task is to find the maximum number of consecutive 'T's or 'F's in the string after performing at most `k` changes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `answerKey` where each character is either 'T' or 'F', and an integer `k` representing the maximum number of changes allowed.
- **Example:** `answerKey = "FFTT", k = 2`
- **Constraints:**
	- 1 <= answerKey.length <= 50000
	- 1 <= k <= answerKey.length
	- answerKey[i] is either 'T' or 'F'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of consecutive 'T's or 'F's that can be achieved after performing at most `k` changes.
- **Example:** `Output: 4`
- **Constraints:**
	- The answer must be the maximum consecutive occurrence of either 'T' or 'F'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest subsequence of consecutive 'T's or 'F's that can be formed after changing at most `k` characters.

- 1. Use a sliding window approach where you iterate over the string while maintaining a window of consecutive characters that are either 'T' or 'F'.
- 2. Track the number of changes you make and adjust the window size such that the number of changes does not exceed `k`.
- 3. Update the result as you move through the string to ensure the maximum length of consecutive 'T's or 'F's is obtained.
{{< dots >}}
### Problem Assumptions ✅
- The string `answerKey` contains only the characters 'T' and 'F'.
- The number of changes is limited by the integer `k`.
{{< dots >}}
## Examples 🧩
- **Input:** `answerKey = "FFTT", k = 2`  \
  **Explanation:** We can replace both 'F's with 'T's, forming the string 'TTTT', which gives us 4 consecutive 'T's.

- **Input:** `answerKey = "TFTF", k = 1`  \
  **Explanation:** We can replace one 'F' with 'T', forming either 'TTTF' or 'TTFT', which gives us 3 consecutive 'T's.

- **Input:** `answerKey = "FTFTFT", k = 1`  \
  **Explanation:** We can replace one 'F' with 'T', resulting in either 'TTFTFT' or 'FTTTFT', both giving us 3 consecutive 'T's.

{{< dots >}}
## Approach 🚀
We can solve this problem efficiently using a sliding window approach to track the maximum number of consecutive 'T's or 'F's that can be formed with at most `k` changes.

### Initial Thoughts 💭
- The problem can be reduced to finding the longest subsequence of 'T's or 'F's after changing at most `k` elements.
- By applying a sliding window, we can efficiently find the longest possible subsequence that meets the constraints.
{{< dots >}}
### Edge Cases 🌐
- If the input string is empty, return 0.
- Ensure the solution efficiently handles the maximum input size (up to 50000 characters).
- If `k` is 0, no changes can be made, and the answer should be the longest sequence of consecutive 'T's or 'F's in the original string.
- Ensure that the solution does not exceed time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int maxConsecutiveAnswers(string key, int k) {
    int ans = 1;
    int fidx = 0, tidx = 0, fcnt = 0, tcnt = 0;
    for(int i = 0; i < key.size(); i++) {
        if(key[i] == 'F') fcnt++;
        else tcnt++;
        while(fcnt > k) {
            if(key[tidx] == 'F') fcnt--;
            tidx++;
        }
        ans = max(ans, i - tidx + 1);
        while(tcnt > k) {
            if(key[fidx] == 'T') tcnt--;
            fidx++;
        }
        ans = max(ans, i - fidx + 1);            
    }
    return ans;
}
```

This function finds the maximum number of consecutive answers that can be obtained by changing at most 'k' characters in the given string 'key'. The string contains two types of characters: 'F' and 'T'. The goal is to find the longest subsequence where at most 'k' characters can be changed from 'F' to 'T' or vice versa.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxConsecutiveAnswers(string key, int k) {
	```
	This defines the function 'maxConsecutiveAnswers', which takes a string 'key' and an integer 'k'. It returns the maximum length of a subsequence where at most 'k' characters can be changed to either 'F' or 'T'.

2. **Variable Initialization**
	```cpp
	    int ans = 1;
	```
	This initializes an integer variable 'ans' to store the maximum length of consecutive answers. The initial value is set to 1 since the minimum answer will be 1.

3. **Variable Initialization**
	```cpp
	    int fidx = 0, tidx = 0, fcnt = 0, tcnt = 0;
	```
	These variables are initialized to keep track of the indices and counts for 'F' and 'T' characters. 'fidx' and 'tidx' are indices for the start of the window, while 'fcnt' and 'tcnt' are the counts of 'F' and 'T' characters within the window.

4. **Loop Start**
	```cpp
	    for(int i = 0; i < key.size(); i++) {
	```
	This loop iterates through each character in the string 'key' to explore different possible subsequences.

5. **Condition Check**
	```cpp
	        if(key[i] == 'F') fcnt++;
	```
	This checks if the current character is 'F'. If it is, the count of 'F' characters within the current window ('fcnt') is incremented.

6. **Condition Check**
	```cpp
	        else tcnt++;
	```
	If the current character is 'T', the count of 'T' characters within the current window ('tcnt') is incremented.

7. **Window Adjustment**
	```cpp
	        while(fcnt > k) {
	```
	This loop ensures that the number of 'F' characters within the window does not exceed 'k'. If the count of 'F' exceeds 'k', the window is adjusted.

8. **Window Adjustment**
	```cpp
	            if(key[tidx] == 'F') fcnt--;
	```
	This checks if the character at the leftmost index ('tidx') is 'F'. If it is, the count of 'F' characters ('fcnt') is decreased.

9. **Window Adjustment**
	```cpp
	            tidx++;
	```
	This moves the leftmost index of the window ('tidx') to the right, effectively shrinking the window from the left.

10. **Update Answer**
	```cpp
	        ans = max(ans, i - tidx + 1);
	```
	This updates the value of 'ans' by comparing the current answer with the length of the current window (i - tidx + 1). It ensures that 'ans' always holds the maximum length of a valid subsequence.

11. **Window Adjustment**
	```cpp
	        while(tcnt > k) {
	```
	This loop ensures that the number of 'T' characters within the window does not exceed 'k'. If the count of 'T' exceeds 'k', the window is adjusted.

12. **Window Adjustment**
	```cpp
	            if(key[fidx] == 'T') tcnt--;
	```
	This checks if the character at the leftmost index ('fidx') is 'T'. If it is, the count of 'T' characters ('tcnt') is decreased.

13. **Window Adjustment**
	```cpp
	            fidx++;
	```
	This moves the leftmost index of the window ('fidx') to the right, shrinking the window from the left.

14. **Update Answer**
	```cpp
	        ans = max(ans, i - fidx + 1);            
	```
	This updates 'ans' again by comparing it with the length of the current window (i - fidx + 1).

15. **Return Statement**
	```cpp
	    return ans;
	```
	This returns the final result, which is the length of the longest valid subsequence where at most 'k' characters can be changed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The sliding window approach iterates through the string once, resulting in a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the solution only requires a few variables to track the window and counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/)

---
{{< youtube XYJv2pySK44 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
