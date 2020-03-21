// Here is a simple improvement which will most probably meet your time constraints.
//  For every divisor i of N, there is also a corresponding divisisor N/i. 
// And to find all pairs of divisors, you need only to loop from 1 to the square root N.
//  So try something along the lines of

    int maxD = (int)Math.sqrt(input);
    int sum=1;
    for(int i = 2; i <= maxD; i++)
    {
        if(input % i == 0)
        {
           sum += i;
           int d = input/i;
           if(d!=i)
              sum+=d;
        }
    }
//final answer=sum+input