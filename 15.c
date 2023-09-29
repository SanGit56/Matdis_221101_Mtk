#include <stdio.h>

int fpb(int a, int b){
	if(b != 0)
        return fpb(b, a%b);
    else
        return a;
} 

int main(){
	int a = 6;
	int b = 9;
	int i;
	
	printf("FPB dari %d dan %d adalah %d", a, b, fpb(a, b));
}
