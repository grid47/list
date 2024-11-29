
+++
authors = ["grid47"]
title = "Leetcode 1705: Maximum Number of Eaten Apples"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1705: Maximum Number of Eaten Apples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1vRYTJqaZ8s"
youtube_upload_date="2020-12-27"
youtube_thumbnail="https://i.ytimg.com/vi/1vRYTJqaZ8s/maxresdefault.jpg"
comments = true
+++



---
You have a special apple tree that grows apples for 'n' days. On each day 'i', the tree grows 'apples[i]' apples, which rot after 'days[i]' days. That means, apples grown on day 'i' will rot after 'i + days[i]'. You can eat at most one apple per day, and you can continue eating after the first 'n' days. You want to know the maximum number of apples you can eat.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays, 'apples' and 'days', both of length 'n'.
- **Example:** `[1, 2, 3, 5, 2], [3, 2, 1, 4, 2]`
- **Constraints:**
	- n == apples.length == days.length
	- 1 <= n <= 2 * 10^4
	- 0 <= apples[i], days[i] <= 2 * 10^4
	- days[i] = 0 if and only if apples[i] = 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of apples you can eat.
- **Example:** `7`
- **Constraints:**
	- The output should be an integer representing the maximum apples you can eat.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the number of apples eaten by choosing the best apples to eat each day, considering their expiry dates.

- 1. Use a priority queue to store the apples that are still available for eating.
- 2. For each day, add newly grown apples to the queue, keeping track of their expiry date.
- 3. Eat the apple with the earliest expiry date available on that day.
- 4. Continue until no more apples are left to eat.
{{< dots >}}
### Problem Assumptions ✅
- The tree will grow apples for 'n' days, and we can eat at most one apple per day.
- Some days may have zero apples grown, in which case nothing rots.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 2, 3, 5, 2], [3, 2, 1, 4, 2]`  \
  **Explanation:** On day 1, you eat an apple grown on day 1. On day 2, you eat an apple grown on day 2. On day 3, you eat an apple grown on day 2. From day 4 to day 7, you eat apples grown on day 4. In total, you eat 7 apples.

- **Input:** `[3, 0, 0, 0, 0, 2], [3, 0, 0, 0, 0, 2]`  \
  **Explanation:** On day 1 to day 3, you eat apples grown on day 1. On day 6 and day 7, you eat apples grown on day 6. In total, you eat 5 apples.

{{< dots >}}
## Approach 🚀
The approach involves using a priority queue to always eat the apple that will rot the soonest.

### Initial Thoughts 💭
- We need to prioritize eating apples that will rot sooner.
- A priority queue is suitable for this problem because it allows us to efficiently get the apple that rots the soonest.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there will be at least one apple in the input, so no need to handle empty arrays.
- Ensure that the solution can handle arrays with a length up to 20,000.
- If an apple's growth or expiry is zero, it should be skipped accordingly.
- The priority queue approach ensures that we efficiently handle large inputs.
{{< dots >}}
## Code 💻
```cpp
int eatenApples(vector<int>& apples, vector<int>& days) {
    
    int n = days.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int res = 0, i = 0;
    
    while(i < n || !pq.empty()) {

        if(i < n && apples[i] > 0) pq.push({i + days[i] - 1, apples[i]});
        
        while(!pq.empty() && pq.top()[0] < i)
            pq.pop();
        
        if(!pq.empty()) {
            res++;
            auto it = pq.top();
            pq.pop();
            if(it[1] > 1) pq.push({it[0], it[1] - 1});
        }
        i++;
    }
        
    return res;
}
```

This function simulates the process of eating apples. Each apple has a shelf life (in days), and the function determines how many apples can be eaten before they spoil.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int eatenApples(vector<int>& apples, vector<int>& days) {
	```
	Defines the function `eatenApples`, which calculates the number of apples that can be eaten before they spoil.

2. **Variable Initialization**
	```cpp
	    int n = days.size();
	```
	Initializes `n` to the size of the `days` vector, which represents the total number of apples.

3. **Priority Queue Setup**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	```
	Sets up a priority queue `pq` that stores apples and their expiration days in ascending order of expiration.

4. **Variable Initialization**
	```cpp
	    int res = 0, i = 0;
	```
	Initializes two variables: `res` to track the number of apples eaten and `i` as an index for the days.

5. **Main Loop**
	```cpp
	    while(i < n || !pq.empty()) {
	```
	Starts a loop that continues while there are apples to process or apples in the priority queue.

6. **Add New Apples to Queue**
	```cpp
	        if(i < n && apples[i] > 0) pq.push({i + days[i] - 1, apples[i]});
	```
	If there are apples available, adds them to the priority queue with their expiration date and quantity.

7. **Remove Expired Apples**
	```cpp
	        while(!pq.empty() && pq.top()[0] < i)
	```
	Removes apples from the priority queue that have expired before the current day `i`.

8. **Pop Expired Apples**
	```cpp
	            pq.pop();
	```
	Pops expired apples from the priority queue.

9. **Eat Apple if Available**
	```cpp
	        if(!pq.empty()) {
	```
	Checks if there are any apples remaining in the priority queue to be eaten.

10. **Increment Apple Counter**
	```cpp
	            res++;
	```
	Increments the counter `res` to track the number of apples eaten.

11. **Get Apple from Queue**
	```cpp
	            auto it = pq.top();
	```
	Retrieves the apple with the earliest expiration date from the priority queue.

12. **Pop Eaten Apple**
	```cpp
	            pq.pop();
	```
	Pops the apple from the priority queue after it has been eaten.

13. **Re-add Apple if Not Fully Eaten**
	```cpp
	            if(it[1] > 1) pq.push({it[0], it[1] - 1});
	```
	If there are still apples remaining after eating one, re-adds them to the priority queue with a reduced quantity.

14. **Increment Day Counter**
	```cpp
	        i++;
	```
	Increments the day counter `i` to simulate moving to the next day.

15. **Return Result**
	```cpp
	    return res;
	```
	Returns the total number of apples that were successfully eaten.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the length of the input arrays. The best case occurs when we need to process all apples.
- **Average Case:** O(n log n), since each operation on the priority queue (insertion and removal) takes O(log n).
- **Worst Case:** O(n log n), as we might need to process all apples and remove them from the queue.

The time complexity is dominated by the operations on the priority queue.

### Space Complexity 💾
- **Best Case:** O(1), if no apples are available to eat.
- **Worst Case:** O(n), as the priority queue can contain all apples at once.

The space complexity is O(n) due to the storage of apples in the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-eaten-apples/description/)

---
{{< youtube 1vRYTJqaZ8s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
