#include <queue>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
struct Nod{
    char c;
    int freq;
    Nod *left;
    Nod *right;
    Nod(): left(NULL),right(NULL),freq(0),c(NULL){};
};

class Compare{
   public: bool operator()(Nod* nod1,Nod* nod2){
        return nod1->freq > nod2->freq;
    }

};

struct myStrs{
	char *ch;
	 long position;
	 long length;
	 myStrs(): ch(NULL),position(0),length(0){};
};

struct HuffmanTable{
    char c;
    char code[30];
    char len;
}huffmanTable[256];

int myIndx=0;

priority_queue<Nod*,vector<Nod*>,Compare> myPQueue;

void buildTable(char* c,int* freq,int ssize){
    for(int i=0;i<ssize;i++)
    {
        Nod *temp = new Nod();
        temp->c=c[i];
        temp->freq = freq[i];
        myPQueue.push(temp);
    }

    while(myPQueue.size()>1)
    {
        Nod *temp1 = myPQueue.top();
        myPQueue.pop();
        Nod *temp2 = myPQueue.top();
        myPQueue.pop();
        Nod *newNod = new Nod();
        newNod->freq = temp1->freq + temp2->freq;
        newNod->left = temp2;
        newNod->right = temp1;
        myPQueue.push(newNod);

    }
}


void printArray(int arr[], int n,char x)
{
    int i;
    for (i = 0; i < n; ++i)
        {
            printf("%d", arr[i]);
            huffmanTable[myIndx].code[i]=arr[i];
        }
     huffmanTable[myIndx].c=x;
      huffmanTable[myIndx].len=i;
     myIndx++;
    printf("\n");
}
long tFreq=0;
int itIsLeaf(struct Nod* nod)
{
    return !(nod->left) && !(nod->right) ;
}

void Codes(struct Nod* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        Codes(root->left, arr, top + 1);
    }

      if (root->right)
    {
        arr[top] = 1;
        Codes(root->right, arr, top + 1);
    }

    if (itIsLeaf(root))
    {
        printf("%c  ", root->c);
		printf("%d: ", root->freq);
        printArray(arr, top,root->c);
		tFreq +=root->freq;
    }
}

