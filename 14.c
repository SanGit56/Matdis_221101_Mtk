#include <stdio.h>
#include <string.h>

void gabung(int angka[], int idx_ki, int idx_tg, int idx_ka){
    int i, j, k;
    int n1 = idx_tg - idx_ki + 1;
    int n2 = idx_ka - idx_tg;
    int kiri[n1], kanan[n2];

    for(i=0;i<n1;i++)
        kiri[i] = angka[idx_ki + i];
        
    for (j=0;j<n2;j++)
        kanan[j] = angka[idx_tg + 1 + j];

    i = 0;
    j = 0;
    k = idx_ki;
    
    while(i<n1 && j<n2){
        if(kiri[i] <= kanan[j]){
            angka[k] = kiri[i];
            i++;
        }else{
            angka[k] = kanan[j];
            j++;
        }
        
        k++;
    }

    while(i<n1){
        angka[k] = kiri[i];
        i++;
        k++;
    }

    while(j<n2){
        angka[k] = kanan[j];
        j++;
        k++;
    }
}

void merge_sort(int angka[], int idx_ki, int idx_ka){
    if (idx_ki < idx_ka){
        int idx_tg = idx_ki + (idx_ka - idx_ki) / 2;

        merge_sort(angka, idx_ki, idx_tg);
        merge_sort(angka, idx_tg+1, idx_ka);

        gabung(angka, idx_ki, idx_tg, idx_ka);
    }
}

int modus(int angka[], int ukuran){
    merge_sort(angka, 0, ukuran);

    int maks = angka[ukuran-1] + 1;
    int a[maks];
    int i;
    
    memset(a, 0, sizeof(a));

    for(i=0;i<ukuran;i++){
        a[angka[i]]++;
    }

    int modus = 0;
    int smnt = a[0];
    for(i=1;i<maks;i++){
        if(a[i] > smnt){
            smnt = a[i];
            modus = i;
        }
    }

    return modus;
}

int main(){
    int angka[] = {23, 13, 37, 13, 23, 13, 23, 13, 37, 13};
    int i;

	printf("Angka modus dari set: [%d", angka[0]);
	for(i=1;i<=9;i++){
		printf(", %d", angka[i]);
	}
    printf("] adalah %d", modus(angka, 10));
}
