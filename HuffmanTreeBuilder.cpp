#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

//Structure used to store the the table
struct HuffmanTable{
    char c;
    char code[32];
    char len;
}hostHuffmanTable[256];


int myIdx=0;
long totalFreq=0;

struct Node{
    char c;
    int freq;
    Node *left;
    Node *right;
    Node(): left(NULL),right(NULL),freq(0),c(NULL){};
};

const int MAX_SIZE =1024;
const int MAX_BITS = 4000;


//A structure that has the property of a String
struct myStringer{	
    char ch[MAX_SIZE];
	 long position;
	 long length;
};

//Used to store bits at decompression
struct decompresserBinary{
	char ch[MAX_BITS];
	long length;
};

class Compare{
   public: bool operator()(Node* node1,Node* node2){
        return node1->freq > node2->freq;
    }

};

priority_queue<Node*,vector<Node*>,Compare> myQueue;


void buildHuffmanTree(char* c,int* freq,int ssize){

    for(int i=0;i<ssize;i++)
    {
        Node *temporaryNode = new Node();
        temporaryNode->c=c[i];
        temporaryNode->freq = freq[i];
        myQueue.push(temporaryNode);
    }

    while(myQueue.size()>1)
    {
        Node *temporaryRightNode = myQueue.top();
        myQueue.pop();
        Node *temporaryLeftNode = myQueue.top();
        myQueue.pop();
        Node *newNode = new Node();
        newNode->freq = temporaryRightNode->freq + temporaryLeftNode->freq;
        newNode->left = temporaryLeftNode;
        newNode->right = temporaryRightNode;
        myQueue.push(newNode);

    }
}

void addToTable(int binaryCode[], int n,char x)
{
    int i;
    for (i = 0; i < n; ++i)
        {
            hostHuffmanTable[myIdx].code[i]=binaryCode[i];
        }
     hostHuffmanTable[myIdx].c=x;
     hostHuffmanTable[myIdx].len=i;
     
	myIdx++;
}

/*Check if a node is leaf*/
int isLeaf(struct Node* root)
{
    return !(root->left) && !(root->right) ;
}

/*Recursion function to walk the tree and store the found leafs in the table*/
void buildHuffmanTable(struct Node* root, int binaryCode[], int top)
{
    if (root->left)
    {
        binaryCode[top] = 0;
        buildHuffmanTable(root->left, binaryCode, top + 1);
    }

     if (root->right)
    {
        binaryCode[top] = 1;
        buildHuffmanTable(root->right, binaryCode, top + 1);
    }

    if (isLeaf(root))
    {
        printf("%c  ", root->c);
	    printf("%d\n", root->freq);
        addToTable(binaryCode, top,root->c);
		totalFreq+=root->freq;
    }
}

