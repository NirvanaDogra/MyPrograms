#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int pow;
    int coeff;
};

typedef struct poly polytype;
polytype ar[30];
int endC;

void insert(int *start, int *end)
{
    int i;
    printf("entr the ending value %d", *start);
    scanf ("%d", end);

   *end=*end+(*start)-1;

  for(i=*start;i<=*end;i++)
  {
      printf("enter the power and coeff %i", i);
      scanf("%d%d", &ar[i].pow, &ar[i].coeff);
  }


}

void add(int startA, int endA, int startB, int endB)
{
   while(startA<=endA && startB<=endB)
   {
       if(ar[startA].pow < ar [startB].pow)
       {
           makeC(ar[startB].pow, ar[startB].coeff);
           startB++;
       }
       else if(ar[startA].pow > ar[startA].pow)
       {
           makeC(ar[startA].pow, ar[startA].coeff);
           startA++;
       }
       else if(ar[startA].pow==ar[startB].pow)
       {
        makeC(ar[startA].pow, (ar[startA].coeff+ar[startB].coeff));
        startA++;
        startB++;
       }

   }

   while(startA<=endA)
   {
       makeC(ar[startA].pow, ar[startA].coeff);
           startA++;
   }
   while(startB<=endB)
   {
       makeC(ar[startB].pow, ar[startB].coeff);
           startB++;

   }

}

void disp(int start)
{
    int i;
    for(i=start;i<=endC;i++)
        printf("coeff :%d pow %d\n", ar[i].coeff, ar[i].pow);
}

void makeC(int p, int c)
{
    ar[endC].pow=p;
    ar[endC].coeff=c;
    endC++;
}

int main()
{
    int startA=0, endA=0, startB=0, endB=0;
    startA=0;
    insert(&startA, &endA);
    startB=endA+1;
    insert(&startB, &endB);
    endC=endB+1;
    add(startA, endA, startB ,endB);
    disp(endB+1);
    scanf("%d", &startA);
    return 0;
}
