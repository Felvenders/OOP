#pragma once
#include <stdlib.h>
#include <iostream>
#include <cstddef>
#include <malloc.h>
#include <Windows.h>
#include <stdio.h>

// Инициализация списка
typedef struct node {

	int key;
	node* next;

}; node;


// Инициализация нулевого элемента
node* initialization(int a) {		// a - значение первого узла

	node* nd;

	nd = (node*)malloc(sizeof(node));
	nd->next = NULL;
	return(nd);

}

// Добавление узла в список
node* addelement(node* nd, int number) {

	node* temp, *nextelement;
	temp = (node*)malloc(sizeof(node)); 
	nextelement = nd->next;		// сохранение указателя на следующий узел
	nd->next = temp;	// предыдущий ссылается на создаваемый
	temp->key = number;		// сохранение поля данных добавляемого узла
	temp->next = nextelement;	// переменная temp ссылается на следующий элемент
	return(temp);

}

// Удаление узла из списка
node* deletelement(node* nd, node* root) {

	node* temp;
	temp = root;

	while (temp->next != nd) {
		temp = temp->next;
	}

	temp->next = nd->next;
	free(nd);
	return(temp);
	
}

// Удаление корня списка
node* deleteroot(node* root) {

	node* temp;
	temp = root->next;
	free(root);		// Освобождаем память из-под старого корня
	return(temp);

}

// 
