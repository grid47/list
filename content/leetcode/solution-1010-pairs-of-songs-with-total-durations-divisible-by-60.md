
+++
authors = ["grid47"]
title = "Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gM5Wu42UTQk"
youtube_upload_date="2021-02-05"
youtube_thumbnail="https://i.ytimg.com/vi/gM5Wu42UTQk/maxresdefault.jpg"
comments = true
+++



---
You are given an array where each element represents the duration of a song in seconds. Your task is to count how many pairs of songs have a total duration that is divisible by 60. Specifically, you need to count how many pairs of songs, indexed as i and j (with i < j), satisfy the condition (time[i] + time[j]) % 60 == 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers where each integer represents the duration of a song in seconds.
- **Example:** `time = [10, 50, 120, 80, 40]`
- **Constraints:**
	- 1 <= time.length <= 6 * 10^4
	- 1 <= time[i] <= 500

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the total number of valid pairs where the sum of the song durations is divisible by 60.
- **Example:** `Output: 2`
- **Constraints:**
	- The result should be an integer representing the number of valid pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently count the pairs of songs whose combined durations are divisible by 60.

- For each song, find the remainder when the song's duration is divided by 60.
- Count how many other songs, when paired with the current song, have a remainder that completes the sum to be divisible by 60.
- Maintain a count of song durations modulo 60 to avoid recalculating the remainder each time.
{{< dots >}}
### Problem Assumptions ✅
- Each song duration is unique, and all are between 1 and 500 seconds.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: time = [10, 50, 120, 80, 40]`  \
  **Explanation:** In this case, two pairs of songs have durations that add up to a multiple of 60: (time[0] = 10, time[1] = 50) and (time[2] = 120, time[4] = 40). These pairs add up to 60 and 160, respectively, both of which are divisible by 60.

- **Input:** `Input: time = [60, 60, 60]`  \
  **Explanation:** For this input, all three pairs (time[0] = 60, time[1] = 60), (time[0] = 60, time[2] = 60), and (time[1] = 60, time[2] = 60) add up to 120, which is divisible by 60. Therefore, the output is 3.

{{< dots >}}
## Approach 🚀
The strategy involves using modular arithmetic to find complementary pairs of song durations that sum to a multiple of 60. We use a hash map or array to track the number of song durations with specific remainders when divided by 60.

### Initial Thoughts 💭
- We need to track the remainder of each song's duration modulo 60 to find pairs that add up to multiples of 60.
- A hash map or a fixed-size array can be used to efficiently count how many song durations correspond to each remainder modulo 60.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as per the problem constraints.
- The solution should efficiently handle large inputs (up to 60,000 elements).
- If all songs have durations that are multiples of 60, every pair will be valid.
- The input array size and the song duration values should be within the specified constraints.
{{< dots >}}
## Code 💻
```cpp
int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> c(60, 0);
    int res = 0;
    for(int t: time) {
        res += c[(600 - t)%60];
        c[t%60] += 1;
    }
    return res;
}
```

This function calculates the number of pairs in the given list of time intervals where the sum of their moduli (with respect to 60) is divisible by 60. It uses a frequency array to efficiently track the counts of time values modulo 60.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numPairsDivisibleBy60(vector<int>& time) {
	```
	Declares the function `numPairsDivisibleBy60` which takes a vector of integers `time` representing the time intervals, and returns the number of valid pairs whose sum is divisible by 60.

2. **Array Initialization**
	```cpp
	    vector<int> c(60, 0);
	```
	Initializes a vector `c` of size 60 to count the occurrences of remainders when each time value is divided by 60.

3. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes the result variable `res` to 0, which will store the number of valid pairs found.

4. **Loop Start**
	```cpp
	    for(int t: time) {
	```
	Starts a loop that iterates through each element `t` in the input `time` vector.

5. **Pair Calculation**
	```cpp
	        res += c[(600 - t)%60];
	```
	For each time value `t`, adds to `res` the count of previously seen time values that form a valid pair with `t` (i.e., their sum is divisible by 60). This is done using the frequency array `c`.

6. **Frequency Update**
	```cpp
	        c[t%60] += 1;
	```
	Increments the count of occurrences for the current remainder `t%60` in the frequency array `c`.

7. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total number of valid pairs found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the list of songs once, and each operation (remainder calculation and count update) takes constant time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we use a fixed-size array of length 60 to store remainder counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/)

---
{{< youtube gM5Wu42UTQk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
