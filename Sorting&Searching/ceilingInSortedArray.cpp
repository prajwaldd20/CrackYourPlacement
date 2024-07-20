pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	pair<int,int> ans;
	 ans.first = -1;
	 ans.second = -1;
	 //Floor
	 int start = 0;
	 int end = n-1;
  // Code to find floor of the number x
	while(start <= end)
	{
		int mid= start +(end-start)/2;
		if(a[mid] <= x)
		{
			ans.first = a[mid];
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	start =0;
	end = n-1;
  // code to find ceil of the number x 
	while(start <= end)
	{
		int mid= start +(end-start)/2;
		if(a[mid] >= x )
		{
			ans.second = a[mid];
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return ans;
	

}
