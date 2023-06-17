/******************************************************************************
2. Best Time to Buy and Sell Stock
    You are given an array of prices where prices[i] is the
    price of a given stock on a ith day.
    
    You want to maximize your profit by choosing a single day to
    buy one stock and choosing a different day in the future to 
    sell that stock.
    
    Return the maximum profit you can achieve from this transaction.
    If you cannot achieve any profit, return 0.
    
    Input: prices = [7, 1, 5, 3, 6, 4]
    Ouput: 5
    Explanation: Buy on day 2(price = 1) and sell on day 5(price = 6)
    profit = 6 - 1 = 5.
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
int main()
{
    int n, price = 0;
    printf("Enter the number of day to take into consideration: ");
    scanf("%d", &n);
    
    int prices[n];
    
    printf("Give the prices: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &price);
        if(prices[i] < 0){
            printf("Enter a non negative number!\n");
            break;
        }else{
            *(prices+i) = price;
        }
        
    }
    
    int btb = *prices;      //Best Time to Buy
    int day1 = 0;
    for(int i = 0; i < n; i++){
        if(btb > *(prices+i)){
            btb = *(prices+i);
            day1 = i;
        }
    }
    
    int bts = 0;            //Best Time to Sell
    int day2 = 0;
    for(int i = day1; i < n; i++ ){
        if(bts < *(prices+i) - *(prices+day1)){
            bts = *(prices+i) - *(prices+day1);
            day2 = i;
        }
    }
    printf("Day %d (price = %d)", day2+1, *(prices+day2));
    
    return 0;
}

