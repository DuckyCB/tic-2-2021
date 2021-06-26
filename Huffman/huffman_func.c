#include <stdio.h>
#include <huffman_func.h>
#include <huffman.h>


/**
 * @brief 
 * 
 * @param capacity 
 * @return Heap* 
 */
Heap *new_empty_treenode_heap(int capacity) {

	Heap* new_heap = malloc_or_exit(sizeof(Heap) * MAXSYMBOL);
	new_heap->capacity = capacity;
	new_heap->used = 0;
	Symcode* array = malloc_or_exit(sizeof(Symcode) * MAXSYMBOL);
	new_heap->nodearray = array;

	return new_heap;

}

/**
 * @brief Returns if the node is a leaf.
 * 
 * @param tn Treenode
 * @return int 0/1
 */
int is_leaf(Treenode *tn) {
	return !(tn->children[0]) && !(tn->children[1]);
}


/**
 * @brief Compares heap strctures *p y *q by minimum according to freq
 * 
 * @param p Treenode
 * @param q Treenode
 * @return int p < q
 */
int treenode_min_compare(const void *p, const void *q) {
	const Treenode *node_p = p, *node_q = q; // No se por que se hace esto
	return node_p->code->count < node_q->code->count;
}


/**
 * @brief Takes the last node from a heap
 * 
 * @param H Heap to take a node from
 * @return Treenode* Last node
 */
Treenode *pop_heap(Heap *H) {

}

/**
 * @brief Adds a node to the heap
 * 
 * @param H Heap to add the node
 * @param tn Treenode to add
 */
void push_heap(Heap *H, Treenode *tn) {

	if (H->capacity > H->used) {
		++H->capacity;
		int i = H->capacity - 1;

		while (i && tn->code->count < H->nodearray[(i - 1) / 2]->code->count) {

			H->nodearray[i] = H->nodearray[(i - 1) / 2];
			i = (i - 1) / 2;
		}

		H->nodearray[i] = tn;
	} else {
		printf("Error: Heap is full");
	}
}

/**
 * @brief 
 * 
 * @param sn 
 * @param fp_comprfile 
 * @return size_t 
 */
size_t fwrite_bitcode(Symcode *sn, FILE *fp_comprfile) {

}

/**
 * @brief 
 * 
 * @param tn 
 * @param fp_comprfile 
 * @return size_t 
 */
size_t frite_symcodes(Treenode *tn, FILE *fp_comprfile) {

}

/**
 * @brief 
 * 
 * @param tn 
 * @param mask 
 * @param masklen 
 */
void generate_bitcodes(Treenode *tn, unsigned long int mask, unsigned int masklen) {

}

/**
 * @brief Creates new symcode.
 * 
 * @param symb Simbol (Character)
 * @param count Frequency of the symbol
 * @param mask Maximun size of the mask
 * @param masklen 
 * @return Symcode* new created symcode
 */
Symcode *new_symcode(unsigned int symb, unsigned int count, unsigned int mask,
							unsigned int masklen) {
	Symcode* new_symcode = malloc_or_exit(sizeof(Symcode));
	new_symcode->symbol = symb;
	new_symcode->count = count;
	new_symcode->mask = mask;
	new_symcode->masklen = masklen;
	return new_symcode;
}

/**
 * @brief Creates new Treenode with NULL childrens.
 * 
 * @param sn Symcode
 * @return Treenode* new created treenode
 */
Treenode *new_treenode(Symcode *sn) {
	Treenode* new_node = malloc_or_exit(sizeof(Treenode));
	new_node->code = sn;
	new_node->children[0] = new_node->children[1] = NULL;
	return new_node;
}


/**
 * @brief ?????????
 * 
 * @param root 
 * @param symbol 
 * @param count 
 * @param mask 
 * @param masklen 
 * @return Treenode* 
 */
Treenode *insert_symcode(Treenode *root, unsigned int symbol, unsigned int count,
								unsigned int mask, unsigned int masklen) {
	// Ni idea de que deberia hacer esto
	Symcode* symcode = new_symcode(symbol, count, mask, masklen);
	Treenode* treenode = new_treenode(symcode);
	return treenode;
}

/**
 * @brief Creates a Huffman tree from a heap?
 * 
 * @param H Heap with characters
 * @return Treenode* 
 */
Treenode *build_huffman_tree(Heap *H) {

}