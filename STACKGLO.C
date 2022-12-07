#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ms 5

int top = -1;
int arr[ms];

void push()
{
   int x;
   if(top == ms-1)
      printf("Stack is overflow.....\n");
   else
      {
	 printf("Enter element to be pushed : ");
	 scanf("%d",&x);
	 top++;
	 arr[top] = x;
      }
}

void pop()
{
   int x;
   if(top == -1)
      printf("Stack is underflow.....\n");
   else
      {
	 x = arr[top];
	 top--;
	 printf("%d is popped out.\n",x);
      }
}

int peek()
{
   return (arr[top]);
}

void printstk()
{
  int i;
  printf("Elements in the stack are.....\n");
  for(i=top;i>=0;i--)
     printf("%d\n",arr[i]);
  printf("\n");
}

void main()
{
  int ch=1,x,i;
  clrscr();
  printf("MENU for operations on STACK.....\n");
  printf("1. PUSH\n2. POP\n3. PEEK\n4. PRINT\n5. QUIT\n");

  while(ch)
  {
     printf("Enter your choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1 : push();
		break;
       case 2 : pop();
		break;
       case 3 : if(top != -1)
		{
		   x = peek();
		   printf("%d is at the top of stack.\n",x);
		}
		else
		   printf("Stack is Empty.....\n");
		break;
       case 4 : if(top == -1)
		   printf("Stack is empty.....\n");
		else
		   printstk();
		break;
       case 5 : exit(1);
       default : printf("ERROR ! Wrong choice.....\n");
     }
  }
  getch();
}














                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
