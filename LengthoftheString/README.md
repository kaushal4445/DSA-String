📝 Length of Last Word
🔗 Problem Link

LeetCode Problem: Length of Last Word

📌 Problem Statement

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is defined as a maximal substring consisting of non-space characters only.

🧠 Intuition
The string may contain trailing spaces, so first ignore them.
Once we reach the last character of the last word:
Count characters until a space is found.
The difference between positions gives the length.
⚙️ Approach
Start from the end of the string.
Skip all trailing spaces.
Mark the end of the last word.
Traverse backward until a space is found.
Return the length using index difference.
💻 Code (C++)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;

        // Skip trailing spaces
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        int j = i;

        // Traverse the last word
        while(i >= 0 && s[i] != ' ') {
            i--;
        }

        return j - i;
    }
};
📊 Example
Input
s = "Hello World"
Output
5
Explanation
Last word = "World"
Length = 5
⏱️ Complexity Analysis
Type	Complexity
Time	O(n)
Space	O(1)
🎯 Key Points
Handles trailing spaces efficiently.
No extra space required.
Works in a single backward pass.
⭐ Visual Walkthrough
"Hello World   "
              ↑ start
Skip spaces → reach 'd'
Move backward → count until space
🚀 Summary
Simple and efficient solution.
Uses two pointers (indices).
Ideal for beginner string problems.
