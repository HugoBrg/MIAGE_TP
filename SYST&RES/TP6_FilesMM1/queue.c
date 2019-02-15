
//----- Include files ----------------------------------------------------------
#include <stdio.h>    			// Needed for printf()
#include <stdlib.h>   			// Needed for rand()
#include <math.h>				// Needed for log()
#include "queue.h"

//******************************************************************************
//*  Function: Print both the future event list as well as the buffer		   *
//*    - Input:  	1) The pointer to the head of the link list                *
//*    -  			2) The pointer to the head of the buffer				   *
//*    - Output: void                                                          *
//******************************************************************************

void print_all(node_t * head,node_t * bhead) {
	printf("*******************************************************************************\n");
	printf("FEL-");
	print_list(head);
	printf("***************************\n");
	printf("BUFFER-");
	print_list(bhead);
	printf("*******************************************************************************\n");
}

//******************************************************************************
//*  Function to generate exponentially distributed RVs using inverse method   *
//*    - Input:  x (mean value of distribution)                                *
//*    - Output: Returns with exponential RV                                   *
//******************************************************************************
double expntl(double x)
{
	double z;                     // Uniform random number from 0 to 1

	// Pull a uniform RV (0 < z < 1)
	do {
		z = ((double) rand() / RAND_MAX);
	}
	while ((z == 0) || (z == 1));

  // return -log(1.0 - (double) random() / (RAND_MAX + 1)) / x;


	return(-x * log(z));
}

//******************************************************************************
//*  Function: Print the future event list                                     *
//*    - Input:  1) The pointer to the head of the link list                   *
//*    - Output: void                                                          *
//******************************************************************************
void print_list(node_t * head) {
    node_t * current = head;
    while (current != NULL) {
        printf("(%d,%c,%lf)", current->callerID,current->event,current->time);
        current = current->next;
        if(current != NULL)
        	printf("|");
    }
    printf("\n");
}

//******************************************************************************
//*  Function: Remove the event at the front of the list                       *
//*    - Input:  1) The pointer to the pointer of the head of the link list    *
//*    - Output: int: A bool type for whether the pop was successful or not	   *
//******************************************************************************
int popEvent(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = 1;
    free(*head);
    *head = next_node;
    return retval;
}

//******************************************************************************
//*  Function: Remove the waiting event at the front of the buffer             *
//*    - Input:  1) The pointer to the file to store the statistics            *
//*    - Input:  2) The pointer to the pointer of the head of the fel          *
//*    - Input:  3) The pointer to the pointer of the head of the queue        *
//*    - Input:  4) The pointer to the busy time counter                       *
//*    - Input:  5) The pointer to the residence time counter                  *
//*    - Input:  6) The pointer to the waiting time counter                    *
//*    - Output: int: A bool type for whether the pop was successful or not    *
//******************************************************************************
int popBuffer(FILE *f,node_t ** head,node_t ** bhead,double *busyTime,double *residenceTime,double *waitingTime,double currentTime) {
	double newTime,serviceTime,wt;
    int retval = -1;
    node_t * next_node = NULL;

    if (*bhead == NULL) {
        return -1;
    }
    // printf("Current Time - %lf\n", currentTime);
    next_node = (*bhead)->next;
    retval = 1;
    // Insert as a departure event
    serviceTime = expntl(SERV_TIME);
    newTime = currentTime+serviceTime;
    *busyTime += serviceTime;
    wt = (currentTime - (*bhead)->time);
    wt = (wt > 0)? wt : 0;
    *waitingTime += wt;
    *residenceTime += (serviceTime+wt);
    // Write the data to file
	fprintf(f, "%d,%lf,%lf,%lf\n",(*bhead)->callerID,(*bhead)->time,wt,(serviceTime+wt));
	insertEvent((head),(*bhead)->callerID,'D',newTime);
    free(*bhead);
    *bhead = next_node;
return retval;
}

//******************************************************************************
//*  Function: Insert an event at the appropriate time of occurence            *
//*    - Input:  1) The pointer to the pointer of the head of the link list    *
//*    - Input:  2) int: ID of the the caller                                  *
//*    - Input:  3) char: Symbol to signify the event                          *
//*    - Input:  4) double: The time the event will occur                      *
//*    - Output: void                                                          *
//******************************************************************************
void insertEvent(node_t ** head,int callerID,char event,double time)
{
  node_t * current = *head;
  node_t * newEvent = NULL;
  if(current == NULL) {
      newEvent=malloc(sizeof(node_t));
      newEvent->next = NULL;
      *head = newEvent;
      newEvent->time=time;
      newEvent->callerID = callerID;
      newEvent->event = event;
  }
  else {
    while(current != NULL) {
        // This is the case when the event needs to be inserted in after the last event
        if(current->time <= time && current->next == NULL) {
            // Create a new memory and re-assign the pointers
            newEvent=malloc(sizeof(node_t));
            newEvent->next = current->next;
            current->next=newEvent;
            newEvent->time=time;
            newEvent->callerID = callerID;
            newEvent->event = event;
            break;
        }
        // This is the case when the event needs to be inserted before the first event
        else if(current->time > time && current == *head) {
            // Create a new memory and re-assign the pointers
            newEvent=malloc(sizeof(node_t));
            newEvent->next = current;
            *head = newEvent;
            newEvent->time=time;
            newEvent->callerID = callerID;
            newEvent->event = event;
            break;
        }
        // This is the case when the event needs to be inserted in between two other events
        else if(current->time < time && current->next->time >= time) {
            // Create a new memory and re-assign the pointers
            newEvent=malloc(sizeof(node_t));
            newEvent->next = current->next;
            current->next=newEvent;
            newEvent->time=time;
            newEvent->callerID = callerID;
            newEvent->event = event;
            break;
        }

      // Proceed to the next event
      current = current->next;
    }
  }
}