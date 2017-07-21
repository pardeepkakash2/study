#include <stdio.h>
/* 
. &arr is a pointer to the array. It points at the base address as arr. But arr decays to a pointer to first element.
. That means &arr + 1 points at the address after the end of the array.
. Dereferencing to *(&arr + 1) gives the address after the end of the last element 
  (which is again the same address as &arr + 1 with a different type; Similar to arr and &arr as *&arr is equivalent to arr).
. Finally, we can subtract the pointer to the first element to get the length of the array :
*(&arr + 1) - arr. (Remember this is pointer arithmetic; Subtraction gives the total number of objects between them).

&arr[0] is equivalent to arr.
arr[0] is equivalent to *arr (value of an address of the pointer).
&arr[i] is equivalent to (arr + i) AND, arr[i] is equivalent to *(arr + i).

& : reference operator. * : dereferance operator.
Note: The * sign when declaring a pointer is not a dereference operator. It is just a similar notation that creates a pointer.
*/

# define my_sizeof(type) ( (char *)(&type+1) - (char*)(&type) ) 
	
int arr[6] = {1,2,3,4,5,6};

/*
	void myFunction(int *param) {parameter as a pointer}
	void myFunction(int param[10]) {parameter as a sized array}
	void myFunction(int param[10]) {parameter as a unsized array}

*/
int asizeof(int arr[6])
{
	return ( (char *)(&arr + 1) - (char *)(&arr) );
}
int main()
{
 	int size = 0;

	/*Finds size of arr[] and stores in 'size'*/
	printf("%ld : %ld\n", my_sizeof(arr), my_sizeof(arr[0]));
	size = my_sizeof(arr) / my_sizeof(arr[0]);
	printf("asize : %d\n", size);

	size = asizeof(arr);	
	printf("asize : %d\n", size);

	printf("%p : %p : asize : %ld\n", (&arr + 1), arr, *(&arr + 1) - arr);
	return 0;
}
