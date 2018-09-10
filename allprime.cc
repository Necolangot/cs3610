/* D. Neco Lubuguin
	CS 3610
	9/6/18
	prime number calculator
	*/
	
	#include <iostream>
	#include <string>
	#include <cstdlib>
	#include <math.h>
	
struct Num{
	int value;
	bool checked;
	Num *link;
};

Num *build_list(int n,Num *head);

void find_prime(Num *head, int n);
	
int main(int argc, char *x[5]){
	Num *head;
	int n = atoi(x[1]), count;
	if (n < 2 || n > 300000){
		std::cout<<"Error! Must input value for n!\n";
		std::exit(1);
	}

	head = build_list(n, head);
	find_prime(head, n);
}

Num *build_list(int n,Num *head){
	head = NULL;
	Num *tail;
	for (int i = 1;i < n;i++){
		Num *temp=new Num;
		temp->value=i+1;
		temp->link = NULL;
		temp->checked = false;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{	
			tail->link=temp;
			tail=temp;
		}
	}
	return(head);	
}

void find_prime(Num *head, int n){
	int p = 2, nextp;
	Num *cursor;
	bool foundp;
	do {
		foundp = false;
		for(cursor = head;cursor->link != NULL;cursor = cursor->link){
			if (cursor->value % p == 0){
				cursor->checked = true;
			}
			else if (foundp = false){
					nextp = cursor->value;
			}
		}
		p = nextp;		
	} while (p <= ((int)sqrt(n)));
}

