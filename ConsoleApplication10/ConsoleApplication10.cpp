#include "pch.h"
#include <iostream>
#include <string>
#include "conio.h"
using namespace std;

 
struct list {
	int data;
	list *next;
};

void add(list *&top, int pos, int x) {
	int i, j = 1;
	list *pnew, *p = top;
	pnew = new list;
	pnew->data = x;
	if (pos <= 1 || top == NULL) {
		pnew->next = top; 
		top = pnew; 
	} 
	else {
		for (int i = 1; i < pos - 1; i++) {
			if (p->next != NULL) {
				p = p->next; 
				j++;
			}
		}
		if (pos <= j + 1) {
			pnew->next = p->next;  
			p->next = pnew;  
		}
	}
}

bool check(int num) {
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) { return false; }
	} return num > 1;   
}

void print(list *top) {
	list *a = top;
	while (a != NULL) {
		cout << a->data << " ";  
		a = a->next;   
	}
	cout << endl;
}

void solve(list *top) {
	list *curr = top;   
	list *prev = nullptr;  
	while (curr) {
		if (check(curr->data)) {
			prev ? prev->next = curr->next : top = curr->next;
			list *tmp = curr->next;  
			delete curr;   
			curr = tmp; 
		}
		else {
			prev = curr;  
			curr = curr->next;   
		}
	}
}

int main() {
	setlocale(LC_ALL, "eng");
	while (!feof(stdin)) {
		int numb, x;
		list *List = NULL;
		cout << "Enrty count of elements: ";
		cin >> numb;
		for (int i = 1; i <= numb; i++) {
			cout << "Entry " << i << " element -> ";
			cin >> x;
			add(List, i, x);   
		}
		print(List);  
		solve(List);
		cout << "List after call solve function, that delete all of simple numbers:\n";
		print(List);  
	}
	_getch();
	return 0;
}