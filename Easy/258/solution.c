int addDigits(int num){
    if(num < 10){
        return num;
    }
    
    int new_num = 0;
    while(num > 0){
        new_num += num % 10;
        num /= 10;
    }

    return addDigits(new_num);
}
