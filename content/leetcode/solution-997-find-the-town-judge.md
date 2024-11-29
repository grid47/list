
+++
authors = ["grid47"]
title = "Leetcode 997: Find the Town Judge"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 997: Find the Town Judge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "xR2Qg9ENtKQ"
youtube_upload_date="2020-05-10"
youtube_thumbnail="https://i.ytimg.com/vi/xR2Qg9ENtKQ/maxresdefault.jpg"
comments = true
+++



---
In a town with n people, one person may be the judge. The judge trusts no one and is trusted by everyone else. Given a list of trust relationships, identify the town judge or return -1 if no judge exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a number n (the total number of people) and an array trust where trust[i] = [a, b] means that person a trusts person b.
- **Example:** `n = 2, trust = [[1, 2]]`
- **Constraints:**
	- 1 <= n <= 1000
	- 0 <= trust.length <= 104
	- trust[i].length == 2
	- ai != bi
	- 1 <= ai, bi <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the label of the town judge if one exists, or return -1 if no judge can be identified.
- **Example:** `Output: 2`
- **Constraints:**
	- The label of the town judge should be between 1 and n, inclusive.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the person who satisfies the judge's conditions of being trusted by everyone and trusting no one.

- Step 1: Create an array to track the trust levels of each person.
- Step 2: Update the trust levels based on the trust relationships.
- Step 3: Identify the person who has trust level n-1 (trusted by everyone else and trusts no one).
- Step 4: Return the person if found, or -1 if no such person exists.
{{< dots >}}
### Problem Assumptions ✅
- The grid of trust relationships is sparse and doesn't contain redundant pairs.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 2, trust = [[1, 2]]`  \
  **Explanation:** Person 2 is the town judge because they are trusted by person 1 and trust no one else.

- **Input:** `n = 3, trust = [[1, 3], [2, 3]]`  \
  **Explanation:** Person 3 is trusted by both person 1 and person 2, and trusts no one else, making them the town judge.

- **Input:** `n = 3, trust = [[1, 3], [2, 3], [3, 1]]`  \
  **Explanation:** Person 3 cannot be the judge because they trust person 1, violating the condition that the judge trusts no one.

{{< dots >}}
## Approach 🚀
We can solve the problem by using a degree array to track the net trust level of each person.

### Initial Thoughts 💭
- We need to identify the person who is trusted by everyone but trusts no one.
- A simple solution would be to use an array to track the trust level of each person, and then check if any person has a trust level of n-1.
{{< dots >}}
### Edge Cases 🌐
- If trust array is empty, return -1 as no one trusts anyone.
- For large inputs, the solution should efficiently handle trust relationships up to the limit of 10^4.
- If all people trust each other, no town judge exists.
- The solution should work for input sizes up to the maximum constraint of 10^4 trust relationships.
{{< dots >}}
## Code 💻
```cpp
int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> deg(n + 1, 0);
    for(auto x: trust) {
        deg[x[1]]++;
        deg[x[0]]--;
    }
    for(int i = 1; i <= n; i++)
        if(deg[i] == n - 1) return i;
    
    return -1;
}
```

This function determines the town judge in a town of 'n' people based on the trust relationships provided. It returns the town judge if one exists, otherwise it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findJudge(int n, vector<vector<int>>& trust) {
	```
	Defines the function `findJudge` which takes the total number of people (`n`) and a 2D vector `trust` representing trust relationships between people in the town.

2. **Array Initialization**
	```cpp
	    vector<int> deg(n + 1, 0);
	```
	Initializes a vector `deg` to track the net trust score for each person. Each index represents a person, where the value indicates how many people trust them and how many they trust.

3. **Trust Relationships Processing**
	```cpp
	    for(auto x: trust) {
	```
	Loops through each trust relationship in the `trust` vector.

4. **Trust Score Update**
	```cpp
	        deg[x[1]]++;
	```
	Increments the trust score of the person being trusted (`x[1]`) as they gain one more trust.

5. **Trust Score Update**
	```cpp
	        deg[x[0]]--;
	```
	Decrements the trust score of the person who is trusting (`x[0]`) as they lose one trust.

6. **Judge Identification**
	```cpp
	    for(int i = 1; i <= n; i++)
	```
	Loops through each person in the town (from 1 to n).

7. **Judge Identification**
	```cpp
	        if(deg[i] == n - 1) return i;
	```
	Checks if the current person `i` has a trust score of `n - 1`, indicating that they are trusted by everyone else and trust no one. If true, returns this person as the town judge.

8. **Function Return**
	```cpp
	    return -1;
	```
	Returns `-1` if no judge is found, meaning no person satisfies the conditions to be the town judge.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - If no trust relationships exist, the solution only needs to check each person once.
- **Average Case:** O(n + t) - The time complexity is proportional to the number of people and the trust relationships.
- **Worst Case:** O(n + t) - In the worst case, we process all trust relationships and check each person's trust level.

The time complexity is linear with respect to the number of people and trust relationships.

### Space Complexity 💾
- **Best Case:** O(n) - Even if there are no trust relationships, the space complexity remains linear.
- **Worst Case:** O(n) - We use an array to track the trust levels of n people.

The space complexity is linear in terms of the number of people.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-town-judge/description/)

---
{{< youtube xR2Qg9ENtKQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
