#include<stdio.h>
#include<conio.h>
#define mxsize 5
typedef struct cirqueue
{
   int front,rear;
   int arr[mxsize];
}CQ;

void initcq(CQ *q)
{
   q->front = 0;
   q->rear = -1;
}

int isfullcq(CQ q)
{
   if((q.front == 0 && q.rear == mxsize-1) || (q.rear != -1 && q.front == q.rear+1))
      return 1;
   else
      return 0;
}

int isemptycq(CQ q)
{
   if(q.rear == -1)
      return 1;
   else
      return 0;
}

void addcq(CQ *q)
{
   int val;
   if(isfullcq(*q))
     printf("No space to add element circular queue.....Cannot add.\n");
   else
      {
	printf("Enter value to be added : ");
	scanf("%d",&val);
	q->rear = (q->rear+1) % mxsize;
	q->arr[q->rear] = val;
      }
}

void removecq(CQ *q)
{
   if(isemptycq(*q))
       printf("Circular queue is Empty.....Cannot remove.\n");
   else
      {
	 printf("%d is removed from Circular queue.\n",q->arr[q->front]);
	 if(q->front==q->rear)
	    {
	       q->front = 0;
	       q->rear = -1;
	    }
	 else
	    q->front = (q->front+1) % mxsize;
      }
}

void printcq(CQ q)
{
   int i;
   if(isemptycq(q))
      printf("Circular queue is Empty.....\n");
   else
      {
	 printf("Elements of Circular queue are.....\n");
	 if(q.front <= q.rear)
	   {
	     for(i=q.front;i<=q.rear;i++)
	       printf("%d\t",q.arr[i]);
	   }
	 else
	   {
	     for(i=q.front;i<mxsize;i++)
	       printf("%d\t",q.arr[i]);
	     for(i=0;i<=q.rear;i++)
	       printf("%d\t",q.arr[i]);
	   }
	 printf("\n");
      }
 }

void main()
{
   CQ cq;
   int ch=1;
   clrscr();
   initcq(&cq);
   printf("\n M E N U for operations on Circular Queue......\n");
   printf("1. Add element in Circular queue \n");
   printf("2. Delete element from Circular queue \n");
   printf("3. Print Circular queue \n");
   printf("4. Quit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : addcq(&cq);
		 if(!isemptycq(cq))
		    printcq(cq);
		 break;
	case 2 : removecq(&cq);
		 if(!isemptycq(cq))
		    printcq(cq);
		 break;
	case 3 : printcq(cq);
		 break;
	case 4 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
   }
   getch();
}
