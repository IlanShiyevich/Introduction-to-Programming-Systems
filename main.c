  #include <stdio.h>
#include "myMath.h"

int main ()
{
	double num;
	double result;
	printf ("please enter a real number: ");
	scanf ("%lf",&num);
	result = sub(add(Exponent((int)num) , Power(num, 3)) , 2);
	printf ("f(x) = e^x + x^3 -2: %.4lf \n", result);
	result = add(mul(3 , num) , mul(2 , Power(num,2)));
	printf ("f(x) = 3x + 2x^2:    %.4lf \n", result);
	result = sub(div(mul(4 , Power(num, 3)),5) , mul(2 , num));
	printf("f(x) = (4x^3)/5-2x:   %.4lf \n",result);
}




