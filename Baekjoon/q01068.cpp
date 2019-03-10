#include <iostream>
#include <vector>
using namespace std;

#define DATA	int
#define INIT	0

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
	
	bool Insert(DATA data_parent, DATA data);
	
	void Traverse(TNode * _root, int mode); // 0 : preorder, 1 : inoreder, 2 : postorder
	
	int CountLeaf();
	
	bool Delete(DATA target); // 삭제 시 자식노드들 데이터 반환 안함 
};

int main(void) {
	int n, parent, target;
	Tree tree;
	tree.Init(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> parent;
		if(parent != -1)
			tree.Insert(parent,i);
	}
	cin >> target;
	tree.Delete(target);
	cout << tree.CountLeaf();
	//tree.Traverse(tree.root ,0);

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

bool Tree::Insert(DATA data_parent, DATA data) {
	TNode * newTNode = new TNode(data);
	TNode * parent = Tree::Search(data_parent);
	
	if(parent->leftChild == NULL)
		parent->leftChild = newTNode;
	else if(parent->rightChild == NULL)
		parent->rightChild = newTNode;
	else return false;
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

int Tree::CountLeaf() {
	vector<TNode*> stack;
	TNode * cur;
	
	int count = 0;
	stack.push_back(root);
	while( !stack.empty() ) {
		cur = stack.back();
		stack.pop_back();
		
		if(cur->leftChild == NULL && cur->rightChild == NULL) {
			count++;
		}
		else {
			if(cur->leftChild != NULL)
				stack.push_back(cur->leftChild);
			if(cur->rightChild != NULL)
				stack.push_back(cur->rightChild);
		}	
	}
	
	return count;
}

bool Tree::Delete(DATA target) {
	vector<TNode*> stack;
	TNode * cur;
	
	stack.push_back(root); // this.root는 안되는거? 
	
	while( !stack.empty() ) {
		cur = stack.back();
		stack.pop_back();
		
		if(cur->leftChild->data == target) {
			cur->leftChild = NULL;
			return true;
		}
		else if(cur->rightChild->data == target) {
			cur->rightChild = NULL;
			return true;
		}
		else {
			if(cur->leftChild != NULL)
				stack.push_back(cur->leftChild);
			if(cur->rightChild != NULL)
				stack.push_back(cur->rightChild);
		}	
	}
	
	return false;
}
