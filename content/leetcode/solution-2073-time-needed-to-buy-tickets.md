
+++
authors = ["grid47"]
title = "Leetcode 2073: Time Needed to Buy Tickets"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2073: Time Needed to Buy Tickets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "cVmS9N6kf2Y"
youtube_upload_date="2024-04-09"
youtube_thumbnail="https://i.ytimg.com/vi/cVmS9N6kf2Y/maxresdefault.jpg"
comments = true
+++



---
You are given a queue of `n` people, where each person wants to buy a specific number of tickets. The task is to determine the time taken for the person at index `k` to finish buying all their tickets.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `tickets` of length `n` where each element represents the number of tickets the i-th person wants to buy, and an integer `k` representing the position of the person for whom we need to calculate the time.
- **Example:** `tickets = [3, 2, 5], k = 1`
- **Constraints:**
	- 1 <= n <= 100
	- 1 <= tickets[i] <= 100
	- 0 <= k < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the time taken for the person at position `k` to finish buying all their tickets.
- **Example:** `Output: 8`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the total time it takes for the k-th person to finish buying their tickets based on the ticket queue process.

- Start by simulating the process of people buying tickets.
- For each person, allow them to buy 1 ticket at a time and move to the back of the queue until they finish all their tickets.
- Keep track of the time it takes for the person at position k to complete the process.
{{< dots >}}
### Problem Assumptions ✅
- The people in the queue take 1 second to buy 1 ticket.
- Once a person finishes buying all their tickets, they leave the queue.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the queue initially has the values [3, 2, 5], with the person at index 1 needing to buy tickets. After several rounds of buying tickets, the total time taken for the k-th person to finish is 8 seconds.

{{< dots >}}
## Approach 🚀
The problem is solved by simulating the process of people buying tickets. The k-th person’s time is tracked as the queue progresses.

### Initial Thoughts 💭
- We need to process each person in the queue until the person at index k has finished buying tickets.
- We can iterate over the queue repeatedly, subtracting 1 ticket from each person in each round, until the person at k finishes.
{{< dots >}}
### Edge Cases 🌐
- The queue must not be empty (n >= 1).
- For larger inputs, the algorithm should still work efficiently within the given constraints.
- When k is 0, the first person in the queue, they will finish earlier as they are at the front.
{{< dots >}}
## Code 💻
```cpp
int timeRequiredToBuy(vector<int>& nums, int k) {
    int res = 0, key = nums[k];
    for(int i = 0; i < nums.size(); i++) {
      res += min(key - (i > k), nums[i]);
    }
    return res;
}
```

This function calculates the total time required to buy all items in the `nums` array where each item's purchase time depends on the relative position of the index `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int timeRequiredToBuy(vector<int>& nums, int k) {
	```
	This is the function signature for `timeRequiredToBuy`, which takes two inputs: `nums`, a vector representing the time required to buy each item, and `k`, the index of the item for which the time to purchase is calculated. It returns an integer representing the total time.

2. **Variable Declaration**
	```cpp
	    int res = 0, key = nums[k];
	```
	This line declares two variables: `res` (the variable to accumulate the total time required) and `key` (the time required to buy the item at index `k`).

3. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	This loop iterates over the `nums` vector, processing each item to calculate the total time.

4. **Calculation**
	```cpp
	      res += min(key - (i > k), nums[i]);
	```
	This line updates the total time `res`. It adds the smaller of two values: the time required for the item at index `i`, considering whether `i` is greater than `k`, and the actual time of the item.

5. **Return**
	```cpp
	    return res;
	```
	This line returns the total accumulated time, which is the result of the calculation done in the loop.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The worst case occurs when each person buys at least 1 ticket, resulting in a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use O(n) space to store the tickets array and track the time.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/time-needed-to-buy-tickets/description/)

---
{{< youtube cVmS9N6kf2Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
