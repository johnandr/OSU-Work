#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>
#include <math.h>
#include "randFunc.h"

const float GRAIN_GROWS_PER_MONTH =		8.0;
const float ONE_DEER_EATS_PER_MONTH =	0.5;

const float AVG_PRECIP_PER_MONTH =		6.0;
const float AMP_PRECIP_PER_MONTH =		6.0;
const float RANDOM_PRECIP =				2.0;

const float AVG_TEMP =					50.0;
const float AMP_TEMP =					20.0;
const float RANDOM_TEMP =				10.0;

const float MIDTEMP =					40.0;
const float MIDPRECIP =					10.0;

const int	NUMT =						4;
const int	NUM =						3;

int		NowYear;		// 2016 - 2021
int		NowMonth;		// 0 - 11

float	NowPrecip;		// inches of rain per month
float	NowTemp;		// temperature this month
float	NowHeight;		// grain height in inches
int		NowNumDeer;		// number of deer in the current pop

float	NowMoldFactor;
float	NowMoldLoss;

void 	GrainDeer(struct Barriers*);
void 	Grain(struct Barriers*);
void 	Watcher(struct Barriers*);
void 	Mold(struct Barriers*);
float 	tempFactor(float);
float	precipFactor(float);
int 	stateInit(struct Barriers*);

struct Barriers
{
	pthread_barrier_t doneComputing;
	pthread_barrier_t doneAssigning;
	pthread_barrier_t donePrinting;
};

int main()
{
	// starting date and time:
	NowMonth =    0;
	NowYear  = 2016;

	// starting state (feel free to change this if you want):
	NowNumDeer = 1;
	NowHeight =  1.;

	NowMoldFactor = .1;
	NowMoldLoss = 0.;

	srand(time(NULL));

	// Starting Values
	float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

	float temp = AVG_TEMP - AMP_TEMP * cos(ang);
	NowTemp = temp + Ranf( -RANDOM_TEMP, RANDOM_TEMP );

	float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin(ang);
	NowPrecip = precip + Ranf( -RANDOM_PRECIP, RANDOM_PRECIP );
	if(NowPrecip < 0.)
	{
		NowPrecip = 0.;
	}

/*
	pthread_barrier_t doneComputing;
	pthread_barrier_t doneAssigning;
	pthread_barrier_t donePrinting;

	pthread_barrier_init(&doneComputing, NULL, 4);
	pthread_barrier_init(&doneAssigning, NULL, 4);
	pthread_barrier_init(&donePrinting, NULL, 4);
*/

	printf("M-Y\tTemp\t\tPrecip\t\tHeight\t\tDeer\tMold\n");
//	printf("%d-%d\t%f\t%f\t%f\t%d\t%f\n", NowMonth, NowYear, NowTemp, NowPrecip, NowHeight, NowNumDeer, NowMoldLoss);

	struct Barriers b;
	stateInit(&b);

	omp_set_num_threads( 4 );
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			GrainDeer( &b );
		}

		#pragma omp section
		{
			Grain( &b );
		}

		#pragma omp section
		{
			Watcher( &b );
		}

		#pragma omp section
		{
			Mold( &b );
		}
	}       // implied barrier -- all functions must return in order to allow any of them to get past here

	return 0;
}

void GrainDeer( struct Barriers* b )
{
	while( NowYear <= 2021 )
	{
		float height = NowHeight;
		float numdeer = (float) NowNumDeer;
		
		if(height > numdeer)
		{
			numdeer++;
		}else
		{
			numdeer--;
			if( numdeer < 0)
				numdeer = 0;
		}

		pthread_barrier_wait(&b->doneComputing);

		NowNumDeer = (int) numdeer;

		pthread_barrier_wait(&b->doneAssigning);

		pthread_barrier_wait(&b->donePrinting);
	}
}

void Grain( struct Barriers* b )
{
	while( NowYear <= 2021 )
	{
		float height = NowHeight;
		float temp = NowTemp;
		float precip = NowPrecip;
		float numdeer = (float)NowNumDeer;
		float moldfactor = NowMoldFactor;
		float moldloss = height * moldfactor;

		height += tempFactor(temp) * precipFactor(precip) * GRAIN_GROWS_PER_MONTH;
		height -= numdeer * ONE_DEER_EATS_PER_MONTH;
		height -= moldfactor;

		// Clamping height to zero
		if(height < 0.)
		{
			height = 0.;
		}

		pthread_barrier_wait(&b->doneComputing);

		NowHeight = height;
		NowMoldLoss = moldloss;

		pthread_barrier_wait(&b->doneAssigning);

		pthread_barrier_wait(&b->donePrinting);
	}
}

void Watcher( struct Barriers* b )
{
	while( NowYear <= 2021)
	{
		pthread_barrier_wait(&b->doneComputing);

		pthread_barrier_wait(&b->doneAssigning);

		printf("%d-%d\t%f\t%f\t%f\t%d\t%f\n", NowMonth, NowYear, NowTemp, NowPrecip, NowHeight, NowNumDeer, NowMoldLoss);

		NowMonth = (NowMonth + 1) % 12;

		if( NowMonth == 0 )
			NowYear++;

		float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

		float temp = AVG_TEMP - AMP_TEMP * cos( ang );
		NowTemp = temp + Ranf( -RANDOM_TEMP, RANDOM_TEMP );

		float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
		NowPrecip = precip + Ranf( -RANDOM_PRECIP, RANDOM_PRECIP );
		if( NowPrecip < 0. )
			NowPrecip = 0.;

		pthread_barrier_wait(&b->donePrinting);

	}
}

void Mold( struct Barriers* b )
{
	while( NowYear <= 2021 )
	{
		float temp = NowTemp;
		float precip = NowPrecip;
		float loss;
		
		if(temp > 45 && precip > 6)
			loss = .2;
		else
			loss = .1;
		
		pthread_barrier_wait(&b->doneComputing);

		NowMoldFactor = loss;

		pthread_barrier_wait(&b->doneAssigning);

		pthread_barrier_wait(&b->donePrinting);
	}
}

float tempFactor( float factor )
{
	return exp(-pow((factor - MIDTEMP)/10., 2.));
}

float precipFactor( float factor )
{
	return exp(-pow((factor - MIDPRECIP)/10., 2.));
}


int stateInit( struct Barriers *s )
{
/*
	// starting date and time:
	s->NowMonth =    0;
	s->NowYear  = 2016;

	// starting state (feel free to change this if you want):
	s->NowNumDeer = 1;
	s->NowHeight =  1.;

	s->moldFactor = .1;
	s->moldLoss = 0.;

	// Starting Values
	s->ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

	s->temp = AVG_TEMP - AMP_TEMP * cos(s->ang);
	s->NowTemp = s->temp + Ranf( -RANDOM_TEMP, RANDOM_TEMP );

	s->precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin(s->ang);
	s->NowPrecip = s->precip + Ranf( -RANDOM_PRECIP, RANDOM_PRECIP );
	if(s->NowPrecip < 0.)
	{
		s->NowPrecip = 0.;
	}
*/
	// Init Barriers
	pthread_barrier_init(&s->doneComputing, NULL, 4);
	pthread_barrier_init(&s->doneAssigning, NULL, 4);
	pthread_barrier_init(&s->donePrinting, NULL, 4);

	return 0;
}


