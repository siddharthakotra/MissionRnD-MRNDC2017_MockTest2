/*

Four kids sat in a circle like around a carrom board. Between them there is an image.
Each will get a chance to throw the coin which contains L, R

If coin shows L, The image is rotated anticlockwise direction i.e, -90 deg
If coin shows R, The image is rotated clockwise direction i.e, +90 deg

Input is the 2-D Array where each integer represents each pixel of an image,

All the coin throws are given in form of string like "LLRLLRRLR" (case insensitive)

How would the image look after applying all the rotations ?

Example: If the string is "LL",

Then after one rotation .

1	2	3				3	6	9
4	5	6    ---->			2	5	8
7	8	9				1	4	7

Another one left rotation

3	6	9				9	8	7
2	5	8	----->			6	5	4
1	4	7				3	2	1

So final answer after applying "LL" rotations is

1	2	3	  o/p			9	8	7
4	5	6    ---->			6	5	4
7	8	9				3	2	1

NOTES:
1. Dice throws is case insensitive ex: "lRrL"
2. Given 2-D array is square array.
3. Order of matrix can be < 500.
4. No need to return anything. Manipulate input array itself.
5. Len is the number of rows/cols of the 2d array.

Constraints :
0<=len<=500
0<=strlen(seq)<=500
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate_array_helper(int**, int, char);
void rotate_right(int**, int len);
void rotate_left(int**, int len);

void rotateArray(int **arr, int len, char *seq)
{
	//Manipulate input array for output
	if (len <= 0 || len > 500 || strlen(seq) <= 0 || strlen(seq) > 500){
		return;
	}
	int i;
	for (i = 0; seq[i] != '\0'; i++){
		rotate_array_helper(arr, len, seq[i]);
	}
	
}
void rotate_array_helper(int **a, int len, char seq){
	switch (seq){
		case 'l':
		case 'L':
			rotate_left(a, len);
			break;
		case 'r':
		case 'R':
			rotate_right(a, len);
			break;
	}
}
void rotate_left(int** arr, int len){
	int i, j, k = 0, l = 0;
	int **b;
	b = (int**)malloc(len*(sizeof(int*)));
	for (i = 0; i < len; i++){
		b[i] = (int*)malloc(len*(sizeof(int)));
	}
	for (i = len - 1, k = 0; i >= 0; i--,k++){
		for (j = 0, l = 0; j < len; j++,l++){
			b[k][l] = arr[j][i];
		}
	}
	for (i = 0; i < len; i++){
		for (j = 0; j < len; j++){
			arr[i][j] = b[i][j];
		}
	}
}
void rotate_right(int **arr, int len){
	int i, j, k = 0, l = 0;
	int **b;
	b = (int**)malloc(len*(sizeof(int*)));
	for (i = 0; i < len; i++){
		b[i] = (int*)malloc(len*(sizeof(int)));
	}
	for (i = 0, k = 0; i < len; i++,k++){
		for (j = len-1,l = 0; j >= 0; j--, l++){
			b[k][l] = arr[j][i];
		}
	}
	for (i = 0; i < len; i++){
		for (j = 0; j < len; j++){
			arr[i][j] = b[i][j];
		}
	}
}