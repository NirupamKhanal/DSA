/* Trie/Prefix Tree/Digital Tree */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define num_chars 256

typedef struct trieNode {
    struct trieNode *children[num_chars]; 
    bool terminal; 
} trieNode; 

trieNode *createNode() {
    trieNode *newNode = malloc(sizeof *newNode); 

    for (int i = 0; i < num_chars; i++) {
        newNode -> children[i] = NULL; 
    }
    newNode -> terminal = false; 
    return newNode;
}

bool trieInsert(trieNode **root, char *signedText) {
    if (*root == NULL) {
        *root = createNode(); 
    }

    unsigned char *text = (unsigned char *)signedText; 
    trieNode *temp = *root; 
    int length = strlen(signedText);

    for (int i = 0; i < length; i++) {
        if (temp -> children[text[i]] == NULL) {
            temp -> children[text[i]] = createNode();
        }
        temp = temp -> children[text[i]]; 
    }
    
    if (temp -> terminal) {
        return false; 
    } 
    else {
        temp -> terminal = true; 
        return true;
    }
}

void printTrie_rec(trieNode *node, unsigned char *prefix, int length) {
    unsigned char newPrefix[length+2]; 
    memcpy(newPrefix, prefix, length); 
    newPrefix[length+1] = 0; 

    if (node -> terminal) {
        printf("Word: %s\n", prefix); 
    }

    for (int i = 0; i < num_chars; i++) {
        if (node -> children[i] != NULL) {
            newPrefix[length] = i; 
            printTrie_rec(node -> children[i], newPrefix, length+1);
        }
    }
}

void printTrie(trieNode * root) {
    if (root == NULL) {
        printf("Trie is empty!\n"); 
        return; 
    }
    printTrie_rec(root, NULL, 0); 
}

bool searchTrie(trieNode *root, char *signedText) {
    unsigned char *text = (unsigned char *) signedText; 
    int length = strlen(signedText); 
    trieNode * temp = root; 

    for (int i = 0; i < length; i++) {
        if (temp -> children[text[i]] == NULL) {
            return false; 
        }
        temp = temp -> children[text[i]]; 
    }
    return temp -> terminal; 
}

bool node_has_children(trieNode *node) {
    if (node == NULL) return false; 

    for (int i = 0; i < num_chars; i++) {
        if (node -> children[i] != NULL) {
            return true; 
        }
    }
    return false; 
}

trieNode* deleteStr_rec(trieNode *node, char *text, bool *deleted) {
    if (node == NULL) return node; 

    if (*text == '\0') {
        if (node -> terminal) {
            node -> terminal = false; 
            *deleted = true; 

            if (node_has_children(node) == false) {
                free(node); 
                node = NULL;
            }
        }
        return node; 
    }

    node -> children[text[0]] = deleteStr_rec(node -> children[text[0]], text+1, deleted); 
    if (*deleted && node_has_children(node) == false && node -> terminal == false) {
        free(node); 
        node = NULL; 
    }
    return node; 
}

bool deleteStr(trieNode** root, char *signedText) {
    unsigned char *text = (unsigned char *) signedText; 
    bool result = false; 

    if (*root == NULL) return false; 

    *root = deleteStr_rec(*root, text, &result); 
    return result; 
}

int main() {
    trieNode * root = NULL; 

    trieInsert(&root, "KIT"); 
    trieInsert(&root, "CATTLE"); 
    trieInsert(&root, "KIN"); 
    trieInsert(&root, "CAT"); 
    trieInsert(&root, "HAPPY"); 
    printTrie(root); 

    printf("Search for CATTLE: %d\n", searchTrie(root, "CATTLE")); 
    printf("Search for DOG: %d\n", searchTrie(root, "DOG")); 
    deleteStr(&root, "KIN"); 
    deleteStr(&root, "HAPPY"); 
    deleteStr(&root, "DOG"); 
    printTrie(root); 
}
