class Solution {
public:
    string intToRoman(int num) {
        
        vector<pair<int, string>> mp = {
            {1, "I"},{4,"IV"}, {5, "V"}, {9,"IX"},
            {10, "X"}, {40,"XL"},{50,"L"},{90,"XC"},
            {100,"C"},{400,"CD"},{500,"D"},{900,"CM"},
            {1000,"M"}
        }; 
    string result ="";
       for(int i=mp.size()-1;i>=0;i--)
       {
        if(num == 0)
         break;

         int times = num / mp[i].first;
         while(times--)
         {
            result += mp[i].second;
         }
         num = num%mp[i].first;
       }
        return result;
    }
};
