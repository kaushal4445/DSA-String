class Solution {
public:
    bool rotateString(string s, string goal) {
        // if(s.length() != goal.length()){
        //     return false;
        // }
        // for(int i =0; i<s.length(); i++){
        //     string rotated = s.substr(i)  + s.substr(0, i);
        //   if(rotated == goal){
        //     return true;
        //   }
        // }
        // return false;


           if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
    
};
