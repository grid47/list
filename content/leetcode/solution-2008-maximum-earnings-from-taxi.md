
+++
authors = ["grid47"]
title = "Leetcode 2008: Maximum Earnings From Taxi"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2008: Maximum Earnings From Taxi in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QoAuE1v2vxA"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/QoAuE1v2vxA/maxresdefault.jpg"
comments = true
+++



---
You are driving a taxi along a road with `n` points. Each point represents a location on the road. Passengers request rides from one point to another, and for each ride, you earn the distance traveled plus a tip. Your goal is to maximize your earnings by picking up passengers optimally. You can only carry one passenger at a time, and may pick up a new passenger at any point after dropping off the previous one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two values, `n` and `rides`. `n` is the number of points on the road (1 <= n <= 10^5), and `rides` is a list of ride requests. Each ride is represented as a triplet [start, end, tip], where start and end are points on the road (1 <= start < end <= n), and tip is the additional tip the passenger is willing to give (1 <= tip <= 10^5).
- **Example:** `n = 5, rides = [[2,5,4],[1,5,1]]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= rides.length <= 3 * 10^4
	- rides[i].length == 3
	- 1 <= start < end <= n
	- 1 <= tipi <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum earnings you can achieve by picking up passengers optimally.
- **Example:** `7`
- **Constraints:**
	- The output is a single integer representing the maximum earnings.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the total earnings by picking up passengers in such a way that no two passengers' rides overlap in terms of the points they cover.

- Sort the rides based on the start point of each ride.
- Use dynamic programming to determine the maximum earnings by evaluating each possible ride combination.
- For each ride, determine if it is optimal to pick it up or skip it by considering the maximum earnings from subsequent non-overlapping rides.
{{< dots >}}
### Problem Assumptions ✅
- The ride requests are valid, and each request has valid start and end points.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, rides = [[2,5,4],[1,5,1]]`  \
  **Explanation:** You have two ride requests. You can pick up passenger 0 from point 2 to 5 and earn `5 - 2 + 4 = 7` dollars. Thus, the maximum earnings is 7.

- **Input:** `n = 20, rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]`  \
  **Explanation:** By optimally selecting the rides, you can earn a total of 20 dollars from the given requests.

{{< dots >}}
## Approach 🚀
This problem can be solved using dynamic programming (DP). We will use DP to calculate the maximum earnings we can get for each ride while ensuring that no rides overlap.

### Initial Thoughts 💭
- Sorting the rides based on their start point ensures we consider them in the correct order.
- The key challenge is to efficiently find the next available ride that doesn't overlap with the current one, which can be achieved with binary search.
{{< dots >}}
### Edge Cases 🌐
- If the input rides list is empty, return 0.
- Ensure that the solution handles large input sizes efficiently within time limits.
- Handle cases where multiple rides start at the same point.
- Ensure that no two rides overlap and that each ride's start and end points are valid.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> rides;
vector<long long> memo;
int n;

long long dp(int idx) {
    
    if(idx == rides.size()) return 0;
    
    if(memo[idx] != -1) return memo[idx];
    
    long long ans = dp(idx + 1);
            
    
    int end = rides[idx][1];
    
    int l = idx + 1, r = rides.size() - 1;
    int pos = rides.size();
    
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        if(rides[mid][0] >= end) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
        
    ans = max(ans, dp(pos) + rides[idx][2]);        
    return memo[idx] = ans;
}

long long maxTaxiEarnings(int n, vector<vector<int>>& ride) {
    this->n = n;
    rides = ride;
    sort(rides.begin(), rides.end());
    
    for(int i = 0; i < rides.size(); i++)
        rides[i][2] += rides[i][1] - rides[i][0];
    
    memo.resize(rides.size() + 1, -1);
    return dp(0);

}
```

The code implements a solution for calculating the maximum taxi earnings by considering rides and using dynamic programming for efficient computation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<vector<int>> rides;
	```
	Declares a 2D vector `rides` to store the start and end times of the rides.

2. **Variable Initialization**
	```cpp
	vector<long long> memo;
	```
	Declares a vector `memo` to store the intermediate results of the dynamic programming solution.

3. **Variable Initialization**
	```cpp
	int n;
	```
	Declares an integer variable `n` to store the number of rides.

