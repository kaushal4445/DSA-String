

class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorval = 0;
        for(int i =0; i<s.size(); i++){
            xorval ^=s[i];
        }
           for(int i =0; i<t.size(); i++){
            xorval ^=t[i];
        }
        return xorval;
    }
};
