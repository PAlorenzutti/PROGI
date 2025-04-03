#include <stdio.h>

typedef struct {
	int day;
	int month;
	int year;
} tData;

tData LeData();
int AnoBissexto(int year);
void ImprimeData(tData data);
tData CorrigeData(tData data);
int NumeroDias(tData data);

int main()
{
	int n, i = 0;
	scanf("%d", &n);

	for (; i < n; i++) { ImprimeData(CorrigeData(LeData())); }	

	return 0;
}

tData CorrigeData(tData data){
	if (data.month > 12) data.month = 12;
	else if (data.month < 1) data.month = 1;
	
	int d = NumeroDias(data);
	if (data.day > d) data.day = d;
	else if (data.day < 1) data.day = 1;

	return data;
}

tData LeData(){
	tData data;
	scanf("%d %d %d", &data.day, &data.month, &data.year);
	return data;
}

int AnoBissexto(int year){
	return !(year%4);
}

void ImprimeData(tData data){
	printf("'%02d/%02d/%04d':", data.day, data.month, data.year);
	if (AnoBissexto(data.year)) printf("Bisexto\n");
	else printf("Normal\n");
}

int NumeroDias(tData data){
	int m = data.month;
	int d = 31;
	if (m == 4 || m == 6 || m == 9 || m == 11) d = 30;
	else if (m == 2){
		if (AnoBissexto(data.year)) d = 29;
		else d = 28;
	}
	return d;
}