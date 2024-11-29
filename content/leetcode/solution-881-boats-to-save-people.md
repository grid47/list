
+++
authors = ["grid47"]
title = "Leetcode 881: Boats to Save People"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 881: Boats to Save People in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FygGZScawYs"
youtube_upload_date="2023-04-03"
youtube_thumbnail="https://i.ytimg.com/vi/FygGZScawYs/maxresdefault.jpg"
comments = true
+++



---
You are given a list of people where each person has a certain weight, and a boat with a weight limit. Each boat can carry at most two people at the same time, as long as their combined weight does not exceed the boat's weight limit. Your task is to determine the minimum number of boats required to rescue everyone.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers where each integer represents the weight of a person. You are also given a weight limit that each boat can carry.
- **Example:** `Input: people = [2, 3, 5, 8], limit = 8`
- **Constraints:**
	- 1 <= people.length <= 5 * 10^4
	- 1 <= people[i] <= limit <= 3 * 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** You should return a single integer, which represents the minimum number of boats required to carry all the people.
- **Example:** `Output: 3`
- **Constraints:**
	- The output is a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of boats used while ensuring that no boat carries more than its weight limit.

- Sort the list of people by their weight.
- Use a two-pointer technique where one pointer starts at the lightest person and the other starts at the heaviest.
- If the combined weight of the two people is within the limit, they can share a boat.
- If not, the heavier person takes a boat alone.
- Continue this process until all people have been assigned to a boat.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains weights of people that range between 1 and the boat's limit.
- There are no edge cases where a person weighs more than the boat's limit, as this will never be the case based on the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: people = [2, 3, 5, 8], limit = 8`  \
  **Explanation:** The sorted people array is [2, 3, 5, 8]. The heaviest person (8) takes a boat alone, the next pair (2, 5) can share a boat, leaving 3 to take a boat on their own. Hence, 3 boats are needed.

- **Input:** `Input: people = [4, 2, 6, 3], limit = 7`  \
  **Explanation:** The sorted people array is [2, 3, 4, 6]. The pair (2, 6) shares a boat, and the pair (3, 4) shares a boat. Hence, 2 boats are needed.

{{< dots >}}
## Approach 🚀
The solution can be approached using a greedy strategy with a two-pointer technique. By sorting the array of people, we can try to pair the lightest and heaviest people to minimize the number of boats used.

### Initial Thoughts 💭
- The lightest and heaviest people should ideally share a boat if their combined weight is within the limit.
- By sorting the people by their weights and applying a two-pointer strategy, we can efficiently assign people to boats.
{{< dots >}}
### Edge Cases 🌐
- The problem constraints guarantee that there will be at least one person.
- Ensure that the solution can handle up to 50,000 people efficiently.
- When everyone is of the same weight, pairing them optimally will reduce the number of boats.
- The input size can be large, so an efficient solution using sorting and two-pointer strategy is required.
{{< dots >}}
## Code 💻
```cpp
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int lo = 0, hi = people.size() - 1;
    int boats = 0;
    while(lo <= hi) {
        
        if(people[lo] + people[hi] <= limit) {
            lo += 1;
            hi -= 1;
        } else hi -= 1;
        
        boats++;
    }
    
    return boats;
}
```

This algorithm calculates the minimum number of boats required to rescue all the people. It sorts the people by weight and uses a two-pointer technique to pair the heaviest and lightest people that can fit into a boat together.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numRescueBoats(vector<int>& people, int limit) {
	```
	This line defines the function `numRescueBoats` that accepts a vector of people and a limit for the boat's weight capacity.

2. **Sorting**
	```cpp
	    sort(people.begin(), people.end());
	```
	The list of people is sorted in non-decreasing order to facilitate pairing the heaviest and lightest people.

3. **Initialization**
	```cpp
	    int lo = 0, hi = people.size() - 1;
	```
	Two pointers `lo` and `hi` are initialized, where `lo` points to the lightest person, and `hi` points to the heaviest.

4. **Variable Setup**
	```cpp
	    int boats = 0;
	```
	A counter `boats` is initialized to track the number of boats needed.

5. **Loop Setup**
	```cpp
	    while(lo <= hi) {
	```
	The loop continues as long as the `lo` pointer is less than or equal to the `hi` pointer, meaning there are people still unpaired.

6. **Condition Check**
	```cpp
	        if(people[lo] + people[hi] <= limit) {
	```
	The condition checks if the lightest (`lo`) and heaviest (`hi`) person can be paired together in one boat without exceeding the weight limit.

7. **Pointer Adjustment**
	```cpp
	            lo += 1;
	```
	If they can be paired, the `lo` pointer is moved right to consider the next lightest person.

8. **Pointer Adjustment**
	```cpp
	            hi -= 1;
	```
	The `hi` pointer is moved left to consider the next heaviest person.

9. **Condition Check (Else)**
	```cpp
	        } else hi -= 1;
	```
	If the lightest and heaviest people can't fit together, only the heaviest person (pointed by `hi`) is placed in a boat.

10. **Boats Increment**
	```cpp
	        boats++;
	```
	Regardless of whether two people are paired or only one person is placed in the boat, the boat count is incremented.

11. **Return Statement**
	```cpp
	    return boats;
	```
	The function returns the total number of boats needed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), followed by a linear scan with two pointers.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting the array, though this could be O(1) if sorting in place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/boats-to-save-people/description/)

---
{{< youtube FygGZScawYs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
