#pragma once
#include <stdlib.h>
#include <iostream>
#include <cstddef>
#include <malloc.h>
#include <Windows.h>
#include <stdio.h>

// ������������� ������
typedef struct node {

	int key;
	node* next;

}; node;


// ������������� �������� ��������
node* initialization(int a) {		// a - �������� ������� ����

	node* nd;

	nd = (node*)malloc(sizeof(node));
	nd->next = NULL;
	return(nd);

}

// ���������� ���� � ������
node* addelement(node* nd, int number) {

	node* temp, *nextelement;
	temp = (node*)malloc(sizeof(node)); 
	nextelement = nd->next;		// ���������� ��������� �� ��������� ����
	nd->next = temp;	// ���������� ��������� �� �����������
	temp->key = number;		// ���������� ���� ������ ������������ ����
	temp->next = nextelement;	// ���������� temp ��������� �� ��������� �������
	return(temp);

}

// �������� ���� �� ������
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

// �������� ����� ������
node* deleteroot(node* root) {

	node* temp;
	temp = root->next;
	free(root);		// ����������� ������ ��-��� ������� �����
	return(temp);

}

// 
