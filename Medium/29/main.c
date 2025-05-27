    #include <stddef.h>
    #define INT_MIN
    #define INT_MAX

    int divide(int dividend, int divisor) {
        long long div = dividend;
        long long dsor;
        dsor = divisor;

        if (div==INT_MIN && dsor==-1){
            return INT_MAX;
        }
        
        if (dsor == 0){
            return INT_MAX;  
        } 

        if (dsor && (dsor & (dsor - 1)) == 0) { 
            int shifts = 0;
            while (dsor != 1) {
                dsor >>= 1;
                shifts++;  
            }
            return (int)(div >> shifts);
        }

        return (int)(div / dsor);
    }