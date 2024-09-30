/*
 * Instructions:
 *
 * 1. Instantiate a new object of type struct s and print out its size. Use
 *    sizeof(variable_name) to compute the size of an object.
 *      struct s structure;
 *
 * 2. Instantiate a pointer to struct s:
 *      struct s *s_ptr;
 * 3. Call malloc to allocate some memory for struct *s_ptr.
 * 4. Print the address of the memory region that malloc() returns.
 * 5. Set the values of the elements in the struct to 0.
 * 6. malloc() a second pointer to a struct s, and point its next element to
 *    the address of the first struct you malloc'd.
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct s {
    struct s *next;

    int k;
};


int main() {
	struct s newObj;
	printf("Size of newObj: %lu bytes\n", sizeof(newObj));
	
	struct s *s_ptr;
	
	s_ptr = (struct s *)malloc(sizeof(struct s));
	printf("Address of newObj: %p\n", (void *)s_ptr);
	
	s_ptr->next = NULL;
	s_ptr->k = 0;
	
	struct s *s2_ptr;
	s2_ptr = (struct s *)malloc(sizeof(struct s));
	
	s2_ptr->next = s_ptr;
	s2_ptr->k = 0;
	
	printf("s2_ptr is at : %p\n", (void *) s2_ptr);	
	printf("s2_ptr->next: %p\n", (void *)s2_ptr->next);
	
}
