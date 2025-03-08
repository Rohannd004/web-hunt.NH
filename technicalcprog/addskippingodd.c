#include <stdio.h>
int add(int num) {
    if(num<=0){
        return 0;
    }
    if(num %10 == 3 || num %10 == 5 || num % 10 == 7) {
        return add(num-1);
    }
    return num + add(num-1);
}
int main()
{
    printf("%d",add(100));
    return 0;
}