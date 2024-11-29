
+++
authors = ["grid47"]
title = "Leetcode 1620: Coordinate With Maximum Network Quality"
date = "2024-05-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1620: Coordinate With Maximum Network Quality in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TqKDnzkRsh0"
youtube_upload_date="2020-11-30"
youtube_thumbnail="https://i.ytimg.com/vi/TqKDnzkRsh0/maxresdefault.jpg"
comments = true
+++



---
You are given an array of network towers, where each tower is represented by a list [xi, yi, qi] denoting its location (xi, yi) on the X-Y plane and its quality factor qi. You are also given a radius, and a tower is considered reachable if the distance between the tower and a coordinate is less than or equal to the radius. The signal quality of a tower at a coordinate (x, y) is calculated using the formula ⌊qi / (1 + d)⌋, where d is the Euclidean distance between the tower and the coordinate. The total network quality at a coordinate is the sum of the signal qualities from all the reachable towers. Your task is to find the coordinate with the maximum network quality. If multiple coordinates have the same network quality, return the lexicographically smallest coordinate.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of towers, where each tower is represented by [xi, yi, qi], and an integer radius.
- **Example:** `towers = [[3, 4, 5], [7, 8, 9], [2, 1, 10]], radius = 3`
- **Constraints:**
	- 1 <= towers.length <= 50
	- towers[i].length == 3
	- 0 <= xi, yi, qi <= 50
	- 1 <= radius <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the coordinate [cx, cy] with the highest network quality. If there are multiple such coordinates, return the lexicographically smallest one.
- **Example:** `For towers = [[3, 4, 5], [7, 8, 9], [2, 1, 10]] and radius = 3, the output would be [3, 4].`
- **Constraints:**
	- The result should be a valid coordinate in the form of an array with two integers [cx, cy].

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the network quality by evaluating all possible coordinates within the range and checking the signal strength from reachable towers.

- For each possible coordinate (cx, cy) within a bounded grid (0 <= cx, cy <= 50), calculate the network quality by summing the signal strengths from all reachable towers.
- A tower is reachable if its Euclidean distance to the coordinate is less than or equal to the given radius.
- Compare the network quality for all coordinates and keep track of the maximum quality.
- If multiple coordinates have the same quality, return the lexicographically smallest one.
{{< dots >}}
### Problem Assumptions ✅
- Coordinates and tower data are provided within the given bounds.
- Euclidean distance is used for determining the reachability of towers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: towers = [[3, 4, 5], [7, 8, 9], [2, 1, 10]], radius = 3`  \
  **Explanation:** At coordinate (3, 4), the signal strengths from the reachable towers (those within the radius) are summed to give the network quality. This is compared with other coordinates to find the maximum network quality.

- **Input:** `Input: towers = [[5, 7, 6], [1, 2, 8], [8, 3, 4]], radius = 4`  \
  **Explanation:** The network quality is calculated for all possible coordinates within the given range, and the coordinate with the highest quality is selected.

- **Input:** `Input: towers = [[1, 1, 5], [2, 2, 7], [3, 3, 9]], radius = 5`  \
  **Explanation:** The signal strengths are evaluated at different coordinates, and the coordinate with the highest sum of signal qualities is returned.

{{< dots >}}
## Approach 🚀
The approach involves iterating over all possible coordinates and calculating the total network quality by checking the reachability of each tower based on the Euclidean distance.

### Initial Thoughts 💭
- We need to calculate the signal quality for each reachable tower and sum them for all potential coordinates.
- We can brute-force all coordinates in the given range and evaluate the network quality for each, but care should be taken to handle the radius constraint efficiently.
{{< dots >}}
### Edge Cases 🌐
- If no towers are provided, the result should be a default coordinate, e.g., [0, 0].
- The algorithm should handle up to 50 towers efficiently.
- The radius can be small (1), in which case only very nearby towers will contribute to the network quality.
- Make sure to efficiently calculate the Euclidean distance to avoid excessive computation.
{{< dots >}}
## Code 💻
```cpp
vector<int> bestCoordinate(vector<vector<int>>& tow, int rad) {
    
    int n = tow.size();

    int mx = INT_MIN;
    vector<vector<int>> res;
    
    for(int i = 0; i <= 50; i++)
    for(int j = 0; j <= 50; j++) {
        
        int sum = 0;
        for(int k = 0; k < n; k++) {
            int x = tow[k][0], y = tow[k][1];
            float r = sqrt((x - i) * (x - i) + (y - j) * (y - j));
            int ss = 0;
            if(r <= rad) {
                ss = tow[k][2]/(1 + r);
            }
            sum += ss;
        }
        if(mx < sum) {
            mx = sum;
            res = {{i, j}};
        } else if(mx == sum) {
            res.push_back({i, j});
        }
    }
    sort(res.begin(), res.end());
    return res[0];
}
```

This function determines the best coordinate from a set of coordinates, based on the maximum sum of contributions from nearby points within a specified radius. The best coordinate is the one that yields the highest score when considering all points within a distance determined by the radius.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> bestCoordinate(vector<vector<int>>& tow, int rad) {
	```
	Define the function `bestCoordinate` which takes a 2D vector of points `tow` and a radius `rad`. The function aims to return the best coordinate based on maximum weighted sum of nearby points within the radius.

