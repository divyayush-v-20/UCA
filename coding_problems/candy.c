int maxi(int a, int b){
    return (a > b) ? a : b;
}
int candy(int* arr, int n) {

    int candies[n];
    for(int i = 0; i < n; i++) candies[i] = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]) candies[i] = candies[i - 1] + 1;
    }
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > arr[i + 1]) candies[i] = maxi(candies[i], candies[i + 1] + 1);
    }

    int sum = 0;
    for(int i = 0; i < n; i++) sum += candies[i];
    return sum;

}