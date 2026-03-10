/*
find power of x raise to power n (x=base, power=n).

brute:

double myPow(double base, int power) {
         if(power==0 || base==1.0) return 1.0;
         int power2 = power;
         if(power2 < 0){
            base = 1/base;
            power2 = power2 * -1;
         }
         double ans=1.0;
         for(int i=0;i<power2;i++){
         ans=ans*base;
         }
         return ans;
}

tc: O(n) or O(power)
sc: O(1)

*/




/* 
optimal: binary exponentiation (power = exponent)

double myPow(double base, int power) {
        long long power2 = power;
        if(power2 < 0) power2 = -1 * power2;
        double ans = 1.0;
        while(power2 > 0){
            if(power2 % 2 == 1){
                ans = ans * base;
                power2 = power2 - 1;
            }else{
                base = base * base;
                power2 = power2 / 2;
            }
        }
        if(power < 0)return ((double)1.0/ ans);
        return ans;
}


tc: O(log n) or O(log power)
sc: O(1)

*/
