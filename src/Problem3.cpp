/*

Akash is genius reverse engineer, invented a world demanded machine and Kept in a secret building with a passkey.
Sam is very excited to see his wonderful creation. So, she went to the building with the pass key which is a
numeric code example "547". But there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door.

First door pass key is the largest number that can be formed by given passkey -> 754
Second door pass key is the next largest number that can be formed -> 745
Third door opens for next largest number ->574



Find which Nth door's room contains the machine or How many doors should Sam cross ?

Given input is in form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

explanation: (1) 875 (2) 857 (3) 785 (4) 758

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

Return NULL for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *prev;
	struct node *next;
};
void permute(int *, int, int, int, long);
void swap(int*, int*);
int count = 1;
int found = 0;

int doorstoCross(struct node *passKey)
{
	if (passKey == NULL){
		return -1;
	}
	struct node *temp = passKey;
	int *a = (int*)malloc(15 * sizeof(int)), i = 0, j, k;
	long num = 0;
	while (temp){
		a[i++] = temp->num;
		num = num * 10 + temp->num;
		temp = temp->next;
	}
	i--;
	if (i > 12){
		return -1;
	}
	for (j = 0; j < i + 1; j++){
		for (k = 0; k < i; k++){
			if (a[k]<a[k + 1]){
				swap(&a[k], &a[k + 1]);
			}
		}
	}
	count = 1;
	found = 0;
	permute(a, 0, i,i,num);
	return count;
	
}
void permute(int *a, int x, int y,int len,long num)
{
	int i;
	long result = 0;
	if (found == 1){
		return;
	}
	if (x == y){
		for (int j = 0; j <= len; j++){
			result = result * 10 + a[j];
		}
		if (result == num){
			found = 1;
			return;
		}
		else{
			count++;
			return;
		}
	}
	else
	{
		for (i = x; i <= y; i++)
		{
			swap((a + x), (a + i));
			 permute(a, x + 1, y,len,num);
			 if (found == 1){
				 return;
			 }
			swap((a + x), (a + i));
		}
	}
}
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}