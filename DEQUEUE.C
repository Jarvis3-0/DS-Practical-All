#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define mxsize 5
typedef struct dequeue
{
   int fleft,fright;
   int rleft,rright;
   int arr[mxsize];
}DEQ;

void initdlq(DEQ *q)
{
   q->fleft = 0;
   q->rleft = -1;
}

void initdrq(DEQ *q)
{
   q->fright = mxsize-1;
   q->rright = mxsize;
}

int isfulllq(DEQ q)
{
   if((q.rleft == mxsize-1) || (q.rleft == q.rright-1))
      return 1;
   else
      return 0;
}

int isfullrq(DEQ q)
{
   if((q.rright == 0) || (q.rright == q.rleft+1))
      return 1;
   else
      return 0;
}

int isemptylq(DEQ q)
{
   if(q.rleft == -1)
      return 1;
   else
      return 0;
}

int isemptyrq(DEQ q)
{
   if(q.rright == mxsize)
      return 1;
   else
      return 0;
}

void insertlq(DEQ *q)
{
   int val;
   if(isfulllq(*q))
     printf("No space to add element in Left sided queue.....Cannot add.\n");
   else
      {
	printf("Enter value to be added : ");
	scanf("%d",&val);
	q->arr[++q->rleft] = val;
      }
}

void insertrq(DEQ *q)
{
   int val;
   if(isfullrq(*q))
     printf("No space to add element in Right sided queue.....Cannot add.\n");
   else
      {
	printf("Enter value to be added : ");
	scanf("%d",&val);
	q->arr[--q->rright] = val;
      }
}

void removelq(DEQ *q)
{
   if(isemptylq(*q))
       printf("Left sided queue is Empty.....Cannot remove.\n");
   else
      {
	 printf("%d is removed from left sided queue.\n",q->arr[q->fleft++]);
	 if(q->fleft==q->rleft+1)
	    {
	       q->fleft = 0;
	       q->rleft = -1;
	     }
      }
}

void removerq(DEQ *q)
{
   if(isemptyrq(*q))
       printf("Right sided queue is Empty.....Cannot remove.\n");
   else
      {
	 printf("%d is removed from left sided queue.\n",q->arr[q->fright--]);
	 if(q->fright==q->rright-1)
	    {
	      q->fright = mxsize-1;
	      q->rright = mxsize;
	    }
      }
}

void printdlq(DEQ q)
{
   int i;
   if(isemptylq(q))
      printf("Left sided queue is Empty.....\n");
   else
      {
	 printf("Elements of Left sided queue are.....\n");
	 for(i=q.fleft;i<=q.rleft;i++)
	    printf("%d\t",q.arr[i]);
	 printf("\n");
      }
    }

void printdrq(DEQ q)
{
   int i;
   if(isemptyrq(q))
      printf("Right sided queue is Empty.....\n");
   else
      {
	 printf("Elements of Right sided queue are.....\n");
	 for(i=q.fright;i>=q.rright;i--)
	    printf("%d\t",q.arr[i]);
	 printf("\n");
      }
}

void main()
{
   DEQ dq;
   int ch=1;
   clrscr();
   initdlq(&dq);
   initdrq(&dq);
   printf("\n M E N U for operations on Double Ended Queue......\n");
   printf("1. Add element in left sided queue \n");
   printf("2. Add element in right sided queue \n");
   printf("3. Delete element from left sided queue \n");
   printf("4. Delete element from right sided queue \n");
   printf("5. Print left sided queue \n");
   printf("6. Print right sided queue \n");
   printf("7. Quit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : insertlq(&dq);
		 if(!isemptylq(dq))
		    printdlq(dq);
		 break;
	case 2 : insertrq(&dq);
		 if(!isemptyrq(dq))
		    printdrq(dq);
		 break;
	case 3 : removelq(&dq);
		 if(!isemptylq(dq))
		    printdlq(dq);
		 break;
	case 4 : removerq(&dq);
		 if(!isemptyrq(dq))
		    printdrq(dq);
		 break;
	case 5 : printdlq(dq);
		 break;
	case 6 : printdrq(dq);
		 break;
	case 7 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
   }
   getch();
}
