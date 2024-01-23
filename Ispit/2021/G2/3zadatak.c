#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
typedef struct person{
    char name[MAXN];
    int height;
    int weight;
}Person;

typedef struct node{
    Person client;
    struct Cvor * left, *right;

}Node;

Node* makeNode(char *name, int height, int weight){
    Node *node = malloc(sizeof (Node));
    strcpy(node->client.name,name);
    node->client.height = height;
    node->client.weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insertNode(Node **root, char *name, int height, int weight){
    Node *newNode = makeNode(name,height,weight);
    if(newNode == NULL)
        return 1;
    if(*root == NULL){
        *root = newNode;
        return 0;
    }
    Node *tmp = *root;
    while(1){
        if(strcmp(tmp->client.name,name) > 0){
                if(tmp->left){
                    tmp = tmp->left;
                }else{
                    break;
                }
        }else{
            if(tmp->right){
                tmp = tmp->right;
            }else{
                break;
            }
        }
    }
    if(strcmp(tmp->client.name,name) > 0){
        tmp->left = newNode;
    }else{
        tmp->right = newNode;
    }

    return 0;
}

void inorderBST(Node *node){
    if(node == NULL)
        return;
    inorderBST(node->left);
    printf("%s %d %d\n", node->client.name, node->client.height, node->client.weight);
    inorderBST(node->right);
}

int maxHeight(Node *node){
    if(node == NULL)
        return -1;
    int maxL = maxHeight(node->left);
    int maxD = maxHeight(node->right);
    int tmp = (maxD > maxL) ? maxD : maxL;
    int maxK = tmp > node->client.height ? tmp : node->client.height;
    return maxK;
}
int minHeight(Node *node){
    if(node == NULL)
        return 300;
    int minL = minHeight(node->left);
    int minD = minHeight(node->right);
    int tmp = (minD > minL) ? minL : minD;
    int minK = tmp > node->client.height ? node->client.height : tmp;
    return minK;
}
int insertWeightNode(Node **root, char *name, int height, int weight){
    Node *newNode = makeNode(name,height,weight);
    if(newNode == NULL)
        return 1;
    if(*root == NULL){
        *root = newNode;
        return 0;
    }
    Node *tmp = *root;
    while(1){
        if(tmp->client.weight < weight){
            if(tmp->left){
                tmp = tmp->left;
            }else{
                break;
            }
        }else{
            if(tmp->right){
                tmp = tmp->right;
            }else{
                break;
            }
        }
    }
    if(tmp->client.weight < weight){
        tmp->left = newNode;
    }else{
        tmp->right = newNode;
    }

    return 0;
}

void lessThen(Node *root, Node **newTrees, int weight){
    if(root == NULL){
        return;
    }

    lessThen(root->left,newTrees,weight);
    lessThen(root->right,newTrees,weight);
    if(root->client.weight < weight){
        insertWeightNode(newTrees,root->client.name, root->client.height, root->client.weight);
    }

}
void freeBST(Node **root){
    if(*root == NULL)
        return;

    freeBST(&(*root)->left);
    freeBST(&(*root)->right);
    free(*root);
    *root = NULL;
}

int main() {
    Node *root = NULL;
    FILE *f = fopen("C:\\Users\\Milos\\Desktop\\Milos\\UUP\\Ispit\\2021\\G2\\UUP-21-22-JAN-G2-Z3_fajl.txt","r");
    if(f == NULL){
        printf("1");
        return 1;
    }

    char name[MAXN];
    int height, weight;
    int n = 0;
    // Assuming the file has lines in the format "name,height,weight"
    while (fscanf(f, "%[^,],%d,%d\n", name, &height, &weight) == 3){
        //printf("%d\n",n++);

        if(insertNode(&root,name,height,weight) == 1){
            free(root);
            return 1;
        }/*
        if(insertWeightNode(&root,name,height,weight) == 1){
            free(root);
            return 1;
        }*/
    }
   // printf("proso");

    inorderBST(root);

    int max = maxHeight(root);
    printf("%d\n", max);
    int min = minHeight(root);
    printf("%d\n", min);
    Node *newTree = NULL;
    int targetWeight;
    scanf("%d", &targetWeight);
    lessThen(root,&newTree, targetWeight);
    inorderBST(newTree);
    freeBST(&root);
    freeBST(&newTree);
    fclose(f);
    return 0;
}
















