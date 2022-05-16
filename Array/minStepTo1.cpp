//Find minimin path and can perform 3 functions only to reach 1 given an value n
//find min path to reach from n to 1
//1.) Subtract 1 from it. (n = n -1) ,
//2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
//3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  

int findMinStepCount(int n){
    if(n<=1)
        return 0;
    
    int count=INT_MAX;
    if(n%3==0)
        count=findMinStepCount(n/3);
    if(n%2==0)
        count=min(count,findMinStepCount(n/2));    
    return min(count,findMinStepCount(n-1))+1;
}


