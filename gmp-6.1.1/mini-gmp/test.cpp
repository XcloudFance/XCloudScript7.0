
#include <iostream> 
extern "C"{
#include "mini-gmp.c" //gmp 
}
void BBSAlgorithm(mpz_t s,mpz_t n)
{
mpz_t t,X0;
mpz_pow_ui(t,s, 2);
mpz_mod(X0, t, n);


for(int i=0; ;i++)
{
mpz_t Xi;
mpz_set(Xi,X0);
mpz_pow_ui(Xi,Xi, 2);
mpz_mod(Xi, Xi, n);

mpz_t Bi;
mpz_set(Bi,Xi);
mpz_mod(Bi, Bi, s);



}

}

int main()
{
mpz_t s,n;
mpz_init_set_str(s, "192649", 10);//
mpz_init_set_str(n, "101355", 10);
BBSAlgorithm( s, n);
return 0;
}
