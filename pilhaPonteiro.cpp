#include <iostream>
#include <locale.h>
using namespace std;

struct No {
    float dado;
	struct No *prox;	
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

int count(Pilha *p) {
	int i = 0;
	No *no;
	no = p->topo;
	while (no != NULL) {
		i++;
		no = no->prox;
	}
	return i;
}

void print(Pilha *p) {
	No *no;
	no = p->topo;
	cout << "Qtde de elementos: " << count(p) << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "--------------------" << endl;
}

void freePilha(Pilha *p) {
    No *no;
	no = p->topo;
	while (no != NULL) {
		No *aux = no->prox;
		free(no);
		no = aux;
	}	
	free(p);
}

void push(Pilha *p, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

float pop(Pilha *p) {
	float v;
	int podeDesempilhar = (p->topo != NULL);
	if (podeDesempilhar) {
		No *no = p->topo;
		v = no->dado;
		p->topo = no->prox;
		free(no);
	}
	else {
		v = -1;
	}
	return v;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	Pilha *pilhaFloat;
	pilhaFloat = init();
	
	cout << "Pilha vazia: " 
	     << (isEmpty(pilhaFloat)?"SIM":"NÃO") << endl;
	
	push(pilhaFloat, 15);
	
	print(pilhaFloat);
	push(pilhaFloat, 20);
	push(pilhaFloat, 25);
	push(pilhaFloat, 30);
	push(pilhaFloat, 35);
	push(pilhaFloat, 40);
	push(pilhaFloat, 45);
	push(pilhaFloat, 50);
	push(pilhaFloat, 55);
	push(pilhaFloat, 60);
	push(pilhaFloat, 65);
	print(pilhaFloat);
	
	freePilha(pilhaFloat);
	return 0;
}