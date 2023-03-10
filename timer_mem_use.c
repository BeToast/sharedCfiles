#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
int main(int argc, char** argv){
	struct timeval tv;
	struct timezone tz;
	int i,j,index,iterations,array_size;
	float *arrayPtr;
	double start,stop,init;
	if (argc!=3) {
		fprintf(stderr, "Usage: %s <Size of array><no of iterations>\n", argv[0]);
		exit(1);
	}
  printf("time_pass, time\n");
	// progname=argv[0];
	array_size=atoi(argv[1]);
	iterations=atoi(argv[2]);
	// start time
	gettimeofday( &tv,&tz);
	init=tv.tv_sec + tv.tv_usec*0.000001;
	// create large float arrays
	arrayPtr=calloc(array_size,sizeof(float));
	//initialise array
	for(i=0;i<array_size;++i) { arrayPtr[i]=9999.99; }
	// Main loop
	// Process array and time each pass.. memory is
	// not locked so should see variations due to paging. Use random no
	// generator to access array randomly ==> more page faults
	for(j=0;j<iterations;++j)
	{
		// random seed
		srand(time(NULL));
		gettimeofday( &tv,&tz);
		start=tv.tv_sec + tv.tv_usec*0.000001;
		for(i=0;i<array_size;++i)
		{
			// generate random index
			index = rand() % array_size;
			arrayPtr[index]=arrayPtr[index]/0.9999;
		}
		gettimeofday( &tv,&tz);
		stop=tv.tv_sec + tv.tv_usec*0.000001;
		printf("time_pass_%d,%lf\n",j+1, (stop-start)*1000);
		// sleep for 10 sec
		sleep(10);
	}
	// release memory
	free(arrayPtr);
	gettimeofday( &tv,&tz);
	stop=tv.tv_sec + tv.tv_usec*0.000001;
	printf("total_time,%lf\n", (stop-init)*1000);
	return 0;
}
