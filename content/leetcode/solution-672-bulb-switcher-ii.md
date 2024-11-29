
+++
authors = ["grid47"]
title = "Leetcode 672: Bulb Switcher II"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 672: Bulb Switcher II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/672.webp"
youtube = "wx272jQLwkA"
youtube_upload_date="2022-12-30"
youtube_thumbnail="https://i.ytimg.com/vi/wx272jQLwkA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/672.webp" 
    alt="A set of bulbs where switches are turned on and off, with each change softly glowing."
    caption="Solution to LeetCode 672: Bulb Switcher II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are in a room with `n` bulbs, all initially turned on. There are four buttons on the wall, each with a different functionality: flip all bulbs, flip even-numbered bulbs, flip odd-numbered bulbs, and flip bulbs with labels `j = 3k + 1`. You need to make exactly `presses` presses. For each press, you can choose any button. Return the number of distinct possible configurations of the bulbs after performing all the presses.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers `n` (the number of bulbs) and `presses` (the number of presses to make).
- **Example:** `n = 3, presses = 1`
- **Constraints:**
	- 1 <= n <= 1000
	- 0 <= presses <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct possible configurations of the bulbs after performing exactly `presses` presses.
- **Example:** `4`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the number of distinct possible configurations after exactly `presses` presses.

- 1. Identify the effect of each button on the bulbs' states.
- 2. Calculate the number of distinct configurations possible based on the combination of button presses.
- 3. Return the number of distinct configurations as the result.
{{< dots >}}
### Problem Assumptions ✅
- The problem assumes that all bulbs are initially on and that presses are made sequentially.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 1, presses = 1`  \
  **Explanation:** With one bulb and one press, the bulb can either be off (by pressing button 1) or stay on (by pressing button 2).

- **Input:** `n = 2, presses = 1`  \
  **Explanation:** With two bulbs and one press, the three possible configurations are [off, off], [on, off], and [off, on].

{{< dots >}}
## Approach 🚀
The solution involves simulating the effect of pressing the buttons and calculating the number of unique configurations.

### Initial Thoughts 💭
- Each button press can affect different bulbs, and some presses may result in the same configuration.
- We need to calculate the number of unique bulb configurations after all presses.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs in this problem.
- Ensure the solution can handle the maximum values of `n` and `presses` (1000 each).
- If `presses` is 0, the configuration remains unchanged, and the result is 1.
- Handle edge cases where `n` is very small or `presses` is 0.
{{< dots >}}
## Code 💻
```cpp
int flipLights(int n, int m) {
    if(m==0) return 1;
    if(n==1) return 2;
    if(n==2&&m==1) return 3;
    if(n==2) return 4;
    if(m==1) return 4;
    if(m==2) return 7;
    if(m>=3) return 8;
    return 8;        
}
```

The `flipLights` function calculates the number of distinct light configurations that can be achieved by flipping `n` lights `m` times, based on a series of conditions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int flipLights(int n, int m) {
	```
	This is the function definition for `flipLights`, which calculates the number of distinct configurations of `n` lights after `m` flips.

2. **Check if m is 0**
	```cpp
	    if(m==0) return 1;
	```
	If `m` is 0, meaning no flips are performed, the function returns 1, representing the initial configuration of the lights.

3. **Check if n is 1**
	```cpp
	    if(n==1) return 2;
	```
	If there is only one light (`n == 1`), there are two possible configurations: on or off, so the function returns 2.

4. **Handle Case for n=2 and m=1**
	```cpp
	    if(n==2&&m==1) return 3;
	```
	If there are two lights (`n == 2`) and one flip (`m == 1`), there are three possible configurations: both off, one on and the other off, or both on, so the function returns 3.

5. **Handle Case for n=2**
	```cpp
	    if(n==2) return 4;
	```
	If there are two lights (`n == 2`), and no other conditions are met, the function returns 4, representing all possible configurations (both off, one on, both on, and the reverse order of the previous configuration).

6. **Handle Case for m=1**
	```cpp
	    if(m==1) return 4;
	```
	If there is only one flip (`m == 1`), and no other conditions are met, the function returns 4, representing the configurations after one flip.

7. **Handle Case for m=2**
	```cpp
	    if(m==2) return 7;
	```
	If there are exactly two flips (`m == 2`), the function returns 7, representing the distinct light configurations that can be achieved with two flips.

8. **Handle Case for m>=3**
	```cpp
	    if(m>=3) return 8;
	```
	If there are three or more flips (`m >= 3`), the function returns 8, representing all possible configurations of the lights.

9. **Return Default Case**
	```cpp
	    return 8;        
	```
	If none of the above conditions are met, return 8 as the default case, representing all possible configurations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * presses)
- **Average Case:** O(n * presses)
- **Worst Case:** O(n * presses)

The time complexity is based on simulating each press, which can involve looping through `n` bulbs for each of the `presses`.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to storing the states of the bulbs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/bulb-switcher-ii/description/)

---
{{< youtube wx272jQLwkA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
