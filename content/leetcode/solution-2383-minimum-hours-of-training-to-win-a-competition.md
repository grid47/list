
+++
authors = ["grid47"]
title = "Leetcode 2383: Minimum Hours of Training to Win a Competition"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2383: Minimum Hours of Training to Win a Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ueU_i8H3-9g"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ueU_i8H3-9g/maxresdefault.webp"
comments = true
+++



---
You are preparing for a competition where you will face a series of opponents. Each opponent has a specified energy and experience. To defeat an opponent, your energy and experience must both exceed theirs. Before entering the competition, you are allowed to train to improve your energy or experience. For every hour of training, you can either increase your energy or your experience by one. You need to determine the minimum number of training hours required to defeat all the opponents in order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, initialEnergy and initialExperience, representing your initial energy and experience, respectively. It also includes two arrays, energy and experience, where each element corresponds to an opponent's energy and experience.
- **Example:** `initialEnergy = 5, initialExperience = 3, energy = [1, 4, 3, 2], experience = [2, 6, 3, 1]`
- **Constraints:**
	- n == energy.length == experience.length
	- 1 <= n <= 100
	- 1 <= initialEnergy, initialExperience, energy[i], experience[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of hours of training required to defeat all the opponents.
- **Example:** `Output: 8`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the minimum number of training hours, we need to ensure that after each training hour, either your energy or experience is increased to ensure you can defeat each opponent.

- 1. Iterate through the opponents in order.
- 2. For each opponent, check if you have enough energy and experience to defeat them.
- 3. If not, determine the necessary amount of training required to surpass their energy and experience.
- 4. Keep track of the total number of training hours spent and update your energy and experience as you defeat each opponent.
{{< dots >}}
### Problem Assumptions ✅
- You will always be able to train enough to defeat all opponents.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: initialEnergy = 5, initialExperience = 3, energy = [1, 4, 3, 2], experience = [2, 6, 3, 1]`  \
  **Explanation:** In this example, you need to train for 8 hours: 6 hours to increase your energy and 2 hours to increase your experience. After training, you'll be able to defeat all the opponents in order, reducing your energy and increasing your experience as you progress.

- **Input:** `Input: initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]`  \
  **Explanation:** In this case, you already have enough energy and experience to defeat the single opponent, so no training is required.

{{< dots >}}
## Approach 🚀
The problem can be approached by simulating the competition, calculating the necessary training hours before each opponent to ensure you have the required energy and experience.

### Initial Thoughts 💭
- You can train at any point, so it's important to train only as much as necessary.
- By carefully selecting the most efficient use of training hours, we can minimize the total number of hours spent.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one opponent to face.
- The solution must handle the maximum number of opponents (100) efficiently.
- If your initial energy and experience are already sufficient, the result will be 0.
- Ensure the solution works efficiently for the maximum possible input size.
{{< dots >}}
## Code 💻
```cpp
int minNumberOfHours(int ie, int ig, vector<int>& energy, vector<int>& experience) 
{
    int hours = 0;
    for (int i = 0; i < energy.size(); i++)
    {
        if (energy[i] >= ie)
        {
            hours += energy[i] - ie + 1;
            ie += energy[i] - ie + 1;
        }
        if (experience[i] >= ig)
        {
            hours += experience[i] - ig + 1;
            ig += experience[i] - ig + 1;
        }
			// At the end increase the experience by experience[i] and decrease the energy by energy[i].
        ie -= energy[i];
        ig += experience[i];
    }
    return hours;
}
```

This function calculates the minimum number of hours needed to improve a person's energy and experience to meet the required thresholds, adjusting the values after each improvement.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minNumberOfHours(int ie, int ig, vector<int>& energy, vector<int>& experience) 
	```
	This line declares the function `minNumberOfHours` that accepts initial energy (`ie`), initial experience (`ig`), and vectors `energy` and `experience` to track improvements.

2. **Variable Declaration**
	```cpp
	    int hours = 0;
	```
	A variable `hours` is initialized to 0 to track the total number of hours required for energy and experience adjustments.

3. **For Loop**
	```cpp
	    for (int i = 0; i < energy.size(); i++)
	```
	A `for` loop that iterates through each energy and experience value.

4. **Condition Check**
	```cpp
	        if (energy[i] >= ie)
	```
	Check if the energy value at index `i` is greater than or equal to the initial energy `ie`.

5. **Energy Adjustment**
	```cpp
	            hours += energy[i] - ie + 1;
	```
	If the energy at index `i` is sufficient, increase `hours` by the difference between energy and initial energy, plus one.

6. **Energy Update**
	```cpp
	            ie += energy[i] - ie + 1;
	```
	Update `ie` to the new value by adding the improvement in energy.

7. **Condition Check**
	```cpp
	        if (experience[i] >= ig)
	```
	Check if the experience value at index `i` is greater than or equal to the initial experience `ig`.

8. **Experience Adjustment**
	```cpp
	            hours += experience[i] - ig + 1;
	```
	If the experience at index `i` is sufficient, increase `hours` by the difference between experience and initial experience, plus one.

9. **Experience Update**
	```cpp
	            ig += experience[i] - ig + 1;
	```
	Update `ig` to the new value by adding the improvement in experience.

10. **Comment**
	```cpp
				// At the end increase the experience by experience[i] and decrease the energy by energy[i].
	```
	This comment explains the final adjustment to `ie` and `ig` after processing each energy and experience value.

11. **Energy Update**
	```cpp
	        ie -= energy[i];
	```
	Decrease `ie` by the energy value at index `i` to reflect the consumption of energy.

12. **Experience Update**
	```cpp
	        ig += experience[i];
	```
	Increase `ig` by the experience value at index `i` to reflect the gain in experience.

13. **Return Statement**
	```cpp
	    return hours;
	```
	Return the total number of hours calculated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in relation to the number of opponents, as we process each opponent in sequence.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few variables to keep track of the energy, experience, and training hours.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/description/)

---
{{< youtube ueU_i8H3-9g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
