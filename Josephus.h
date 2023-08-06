#define totalNames 100

int isAlreadyAdded(int arr[], int value, int index);
void readNameFromFile(unsigned int index, char * name, FILE * fpt);


int isListEmpty(struct node * head);
int getListLength(struct node * head);


void printEmployeeData(struct person * emp);
void printNodeData(struct node * node_x);
void printClockwise(struct node * head);
void printAnticlockwise(struct node * head);


void insertNodeAtStart(struct node ** head, char * NAME, int number);
void insertNodeAtEnd(struct node * head, char * NAME, int number);
