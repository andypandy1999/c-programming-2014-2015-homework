#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define start_stack_size 5
#define string_size 50

struct stack_t{
 int *data;
 int top, size;
};

void stack_i(struct stack_t *s); 
void stack_des(struct stack_t *s); 
int stack_gs(struct stack_t *s); 
void stack_res(struct stack_t *s); 
void stack_pb(struct stack_t *s, int value); 
int stack_pu(struct stack_t *s); 
char *string_i(char string[string_size]); 

int calculator(struct stack_t *s, char operaciq[string_size]); 

int main()
{
 struct stack_t opera_stack;
 char operaciq[string_size];
 int res;
 string_i(operaciq);
 stack_i(&opera_stack);
 res = calculator(&opera_stack, operaciq);
 if(res == INT_MIN)
 {
 printf("To proceed the calculator, it need more expressions!");
 }else if(res== INT_MAX)
 {
 printf("You have entered too many !!\n");
 }
 else
 {
 printf("The result: %d\n ", res);
 }
 stack_des(&opera_stack);
 return 0;
}

void stack_i(struct stack_t *s)
{
 s->size = start_stack_size;
 s->top = 0;
 s->data = (int*) malloc(s->size * sizeof(int));
}

void stack_des(struct stack_t *s)
{
 s->size = 0;
 s->top = 0;
 free(s->data);
}

int stack_gs(struct stack_t *s)
{
 return s->top;
}

void stack_pb(struct stack_t *s, int value)
{
 if(s->top < s->size)
 {
 s->data[s->top++] = value;
 }
 else
 {
 stack_res(s);
 s->data[s->top++] = value;
 }
}

void stack_res(struct stack_t *s)
{
 int *new_s_data;
 int new_s_size;
 int i;
 if(s->top == s->size)
 {
  new_s_size = s->size * 2;
 new_s_data = (int*) malloc(new_s_size * sizeof(int));
 for(i=0; i<s->size; i++)
 {
 new_s_data[i] = s->data[i];
 }
 }
 else if(s->top < (s->top/2))
 {
 new_s_size = s->size / 2;
 new_s_data = (int*) malloc(new_s_size * sizeof(int));
 for(i=0; i<s->size; i++)
 {
 new_s_data[i] = s->data[i];
 }
 free(s->data);
 s->data = new_s_data;
 }
}

int stack_pu(struct stack_t *s)
{
 if(s->top != 0)
 {
 s->top = s->top - 1;
 if(s->size < start_stack_size)
 {
 stack_res(s);
 }
 return s->data[s->top];
 }
 else
 {
 return INT_MIN;
 }
}

void stack_copy(struct stack_t *from, struct stack_t *to)
{
 to->size = from->size;
 to->top = 0;
 to->data = (int*) malloc(to->size * sizeof(int));
 for(to->top = 0; to->top<to->size; to->size++)
 {
 to->data[to->top] = from->data[to->top];
 }
}
char *string_i(char string[string_size])
{
 printf("Please enter an expression: ");
 scanf("%s", string);
 return string;
}


int calculator(struct stack_t *s, char operaciq[string_size])
{
 int i, value, res, firstn, secondn;
 for(i = 0; operaciq[i] != '\0'; i++)
 {
 if(operaciq[i] >= '0' && operaciq[i] <= '9') 
 {
 value = operaciq[i] - '0';
 stack_pb(s,value);
 }
 else if(operaciq[i] == '+' || operaciq[i] == '-' || operaciq[i] == '*' || operaciq[i] == '/')
 {
 if(stack_gs(s) < 2)
 {
 return INT_MIN;
 }
 else
 {
 secondn = stack_pu(s);
 firstn = stack_pu(s);
 switch(operaciq[i])
 {
 case '*' :
 res = firstn * secondn;
 break;

 case '/' :
 res = firstn / secondn;
 break;

 case '+' :
 res= firstn + secondn;
 break;

 case '-' :
 res = firstn - secondn;
 break;
 }
 stack_pb(s,res);
 }
 }
 }
 if(stack_gs(s) == 1)
 {
 return res;
 }
 else
 {
 return INT_MAX;
 }
}