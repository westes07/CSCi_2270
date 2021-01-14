#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

/* ------------------------------------------------------ */
MovieTree::MovieTree(){
	root = NULL;
}

void deleteListNode(LLMovieNode* head){
    if(head == NULL){
        return;
    }
    deleteListNode(head->next);
    delete head;
}

void deleteTreeNode(TreeNode* node){
	if(node == NULL){
		return;
	}
	deleteTreeNode(node->leftChild);
	deleteTreeNode(node->rightChild);
	deleteListNode(node->head);
	delete node;
}

MovieTree::~MovieTree(){
	deleteTreeNode(root);
}
/* ------------------------------------------------------ */

void _grader_inorderTraversal(TreeNode * root) {
		if (root == NULL) {
			return;
		}

		_grader_inorderTraversal(root->leftChild);
		cout << root->titleChar << " ";
		_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key){
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key){
    return searchCharHelper(root, key);
}

void showMovieList(LLMovieNode* movie){
	if (movie == NULL){
		return;
	}
	cout << " >> " << movie->title << " " << movie->rating << endl;
	showMovieList(movie->next);
}

void showCollectionHelper(TreeNode* node){
	if(node == NULL){
		return;
	}
	showCollectionHelper(node->leftChild);
	cout << "Movies starting with letter: " << node->titleChar << endl;
	showMovieList(node->head);
	showCollectionHelper(node->rightChild);
}

void MovieTree::showMovieCollection(){
	showCollectionHelper(root);
}

void MovieTree::insertMovie(int ranking, std::string title, int year, float rating){
	TreeNode* curr = root;
	while (curr != NULL){
		if (title[0] < curr->titleChar){
			if (curr->leftChild == NULL){
				break;
			}
			curr = curr->leftChild;
		}
		if (title[0] > curr->titleChar){
			if (curr->rightChild == NULL){
				break;
			}
			curr = curr->rightChild;
		}
		if (title[0] == curr->titleChar){
			break;
		}
		
	}


	
	LLMovieNode* newMovie = getLLMovieNode(ranking, title, year, rating);
	
	if (searchCharNode(title[0]) == NULL){
		TreeNode* newNode = new TreeNode;
		
		newNode->head = newMovie;
		newNode->titleChar = title[0];
		newNode->parent = curr;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
        
        if(root == NULL){
            root = newNode;
            return;
        }
        
		if (title[0] < curr->titleChar){
			curr->leftChild = newNode;
		} else if (title[0] > curr->titleChar) {
			curr->rightChild = newNode;
		}
	} else {
	    if(title < curr->head->title){
	        newMovie->next = curr->head;
	        curr->head = newMovie;
	        return;
	    }
		LLMovieNode* listNode = curr->head;
		if(listNode->next == NULL){
		    listNode->next=newMovie;
		    return;
		}
		while (listNode->next != NULL){
		    if (title > listNode->next->title){
				listNode = listNode->next;
			} else {
			    break;
			}
		}
		newMovie->next = listNode->next;
		listNode->next = newMovie;
	}
}


LLMovieNode* findMovieInList(LLMovieNode* movie, std::string title){
	LLMovieNode* curr = movie;
	while (curr != NULL){
		if (title == curr->title){
			break;
		}
		curr = curr->next;
	}
	return curr;
}

void MovieTree::removeMovieRecord(std::string title){
	TreeNode* treeNode = searchCharNode(title[0]);
	if (treeNode == NULL){
		cout << "Movie not found." << endl;
		return;
	}

	LLMovieNode* toDelete = findMovieInList(treeNode->head, title);
	if (toDelete == NULL){
		cout << "Movie not found." << endl;
		return;
	}

    if(toDelete == treeNode->head){
        treeNode->head = toDelete->next;
        delete toDelete;
    } else {
        LLMovieNode* curr = treeNode->head;
	    while (curr->next != NULL){
		    if (title == curr->next->title){
		    	break;
		    }
		    curr = curr->next;
	    }
    	curr->next = toDelete->next;
	    delete toDelete;
    }

	if (treeNode->head == NULL){
	    if(treeNode->leftChild == NULL && treeNode->rightChild == NULL && treeNode==root){
	        root = NULL;
	        delete treeNode;
	        return;
	    }else if(treeNode->leftChild == NULL && treeNode->rightChild == NULL){
	        if(treeNode->titleChar < treeNode->parent->titleChar){
				treeNode->parent->leftChild = NULL;
			} else if(treeNode->titleChar > treeNode->parent->titleChar){
				treeNode->parent->rightChild = NULL;
			}
			delete treeNode;
	        return;
	    }
	    
		TreeNode* node = treeNode->rightChild;
		if (node == NULL){
			node = treeNode->leftChild;
			while(node->rightChild != NULL){
			    node = node->rightChild;
			}
			if(node != treeNode->leftChild){
			    node->parent->rightChild = node->leftChild;
			    node->leftChild = treeNode->leftChild;
			}
			node->rightChild = treeNode->rightChild;
		} else {
			while (node->leftChild != NULL){
				node = node->leftChild;
			}
			
			node->leftChild = treeNode->leftChild;
			if (node != treeNode->rightChild){
				node->parent->leftChild = node->rightChild;
				node->rightChild = treeNode->rightChild;
			}
			node->leftChild = treeNode->leftChild;
		}
		if(node->leftChild != NULL){
			node->leftChild->parent = node;
		} 
		if (node->rightChild != NULL){
			node->rightChild->parent = node;
		}
		if(treeNode == root){
		    node->parent = NULL;
		    root = node;
		} else {
		    node->parent = treeNode->parent;
		    if (node->titleChar < treeNode->parent->titleChar){
			    treeNode->parent->leftChild = node;
		    } else if (node->titleChar > treeNode->parent->titleChar) {
			    treeNode->parent->rightChild = node;
		    }
		}
		
		delete treeNode;
	}
}

void MovieTree::leftRotation(TreeNode* curr){
	TreeNode* y = curr->rightChild;
	
	if (curr == root && curr->rightChild != NULL){
		curr->parent = y;
		y->parent = NULL;
		curr->rightChild = y->leftChild;
		y->leftChild = curr;
		root = y;
		return;
	}else if (curr->rightChild != NULL){
		y->parent = curr->parent;
		curr->parent = y;
		curr->rightChild = y->leftChild;
		y->leftChild = curr;
		if (y->titleChar < y->parent->titleChar){
			y->parent->leftChild = y;
		} else if (y->titleChar > y->parent->titleChar){
			y->parent->rightChild = y;
		}
		
	}
}