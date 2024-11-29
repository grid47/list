
+++
authors = ["grid47"]
title = "Leetcode 1921: Eliminate Maximum Number of Monsters"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1921: Eliminate Maximum Number of Monsters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6QQRayzOTD4"
youtube_upload_date="2021-07-04"
youtube_thumbnail="https://i.ytimg.com/vi/6QQRayzOTD4/maxresdefault.jpg"
comments = true
+++



---
You are defending your city from a group of n monsters. You are given two arrays dist and speed, where dist[i] is the initial distance of the ith monster from the city, and speed[i] is the speed of the ith monster in kilometers per minute. Your weapon takes one minute to charge and can eliminate one monster once fully charged. The game ends if any monster reaches the city before your weapon is ready. Return the maximum number of monsters you can eliminate or n if all monsters can be eliminated before they reach the city.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays dist and speed, both of size n. dist[i] is the initial distance of the ith monster, and speed[i] is the speed of the ith monster.
- **Example:** `dist = [2,4,6], speed = [2,1,1]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= dist[i], speed[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of monsters that can be eliminated before any of them reach the city, or return n if all monsters can be eliminated.
- **Example:** `3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the time each monster takes to reach the city, sort them, and eliminate monsters one by one until any of them reach the city.

- For each monster, calculate the time it takes to reach the city: dist[i] / speed[i].
- Sort the times in ascending order.
- Iterate through the sorted times, and eliminate monsters as long as their arrival time is greater than the time elapsed (which increases with each elimination).
{{< dots >}}
### Problem Assumptions ✅
- The input arrays dist and speed will always have the same length.
- The values in dist are the initial distances of the monsters, and speed represents their constant speed.
{{< dots >}}
## Examples 🧩
- **Input:** `dist = [2,4,6], speed = [2,1,1]`  \
  **Explanation:** The monsters start at distances [2,4,6] and move at speeds [2,1,1]. We compute the time each monster takes to reach the city, which is [1,4,6]. After eliminating each monster one by one, we find that all 3 can be eliminated before reaching the city.

{{< dots >}}
## Approach 🚀
The approach involves calculating how long each monster takes to reach the city and sorting the times. We then iterate through the sorted list of times, eliminating monsters one by one until we can no longer eliminate any more.

### Initial Thoughts 💭
- We can calculate the time for each monster by dividing dist[i] by speed[i].
- After sorting the monsters by their arrival time, we can eliminate monsters in sequence until we hit a monster that arrives before we can eliminate it.
- The solution relies on sorting and then a single scan through the list of monsters, which ensures it runs in O(n log n) time.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one monster.
- The solution must handle cases where n is large (up to 10^5).
- If all monsters are close to the city and have high speeds, they may reach the city quickly, limiting how many can be eliminated.
- The algorithm needs to be efficient in both time and space due to the constraints on n.
{{< dots >}}
## Code 💻
```cpp
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

    int n = dist.size();
    vector<double> res(n, 0);
    for(int i = 0; i < n; i++)
    res[i] = (double(dist[i]) / speed[i]);

    sort(res.begin(), res.end());

    long j = 0, ans = 0;
    for (int i = 0; i < n; i++)
        if(j < res[i]) {
            ans++;
            j++;
        } else break;

    return (int) ans;
}
```

This function calculates the maximum number of eliminations that can be made from two vectors: 'dist' and 'speed', by calculating the time it takes for each element to reach its destination, sorting the times, and then simulating the eliminations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
	```
	Defines the function 'eliminateMaximum' which accepts two vectors: 'dist' for distances and 'speed' for speeds, and returns an integer value representing the maximum number of eliminations.

2. **Variable Initialization**
	```cpp
	    int n = dist.size();
	```
	Initializes the variable 'n' to store the size of the 'dist' vector.

3. **Array Initialization**
	```cpp
	    vector<double> res(n, 0);
	```
	Initializes a vector 'res' of size 'n' to store the calculated times for each element.

4. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Begins a loop that iterates over each index 'i' of the 'dist' and 'speed' vectors.

5. **Time Calculation**
	```cpp
	    res[i] = (double(dist[i]) / speed[i]);
	```
	Calculates the time taken for each element to reach its destination by dividing the distance 'dist[i]' by the speed 'speed[i]', and stores the result in the 'res' vector.

6. **Sorting**
	```cpp
	    sort(res.begin(), res.end());
	```
	Sorts the 'res' vector in ascending order to get the fastest times first.

7. **Variable Initialization**
	```cpp
	    long j = 0, ans = 0;
	```
	Initializes variables 'j' (the current elimination count) and 'ans' (to store the total number of eliminations).

8. **Loop Start**
	```cpp
	    for (int i = 0; i < n; i++)
	```
	Begins another loop to simulate the elimination process using the sorted times from the 'res' vector.

9. **Condition Check**
	```cpp
	        if(j < res[i]) {
	```
	Checks if the current elimination count 'j' is less than the corresponding time in the sorted 'res' vector.

10. **Elimination**
	```cpp
	            ans++;
	```
	If the condition is met, the elimination count 'ans' is incremented.

11. **Increment**
	```cpp
	            j++;
	```
	Increments the elimination index 'j'.

12. **Exit Condition**
	```cpp
	        } else break;
	```
	If the condition is not met, the loop breaks, stopping the elimination process.

13. **Return Statement**
	```cpp
	    return (int) ans;
	```
	Returns the total number of eliminations as an integer.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The solution requires sorting the times, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store the computed times for each monster, requiring O(n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/)

---
{{< youtube 6QQRayzOTD4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
