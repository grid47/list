
+++
authors = ["grid47"]
title = "Leetcode 825: Friends Of Appropriate Ages"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 825: Friends Of Appropriate Ages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0_4H68f85HQ"
youtube_upload_date="2020-05-19"
youtube_thumbnail="https://i.ytimg.com/vi/0_4H68f85HQ/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `ages`, where each element represents the age of a person on a social media platform. A person will not send a friend request to another person if any of the following conditions are true:

1. The recipient's age is less than or equal to half of the sender's age plus 7.
2. The recipient's age is greater than the sender's age.
3. The recipient's age is greater than 100 and the sender's age is less than 100.

Otherwise, the sender can send a friend request. Return the total number of friend requests made between people.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `ages` of length `n` (the number of people). Each element represents the age of a person.
- **Example:** `Input: ages = [18, 20, 30, 40]`
- **Constraints:**
	- 1 <= n <= 2 * 10^4
	- 1 <= ages[i] <= 120

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the total number of valid friend requests made according to the given conditions.
- **Example:** `Output: 4`
- **Constraints:**
	- The output must be an integer representing the number of friend requests.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the total number of friend requests by checking each pair of people in the `ages` array and applying the given conditions.

- Step 1: Create a frequency map of the ages.
- Step 2: For each pair of distinct ages, check if they meet the conditions for sending a friend request.
- Step 3: If a valid request is possible, add the appropriate number of requests to the result.
{{< dots >}}
### Problem Assumptions ✅
- There are no people with ages less than 1 or greater than 120.
- The problem guarantees that the input array will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ages = [18, 20, 30, 40]`  \
  **Explanation:** The person with age 20 will send a request to 18, 30, and 40. The person with age 30 will send a request to 40. This results in a total of 4 requests.

{{< dots >}}
## Approach 🚀
The approach involves iterating through each possible pair of people in the `ages` array and applying the given conditions to count the valid requests.

### Initial Thoughts 💭
- The conditions for sending a friend request are simple comparisons of the ages.
- We can take advantage of counting the occurrences of each age and use these counts to avoid directly comparing every possible pair of people.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one person, so the input will never be empty.
- When the input size is large, the solution should still handle it efficiently.
- Ensure correct handling of the edge case where someone is 100 years old or more.
- The algorithm should efficiently handle inputs with up to 20,000 elements.
{{< dots >}}
## Code 💻
```cpp
int numFriendRequests(vector<int>& ages) {
    unordered_map<int, int> cnt;
    for(int age: ages)
        cnt[age]++;

    int res = 0;
    for(auto a: cnt)
    for(auto b: cnt)
    if(request(a.first, b.first))
        res += a.second * (b.second - (a.first == b.first? 1: 0));
    return res;
}

bool request(int a, int b) {
    return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}
```

This function counts the number of friend requests that can be made based on the ages of people in a given vector, using specific conditions to decide whether one person can send a friend request to another.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numFriendRequests(vector<int>& ages) {
	```
	Declares the function `numFriendRequests` that takes a vector of integers `ages` representing the ages of individuals, and returns the number of valid friend requests.

2. **Map Initialization**
	```cpp
	    unordered_map<int, int> cnt;
	```
	Initializes an unordered map `cnt` to keep track of the frequency of each age in the `ages` vector.

3. **Loop**
	```cpp
	    for(int age: ages)
	```
	Iterates through each `age` in the `ages` vector to populate the `cnt` map with the count of each age.

4. **Map Update**
	```cpp
	        cnt[age]++;
	```
	Increments the count of the current `age` in the `cnt` map.

5. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Declares and initializes an integer variable `res` to store the total number of valid friend requests.

6. **Nested Loop**
	```cpp
	    for(auto a: cnt)
	```
	Begins a loop that iterates over each age `a` in the `cnt` map, representing the first person in a potential friend request.

7. **Nested Loop**
	```cpp
	    for(auto b: cnt)
	```
	Begins a second nested loop that iterates over each age `b` in the `cnt` map, representing the second person in a potential friend request.

8. **Condition Check**
	```cpp
	    if(request(a.first, b.first))
	```
	Checks whether a valid friend request can be made between person `a` and person `b` by calling the `request` function.

9. **Calculation**
	```cpp
	        res += a.second * (b.second - (a.first == b.first? 1: 0));
	```
	If a valid request is possible, increment `res` by the product of the counts of ages `a` and `b`, adjusting for the case where `a` and `b` are the same age.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total number of valid friend requests calculated.

11. **Function Declaration**
	```cpp
	bool request(int a, int b) {
	```
	Declares the `request` function that checks whether a person with age `a` can send a friend request to a person with age `b` based on specific conditions.

12. **Condition Check**
	```cpp
	    return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
	```
	Returns true if the conditions for a valid friend request are met, otherwise false. The conditions include age restrictions for sending requests.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of people, as we can use frequency counting to reduce the number of comparisons.
- **Average Case:** O(n^2), if we need to check all pairs of ages.
- **Worst Case:** O(n^2), for the largest inputs where all people have distinct ages.

The time complexity is O(n^2) in the worst case, where we need to compare each pair of distinct ages.

### Space Complexity 💾
- **Best Case:** O(1), if there are few distinct ages.
- **Worst Case:** O(n), where n is the number of distinct ages.

The space complexity is O(n) due to the space required for the frequency map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/friends-of-appropriate-ages/description/)

---
{{< youtube 0_4H68f85HQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
