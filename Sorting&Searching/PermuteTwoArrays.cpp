
class Solution {
    void merge(long long  arr[], long long  l, long long  m, long long  r)
    {
         // Your code here
         
         // first array = l to m
         // second = m+1 to r

        long long  i=l, j=m+1;
        vector<long long > temp;
        
        while( i <= m && j <=r)
        {
            if(arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=m)
        {
            temp.push_back(arr[i++]);
        }
        while(j<=r)
        {
            temp.push_back(arr[j++]);
        }
        
        for(long long i=l;i<=r;i++)
        {
            arr[i] =temp[i-l];
        }
    }
    public:
    void mergeSort(long long  arr[], long long  l, long long  r)
    {
        //code here
       if(l>=r)
       return;
            long long  mid = l + (r-l)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
       
    }
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        mergeSort(a, 0, n-1);
        mergeSort(b, 0, n-1);
        int i=0, j=n-1;
        while( i< n  )
        {
            if(a[i++] + b[j--] <k)
            {
                return false;
            }
        }
        return true;
    }
};

