
+++
authors = ["grid47"]
title = "Leetcode 229: Majority Element II"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 229: Majority Element II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/229.webp"
youtube = "Eua-UrQ_ANo"
youtube_upload_date="2023-10-05"
youtube_thumbnail="https://i.ytimg.com/vi/Eua-UrQ_ANo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/229.webp" 
    alt="A sequence of numbers with one element glowing brightly, signifying the majority element."
    caption="Solution to LeetCode 229: Majority Element II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array, find all elements that appear more than ⌊n/3⌋ times, where n is the length of the array. Your task is to return a list of all such elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of integers, where the length of the array is between 1 and 5 * 10^4. The elements in the array can range from -10^9 to 10^9.
- **Example:** `Input: nums = [1, 1, 1, 2, 3, 3]`
- **Constraints:**
	- 1 <= nums.length <= 5 * 10^4
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of integers representing the elements that appear more than ⌊n/3⌋ times in the input array.
- **Example:** `Output: [1]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify elements that appear more than ⌊n/3⌋ times in the array efficiently.

- Initialize counters and candidate variables for the two most frequent elements.
- Traverse the array to count occurrences and determine the two most frequent elements.
- Perform a second pass through the array to confirm the exact counts of the candidates.
- Return the elements that meet the frequency condition.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always have at least one element.
- The array length will not exceed 50,000 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 1, 1, 2, 3, 3]`  \
  **Explanation:** The length of the array is 6, and ⌊6/3⌋ = 2. The number 1 appears three times, which is greater than 2, so it is included in the result. The number 3 appears twice, which is equal to ⌊6/3⌋, so it is not included in the result.

- **Input:** `Input: nums = [4, 4, 4, 5, 5, 6, 7]`  \
  **Explanation:** For this example, ⌊7/3⌋ = 2. The number 4 appears three times, which is greater than 2, so it is included. The number 5 appears twice, which equals ⌊7/3⌋, and is not included. The numbers 6 and 7 each appear once, so they are not included.

{{< dots >}}
## Approach 🚀
We can use a two-pass approach to solve this problem in linear time and constant space.

### Initial Thoughts 💭
- We need to find elements that appear more than ⌊n/3⌋ times. This suggests we may need to check the counts of the most frequent elements.
- A simple counting approach can be used to identify potential candidates. After identifying candidates, we need to count their actual occurrences in the array.
{{< dots >}}
### Edge Cases 🌐
- An empty input is not allowed according to the constraints.
- The solution must efficiently handle arrays of up to 50,000 elements.
- If all elements are the same, that element will always appear more than ⌊n/3⌋ times.
- The solution must work within linear time and constant space.
{{< dots >}}
## Code 💻
```cpp
vector<int> majorityElement(vector<int>& nums) {
        std::vector<int> result;
int n = nums.size();

if (n == 0) return result;

int cnt1 = 0, cnt2 = 0;
int cnd1 = 0, cnd2 = 0;

for (int i = 0; i < n; i++) {
    int val = nums[i];

    if (val == cnd1) cnt1++;
    else if (val == cnd2) cnt2++;
    else if (cnt1 == 0) { cnt1 = 1; cnd1 = val; }
    else if (cnt2 == 0) { cnt2 = 1; cnd2 = val; }
    else { cnt1--; cnt2--; }
}

cnt1 = 0;
cnt2 = 0;

for (int i = 0; i < n; i++) {
    int val = nums[i];

    if (val == cnd1) cnt1++;
    else if (val == cnd2) cnt2++;
}

n = n / 3;

if (cnt1 > n) result.push_back(cnd1);
if (cnt2 > n) result.push_back(cnd2);

return result;
}
```

This function uses the Boyer-Moore Voting Algorithm to find elements that appear more than n/3 times in an integer array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> majorityElement(vector<int>& nums) {
	```
	Defines the function `majorityElement` which takes a reference to a vector of integers and returns a vector of integers that appear more than n/3 times in the array.

2. **Variable Initialization**
	```cpp
	        std::vector<int> result;
	```
	Initializes an empty vector `result` to store the elements that appear more than n/3 times.

3. **Variable Initialization**
	```cpp
	int n = nums.size();
	```
	Stores the size of the input vector `nums` in the variable `n`.

4. **Edge Case Check**
	```cpp
	if (n == 0) return result;
	```
	Checks if the input array is empty and returns an empty result if true.

5. **Variable Initialization**
	```cpp
	int cnt1 = 0, cnt2 = 0;
	```
	Initializes two counters `cnt1` and `cnt2` for tracking the occurrences of two candidate elements.

6. **Variable Initialization**
	```cpp
	int cnd1 = 0, cnd2 = 0;
	```
	Initializes two candidate elements `cnd1` and `cnd2` to track the most frequent elements.

7. **Main Loop**
	```cpp
	for (int i = 0; i < n; i++) {
	```
	Starts a loop to iterate over all elements of the array.

8. **Element Check**
	```cpp
	    int val = nums[i];
	```
	Assigns the current element of the array to the variable `val`.

9. **Voting Logic**
	```cpp
	    if (val == cnd1) cnt1++;
	```
	If the current element equals the first candidate `cnd1`, increment `cnt1`.

10. **Voting Logic**
	```cpp
	    else if (val == cnd2) cnt2++;
	```
	If the current element equals the second candidate `cnd2`, increment `cnt2`.

11. **Candidate Assignment**
	```cpp
	    else if (cnt1 == 0) { cnt1 = 1; cnd1 = val; }
	```
	If `cnt1` is 0, assign the current element to `cnd1` and set `cnt1` to 1.

12. **Candidate Assignment**
	```cpp
	    else if (cnt2 == 0) { cnt2 = 1; cnd2 = val; }
	```
	If `cnt2` is 0, assign the current element to `cnd2` and set `cnt2` to 1.

13. **Voting Logic**
	```cpp
	    else { cnt1--; cnt2--; }
	```
	If neither candidate matches, decrement both `cnt1` and `cnt2`.

14. **Recounting Phase**
	```cpp
	cnt1 = 0;
	```
	Resets the count of `cnd1` for a second pass through the array.

15. **Recounting Phase**
	```cpp
	cnt2 = 0;
	```
	Resets the count of `cnd2` for a second pass through the array.

16. **Recounting Phase**
	```cpp
	for (int i = 0; i < n; i++) {
	```
	Starts a second loop to recount occurrences of the candidates.

17. **Element Count**
	```cpp
	    int val = nums[i];
	```
	Assigns the current element of the array to the variable `val` again.

18. **Element Count**
	```cpp
	    if (val == cnd1) cnt1++;
	```
	Increments the count for `cnd1` if the current element matches `cnd1`.

19. **Element Count**
	```cpp
	    else if (val == cnd2) cnt2++;
	```
	Increments the count for `cnd2` if the current element matches `cnd2`.

20. **Final Check**
	```cpp
	n = n / 3;
	```
	Calculates n/3 to determine the threshold for a majority element.

21. **Result Construction**
	```cpp
	if (cnt1 > n) result.push_back(cnd1);
	```
	If `cnd1` appears more than n/3 times, add it to the result vector.

22. **Result Construction**
	```cpp
	if (cnt2 > n) result.push_back(cnd2);
	```
	If `cnd2` appears more than n/3 times, add it to the result vector.

23. **Return Result**
	```cpp
	return result;
	```
	Returns the vector `result`, which contains the majority elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we perform two passes over the array (one for candidate identification and one for count verification).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only store a constant number of variables to track the two potential candidates.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/majority-element-ii/description/)

---
{{< youtube Eua-UrQ_ANo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
