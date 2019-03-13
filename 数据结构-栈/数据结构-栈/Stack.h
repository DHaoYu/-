
typedef int TypeData;
typedef struct Stack
{
	TypeData *array;
	TypeData top;
	TypeData capecity;
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
void Stackpop(Stack *s);