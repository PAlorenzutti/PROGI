#include <stdio.h>

int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
int area(int x1, int y1, int x2, int y2);

int main(){
    int xL1, xR1, yL1, yR1, xL2, xR2, yL2, yR2;
    scanf("%d %d %d %d", &xL1, &yL1, &xR1, &yR1);
    scanf("%d %d %d %d", &xL2, &yL2, &xR2, &yR2);

    printf("RESP:%d", area_total(xL1, yL1, xR1, yR1, xL2, yL2, xR2, yR2));

    return 0;
}

int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){
    int sum = area(r1_x1, r1_y1, r1_x2, r1_y2) + area(r2_x1, r2_y1, r2_x2, r2_y2);
    
    int repeat = 0;
    if (r2_x1 <= r1_x2 && r2_y1 <= r1_y2){
        int x = r2_x1, y = r2_y1;
        int x2 = r2_x2, y2 = r1_y2;

        if (r2_x2 != r1_x2) x2 = r2_x2 - r1_x2;
        
        repeat = area(x, y, x2, y2);
    }
    return sum - repeat;
}

int area(int x1, int y1, int x2, int y2){
    int x = x2 - x1;
    if (x < 0) x *= -1;

    int y = y2 - y1;
    if (y < 0) y *= -1;

    return x * y;    
}