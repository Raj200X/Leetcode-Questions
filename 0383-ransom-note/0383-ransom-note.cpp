class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> mag(26,0);
        for (char c : magazine) {
            if (isalpha(c)) {
                c = tolower(c);          
                mag[c - 'a']++;         
            }
        }
        vector <int> ran(26,0);
        for (char c : ransomNote) {
            if (isalpha(c)) {
                c = tolower(c);          
                ran[c - 'a']++;         
            }
        }
        for (int i = 0;i<mag.size();i++){
            if (mag[i]<ran[i]){
                return false;
            }
        }
        return true;
    }
};