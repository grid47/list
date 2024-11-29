
+++
authors = ["grid47"]
title = "Leetcode 2126: Destroying Asteroids"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2126: Destroying Asteroids in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "e9FIRRXjKJI"
youtube_upload_date="2022-01-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/e9FIRRXjKJI/maxresdefault.webp"
comments = true
+++



---
You are given a planet with an initial mass. There are asteroids approaching the planet, each with its own mass. The planet can destroy an asteroid if its current mass is greater than or equal to the asteroid's mass. After destroying an asteroid, the planet's mass increases by the asteroid's mass. You need to determine if the planet can destroy all the asteroids by strategically choosing the order of the collisions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer representing the planet's mass and an array of integers representing the mass of each asteroid.
- **Example:** `mass = 15, asteroids = [7, 4, 9, 3, 2]`
- **Constraints:**
	- 1 <= mass <= 10^5
	- 1 <= asteroids.length <= 10^5
	- 1 <= asteroids[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if all the asteroids can be destroyed, otherwise return false.
- **Example:** `Input: mass = 15, asteroids = [7, 4, 9, 3, 2] Output: true`
- **Constraints:**
	- The mass of the planet and asteroids is within the specified range.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if the planet can destroy all the asteroids, we need to check if the planet's mass is sufficient for each asteroid as we go through the list.

- Sort the asteroids in ascending order.
- Iterate over each asteroid and check if the planet's current mass is greater than or equal to the asteroid's mass.
- If the planet can destroy the asteroid, increase the planet's mass by the asteroid's mass.
- If at any point the planet cannot destroy an asteroid, return false.
{{< dots >}}
### Problem Assumptions ✅
- The asteroids are processed in a way that allows the planet to destroy them in the most efficient order.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mass = 15, asteroids = [7, 4, 9, 3, 2]`  \
  **Explanation:** The planet starts with a mass of 15. By sorting the asteroids, the planet can destroy them in the order [2, 3, 4, 7, 9]. After destroying all asteroids, the planet's mass will be 15 + 2 + 3 + 4 + 7 + 9 = 40. Since the planet can destroy all asteroids, the output is true.

- **Input:** `Input: mass = 10, asteroids = [4, 9, 8, 6]`  \
  **Explanation:** The planet starts with a mass of 10. By sorting the asteroids, the planet can destroy them in the order [4, 6, 8]. However, after destroying the asteroid with mass 8, the planet's mass is still only 18, which is not enough to destroy the asteroid with mass 9. Therefore, the output is false.

{{< dots >}}
## Approach 🚀
To solve this problem, we can first sort the asteroids by mass in ascending order, then iterate through them to check if the planet can destroy each asteroid. If the planet cannot destroy an asteroid, we return false.

### Initial Thoughts 💭
- Sorting the asteroids allows the planet to destroy the smaller ones first, maximizing its chances of surviving.
- We need to ensure that the planet's mass is always sufficient to destroy the next asteroid.
{{< dots >}}
### Edge Cases 🌐
- If there are no asteroids, return true since there is nothing to destroy.
- Ensure that the solution efficiently handles up to 10^5 asteroids.
- If the planet's mass is very small compared to the asteroids, it may not be able to destroy even the smallest asteroid.
- The solution should be able to handle the maximum number of asteroids and mass values.
{{< dots >}}
## Code 💻
```cpp
bool asteroidsDestroyed(int mass, vector<int>& ast) {
    sort(ast.begin(), ast.end());
    int n = ast.size();
    long long mss = mass;
    for(int i = 0;i < n; i++) {
        if(mss >= ast[i])
            mss += ast[i];
        else return false;
    }
    return true;
}
```

This function determines if a spacecraft can destroy all asteroids in the array. Starting with an initial mass, it checks if the mass is enough to destroy each asteroid, updating the mass after each destruction. If at any point the mass is insufficient, it returns false.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool asteroidsDestroyed(int mass, vector<int>& ast) {
	```
	This line defines the function 'asteroidsDestroyed', which takes an integer 'mass' (the initial mass) and a reference to a vector 'ast' (representing the asteroid sizes) as input. The function returns a boolean indicating whether all asteroids can be destroyed.

2. **Sorting**
	```cpp
	    sort(ast.begin(), ast.end());
	```
	This line sorts the asteroid sizes in ascending order, ensuring the spacecraft will destroy the smallest asteroids first, which maximizes the chance of success.

3. **Variable Initialization**
	```cpp
	    int n = ast.size();
	```
	This line stores the number of asteroids in the variable 'n', which will be used in the subsequent loop to iterate over all asteroids.

4. **Variable Initialization**
	```cpp
	    long long mss = mass;
	```
	This line initializes 'mss' with the spacecraft's initial mass. The variable 'mss' will be updated as asteroids are destroyed.

5. **Loop Start**
	```cpp
	    for(int i = 0;i < n; i++) {
	```
	This line starts a loop that iterates over each asteroid in the sorted 'ast' vector.

6. **Check Mass Sufficiency**
	```cpp
	        if(mss >= ast[i])
	```
	This line checks if the spacecraft's current mass ('mss') is greater than or equal to the mass of the current asteroid ('ast[i]'). If the mass is sufficient, it proceeds to destroy the asteroid.

7. **Update Mass**
	```cpp
	            mss += ast[i];
	```
	This line updates the spacecraft's mass by adding the mass of the destroyed asteroid to 'mss'.

8. **Return False**
	```cpp
	        else return false;
	```
	If at any point the spacecraft's mass is insufficient to destroy the asteroid, this line returns false, indicating the spacecraft cannot destroy all asteroids.

9. **Return True**
	```cpp
	    return true;
	```
	If the loop completes without returning false, this line returns true, indicating the spacecraft was able to destroy all asteroids.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The sorting step takes O(n log n), and the iteration over the asteroids takes O(n). Thus, the overall time complexity is O(n log n), where n is the number of asteroids.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the sorted list of asteroids, but can be O(1) if sorting is done in-place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/destroying-asteroids/description/)

---
{{< youtube e9FIRRXjKJI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
