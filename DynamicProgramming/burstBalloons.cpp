class Solution {
    int t[302][302];

    int solve(vector<int> &arr, int i, int j)
    {
        // base condition

        if(i >j) return 0; 

        // if already present,return the value

        if(t[i][j] != -1) return t[i][j];

        // for loop 
        // move k 
        int maxi =0;
        for(int k= i;k<= j;k++)
        {
            int tempAns = solve(arr, i, k-1) + solve(arr, k+1, j) + 
                            arr[i-1] * arr[k] *arr[j+1];

            maxi = max(tempAns, maxi);
            
        }

        return t[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        
        memset(t, -1, sizeof(t));

        int n=nums.size();


        nums.push_back(1);              //  Just to handle boundary conditions
        nums.insert(nums.begin(), 1);  // 


        int ans = solve(nums, 1, n); // dp function

        return ans;

    }
};
