#include <stdio.h>
#include <string.h>


int soma(int* nums, int tam) {
    int y = 0;
    
    for(int i = 0; i < tam; i++) {
        y += nums[i];
    }

    return y;

}

int main() {
    int nums[3];

    nums[0]=10;
    nums[1]=20;
    nums[2]=30;



    printf("%d",  soma(nums, 3));
}