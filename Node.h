struct person
{
   char name[20];
   int num;             ///Storing sequence of person inserting in list
};

struct node
{

    struct person data;

    struct node * next;
    struct node * prev;
};
