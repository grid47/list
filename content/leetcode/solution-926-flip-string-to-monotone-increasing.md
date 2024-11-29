
+++
authors = ["grid47"]
title = "Leetcode 926: Flip String to Monotone Increasing"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 926: Flip String to Monotone Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tMq9z5k3umQ"
youtube_upload_date="2023-01-17"
youtube_thumbnail="https://i.ytimg.com/vi/tMq9z5k3umQ/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string s consisting of only '0's and '1's. A binary string is called monotone increasing if all '0's appear before '1's. You can flip any character in the string, changing it from '0' to '1' or from '1' to '0'. Your task is to return the minimum number of flips required to make the string monotone increasing.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string s. The string consists of only '0' and '1'.
- **Example:** `Input: s = "01010"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- Each character in s is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of flips required to make the string monotone increasing.
- **Example:** `Output: 2`
- **Constraints:**
	- The string will have at least one character.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum number of flips needed to make the string monotone increasing.

- 1. Initialize two counters: one for the number of '1's encountered and one for the number of flips.
- 2. Iterate through the string. For each '1', increment the counter for '1's.
- 3. For each '0', update the flip counter to the minimum of the current flips or the number of '1's encountered so far, as flipping '0' to '1' can make the string more monotone.
- 4. Return the final value of the flip counter.
{{< dots >}}
### Problem Assumptions ✅
- The input string is valid and consists only of '0's and '1's.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "101010"`  \
  **Explanation:** In this case, we can flip the '1' at position 1 and the '0' at position 2 to get a monotone increasing string '000111'. Thus, the minimum number of flips is 2.

- **Input:** `Input: s = "11000"`  \
  **Explanation:** Here, the string is already monotone increasing, so no flips are required, and the output is 0.

{{< dots >}}
## Approach 🚀
The solution approach involves traversing the string once and tracking the number of '1's and '0's. We update the minimum flips required dynamically based on the current characters.

### Initial Thoughts 💭
- The string needs to be split into two parts: all '0's followed by all '1's.
- Flipping any '1' to '0' or '0' to '1' can help achieve a monotone string.
- We can solve this problem in linear time by tracking the number of '1's and calculating the minimum flips as we traverse the string.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one character in the input string.
- For large inputs (up to 100,000 characters), the algorithm needs to run efficiently in linear time.
- If the string is already monotone increasing, the minimum flips should be 0.
- The input string consists of only '0's and '1's.
{{< dots >}}
## Code 💻
```cpp
int minFlipsMonoIncr(string s) {
    int cnt_one = 0, cnt_flip = 0;
    for(char c: s) {
        if(c == '1') cnt_one++;
        else         cnt_flip++;
        cnt_flip = min(cnt_one, cnt_flip);
    }
    return cnt_flip;
}
```

The function 'minFlipsMonoIncr' calculates the minimum number of flips required to make the binary string 's' non-decreasing (all 0s followed by all 1s). It counts the number of 1s and calculates the number of flips necessary at each step to achieve this.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minFlipsMonoIncr(string s) {
	```
	Define the function 'minFlipsMonoIncr' that takes a binary string 's' and returns an integer representing the minimum number of flips required to make the string non-decreasing.

2. **Variable Initialization**
	```cpp
	    int cnt_one = 0, cnt_flip = 0;
	```
	Initialize two variables, 'cnt_one' to count the number of 1s in the string, and 'cnt_flip' to track the number of flips required to make the string non-decreasing.

3. **For Loop**
	```cpp
	    for(char c: s) {
	```
	Start a loop to iterate through each character 'c' in the string 's'.

4. **Character Check - 1**
	```cpp
	        if(c == '1') cnt_one++;
	```
	If the current character is '1', increment the 'cnt_one' variable to count the 1s.

5. **Character Check - 0**
	```cpp
	        else         cnt_flip++;
	```
	If the current character is '0', increment the 'cnt_flip' variable to track the flips required to make the string non-decreasing.

6. **Update Flip Count**
	```cpp
	        cnt_flip = min(cnt_one, cnt_flip);
	```
	At each step, update 'cnt_flip' to be the minimum of the current 'cnt_flip' and 'cnt_one'. This ensures we are counting the minimum number of flips necessary at each point.

7. **Return Result**
	```cpp
	    return cnt_flip;
	```
	Return the value of 'cnt_flip', which now contains the minimum number of flips required to make the string non-decreasing.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string. We only make one pass over the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)

---
{{< youtube tMq9z5k3umQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
