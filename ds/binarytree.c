#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define MIN 3

struct BTree
 {
  int value[MAX + 1], count;
  struct BTree *link[MAX + 1];
};

struct BTree *root;

struct BTree *createNode(int value, struct BTree *child)
{
  struct BTree *newNode;
  newNode = (struct BTree *)malloc(sizeof(struct BTree));
  newNode->value[1] = value;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}

void insertNode(int value, int pos, struct BTree *node,struct BTree *child)
 {
  int j = node->count;
  while (j > pos) {
    node->value[j + 1] = node->value[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->value[j + 1] = value;
  node->link[j + 1] = child;
  node->count++;
}

void splitNode(int value, int *pvalue, int pos, struct BTree *node,struct BTree *child, struct BTree **newNode)
 {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (struct BTree *)malloc(sizeof(struct BTree));
  j = median + 1;
  while (j <= MAX)
 {
    (*newNode)->value[j - median] = node->value[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) {
    insertNode(value, pos, node, child);
  } else
  {
    insertNode(value, pos - median, *newNode, child);
  }
  *pvalue = node->value[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}


int setValue(int value, int *pvalue,
           struct BTree *node, struct BTree **child) 
{
  int pos;
  if (!node)
 {
    *pvalue = value;
    *child = NULL;
    return 1;
  }

  if (value < node->value[1]) 
{
    pos = 0;
  } else {
    for (pos = node->count;
       (value < node->value[pos] && pos > 1); pos--)
      ;
    if (value == node->value[pos])
 {
      printf("The duplicates are not allowed\n");
      return 0;
    }
  }
  if (setValue(value, pvalue, node->link[pos], child)) 
{
    if (node->count < MAX) {
      insertNode(*pvalue, pos, node, *child);
    } else {
      splitNode(*pvalue, pvalue, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

void insert(int value) 
{
  int flag, i;
  struct BTree *child;

  flag = setValue(value, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}

void search(int value, int *pos, struct BTree *myNode)
 {
  if (!myNode)
 {
    return;
  }

  if (value < myNode->value[1])
 {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (value < myNode->value[*pos] && *pos > 1); (*pos)--)
      ;
    if (value == myNode->value[*pos]) 
{
      printf("%d is found", value);
      return;
    }
  }
  search(value, pos, myNode->link[*pos]);

  return;
}

void traversal(struct BTree *myNode)
 {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++)
 {
      traversal(myNode->link[i]);
      printf("%d ", myNode->value[i + 1]);
    }
    traversal(myNode->link[i]);
  }
}

int main() 
{
  int value, ch;

  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);
  insert(60);
  insert(70);
  insert(80);
  insert(90);
  insert(100);

  traversal(root);

  printf("\n");
  search(99, &ch, root);
}

