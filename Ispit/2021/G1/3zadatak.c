//
// Created by Milos on 1/23/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXN 100
typedef struct person{
    char name[MAXN];
    char diet[MAXN];
    int kgLost;

}Person;



typedef struct node{
    Person person;
    struct Node *left;
    struct Node *right;
}Node;

Node *makeNode(char *name, char *diet, int kgLost){
    Node *node = malloc(sizeof(Node));
    strcpy(node->person.name, name);
    strcpy(node->person.diet, diet);
    node->person.kgLost = kgLost;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int insertNodeBST(Node **root, char *name, char *diet, int kgLost){
    Node *newNode = makeNode(name,diet,kgLost);
    if(newNode == NULL){
        return  1;
    }
    if(*root == NULL){
        *root = newNode;
        return 0;
    }
    Node *tmp = *root;
    while(1){
        if(strcmp(tmp->person.diet,diet) > 0){
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
    if(strcmp(tmp->person.diet,diet) > 0){
        tmp->left = newNode;
    } else{
        tmp->right = newNode;
    }

    return 0;
}

void printNodesInorderBST(Node *root){
    if(root == NULL){
        return;
    }
    printNodesInorderBST(root->left);
    printf("%s %s %d\n", root->person.name,root->person.diet,root->person.kgLost);
    printNodesInorderBST(root->right);

}
void mostEfficientDiet(Node *root,double *max,int *sumKG,int *numDiet,char *maxName,char *name){
    if(root == NULL)
        return;
    mostEfficientDiet(root->left,max,sumKG,numDiet,maxName,name);
    if(max == -1){
        max = 0;
        strcpy(name,root->person.diet);
    }
    if(strcmp(name,root->person.diet) != 0){
        double efficient = 1.0*(*sumKG)/(*numDiet);
        if(efficient > *max){
            *max = efficient;
            strcpy(maxName,name);
        }
        *sumKG = root->person.kgLost;
        *numDiet = 1;
        strcpy(name,root->person.diet);
    }else{
        *sumKG += root->person.kgLost;
        *numDiet +=1;
    }
    mostEfficientDiet(root->right,max,sumKG,numDiet,maxName,name);
}
void findNodesInorderBST(Node *root, char *str){
    if(root == NULL){
        return;
    }
    findNodesInorderBST(root->left,str);
//    if(strstr(root->person.name,str) != NULL){
//        printf("%s %s %d\n", root->person.name,root->person.diet,root->person.kgLost);
//    }


    findNodesInorderBST(root->right,str);
    int tmp = 0;
    for(int i  = 0; i < strlen(str); i++){
        for(int j = 0; j < strlen(root->person.name); j++){
            char x = root->person.name[j];
            if(str[i] == x || str[i] == x - 32 || str[i] == x + 32){
                tmp++;
                break;
            }
        }
    }
    if(tmp == strlen(str)){
        printf("%s %s %d\n", root->person.name,root->person.diet,root->person.kgLost);
    }

}

void deleteTree(Node **root){
    if(*root == NULL)
        return;
    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

int main(){
    Node *root = NULL;

    int komanda;

    while(1){
        printf("Dobrodosli na meni\n");
        printf("1 komanda: Ucitavanje dijeta iz fajl (Obavezno iskoristiti kao prvu komandu!!!)\n");
        printf("2 komanda: Ispis svih osoba sa dijetama i njihovim izgubljenim kilogramima\n");
        printf("3 komanda: Ispisati najefikasniju dijetu\n");
        printf("4 komanda: Pretrazivanje dijeta po imenima osoba\n");
        printf("5 komanda: Izlazak iz programa i brisanje stabla\n");
        printf("Bilo koja druga komanda se nece uvaziti\n");
        scanf("%d",&komanda);
        if(komanda == 1){
            if(root != NULL){
                printf("Ucitali ste vec dijete\n");
                continue;
            }
            FILE *file = fopen("C:\\Users\\Milos\\Desktop\\Milos\\UUP\\Ispit\\2021\\G1\\UUP-21-22-JAN-G1-Z3 fajl.txt","r");
            if(file == NULL){
                printf("1\n");
                return  1;
            }
            char name[MAXN], diet[MAXN];
            int kgLost;

            while(fscanf(file,"%[^,],%[^,],%d\n",name,diet,&kgLost) == 3){
                if(insertNodeBST(&root,name,diet,kgLost) == 1){
                    printf("1\n");
                    return 1;
                }
            }
        }else if(komanda == 2){
            if(root == NULL) {
                printf("Niste ucitali stablo\n");
                continue;
            }
            printNodesInorderBST(root);
        }else if(komanda == 3){
            if(root == NULL) {
                printf("Niste ucitali stablo\n");
                continue;
            }
            char maxName[MAXN], nameC[MAXN];
            strcpy(maxName,"");
            strcpy(nameC,"");
            double max = -1;
            int sumKG = 0;
            int numDiet = 0;
            double efficient = 0;
            mostEfficientDiet(root,&max,&sumKG,&numDiet,maxName,nameC);
            efficient = 1.0*sumKG/numDiet;
            if(efficient > max){
                max = efficient;
                strcpy(maxName,nameC);
            }
            printf("%s %.2lf\n", maxName,max);
        }else if(komanda == 4){
            if(root == NULL) {
                printf("Niste ucitali stablo\n");
                continue;
            }
            char findStr[MAXN];
            scanf("%s",findStr);
            findNodesInorderBST(root,findStr);
        }else if(komanda == 5){
            if(root == NULL) {
                printf("Niste ucitali stablo\n");
                continue;
            }
            deleteTree(&root);
            break;
        }else{
            continue;
        }
    }
    //1

    //2

    //3

    //4

    //5

    return 0;
}
