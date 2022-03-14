# include<stdio.h>



int mult_v(int x1, int x2, int m){
	if(x1 == 0){
		return m;
	}

	if(x1 > 0){
		return mult_v(x1 - 1, x2, m + x2);
	}
	else{
		return mult_v(x1 + 1, x2, m - x2);
	}
}



int multiplica3(int x1, int x2){
	return mult_v(x1, x2, 0);
}



int main(){
	int x1, x2;
	printf("x1 = ");
	scanf("%d", &x1);
	printf("x2 = ");
	scanf("%d", &x2);
	printf("x1 * x2 = %d\n", multiplica3(x1, x2));

	return 0;
}
