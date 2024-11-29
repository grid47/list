
+++
authors = ["grid47"]
title = "Leetcode 2100: Find Good Days to Rob the Bank"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2100: Find Good Days to Rob the Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "skEtLRG05RQ"
youtube_upload_date="2021-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/skEtLRG05RQ/maxresdefault.webp"
comments = true
+++



---
You are planning a bank robbery with a gang of thieves. You are given a list, 'security', where each element represents the number of guards present on duty each day. You are also given an integer, 'time', which represents the number of days before and after the current day that must have specific guard arrangements for it to be a good day for the robbery.
A good day to rob the bank is defined as:
1. There must be at least 'time' days before and after the current day.
2. The number of guards on the days before the current day must be non-increasing.
3. The number of guards on the days after the current day must be non-decreasing.
Return a list of all the days that are good days to rob the bank.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list 'security' representing the number of guards present on each day and an integer 'time' representing the number of days before and after the current day to consider.
- **Example:** `security = [4, 2, 3, 2, 5, 6, 1], time = 2`
- **Constraints:**
	- 1 <= security.length <= 10^5
	- 0 <= security[i], time <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of indices representing the days that are good days to rob the bank.
- **Example:** `Output: [2, 3]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the days that satisfy the condition of having non-increasing guard numbers before the day and non-decreasing guard numbers after it.

- Precompute the number of consecutive non-increasing days before each day.
- Precompute the number of consecutive non-decreasing days after each day.
- Iterate through the array and check if a day satisfies the condition of having enough non-increasing days before it and non-decreasing days after it.
{{< dots >}}
### Problem Assumptions ✅
- The input list 'security' is non-empty.
- The integer 'time' is within the valid range.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: security = [4, 2, 3, 2, 5, 6, 1], time = 2`  \
  **Explanation:** On day 2, security[0] >= security[1] >= security[2] <= security[3] <= security[4], making it a valid day to rob the bank. Similarly, day 3 also satisfies the condition.

- **Input:** `Example 2: security = [3, 2, 1, 3, 2], time = 1`  \
  **Explanation:** The days that meet the conditions are day 1 and day 3 because each of them has at least 1 day before and after with the required guard arrangements.

- **Input:** `Example 3: security = [1, 2, 3, 4, 5], time = 2`  \
  **Explanation:** No day has 2 previous days with non-increasing guards, so no days satisfy the condition.

{{< dots >}}
## Approach 🚀
The solution involves computing two auxiliary arrays: one for the number of consecutive non-increasing days before each day and another for the number of consecutive non-decreasing days after each day.

### Initial Thoughts 💭
- We need to ensure that we correctly identify the days with appropriate guard patterns before and after them.
- We will use two auxiliary arrays to track the number of non-increasing days before and non-decreasing days after each day, which will allow us to efficiently check each day.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases for empty inputs as the problem guarantees that the input array will not be empty.
- The solution needs to handle arrays of up to 10^5 elements efficiently.
- Ensure the solution handles cases where 'time' is 0, which means every day is a good day.
- The solution must operate within the time complexity of O(n), where n is the length of the array.
{{< dots >}}
## Code 💻
```cpp
vector<int> goodDaysToRobBank(vector<int>& sec, int time) {

    int n = sec.size();
    vector<int> pre(n, 0), suf(n, 0);
    pre[0] = 0;
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(sec[i] <= sec[i - 1])
            cnt++;
        else cnt = 0;
        pre[i] = cnt;
    }
    
    suf[n - 1] = 0;
    cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        if(sec[i] <= sec[i + 1])
            cnt++;
        else cnt = 0;
        suf[i] = cnt;
    }
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (pre[i] >= time && suf[i] >= time)
            ans.push_back(i);
    }
    
    return ans;
}
```

This function finds the days when a bank can be robbed. It utilizes a sliding window technique, calculating pre-computed sequences to identify valid days.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
	```
	Function definition for finding good days to rob a bank, taking an array of security levels 'sec' and time constraint 'time'.

2. **Variable Initialization**
	```cpp
	    int n = sec.size();
	```
	Calculating the size of the 'sec' array to determine the number of elements.

3. **Variable Initialization**
	```cpp
	    vector<int> pre(n, 0), suf(n, 0);
	```
	Declaring two vectors 'pre' and 'suf' to store the precomputed and suffixed values for each day.

4. **Array Initialization**
	```cpp
	    pre[0] = 0;
	```
	Initializing the first element of the 'pre' vector to 0 as the base case.

5. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializing the counter variable 'cnt' to keep track of the consecutive days.

6. **Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Starting a loop to iterate through each day, starting from the second day.

7. **Condition Check**
	```cpp
	        if(sec[i] <= sec[i - 1])
	```
	Checking if the current security level is less than or equal to the previous day's security level.

8. **Counter Update**
	```cpp
	            cnt++;
	```
	Incrementing the counter when the condition is true, i.e., the security level is non-increasing.

9. **Counter Reset**
	```cpp
	        else cnt = 0;
	```
	Resetting the counter if the condition is false, meaning the security level is increasing.

10. **Array Update**
	```cpp
	        pre[i] = cnt;
	```
	Storing the value of 'cnt' in the 'pre' vector at index 'i'.

11. **Array Initialization**
	```cpp
	    suf[n - 1] = 0;
	```
	Initializing the last element of the 'suf' array to 0.

12. **Variable Reset**
	```cpp
	    cnt = 0;
	```
	Resetting the counter variable for the next loop to calculate the suffix array.

13. **Loop**
	```cpp
	    for (int i = n - 2; i >= 0; i--) {
	```
	Starting a loop to iterate backwards through the security levels to compute the suffix array.

14. **Condition Check**
	```cpp
	        if(sec[i] <= sec[i + 1])
	```
	Checking if the current security level is less than or equal to the next day's security level.

15. **Counter Update**
	```cpp
	            cnt++;
	```
	Incrementing the counter when the condition is true.

16. **Counter Reset**
	```cpp
	        else cnt = 0;
	```
	Resetting the counter if the condition is false.

17. **Array Update**
	```cpp
	        suf[i] = cnt;
	```
	Storing the counter value 'cnt' in the 'suf' vector at index 'i'.

18. **Variable Initialization**
	```cpp
	    vector<int> ans;
	```
	Declaring the 'ans' vector to store the final results.

19. **Loop**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	Starting a loop to check each day if it satisfies the condition for robbing.

20. **Condition Check**
	```cpp
	        if (pre[i] >= time && suf[i] >= time)
	```
	Checking if the precomputed and suffixed values for the current day are greater than or equal to the specified time.

21. **Add to Result**
	```cpp
	            ans.push_back(i);
	```
	If the condition is true, adding the day 'i' to the result array.

22. **Return Statement**
	```cpp
	    return ans;
	```
	Returning the final list of days that satisfy the conditions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the length of the input array since we iterate through the array a constant number of times.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the auxiliary arrays used to store the precomputed results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/)

---
{{< youtube skEtLRG05RQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
