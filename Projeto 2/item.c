#include <stdlib.h>
#include <stdio.h>
#include "item.h"


struct item_
{ 
   int chave;
};

ITEM *item_criar (int chave){
   ITEM *item;
   
   item = (ITEM *) malloc(sizeof(ITEM));
   
   if (item != NULL){
      item->chave = chave;
      return(item);
   }
   return(NULL);
}

bool item_apagar(ITEM **item){
   if (*item != NULL){
      free (*item);
      *item = NULL; /*Boa pratica!*/
      return(true);
   }
   return(false);
}

int item_get_chave(ITEM *item){
    if (item != NULL)
      return(item->chave);
    exit(1);
}

bool item_set_chave(ITEM *item, int chave){
  if (item != NULL){
    item->chave = chave;
    return (true);
  }
  return (false);
}

void item_imprimir(ITEM *item){
     if (item != NULL)
        printf("[%d] ", item->chave);
}

int item_comparar(ITEM *item1, ITEM *item2){
   if(item1->chave == item2->chave) return 0;
   else if(item1->chave > item2->chave) return 1;
   else return -1;
}
