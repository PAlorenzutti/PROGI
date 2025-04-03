#include <stdio.h>

int main(){
	int n, i = 1, num = 1, p1, p2, p3, t, info = 0;
	scanf("%d", &n);

	int femBest, femWorst, maleBest, maleWorst;
	int delFemBest, delFemSum = 0, delMaleBest, delMaleSum = 0;
	int bestDelFemSum = -1, bestDelMaleSum = -1;
	int maleB1 = -1, maleB2 = -1, maleB3 = -1, maleW1 = 11, maleW2 = 11, maleW3 = 11;
	int femB1 = -1, femB2 = -1, femB3 = -1, femW1 = 11, femW2 = 11, femW3 = 11;

	char g, h;
	for (i = 1; i <= n;){
		scanf("%d", &num);
		while (info < 2 && num != -1){
			if (info == 0) scanf("%c", &g);
			else scanf("%d %d %d", &p1, &p2, &p3);
			info++;
		}
		info = 0;

		if (num == -1) {
			printf("MELHORES ATLETAS DA DELEGACAO %d\n", i);
			printf("MASCULINO: %d FEMININO: %d\n", maleBest, femBest);
			printf("PIORES ATLETAS DA DELEGACAO %d\n", i);
			printf("MASCULINO: %d FEMININO: %d\n\n", maleWorst, femWorst);
			
			if (delFemSum > bestDelFemSum) {
				bestDelFemSum = delFemSum;
				delFemBest = i;
			}
			if (delMaleSum > bestDelMaleSum) {
				bestDelMaleSum = delMaleSum;
				delMaleBest = i;
			}

			maleB1 = -1, maleB2 = -1, maleB3 = -1, maleW1 = 11, maleW2 = 11, maleW3 = 11;
			femB1 = -1, femB2 = -1, femB3 = -1, femW1 = 11, femW2 = 11, femW3 = 11;
			delMaleSum = 0, delFemSum = 0;
			i++;
		}
		else {
			if (p1 > p2) { 
				t = p2; p2 = p1; p1 = t; 
			}
			if (p1 > p3){ 
				t = p3; p3 = p1; p1 = t; 
			}
			if (p2 > p3){ 
				t = p3; p3 = p2; p2 = t; 
				}

			if (g == 'F'){
				delFemSum += p3;

				if(p3 >= femB3){
					if(p3 > femB3){
						femB2 = p2; femB1 = p1; femBest = num; 
					}else if(p2 >= femB2){
						if(p2 > femB2 || p1 > femB1 || (p1 == femB1 && num < femBest)){ 
							femB1 = p1; femBest = num; 
						} 
						
						femB2 = p2; 
					}
					
					femB3 = p3;
				}

				if (p3 <= femW3){
					if (p3 < femW3) { femW2 = p2; femW1 = p1; femWorst = num; }
					else if (p2 <= femW2) {	if (p2 < femW2 || p1 < femW1 || (p1 == femW1 && num > femWorst)) { femW1 = p1; femWorst = num; } femW2 = p2; }
					femW3 = p3;
				}	
			}
			else if (g == 'M') {
				delMaleSum += p3;
				if (p3 >= maleB3){
					if (p3 > maleB3) { maleB2 = p2; maleB1 = p1; maleBest = num; }
					else if (p2 >= maleB2) { if (p2 > maleB2 || p1 > maleB1 || (p1 == maleB1 && num < maleBest)) { maleB1 = p1; maleBest = num; } maleB2 = p2; }
					maleB3 = p3;
				}
				if (p3 <= maleW3){
					if (p3 < maleW3) { maleW2 = p2; maleW1 = p1; maleWorst = num; }
					else if (p2 <= maleW2) { if (p2 < maleW2 || p1 < maleW1 || (p1 == maleW1 && num > maleWorst)) { maleW1 = p1; maleWorst = num; } maleW2 = p2; }
					maleW3 = p3;
				}
			}
		}
	}

	printf("DELEGACAO CAMPEA:\n");
	printf("MASCULINO: %d FEMININO: %d\n", delMaleBest, delFemBest);

	return 0;
}