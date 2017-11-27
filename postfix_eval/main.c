#include <stdio.h>
#include <stdlib.h>

typedef enum {plus, minus, times, divide, eos, mod, rparen, lparen, operand} precedence;
int stack[20];
char expr[20];
int n;
int top;
void push(int x)
{
	printf("pushing %d\n", x);
	stack[++top]=x;
}
int pop()
{
	return stack[top--];
}
precedence getToken(char *symbol, char *n)
{
    *symbol=expr[(*n)++];

    switch(*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '-': return minus;
	case '+': return plus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;


	}

}

void printToken(precedence token)
{
    switch(token)
    {
      case plus:
		printf("+");
		break;
	case minus:
		printf("-");
		break;
	case divide:
		printf("/");
		break;
	case times:
		printf("*");
		break;
	case mod:
		printf("%%");
		break;
    }

}

int eval()
{
    int obj1;
    int obj2;
    precedence token;
    char symbol;
    n=0;
    top=0;


    for(token=getToken(&symbol, &n); token!=eos; token=getToken(&symbol, &n))
    {
      if(token==operand)
            push(symbol-'0');
      else if(token==minus)
      {
           obj1=pop();
           obj2=pop();
          push(obj2-obj1);
      }
      else if(token==plus)
      {
          obj1=pop();
           obj2=pop();
           printf("%d", obj1);
          push(obj2+obj1);
      }
       else if(token==divide)
      {
          obj1=pop();
           obj2=pop();
          push(obj2/obj1);
      }
       else if(token==times)
      {
          obj1=pop();
           obj2=pop();
          push(obj2*obj1);
      }
       else if(token==mod)
      {
          obj1=pop();
           obj2=pop();
          push(obj2%obj1);
      }


    }

    return pop();



}


int main()
{

	printf("Enter expression: ");
	scanf("%s",expr);
	printf("Result: %d",eval());
	scanf("%s",expr);
}
