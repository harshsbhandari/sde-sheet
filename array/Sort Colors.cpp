void sortColors(vector<int>& arr) {
    int n = arr.size();
    int low, mid, high;

    // 'low' aur 'mid' - zero par set aur 'high' - last index par set 
    low = mid = 0;
    high = n-1;

    while(mid <= high){
        // agar 'mid' index par '0' h, to wo starting me hona chahiye, to hum swap karte h 'low' aur 'mid' ko, aur 'mid' aur 'low' dono ko increment karenge 
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }  

        // agar 'mid' index par '2' h, to wo ending me hona chahiye, to hum swap karte h 'mid' aur 'high' ko, aur sirf 'high' ko decrement karenge
        // 'mid' ko increment isliye nahi kia qki, swap karne par ho sakta h ki 'mid' par '0' aa jaye, aur 'mid++' kia to, '0' middle me rhe jayega
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
        // '1' encounter ho par sirf 'mid' ko increment karenge qki, '1' ko middle me hi hona chahiye
        else if(arr[mid] == 1)
            mid++;
    }


}