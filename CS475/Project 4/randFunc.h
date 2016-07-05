#include <stdlib.h>

float Ranf( float low, float high )
{
	float r = (float) rand( );               // 0 - RAND_MAX

	return(   low  +  r * ( high - low ) / (float)RAND_MAX   );
}

int Ranf( int ilow, int ihigh )
{
	float low = (float)ilow;
    float high = (float)ihigh + 0.9999f;

	return (int)(  Ranf(low,high) );
}
