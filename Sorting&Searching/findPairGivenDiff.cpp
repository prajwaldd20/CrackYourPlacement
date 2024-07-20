

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        
      sort(arr.begin(), arr.end());
      
      int i=0, j=1;
      
      while( i <= j && j<n)
      {
          int diff = abs(arr[i] - arr[j]);
          
          if(diff == x && i!=j)
          {
              return 1;
          }
          else if(diff >x)
          {
              i++;
          }
          else
          {
              j++;
          }
      }
        return -1;
    }
};


