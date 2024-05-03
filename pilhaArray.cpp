#include <iostream>
#include <locale.h>
using namespace std;

#define MAX 10

struct Pilha {
	int qtde;
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return (p->qtde);
}

void freePilha(Pilha *p) {
	free(p);
}

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	int podeDesempilhar = (p->qtde > 0);
	float v;
	if (podeDesempilhar) {
		v = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else {
		v = -1;
	}
	return v;
}

void print(Pilha *p) {
	cout << "Qtde de elementos: " << count(p) << endl;
	for(int i = p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "--------------------" << endl;
	
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	Pilha *pilhaFloat;
	pilhaFloat = new Pilha();
	pilhaFloat = init();
	
	cout << "Pilha vazia: " 
	     << (isEmpty(pilhaFloat)?"SIM":"NÃO") << endl;
	
	cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 15)?"SIM":"NÂO") << endl;
	print(pilhaFloat);
	
	cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 20)?"SIM":"NÂO") << endl;
	cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 25)?"SIM":"NÂO") << endl;
    cout << "Empilhado valor: "  
	     << (push(pilhaFloat, 30)?"SIM":"NÂO") << endl;
	cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 35)?"SIM":"NÂO") << endl;	     
    cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 40)?"SIM":"NÂO") << endl;
	cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 45)?"SIM":"NÂO") << endl;
    cout << "Empilhado valor: "  
	     << (push(pilhaFloat, 50)?"SIM":"NÂO") << endl;
	cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 55)?"SIM":"NÂO") << endl;	     
    cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 60)?"SIM":"NÂO") << endl;
	cout << "Empilhado valor: " 
	     << (push(pilhaFloat, 65)?"SIM":"NÂO") << endl;	
	print(pilhaFloat);
	
	freePilha(pilhaFloat);
	return 0;
}