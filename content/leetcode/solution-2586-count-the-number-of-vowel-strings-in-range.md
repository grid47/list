
+++
authors = ["grid47"]
title = "Leetcode 2586: Count the Number of Vowel Strings in Range"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2586: Count the Number of Vowel Strings in Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mHra3okBpdQ"
youtube_upload_date="2023-03-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mHra3okBpdQ/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums`. You can rearrange the elements of `nums` to any order (including the given order). Define the prefix sum array of `nums` as `prefix[i] = sum(nums[0] to nums[i])` after rearranging. The score of `nums` is the number of positive integers in the `prefix` array. Return the maximum score you can achieve by rearranging the elements of `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums`.
- **Example:** `For example, `nums = [3, -1, 4, 2, -3, 1, -2]`.`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^6 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer that represents the maximum score achieved by rearranging the elements of `nums`.
- **Example:** `For `nums = [3, -1, 4, 2, -3, 1, -2]`, the output is `5`.`
- **Constraints:**
	- The result will always be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rearrange the array `nums` to maximize the number of positive integers in the prefix sum array.

- 1. Rearrange the array `nums` to maximize positive prefix sums.
- 2. Calculate the prefix sum array and count the number of positive values.
- 3. Return the count as the maximum score.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains valid integers within the given range.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [3, -1, 4, 2, -3, 1, -2]``  \
  **Explanation:** The optimal rearrangement is `nums = [3, 4, 2, 1, -1, -2, -3]`. The prefix sum array becomes `prefix = [3, 7, 9, 10, 9, 7, 4]`, giving a score of 5.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to rearrange the array `nums` to maximize the number of positive prefix sums. A good strategy is to place the positive numbers at the beginning of the array and the negative numbers towards the end.

### Initial Thoughts 💭
- By placing the positive numbers first, we maximize the possibility of obtaining positive prefix sums.
- This approach helps ensure that the sum remains positive as we calculate the prefix sums.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the array will not be empty.
- The solution should be efficient enough to handle up to 10^5 elements in the array.
- If the array contains only negative values, the score will always be 0.
- The length of the array is guaranteed to be within the specified limits.
{{< dots >}}
## Code 💻
```cpp
bool check(char s)
{
    return (s=='a' || s=='e'|| s=='o'|| s=='i' || s=='u');
}
int vowelStrings(vector<string>& words, int left, int right) {
    int ans=0;
    for(int i=left;i<=right;i++)
    {
        if(check(words[i].front()) && check(words[i].back())) ans++;
    }
    return ans;
}
```

This code defines a function to count the number of words in the specified range of a list where both the first and last characters are vowels.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool check(char s)
	```
	This function checks whether the given character 's' is a vowel (either 'a', 'e', 'i', 'o', or 'u').

2. **Return Statement**
	```cpp
	    return (s=='a' || s=='e'|| s=='o'|| s=='i' || s=='u');
	```
	This line returns true if the character 's' is a vowel; otherwise, false.

3. **Function Declaration**
	```cpp
	int vowelStrings(vector<string>& words, int left, int right) {
	```
	This function counts the number of words in the 'words' vector from index 'left' to 'right' where both the first and last characters are vowels.

4. **Variable Declaration**
	```cpp
	    int ans=0;
	```
	This declares and initializes a variable 'ans' to zero, which will be used to count the words with vowels at both ends.

5. **For Loop**
	```cpp
	    for(int i=left;i<=right;i++)
	```
	This loop iterates over the 'words' vector from index 'left' to 'right'.

6. **If Condition**
	```cpp
	        if(check(words[i].front()) && check(words[i].back())) ans++;
	```
	This condition checks if both the first and last characters of the current word are vowels. If true, it increments the 'ans' counter.

7. **Return Statement**
	```cpp
	    return ans;
	```
	This returns the count of words where both the first and last characters are vowels.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The best case occurs when the array is already arranged optimally. The worst case is when we need to sort the array, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the additional storage required for separating positive and negative numbers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/)

---
{{< youtube mHra3okBpdQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