4. **Function Definition**
	```cpp
	long long dp(int idx) {
	```
	Defines a recursive function `dp` to calculate the maximum earnings starting from the ride at index `idx`.

5. **Base Case**
	```cpp
	    if(idx == rides.size()) return 0;
	```
	Base case for the recursion: if all rides have been processed, return 0.

6. **Memoization Check**
	```cpp
	    if(memo[idx] != -1) return memo[idx];
	```
	Checks if the result for the current index `idx` has been computed before, and if so, returns the memoized result.

7. **Recursive Call**
	```cpp
	    long long ans = dp(idx + 1);
	```
	Makes a recursive call to calculate the earnings from the next ride.

8. **Ride End Calculation**
	```cpp
	    int end = rides[idx][1];
	```
	Stores the end time of the current ride.

9. **Binary Search Initialization**
	```cpp
	    int l = idx + 1, r = rides.size() - 1;
	```
	Initializes the left (`l`) and right (`r`) pointers for binary search to find the next non-overlapping ride.

10. **Binary Search**
	```cpp
	    int pos = rides.size();
	```
	Initializes `pos` to store the position of the next ride that starts after the current one ends.

11. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Starts the binary search loop to find the next ride that starts after the current one ends.

12. **Binary Search Check**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculates the middle point of the current binary search range.

13. **Binary Search Update**
	```cpp
	        if(rides[mid][0] >= end) {
	```
	Checks if the start time of the middle ride is after or equal to the current ride's end time.

14. **Binary Search Position Update**
	```cpp
	            pos = mid;
	```
	Updates the position `pos` to the middle index since it is a valid candidate for the next ride.

15. **Binary Search Range Update**
	```cpp
	            r = mid - 1;
	```
	Adjusts the binary search range to the left half.

16. **Binary Search Range Update**
	```cpp
	        } else {
	```
	If the current middle ride doesn't satisfy the condition, adjust the range to the right half.

17. **Binary Search Range Update**
	```cpp
	            l = mid + 1;
	```
	Adjusts the binary search range to the right half.

18. **Recursion Update**
	```cpp
	    ans = max(ans, dp(pos) + rides[idx][2]);
	```
	Updates the result by taking the maximum of the current earnings and the earnings from the next non-overlapping ride plus the current ride's earnings.

19. **Memoization**
	```cpp
	    return memo[idx] = ans;
	```
	Stores the computed result for the current index `idx` in the `memo` array.

20. **Main Function**
	```cpp
	long long maxTaxiEarnings(int n, vector<vector<int>>& ride) {
	```
	Defines the main function `maxTaxiEarnings` that initializes necessary variables and calls the recursive function `dp`.

21. **Variable Initialization**
	```cpp
	    this->n = n;
	```
	Assigns the value of `n` to the class member variable `n`.

22. **Variable Initialization**
	```cpp
	    rides = ride;
	```
	Assigns the input `ride` vector to the `rides` variable.

23. **Sorting**
	```cpp
	    sort(rides.begin(), rides.end());
	```
	Sorts the `rides` vector based on the start times of the rides.

24. **Earnings Update**
	```cpp
	    for(int i = 0; i < rides.size(); i++)
	```
	Iterates through the rides to update the earnings for each ride by adding the duration (end - start).

25. **Earnings Update**
	```cpp
	        rides[i][2] += rides[i][1] - rides[i][0];
	```
	Updates the earnings for each ride by adding the duration (end - start) to the third element.

26. **Memoization**
	```cpp
	    memo.resize(rides.size() + 1, -1);
	```
	Resizes the `memo` vector to accommodate the results for each ride and initializes all entries to -1.

27. **Return DP Call**
	```cpp
	    return dp(0);
	```
	Calls the `dp` function starting from the first ride and returns the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) due to sorting and binary search.
- **Average Case:** O(n log n).
- **Worst Case:** O(n log n) because of the sorting and binary search for each ride.

The time complexity is dominated by the sorting of the rides and the binary search for the next available ride.

### Space Complexity 💾
- **Best Case:** O(n).
- **Worst Case:** O(n) for storing the rides and memoization array.

Space complexity is linear due to the storage of ride data and memoization for dynamic programming.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-earnings-from-taxi/description/)

---
{{< youtube QoAuE1v2vxA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
