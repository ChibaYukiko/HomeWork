#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char table[16]; // table[0]は番兵として使う


void insertionsort (){ //配列を挿入法で整列する

  int i,j;
  char key;


  for(i = 1; i < 16; i++){

    key = table[i];

    //table[0] = key; 番兵
    
    j = i - 1;
    
    while(j>=0 && key < table[j]){
      table[j+1] = table[j];
      j--;
    }
    table[j+1] = key;
  }
  
}

int main(){

  printf(" 16words 入力してください: ");

  scanf("%s", table);

  insertionsort();

  printf("\n 辞書順に文字を並べました : %s \n", table);

}
