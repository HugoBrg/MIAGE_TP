//******************************************************************************
//* This program requires parameters for Inter Arrival time,        *
//** Service time as well as maximum number of customers                       *
//******************************************************************************
//----- Include files ----------------------------------------------------------
#include <stdio.h>    			// Needed for printf()
#include <stdlib.h>   			// Needed for rand()
#include <math.h>				// Needed for log()
#include "queue.h"

// #define MAX 1000000      			// Modify this to change the number of requests
// #define SIM_TIME   1.0e2        // Simulation time

// #define ARR_TIME   1.25         // Mean time between arrivals
// #define SERV_TIME  1.00         // Mean service time
#define RSEED 1234   			// Modify this to change seed of the random number generator function

#define FILENAME "mm1.csv" 		//Change the filename here

int main( int argc, char *argv[])
{
    int line=0; // Etat de la ligne (lien de sortie): 1 si'l y un paquet en train de se transmetre.
    int callerID=0,localCallerID,departures=0;
    
    double prevTime = 0.0,newTime = 0.0,busyTime = 0.0,serviceTime=0.0,waitingTime = 0.0,residenceTime=0.0;
    node_t * fel = NULL;
    node_t * head = fel;
    
    node_t * buffer = NULL;
    node_t * bhead = buffer;
    
    // Check if the command line argument is correct
    if ( argc != 4 ) /* argc should be 4 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s MAX_CUSTOMERS INTER_ARR_TIME SERV_TIME\n", argv[0] );
        exit(-1);
    }
    else if( atof(argv[2]) < 0)
    {
        printf( "Inter arrival time must be greater than 0.\n" );
        exit(-1);
    }
    else if (atof(argv[3]) < 0 )
    {
        printf( "Service time must be greater than 0.\n" );
        exit(-1);
    }
    else
    {
        SERV_TIME = atof(argv[3]);
        ARR_TIME = atof(argv[2]);
        MAX = atoi(argv[1]);
    }
    // Open a file for reading
    FILE *f = fopen(FILENAME, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Assign a seed for the random number
    srand(RSEED);
    
    insertEvent(&head,++callerID,'A',prevTime + expntl(ARR_TIME));
    // print_all(head,bhead);   // UNCOMMENT THIS TO VIEW THE FEL and the buffer
    while(1) {
        switch(head->event){
            case 'A':
	            prevTime = head->time;
	            localCallerID = head->callerID;
	            popEvent(&head);
	            if(!line) {
	            	serviceTime = expntl(SERV_TIME);
		            newTime = prevTime+serviceTime;
		            busyTime += serviceTime;
		            residenceTime += serviceTime;
		            insertEvent(&head,localCallerID,'D',newTime);
		            fprintf(f, "%d,%lf,%lf,%lf\n",localCallerID,prevTime,0.0,serviceTime);
		            line = 1;
		        }
		        else 
		        	insertEvent(&bhead,localCallerID,'A',prevTime);
		        if(callerID < MAX)
		        	insertEvent(&head,++callerID,'A',prevTime + expntl(ARR_TIME));
	    		break;
	    	case 'D':
	    		departures++;
	    		prevTime = head->time;
	            popEvent(&head);
	            if(departures == MAX)
	            if(departures == callerID)
	            	goto Result;
	            if(bhead!=NULL)
	            	popBuffer(f,&head,&bhead,&busyTime,&residenceTime,&waitingTime,prevTime);
	            else
	            	line=0;

                break;
        }
    }
    
Result:
    // CLose file for writing
    fclose(f);
    // Output results
    float lambda = 1/ARR_TIME;
    float mu = 1/SERV_TIME;
    float rho = SERV_TIME/ARR_TIME;
    float queueing_time =  rho/(mu-lambda);
    printf("**************************************STATISTICS*******************************\n");
    if(ARR_TIME < SERV_TIME)
        printf("*   UNSTABLE:\tArrival rate is greater than service rate!!\n");
    printf("*                        Results from M/M/1 simulation                        * \n");
    printf("*******************************************************************************\n");
    printf("* INPUTS:                                     \n");
    printf("*  Total simulated time     = %3.4f sec    \n", prevTime);
    printf("*  Mean time betw arrivals  = %lf sec      \n", ARR_TIME);
    printf("*  Mean service time        = %lf sec      \n", SERV_TIME);
    printf("*******************************************************************************\n");
    printf("* OUTPUTS:                                    \n");
    printf("*  Number of completions    = %u cust      \n", departures);
    printf("*  Throughput rate          = %lf cust/sec \n", departures/prevTime);
    printf("*  Busy Time                = %lf sec      \n", busyTime);
    printf("*  Server utilization (rho) = %lf %%   <--> THEORY:  %lf %%      \n", 100.0 * busyTime/prevTime, 100.0 * SERV_TIME/ARR_TIME );
    printf("*  Mean residence time      = %lf sec  <--> THEORY:  %lf sec      \n", residenceTime/departures, SERV_TIME+ queueing_time);
    printf("*  Mean queueing time       = %lf sec  <--> THEORY:  %lf sec      \n", waitingTime/departures, queueing_time);
    printf("*  Mean number in system    = %lf cust <--> THEORY:  %lf cust      \n", residenceTime/prevTime, lambda*(SERV_TIME+ queueing_time) );
    printf("*  Mean number in queue     = %lf cust <--> THEORY:  %lf cust      \n", (residenceTime-busyTime)/prevTime, lambda*queueing_time);
    printf("*******************************************************************************\n");
    return 0;
}
