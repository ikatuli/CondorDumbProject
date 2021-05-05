#include <stdlib.h> 
#include <gmp.h>

char * luk (unsigned int number) //Тест Люка-Лемера
{
	if (number==2) return "6"; //Тест Люка-Лемера не работает с двойкой.
	mpz_t L,tmp,mersenne;
	mpz_init_set_ui(L,4);
	mpz_init (tmp);	

	//mersenne pow(2, q) - 1;
	mpz_init_set_ui(mersenne,2);
	mpz_pow_ui(mersenne,mersenne,number);//pow(2, q)
	mpz_sub_ui(mersenne,mersenne,1);//pow(2, q) - 1

	for (unsigned long long  i = 1; i <= number-2; i++) //Проверка
	{
		mpz_mul (tmp,L,L);//L*L
		mpz_sub_ui(tmp,tmp,2);//L*L-2
		mpz_mod(L,tmp,mersenne);//(L*L-2) %mersenne
	}

	//char * mpz_get_str(char *str, intbase, mpztop)

	//gmp_printf("Test: %Zd \n",L);

	if (mpz_cmp_ui(L,0)!=0) return "0";
	else 
	{
		mpz_t resolte;// 1ull << (number-1))*mersenne
		mpz_init_set_ui(resolte,2);
		mpz_pow_ui(resolte,resolte,number-1);
		mpz_mul(resolte,resolte,mersenne);
		//gmp_printf("Число: %Zd \n",resolte);
		//printf("str: %s",mpz_get_str(NULL,10,resolte));
		return mpz_get_str(NULL,10,resolte) ; //Если тест прошёл, то вычисляем положительное совершеное число.
	}
}

int prime(unsigned int n) //Проверка на простоту
{
	for(unsigned int i=2;i<=sqrt(n);i++) if(n%i==0)	return 0;
	return 1;
}

int main(int argc , char **argv[])
{
	char * response = "0";
	unsigned int n=0, l=2;

	//printf("%s", luk (7));
	while (n<atoi(argv[1])) {
	if (prime(l) == 1) {
	   	response = luk (l);
		if (response != "0"){
		printf("%s\n",response);
		n+=1;
		}
	}
	l+=1;
	}

}

