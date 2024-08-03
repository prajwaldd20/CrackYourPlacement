//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
        private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
     stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i= n-1;i>=0;i--)
    {
        int curr = arr[i];
        while( s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
    }
    
    
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
     stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for(int i= 0;i<n;i++)
    {
        int curr = arr[i];
        while(s.top() != -1  && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i]= s.top();
        s.push(i);
    }
    return ans;
    }
    
     int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();
        vector<int> next(n);
        next= nextSmallerElement(heights, n);
        vector<int> prev( n);
        prev= prevSmallerElement(heights, n);
        int area= INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l= heights[i];
            if(next[i]== -1)
            {
                next[i]=n;
            }
            int b= next[i]-prev[i]-1;
            int newArea = l*b;
            area = max(area, newArea);

        }
        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<int> height(m,0);
        int maxArea = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j] == 1) height[j]++;
                else
                height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
}; 

