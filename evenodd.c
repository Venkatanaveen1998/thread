#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* PrintEvenNos(void*);
void* PrintOddNos(void*);

int main()
{
	pthread_t t1,t2;
	int max;
	printf("enter the max value \n");
	scanf("%d",&max);
    pthread_create(&t1,NULL,&PrintEvenNos,&max);
    pthread_create(&t2,NULL,&PrintOddNos,&max);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}

void* PrintEvenNos(void* max)
{
   int i;
   printf("data all even numbers\n");
    for(i=0;i<=*(int *)max;i++)
    {
       if(i%2==0)
       {
         printf("%d   ",i);
       } 
    }
}

void* PrintOddNos(void* max)
{
    
    int i;
   printf("data all odd numbers\n");
    for(i=0;i<=*(int *)max;i++)
    {
       if(i%2!=0)
       {
         printf("%d   ",i);
       } 
    } 
}
