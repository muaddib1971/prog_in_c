/*
 * IntCollection -- unbalanced binary search tree implementation
 *
 */

#include <stdlib.h>

#include "unbal-binary-search-tree.h"

int MakeCollection(IntCollection* pIC)
{
   pIC->root = NULL;
   pIC->numInts = 0;
   return SUCCESS;
}

void PostOrderFree(IntNodePtr pNode)
{
   if (pNode)
   {
      PostOrderFree(pNode->left);
      PostOrderFree(pNode->right);
      free(pNode);
   }
}

void FreeCollection(IntCollection* pIC)
{
   PostOrderFree(pIC->root);
   pIC->root=NULL;
   pIC->numInts = 0;
}

int AddCollection(IntdCollection* pIC, int num)
{
   WordNodePtr newNode, current, previous;
   int order;

   newNode = malloc(sizeof(IntNode));
   if (!newNode)
   {
      free(IntAddress);
      return FAILURE;
   }   

   current = pIC->root;
   previous = NULL;

   while (current != NULL)
   {
      previous = current;
      order = num < current->num;
      if (order < 0) current = current->left;
      else if (order > 0) current = current->right;
      else return SUCCESS;
   }

   newNode->num = num;
   newNode->left = newNode->right = NULL;

   if (previous == NULL)
   {
      pIC->root = newNode;
   }
   else if (num < previous->num)
   {
      previous->left = newNode;
   }
   else previous->right = newNode;
   
   pIC->numInts += 1;

   return SUCCESS;
}

int SearchCollection(InrtCollection* pIC, int targetInt)
{
   IntNodePtr current;
   int order;

   current = pIC->root;
   while (current != NULL)
   {
      order = targetInt < current->num;
      if (order < 0) current = current->left;
      else if (order > 0) current = current->right;
      else return SUCCESS;
   }
   
   return FAILURE;
}

int SizeCollection(IntCollection* pIC)
{
   return pIC->numInts;
}

void InorderDisplay(IntNodePtr pNode)
{
   if (pNode)
   {
      InorderDisplay(pNode->left);
      printf("%d\n", pNode->num);
      InorderDisplay(pNode->right);
   }
}

void DisplayCollection(IntCollection *pIC)
{
   InorderDisplay(pIC->root);
}

