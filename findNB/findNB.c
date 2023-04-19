#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long findNb(long long m);

int main(){
	
	long long t = 2262465469675162;
	printf("%lli  ", findNb(t));
	long double k = 9753;
	printf("%lf", pow(((k+1)*k)/2,2.0)-t);
	return 0;
}


long long findNb(long long m)
{	if (m<5)
		return -1;
  	long double sqrtM = sqrt((double) m);
	long long sqrtIM = sqrt(m);
	if (sqrtM != sqrtIM)
		return -1;
	printf("%Lf \n" , sqrtM);
	long double retVal =  (sqrt(1.0+sqrtM*2.0*4.0)-1.0)/2.0; 
	printf("%Lf \n" , retVal);
	long double checkVal;
	if (modfl(retVal, & checkVal) != 0.0)
	//	printf("%lf\n" ,modf(retVal, & checkVal));
		return -1;
	return checkVal;

}

