#include <stdio.h>

int maks(int a, int b){
	if(a > b) return a;
	else return b;
}

int cari_maks(int angka[], int ukuran){
	if(ukuran==1) return angka[0];
	
	return maks(angka[ukuran-1], cari_maks(angka, ukuran-1));
}

int main(){
	int angka[] = {23, 43, 67, 89, 103, 91, 74, 53, 37, 13};
	int i;
	
	printf("Angka terbesar dari set: [%d", angka[0]);
	for(i=1;i<=9;i++){
		printf(", %d", angka[i]);
	}
	printf("] adalah %d", cari_maks(angka, 10));
}
