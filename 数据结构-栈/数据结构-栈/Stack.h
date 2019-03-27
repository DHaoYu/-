
typedef int TypeData;

typedef struct Stack
{
	TypeData *array;
	int top;
	int capecity;
}Stack;

void StackInit(Stack *s);
void StackPush(Stack *s,TypeData data);
void StackPop(Stack *s);
int StackSize(Stack *s);
int StackCapecity(Stack *s);
void StackDestory(Stack *s);
TypeData StackBack(Stack *s);
void _CheckStck(Stack *s);
void print(Stack *s);
