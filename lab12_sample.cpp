#include <stdio.h>
#include <stdlib.h>

typedef struct sPoly {
	int degree;                         // the degree of the node
	double coef;                        // the coefficient of the node
	struct sPoly *next;                 // pointer to the next node
} POLY;

// This function creates a 1-term polynomial of the form coef * x^degree
// and returns the new polynomial.
POLY *oneTerm(int degree, double coef);

// This function adds two polynomials p1 and p2 to form a new polynomial
// and return the new polynomial.
POLY *add(POLY *p1, POLY *p2); 

// This function subtracts polynomial p2 from p1 to form a new polynomial
// and return the new polynomial.
POLY *sub(POLY *p1, POLY *p2);

// This function multiplies two polynomials p1 and p2 to form a new
// polynomial and return the new polynomial.
POLY *mply(POLY *p1, POLY *p2);

// This function prints out the polynomial p1 in human readable form.
void print(POLY *p1);

// This function releases all nodes of the polynomial p1 and returns them
// to the heap space.
void release (POLY *p1);

int main(void)
{
	POLY *A, *A2, *A3, *A4, *A5;        // polynomials of A
	POLY *B, *B2, *B3, *B4, *B5;        // polynomials of B
	POLY *C, *C2, *C3, *C4, *C5;        // polynomials of C
	POLY *X, *One;                      // X = x and One = 1

	X = oneTerm(1, 1);                  // X = degree 1 have coef = 1
	One = oneTerm(0, 1);                // One = degree 0 have coef = 1
	A = add(X, One);                    // A = x + 1
	B = sub(X, One);                    // B = x - 1
	release(X);                         // free X
	release(One);                       // free One
	A2 = mply(A, A);                    // A2 = A * A
	A3 = mply(A2, A);                   // A3 = A2 * A
	A4 = mply(A3, A);
	A5 = mply(A4, A);
	printf("A = ");
	print(A);
	printf("A2 = ");
	print(A2);
	B2 = mply(B, B);                    // B2 = B * B
	B3 = mply(B2, B);                   // B3 = B2 * B
	B4 = mply(B3, B);
	B5 = mply(B4, B);
	C = add(A, B);                      // C = A + B
	release(A);                         // free A
	release(B);                         // free B
	C2 = mply(A2, B2);                  // C2 = A2 * B2
	release(A2);
	release(B2);
	C3 = mply(A3, B3);
	release(A3);
	release(B3);
	C4 = mply(A4, B4);
	release(A4);
	release(B4);
	C5 = mply(A5, B5);
	release(A5);
	release(B5);
	printf("C = ");                      // show the result
	print(C);                            // show the result
	release(C);                          // release C
	printf("C2 = ");
	print(C2);
	release(C2);
	printf("C3 = ");
	print(C3);
	release(C3);
	printf("C4 = ");
	print(C4);
	release(C4);
	printf("C5 = ");
	print(C5);
	release(C5);
	return 0;
}

POLY *oneTerm(int degree, double coef)
{
	POLY *n;                                   // new node
	
	n = (POLY *)malloc(sizeof(POLY));          // generate a node
	n->degree = degree;                        // generate degree
	n->coef = coef;                            // generate coefficient
	n->next = NULL;                            // next points to null
	return n;                                  // return new node
}

POLY *add(POLY *p1, POLY *p2)
{
	POLY *n;                                   // new node
	POLY *head;                                // head of new polynomial
	POLY *prev = NULL;                         // previous position

	n = (POLY *)malloc(sizeof(POLY));          // generate a new node
	n->next = NULL;                            // initial point to null
	head = n;                                  // head of new polynomial
	do {
		if (p1 && (!p2 || p1->degree > p2->degree)) { 
		                                       // p1 have higher degree
			n->degree = p1->degree;            // pass degree to new node
			n->coef = p1->coef;                // pass coef to new node
			p1 = p1->next;                     // p1 go to next degree
		} else if (p2 && (!p1 || p1->degree < p2->degree)) {
		                                       // p2 have higher degree
			n->degree = p2->degree;            // pass degree to new node
			n->coef = p2->coef;                // pass coef to new node
			p2 = p2->next;                     // p2 go to next degree
		} else {                               // have same degree
			n->coef = p1->coef + p2->coef;     // new coefficient
			if (n->coef)	n->degree = p1->degree; // pass degree
			p1 = p1->next;                     // p1 go to next degree
			p2 = p2->next;                     // p2 go to next degree
		}
		if (n->coef) {                         // have coef
			if (n != head)	prev->next = n;    // previous points to this
			prev = n;                          // renew previous position	
		} else	release(n);                    // no coef then release
		n = (POLY *)malloc(sizeof(POLY));      // generate a new node
		n->next = NULL;                        // initial point to null
	} while (p1 || p2);                        // both are null will exit
	prev->next = NULL;                         // next of last node is null
	release(n);                                // free extra n
	return head;                               // return the head
}

