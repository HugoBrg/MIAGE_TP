//----- Include files ----------------------------------------------------------
#include <stdio.h>    			// Needed for printf()
#include <stdlib.h>   			// Needed for rand()
#include <math.h>				// Needed for log()


//----- Linked List -------------------------------------------------------------
// This linked list will store the future events
typedef struct node {
  int callerID;
  char event;
  double time;
  struct node *next;
} node_t;

long int MAX;
double ARR_TIME,SERV_TIME;

//----- Function prototypes ----------------------------------------------------
double expntl(double x);        										// Generate exponential RV with mean x
void print_list(node_t * head);											// Print the future event list
int popEvent(node_t ** head);											// Remove the event at the front of the list
int popBuffer(FILE *f,node_t ** head,node_t ** bhead,
double *busyTime,double *residenceTime,
double *waitingTime,double currentTime);								// Remove the waiting event at the front of the buffer
void insertEvent(node_t ** head,int callerID,char event,double time);	// Insert an event at the appropriate time of occurence
void print_all(node_t * head,node_t * bhead);							// Print both the future event list as well as the buffer