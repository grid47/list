
+++
authors = ["grid47"]
title = "Leetcode 2554: Maximum Number of Integers to Choose From a Range I"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2554: Maximum Number of Integers to Choose From a Range I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iLU7ZBtjc-k"
youtube_upload_date="2023-02-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iLU7ZBtjc-k/maxresdefault.webp"
comments = true
+++



---
You are given an array `banned` consisting of integers, an integer `n`, and an integer `maxSum`. Your task is to return the maximum number of integers you can select from the range [1, n] such that none of them are in the `banned` list and their sum does not exceed `maxSum`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `banned` containing integers, an integer `n` representing the upper limit of the range, and an integer `maxSum` representing the sum limit.
- **Example:** `banned = [3, 7, 5], n = 6, maxSum = 10`
- **Constraints:**
	- 1 <= banned.length <= 10^4
	- 1 <= banned[i], n <= 10^4
	- 1 <= maxSum <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of integers you can select from the range [1, n] without exceeding `maxSum` and ensuring none of them are in the `banned` array.
- **Example:** `3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the count of integers selected from [1, n] under the given constraints.

- 1. Loop through the range [1, n] and for each integer, check if it is in the banned list and if adding it would exceed maxSum.
- 2. If the integer is not in the banned list and does not exceed the sum limit, add it to the selection and update the remaining sum.
- 3. Stop the selection once the sum exceeds maxSum.
{{< dots >}}
### Problem Assumptions ✅
- The array `banned` does not contain duplicate values.
- All integers in the range [1, n] are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `banned = [3, 7, 5], n = 6, maxSum = 10`  \
  **Explanation:** You can choose integers 1, 2, and 6. The sum of 1 + 2 + 6 = 9, which is under the maxSum of 10.

- **Input:** `banned = [1, 2, 3], n = 5, maxSum = 4`  \
  **Explanation:** The only integer you can choose is 4 because all others are banned.

{{< dots >}}
## Approach 🚀
The goal is to select as many integers as possible from the range [1, n] while avoiding the banned integers and ensuring the sum does not exceed maxSum.

### Initial Thoughts 💭
- The problem is essentially a greedy problem where we need to pick the smallest numbers first to maximize the count of selected integers.
- We can iterate through the range [1, n] and keep adding integers that are not banned and do not cause the sum to exceed maxSum.
{{< dots >}}
### Edge Cases 🌐
- The array `banned` will always contain at least one element based on the constraints.
- Ensure the solution handles cases where `banned` is large (up to 10^4 elements).
- Consider cases where all integers in the range [1, n] are banned or the sum limit is too low to select any integer.
- The solution must efficiently handle inputs up to the largest constraint values.
{{< dots >}}
## Code 💻
```cpp
int n;
unordered_map<int, bool> mp;

int maxCount(vector<int>& ban, int n, int mxS) {
    // this->n = n;
    for(int x: ban)
        mp[x] = true;

    // memset(memo, -1, sizeof(memo));
    // memo.resize(n + 1);
    // return dp(1, mxS);
    int cnt = 0;
    for(int i = 1; i < n + 1; i++) {
        if(!mp.count(i) && mxS >= i) {
            cnt++;
            mxS -= i;
        }
        if(mxS < 0) break;
    }
    return cnt;
}
```

This function 'maxCount' calculates how many numbers from 1 to 'n' can be included, where 'ban' contains a list of numbers to be excluded, and 'mxS' represents the maximum sum that can be used to include numbers. It loops through the numbers from 1 to 'n' and checks if the number is not in 'ban' and if it fits within the remaining sum 'mxS'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	Here, the integer 'n' is declared to represent the upper limit for the numbers that can be considered (from 1 to 'n').

2. **Data Structure Initialization**
	```cpp
	unordered_map<int, bool> mp;
	```
	An unordered map 'mp' is declared to store the numbers that are excluded (banned numbers). It maps each excluded number to 'true'.

3. **Function Definition**
	```cpp
	int maxCount(vector<int>& ban, int n, int mxS) {
	```
	This is the function definition for 'maxCount'. It takes a vector of banned numbers, 'ban', an integer 'n' representing the upper limit of the range, and an integer 'mxS' representing the maximum sum constraint.

4. **Initialize Excluded Numbers**
	```cpp
	    for(int x: ban)
	```
	This loop iterates through each banned number in the 'ban' vector and adds it to the unordered map 'mp', marking it as excluded.

5. **Add to Exclusion Map**
	```cpp
	        mp[x] = true;
	```
	This line adds the number 'x' from the 'ban' list to the unordered map 'mp' with a value of 'true', indicating it is a banned number.

6. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	A counter variable 'cnt' is initialized to 0. It will be used to count how many numbers can be included within the sum constraint 'mxS'.

7. **Loop Through Numbers**
	```cpp
	    for(int i = 1; i < n + 1; i++) {
	```
	This loop iterates through numbers from 1 to 'n' and checks if they can be included, based on the conditions set by the problem.

8. **Condition Check: Excluded and Sum**
	```cpp
	        if(!mp.count(i) && mxS >= i) {
	```
	This if-condition checks if the number 'i' is not in the 'mp' map (not banned) and if it fits within the remaining sum 'mxS'.

9. **Increment Counter**
	```cpp
	            cnt++;
	```
	If the number 'i' is not banned and fits within the sum constraint, 'cnt' is incremented to reflect that the number is included.

10. **Update Remaining Sum**
	```cpp
	            mxS -= i;
	```
	This line updates the remaining sum 'mxS' by subtracting the value of 'i', indicating that 'i' has been included.

11. **Break If Sum Is Exceeded**
	```cpp
	        if(mxS < 0) break;
	```
	This checks if the remaining sum 'mxS' has become negative, indicating that no more numbers can be included. If true, the loop is terminated early.

12. **Return Result**
	```cpp
	    return cnt;
	```
	The function returns 'cnt', the total count of numbers that were successfully included within the sum constraint 'mxS'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the range size (since we must check every integer at least once).
- **Average Case:** O(n), assuming a constant-time check for banned integers.
- **Worst Case:** O(n), as we need to check up to n integers for each selection.



### Space Complexity 💾
- **Best Case:** O(1), if no banned integers are used or the solution does not need additional storage.
- **Worst Case:** O(n), since we may store up to n integers in a set or map to check for banned integers.

Space complexity is primarily determined by the storage used to track banned integers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/)

---
{{< youtube iLU7ZBtjc-k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
