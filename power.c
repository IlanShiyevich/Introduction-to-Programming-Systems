#include "myMath.h"

double Exponent(int x) {
	double e = 2.718281;
	double result =2.718281;
	while(x > 1)
{
	result = result * e;
	--x;
}
       return result;
}

double Power(double x , int y)   {
		double result = x;
			while(y > 1)
					{
								result=result*x;
										--y;
											}
				return result;
}
