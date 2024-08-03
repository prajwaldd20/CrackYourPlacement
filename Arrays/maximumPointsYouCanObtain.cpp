class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int maxSum = 0;
        int leftSum = 0, rightSum = 0;
        int n=cardPoints.size();
        for(int i=0 ;i<k;i++)
        {
            leftSum += cardPoints[i];
            maxSum = leftSum;
        }


        int rightIndex = n-1;

        for(int i =k-1; i>=0 ;i--)
        {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;

            maxSum = max(maxSum, leftSum + rightSum);
        }
    return maxSum;
    }
};
