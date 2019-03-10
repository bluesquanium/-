#include <iostream>
#include <vector>
using namespace std;

#define DATA	char
#define INIT	'\0'

class TNode {
public :
	DATA data;
	TNode * leftChild;
	TNode * rightChild;
	
	TNode(DATA _data = INIT) { // constructor
		data = _data;
		leftChild = NULL;
		rightChild = NULL;
	}
	
	TNode * CheckChild(bool lr) { // lr = True -> left, lr = False -> right
		if(lr == true)
			return leftChild;
		else
			return rightChild;
	}
};

class Tree {
public:
	TNode * root;
	
	void Init(DATA data);
	
	TNode * Search(DATA target);
	
	bool Insert(DATA data_parent, DATA data, bool lr);
	
	void Traverse(TNode * _root, int mode); // 0 : preorder, 1 : inoreder, 2 : postorder
	
	void Delete();
};

int main(void) {
	int n;
	cin >> n;
	//scanf("%d", &n);
	if(n < 1)
		return 0;
	Tree tree;
	tree.Init('A');
	for(int i = 0; i < n; i++) {
		char parent, left, right;
		//fflush(stdin);
		cin >> parent >> left >> right;
		//scanf("%c %c %c", &parent, &left, &right);
		//printf("p = %c l = %c r = %c\n", parent, left, right);
		if(left != '.')
			tree.Insert(parent, left, 1);
		if(right != '.')
			tree.Insert(parent, right, 0);
	}
	
	tree.Traverse(tree.root ,0);
	cout << endl;
	tree.Traverse(tree.root ,1);
	cout << endl;
	tree.Traverse(tree.root ,2);

	return 0;
}

void Tree::Init(DATA data) {
	root = new TNode(data);
}

TNode * Tree::Search(DATA target) {
	vector<TNode*> stack;
	TNode * cur;
	
	stack.push_back(root); // this.root는 안되는거? 
	
	while( !stack.empty() ) {
		cur = stack.back();
		stack.pop_back();
		
		if(cur->data == target)
			return cur;
		else {
			if(cur->leftChild != NULL)
				stack.push_back(cur->leftChild);
			if(cur->rightChild != NULL)
				stack.push_back(cur->rightChild);
		}	
	}
	
	return NULL;
}

bool Tree::Insert(DATA data_parent, DATA data, bool lr) {
	TNode * newTNode = new TNode(data);
	TNode * parent = Tree::Search(data_parent);
	
	if(lr == true) {
		if(parent->leftChild != NULL)
			return false;
		parent->leftChild = newTNode;
	}
	else {
		if(parent->rightChild != NULL)
			return false;
		parent->rightChild = newTNode;
	}
	return true;
}

void Tree::Traverse(TNode * _root, int mode) {
	if(_root == NULL)
		return;
	
	if(mode == 0) {
		cout << _root->data;
		Tree::Traverse(_root->leftChild, mode);
		Tree::Traverse(_root->rightChild, mode);
	}
	else if(mode == 1) {
		Tree::Traverse(_root->leftChild, mode);
		cout << _root->data;
		Tree::Traverse(_root->rightChild, mode);
	}
	else if(mode == 2) {
		Tree::Traverse(_root->leftChild, mode);
		Tree::Traverse(_root->rightChild, mode);
		cout << _root->data;
	}
	else {
		cout << "Input the mode correctly!" << endl;
	}
}

void Tree::Delete() {
	// 나중에 필요하면 만들자! 
}
