// BinaryTreeTraversal.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int num = 10000;

typedef struct node *treePointer; //treePointer는 node 포인터 형식
typedef struct node {
	int data;;
	treePointer LChild, RChild;
} node;

void InsertNode(treePointer main, treePointer sub) {
	if (main->data > sub->data) {
		if (!(main->LChild)) {
			main->LChild = sub;
		}
		else {
			InsertNode(main->LChild, sub);
		}
	}
	else {
		if (!(main->RChild)) {
			main->RChild = sub;
		}
		else {
			InsertNode(main->RChild, sub);
		}
	}
}

//전위 순회
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->LChild);
		preorder(ptr->RChild);
	}
}

// 중위 순회
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->LChild);
		cout << ptr->data << ' ';
		inorder(ptr->RChild);
	}
}

// 후위 순회
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->LChild);
		postorder(ptr->RChild);
		cout << ptr->data << "\n";
	}
}

int main()
{
	node nodes[10001]; // num+1
	int cnt = 0;

	
	for (int i = 1; i <= num; i++) {
		int a;
		cin >> a;
		if (a == EOF) {
			break;
		}
		cnt++;
		nodes[i].data = a;
		nodes[i].LChild = NULL;
		nodes[i].RChild = NULL;
	}

	//자식 노드 연결
	for (int i = 2; i <= cnt; i++) {

		InsertNode(&nodes[1], &nodes[i]);
	}

	postorder(&nodes[1]);
    return 0;
}

