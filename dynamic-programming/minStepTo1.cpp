//find min step to 1 from value using these operations
//1.) Subtract 1 from it. (n = n - ­1) ,
//2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
//3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  

int countStepsToOne(int n)
{
    int arr[n];
  	arr[0]=0;
    arr[1]=0;
    for(int i=2;i<=n;i++){
        int count=INT_MAX;
        count=arr[i-1];
        if(i%2==0)
            count=min(count,arr[i/2]);
        if(i%3==0)
            count=min(count,arr[i/3]);
        arr[i]=count+1;
    }
    return arr[n]; 
}
