
+++
authors = ["grid47"]
title = "Leetcode 1859: Sorting the Sentence"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1859: Sorting the Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "MCPhGg_vedE"
youtube_upload_date="2021-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MCPhGg_vedE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string sortSentence(string s) 
    {
        stringstream words(s); 
        string word;
        pair<int, string> m;
        vector<pair<int, string> > sent;
        
        //SECTION 1
        while(words>>word)
        {
            int len = word.size();
            int i = int(word[len-1]) - 48;
            sent.push_back(make_pair(i, word.substr(0, len-1)));
        }
        
        //SECTION 2
        sort(sent.begin(), sent.end());
        
        //SECTION 3
        string ans = "";
        int len = sent.size();
        for(int i=0; i<len; i++)
        {
            ans += sent[i].second;
            if(i!= len-1)
                ans += " ";
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to sort the words in a sentence based on their order specified by a number at the end of each word. Each word in the input string ends with a digit that indicates its position in the sorted order. The goal is to rearrange the words into a correctly ordered sentence while omitting the trailing numbers.

### Approach

To solve this problem, we will follow a structured approach:

1. **Parsing the Input**: We will use a string stream to break the input sentence into individual words.
2. **Extracting Positions**: For each word, we will extract the number at the end to determine its position and store the word without the number.
3. **Sorting Words**: We will sort the words based on their extracted positions.
4. **Constructing the Result**: Finally, we will concatenate the sorted words back into a single string to produce the final result.

### Code Breakdown (Step by Step)

1. **Class Definition**: The implementation starts by defining a class named `Solution`, which encapsulates our method.

    ```cpp
    class Solution {
    public:
    ```

2. **Method Declaration**: The method `sortSentence` takes a string `s` as input and returns the rearranged string.

    ```cpp
    string sortSentence(string s) 
    {
    ```

3. **Using String Stream**: We declare a string stream `words` initialized with the input string `s`. This allows us to read the words from the string conveniently.

    ```cpp
    stringstream words(s); 
    string word;
    ```

4. **Vector Initialization**: We define a vector `sent` to store pairs of integers and strings. Each pair will consist of the position (from the number at the end of the word) and the word itself without that number.

    ```cpp
    vector<pair<int, string> > sent;
    ```

5. **SECTION 1: Parsing Words**: We enter a while loop that continues as long as there are words to read from the string stream. For each word, we perform the following steps:

    - Calculate the length of the word and determine the position by converting the last character (a digit) to an integer.
    - Store the position and the word (without the last character) in the `sent` vector.

    ```cpp
    while(words >> word)
    {
        int len = word.size();
        int i = int(word[len-1]) - 48; // Convert character to integer
        sent.push_back(make_pair(i, word.substr(0, len-1))); // Store the position and word
    }
    ```

6. **SECTION 2: Sorting the Words**: After all words have been parsed and stored in the `sent` vector, we use the `sort` function to sort the vector based on the first element of the pairs (the positions).

    ```cpp
    sort(sent.begin(), sent.end());
    ```

7. **SECTION 3: Constructing the Result**: We initialize an empty string `ans` to build the final output. We then loop through the sorted vector to concatenate the words into the result string, ensuring to add a space between words but not at the end.

    ```cpp
    string ans = "";
    int len = sent.size();
    for(int i=0; i<len; i++)
    {
        ans += sent[i].second; // Append the word
        if(i != len - 1)
            ans += " "; // Append space if not the last word
    }
    ```

8. **Returning the Result**: After constructing the ordered sentence, we return the result string.

    ```cpp
    return ans;
    }
    ```

### Complexity

The time complexity of this solution is \(O(n \log n)\), where \(n\) is the number of words in the sentence. This complexity arises from the sorting step. The space complexity is \(O(n)\) due to the additional storage used for the pairs in the vector.

### Conclusion

In conclusion, the provided code effectively rearranges the words in a sentence based on the numerical suffixes attached to each word. By utilizing a combination of string parsing, data structures, and sorting algorithms, the solution efficiently constructs a new string that reflects the correct word order. This approach not only demonstrates effective problem-solving skills in handling string manipulations but also illustrates the utility of standard library features in C++. The implementation is concise, clear, and achieves the desired outcome with optimal performance, making it a robust solution for similar problems involving word ordering based on embedded numeric information.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sorting-the-sentence/description/)

---
{{< youtube MCPhGg_vedE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
