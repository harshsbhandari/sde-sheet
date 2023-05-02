int maxSubArray(vector<int>& arr) {
    int n = arr.size();

    // start - subarray ka start
    // end - subarray ka end
    // currSum - current element tak ka sum
    // totalMax - max sum (final answer)
    int start = 0, end, currSum = 0, totalMax = INT_MIN;

    for(int i = 0; i < n; i++){
        // current element ko sabse pehle add karo
        currSum += arr[i];

        // check karo kya is element ko add karne par kya hota h; agar 'max sum' 'current sum' se small h to 'max sum' ko update karo aur 'end' ko update karo is element tak
        if(currSum > totalMax){
            totalMax = currSum;
            end = i; 
        }
        
        // agar 'current sum' < 0, to reset karo 'current sum' to zero, aur 'start' ko next element par shift karo
        if(currSum < 0){
            start = i+1;
            currSum = 0;
        }
    }
    // 'start' aur 'end' - max sum subarray kahan se start aur kahan end ho raha h ye batata h 

    // max sum of subarray
    return totalMax;
}