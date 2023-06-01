//stack for storing the state of coin picking

struct curState{
	unsigned coinPos;
	int curSum;
};

struct Stack{
	int top;
	unsigned size;
	struct curState* state;

};

struct Stack * createStack(unsigned size);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, struct curState newState);
struct curState pop(struct Stack* stack);
struct curState peak(struct Stack* stack);



