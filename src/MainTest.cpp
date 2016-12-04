/*
Mock Test 2
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/

#include <stdio.h>
#include<stdlib.h>
#include "FunctionHeaders.h"
# include<string.h>
struct node* createnode(int);
struct node
{
	int num;
	struct node *prev;
	struct node *next;
};
struct node* strtoDLL(char *str)
{
	int len = strlen(str);
	if (len == 0)
		return NULL;

	struct node *head = createnode(str[len - 1] - '0');
	for (int i = len - 2; i >= 0; i--)
	{
		struct node *temp = createnode(str[i] - '0');
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	return head;
}
struct node *createnode(int num)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}
int main(){
	struct node *passkey = strtoDLL("4312");
	int actualAns = doorstoCross(passkey);

}