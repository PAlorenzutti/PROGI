#include <stdio.h>

typedef struct {
	int day;
	int month;
	int year;
} tData;

tData CorrigeData(tData data);
tData LeData();
void ImprimeData(tData data);
int AnoBissexto(int year);
tData ProximoDia(tData data);
int NumeroDias(tData data);
int DataIgual(tData d1, tData d2);

int main(){
	tData inicio, fim, data;
	inicio = CorrigeData(LeData());
	fim = CorrigeData(LeData());
	data = inicio;

	while(!DataIgual(data, fim)){
		ImprimeData(data);
		data = ProximoDia(data);
	}

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

void ImprimeData(tData data){
	printf("'%02d/%02d/%04d'\n", data.day, data.month, data.year);
}

int AnoBissexto(int year){
	return !(year%4);
}

tData ProximoDia(tData data){
	int d = data.day + 1;
	int m = data.month + 1;
	int y = data.year + 1;
	if (d > NumeroDias(data)){
		data.day = 1;
		data.month = m;
		if (data.month > 12){
			data.month = 1;
			data.year = y;
		}
		else data.month = m;
	}
	else data.day = d;

	return data;
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

int DataIgual(tData d1, tData d2){
	return d1.day == d2.day &&
		d1.month == d2.month &&
		d1.year == d2.year;
}