2. **Variable Initialization**
	```cpp
	    int n = tow.size();
	```
	Initialize variable `n` to hold the size of the `tow` array, representing the number of points in the input.

3. **Variable Initialization**
	```cpp
	    int mx = INT_MIN;
	```
	Initialize `mx` to hold the maximum score (initialized to the smallest integer value) to track the highest possible sum.

4. **Vector Initialization**
	```cpp
	    vector<vector<int>> res;
	```
	Initialize an empty 2D vector `res` to store the coordinates with the best score.

5. **For Loop**
	```cpp
	    for(int i = 0; i <= 50; i++)
	```
	Outer loop iterating over possible x-coordinates (ranging from 0 to 50).

6. **For Loop**
	```cpp
	    for(int j = 0; j <= 50; j++) {
	```
	Inner loop iterating over possible y-coordinates (ranging from 0 to 50).

7. **Variable Initialization**
	```cpp
	        int sum = 0;
	```
	Initialize the variable `sum` to store the cumulative score for the current coordinate (i, j).

8. **For Loop**
	```cpp
	        for(int k = 0; k < n; k++) {
	```
	Loop through all points in the input `tow` array to calculate the contribution of each point to the score.

9. **Variable Initialization**
	```cpp
	            int x = tow[k][0], y = tow[k][1];
	```
	Extract the x and y coordinates of the current point `k` from the `tow` array.

10. **Distance Calculation**
	```cpp
	            float r = sqrt((x - i) * (x - i) + (y - j) * (y - j));
	```
	Calculate the Euclidean distance `r` from the current point `(x, y)` to the current coordinate `(i, j)`. This distance determines how much contribution the point will have based on its proximity.

11. **Variable Initialization**
	```cpp
	            int ss = 0;
	```
	Initialize the variable `ss` to store the contribution of the current point to the score.

12. **Conditional Statement**
	```cpp
	            if(r <= rad) {
	```
	Check if the point is within the given radius `rad`.

13. **Score Calculation**
	```cpp
	                ss = tow[k][2]/(1 + r);
	```
	If the point is within radius, calculate its contribution to the score based on its value `tow[k][2]` divided by `(1 + r)` where `r` is the distance.

14. **End Conditional Statement**
	```cpp
	            }
	```
	End the if-statement checking if the point is within radius.

15. **Score Update**
	```cpp
	            sum += ss;
	```
	Add the contribution `ss` to the total score `sum`.

16. **End For Loop**
	```cpp
	        }
	```
	End the loop over all points.

17. **Conditional Statement**
	```cpp
	        if(mx < sum) {
	```
	Check if the current total score `sum` is greater than the maximum score `mx`.

18. **Score Update**
	```cpp
	            mx = sum;
	```
	If the current score is higher, update the maximum score `mx`.

19. **Best Coordinate Update**
	```cpp
	            res = {{i, j}};
	```
	Update the best coordinates `res` with the current coordinate `(i, j)`.

20. **Conditional Statement**
	```cpp
	        } else if(mx == sum) {
	```
	If the current score equals the maximum score, add the current coordinate `(i, j)` to the list of best coordinates.

21. **Best Coordinate Update**
	```cpp
	            res.push_back({i, j});
	```
	Add the current coordinate `(i, j)` to the `res` list of best coordinates.

22. **End Conditional Statement**
	```cpp
	        }
	```
	End the conditional check for the maximum score.

23. **Sorting**
	```cpp
	    sort(res.begin(), res.end());
	```
	Sort the list of best coordinates `res` in lexicographical order.

24. **Return Statement**
	```cpp
	    return res[0];
	```
	Return the first coordinate in the sorted list as the best coordinate.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m^2)
- **Average Case:** O(n * m^2)
- **Worst Case:** O(n * m^2)

Here, n is the number of towers (up to 50), and m is the maximum size of the coordinate grid (51).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m^2)

In the worst case, the space complexity is O(m^2) for storing the network quality calculations for each coordinate.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/coordinate-with-maximum-network-quality/description/)

---
{{< youtube TqKDnzkRsh0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
