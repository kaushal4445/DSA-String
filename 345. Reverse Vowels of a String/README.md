🔄 Reverse Vowels of a String
📌 Problem Statement

Given a string s, reverse only the vowels in the string and return the modified string.

🔤 Vowels include:
a, e, i, o, u (both lowercase and uppercase)

🧠 Intuition

Instead of reversing the whole string, we only focus on vowel characters.

👉 Use two pointers:

One starts from the left
One starts from the right

Move both pointers inward:

Skip non-vowel characters
Swap vowels when found
⚙️ Approach
Create a helper function isVowel() to check vowels.
Initialize two pointers:
left = 0
right = n - 1
While left < right:
Move left forward until it points to a vowel
Move right backward until it points to a vowel
Swap both vowels
Return the modified string
💻 Code (C++)
class Solution {
public:

    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left < right){
            while(left < right && !isVowel(s[left]))
                left++;

            while(left < right && !isVowel(s[right]))
                right--;

            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};


📊 Example
Input:
s = "hello"

Process:
h e l l o
  ↑     ↑
swap → h o l l e

Output:

"holle"

🖼️ Visualization:

Input:  "leetcode"

Step 1: l e e t c o d e
          ↑         ↑
          swap → l e e t c e d o

Step 2: l e e t c e d o
            ↑     ↑
            swap → l o e t c e d e

Output: "leotcede"


⏱️ Complexity Analysis
Type	Complexity
Time Complexity	O(n)
Space Complexity	O(1)

✔ Each character is visited at most once.
