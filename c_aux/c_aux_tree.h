#pragma once

#include "c_aux.h"

#include "c_aux_dlinked_list.h"

typedef struct TreeNode TreeNode;
struct TreeNode{
	TreeNode *  parent;
	DLinkedList children;
	POD data;
};



typedef struct Tree  Tree;
struct Tree{
	TreeNode root;
};

void tree_add_to_root(Tree *tp,POD data) {
	dlinked_list_push(&tp->root.children, data);
}

void tree_add_to_node(TreeNode *tp, POD data) {
	dlinked_list_push(&tp->children, data);
}

void tree_remove_all(TreeNode *tp) {


}
void tree_remove_all_POD(TreeNode *tp, POD p) {



}


void tree_bfs_visit(TreeNode* tp, void(*func)()) {



}
void tree_dfs_visit(TreeNode* tp, void(*func)()) {



}

TreeNode * tree_get_root(Tree *tp) {
	return &tp->root;

}
