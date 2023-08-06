/*********************************************************************
 This program simulates the Josephus Problem (text based) using
 Doubly Circular linked list

 Author: Abdul Basit Qureshi

 Date started:  14th October 2022
 Last Modified: 26th October 2022
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "Josephus.h"
#include "Node.h"

int main()
{
    struct node * head = NULL;
    FILE *fptr;


    fptr = fopen("names.txt","r");      //opening file
    if(fptr == NULL)
    {
        printf("Sorry! Error in opening file.\n");
        exit(1);
    }

    int arr[totalNames];
    srand((unsigned int)time(0));

    ///generating random array of size 100 without repeating any number
    for(int i=0; i<totalNames; i++)
    {
        int tmp = rand()%totalNames;      ///from 0 to 99

        while(i != 0 && isAlreadyAdded(arr, tmp, i))    ///if number is already added then move to next number
            tmp = rand()%totalNames;

        arr[i] = tmp;
    }



    int len, index = 0, lineIndex[totalNames];
    char name[20];

    ///storing starting index of each line from file
    for(int i=0; i<totalNames; i++)
    {
        readNameFromFile(index, name, fptr);
        len = strlen(name);

        lineIndex[i] = index;   ///storing offset of each line in array
        index = index + len + 1;
    }




    int total_persons, start_point, k;
    char direction;


    printf("\n  Welcome to the text based Josephus Problem Program.\n");

    ///asking for total number of people
    do
    {
        printf("\n  Enter the total number of people (max %d): ", totalNames);
        scanf("%d", &total_persons);
        fflush(stdin);
    }while(total_persons > totalNames || total_persons < 0);



    ///inserting in a doubly circular linked list after reading names randomly from file
    for(int i=0; i<total_persons; i++)
    {
        readNameFromFile(lineIndex[arr[i]], name, fptr);

        if(i == 0)    ///will execute in only first iteration
            insertNodeAtStart(&head, name, i+1);
        else
            insertNodeAtEnd(head, name, i+1);
    }
    fclose(fptr);   //closing file

    ///boundary cases if total number of people is 0 or 1
    if(total_persons == 0)
    {
        printf("\n  No one is left!");
        exit(0);
    }
    else if(total_persons == 1)
    {
        printf("\n  Winning person is\n");
        printClockwise(head);
        exit(0);
    }


    ///asking for starting point
    do
    {
        printf("\n  Enter starting point(1 to %d): ", total_persons);
        scanf("%d", &start_point);
        fflush(stdin);
    }while(start_point < 1 || start_point > total_persons);

    while(head->data.num != start_point)    ///changing head according to starting point
        head = head->next;



    ///Determining which Kth person should be killed
    do
    {
        printf("\n  Enter position of which person should be killed (2 to %d): ",total_persons);
        scanf("%d", &k);
        fflush(stdin);
    }while(k < 2 || k > total_persons);


    ///asking for direction
    do
    {
        printf("\n  Enter direction clockwise/anti-clockwise (c or a): ");
        direction = getchar();
        fflush(stdin);
    }while(direction != 'a' && direction != 'c');



    ///printing all people with names according to conditions
    if(direction == 'a')
        printAnticlockwise(head);
    else
        printClockwise(head);

    printf("  are sitting in a Circle.\n\n");




    /**Actual Code and Conditions Start from here**/

    int round = 1;

    struct node * temp = head;

    do  ///will execute when there is at least two person
    {
        if(direction == 'c')        ///when direction is clockwise
        {
            int flag = 0, i = 0;
            struct node * tail = head->prev;

            while(1)
            {
                for(int j=0; j<k-1; j++)
                {
                    ///if it reaches to tail OR reaches to head other than start of the loop
                    if(temp->data.num == tail->data.num || (temp->data.num == head->data.num && i != 0))
                        flag = 1;

                    temp = temp->next;      //moving to the required index
                }

                ///if it reaches to tail OR reaches to head
                if(temp->data.num == tail->data.num || temp->data.num == head->data.num)
                    flag = 1;

                struct node * aft = temp->next;
                if(temp == head)    //if deleting node is  head
                {
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                    free(temp);
                }
                else        //if deleting node is other than head
                {
                    struct node * before = temp->prev;
                    before->next = aft;
                    aft->prev = before;
                    free(temp);
                }
                tail = head->prev;      //settling tail in case tail is deleted and didn't named as tail

                total_persons--;   //minus one from people every time after removing one person from the list

                temp = aft;

                i++;

                if(flag)    ///breaking loop to print remaining persons one iteration completed
                    break;
            }
        }

        else    ///when direction is anti-clockwise
        {
            int flag = 0, i = 0;
            struct node * tail = head->next;

            for(;;)     //infinite loop
            {
                for(int j=0; j<k-1; j++)
                {
                    ///if pointer reaches to tail OR reaches to head other than start of the loop
                    if(temp->data.num == tail->data.num || (temp->data.num == head->data.num && i != 0))
                        flag = 1;

                    temp = temp->prev;      //moving to the required index
                }

                ///if pointer reaches to tail OR reaches to head
                if(temp->data.num == tail->data.num || temp->data.num == head->data.num)
                    flag = 1;


                struct node * aft = temp->prev;
                if(temp == head)    //if deleting node is head
                {
                    head = head->prev;
                    head->next = tail;
                    tail->prev = head;
                    free(temp);
                }

                else    //if deleting node is other than head
                {
                    struct node * before = temp->next;
                    before->prev = aft;
                    aft->next = before;
                    free(temp);
                }
                tail = head->next;

                total_persons--;   //minus one from total people every time after removing one person from the list

                temp = aft;

                i++;

                if(flag)
                    break;
            }

        }

        ///printing remaining persons after every round
        printf("\n  Remaining people after %d iteration\n", round);

        if(direction == 'c')
            printClockwise(head);
        else
            printAnticlockwise(head);


        printf("\n\n");
        round++;

    }while(total_persons != 1);

    printf("\n  So the winning person is\n");
    printClockwise(head);
    getch();

    printf("\n  Exiting the program!\n");
    return 0;
}
