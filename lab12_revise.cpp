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
	POLY *n = NULL;                                   // new node
	POLY *head = NULL;                                // head of new polynomial
	
	head = oneTerm(0, 0);
	n = head;
	while (p1 && p2)
 		if (p1->degree == p2->degree) {
			if (p1->coef + p2->coef) {
				n->next = oneTerm(p1->degree, p1->coef + p2->coef);
				n = n->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		} else if (p1->degree > p2->degree) {
			n->next = oneTerm(p1->degree, p1->coef);
			p1 = p1->next;
			n = n->next;
		} else {
			n->next = oneTerm(p2->degree, p2->coef);
			p2 = p2->next;
			n = n->next;
		}
	for ( ; p1 != NULL; p1 = p1->next, n = n->next)
		n->next = oneTerm(p1->degree, p1->coef);
	for ( ; p2 != NULL; p2 = p2->next, n = n->next)
		n->next = oneTerm(p2->degree, p2->coef);
	return head->next;	
}

POLY *sub(POLY *p1, POLY *p2)
{	
	POLY *n = NULL;                                   // new node
	POLY *head = NULL;                                // head of new polynomial
	
	head = oneTerm(0, 0);
	n = head;
	while (p1 && p2)
 		if (p1->degree == p2->degree) {
			if (p1->coef - p2->coef) {
				n->next = oneTerm(p1->degree, p1->coef - p2->coef);
				n = n->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		} else if (p1->degree > p2->degree) {
			n->next = oneTerm(p1->degree, p1->coef);
			p1 = p1->next;
			n = n->next;
		} else {
			n->next = oneTerm(p2->degree, -p2->coef);
			p2 = p2->next;
			n = n->next;
		}
	for ( ; p1 != NULL; p1 = p1->next, n = n->next)
		n->next = oneTerm(p1->degree, p1->coef);
	for ( ; p2 != NULL; p2 = p2->next, n = n->next)
		n->next = oneTerm(p2->degree, -p2->coef);
	return head->next;	
}

POLY *mply(POLY *p1, POLY *p2)
{
	POLY *n, *hp2 = p2;
	POLY *p3, *p4, *hp3; 
	
	hp3 = p3 = oneTerm(0, 0);
	for ( ; p2 != NULL; p2 = p2->next, p3 = p3->next)
		p3->next = oneTerm(p1->degree + p2->degree, p1->coef * p2->coef);	
	hp4 = p4 = oneTerm(0, 0);
	for (p1 = p1->next; p1 != NULL; p1 = p1->next) {
		for (p2 = hp2; p2 != NULL; p2 = p2->next) {
			p4->next = oneTerm(p1->degree + p2->degree, p1->coef * p2->coef);
			
		}
	}
}	

void print(POLY *p1)
{
	POLY *head = p1;                            // head of new poly.
	
	for ( ; p1 != NULL; p1 = p1->next)          // loop p1
		if (p1->degree == 0) {                  // degree is 0
			if (p1->coef > 0)		printf(" +%lg", p1->coef);  // +
			else					printf(" %lg", p1->coef);   // -
		} else if (p1 == head) {                                // at head
			if (p1->coef == -1)		printf("- ");               // only -
			else if (p1->coef < 0)	printf("%lg ", p1->coef);   // have -
			else if (p1->coef != 1)	printf("%lg ", p1->coef); // 1 no print
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