POLY *sub(POLY *p1, POLY *p2)
{	
	POLY *head = NULL;                         // head of new polynomial
	POLY *prev = NULL;                         // previous position
	POLY *n;                                   // new node

	n = (POLY *)malloc(sizeof(POLY));          // generate a new node
	n->next = NULL;                            // point to null (initialize)
	head = n;                                  // head of new linked list
	do {
		if (p1 && (!p2 || p1->degree > p2->degree)) { 
		                                       // p1 have higher degree
			n->degree = p1->degree;            // pass degree to new node
			n->coef = p1->coef;                // pass coef to new node
			p1 = p1->next;                     // p1 go to next degree
		} else if (p2 && (!p1 || p1->degree < p2->degree)) {
		                                       // p2 have higher degree
			n->degree = p2->degree;            // pass degree to new node
			n->coef = -p2->coef;               // pass coef to new node
			p2 = p2->next;                     // p2 go to next degree
		} else {                               // have same degree
			n->coef = p1->coef - p2->coef;     // new coefficient
			if (n->coef)	n->degree = p1->degree; // pass degree
			p1 = p1->next;                     // p1 go to next degree
			p2 = p2->next;                     // p2 go to next degree
		}
		if (n->coef) {                         // have coef
			if (n != head)	prev->next = n;    // previous points to this
			prev = n;                          // renew previous position	
		} else	release(n);                    // no coef then release
		n = (POLY *)malloc(sizeof(POLY));      // generate a new node
		n->next = NULL;                        // initial point to null
	} while (p1 || p2);                        // both are null will exit
	prev->next = NULL;                         // next of last node is null
	release(n);                                // free extra node
	return head;
}

POLY *mply(POLY *p1, POLY *p2)
{
	POLY *p3, *p4;                                  // poly. to be added
	POLY *hp1, *hp2;                                // head of p1 and p2
	POLY *n;                                        // new node
	POLY *final = NULL;                             // poly. to be return
	POLY *prev;                                     // previous address

	hp1 = p1;                                       // head of p1
	hp2 = p2;                                       // head of p2
	n = (POLY*)malloc(sizeof(POLY));                // generate a new node
	p3 = n;                                         // first poly.
	for ( ; p1 != NULL; p1 = p1->next) {            // loop p1
		if (p1 != hp1)	p4 = n;                     // poly. to be added
		for (p2 = hp2; p2 != NULL; p2 = p2->next) { // loop p2
			n->degree = p1->degree + p2->degree;    // pass degree
			n->coef = p1->coef * p2->coef;          // pass coef
			n->next = NULL;                     // initial point to null
			if (p2 != hp2)	prev->next = n;     // prev node points to this
			prev = n;                           // renew prev
			n = (POLY *)malloc(sizeof(POLY));   // generate a new node
		}
		n->next = NULL;                         // last node points to null
		if (p1 != hp1) {                        // not the first poly.
			final = add(p3, p4);                // add the two poly.
			release(p3);                        // free useless p3
			release(p4);                        // free useless p4
			p3 = final;                         // poly. be added again
		}
	}
	release(n);                                 // free the last node
	return final;                               // return final poly.
}	

void print(POLY *p1)
{
	POLY *head = p1;                            // head of new poly.
	
	for ( ; p1 != NULL; p1 = p1->next)          // loop p1
		if (p1->degree == 0) {                  // degree is 0
			if (p1->coef > 0)		printf(" +%lg", p1->coef);  // +
			else					printf(" %lg", p1->coef);   // -
		} else if (p1 == head) {                                // at head
			if (p1->coef != 1)		printf("%lg ", p1->coef); // 1 no print
			if (p1->degree == 1)	printf("x");              // no degree
			else 					printf("x^%d", p1->degree); // degree
		} else {                                                // middle
			if (p1->coef == -1)		printf(" - ");              // only -
			else if (p1->coef == 1)	printf(" + ");              // only +
			else if (p1->coef < 0)	printf(" %lg ", p1->coef);  // have -
			else					printf(" +%lg ", p1->coef); // need +
			if (p1->degree == 1)	printf("x");              // no degree
			else					printf("x^%d", p1->degree); // degree
		}
	printf("\n");
}
		
void release(POLY *p1)
{
	POLY *prev;                           // position to free

	while (p1 != NULL) {                  // before null
		prev = p1;                        // renew position to free
		p1 = p1->next;                    // renew p1 position
		free(prev);                       // free it
	}
}	


