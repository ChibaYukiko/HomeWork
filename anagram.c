#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char table[256]; //入力した文字列を代入
char answer[256]; //答えを入力

char buffer[256];
char buffer2[256];//search で使う


FILE *fp;


void insertionsort (char *s, int last){ //配列を挿入法で整列する

  int i,j;
  char key;

  for( i=0; i<last; i++ ){
    s[i] = tolower( s[i] );
  }

  for(i = 0; i < last; i++){

    key = s[i];

    j = i - 1;
    
    while(j>=0 && key<s[j]){ //key<table[j]
      s[j+1] = s[j];
      j--;
    }
    s[j+1] = key;
  }

  
}

void search(){

  int n = 0;
 
  while( fgets(buffer, 256, fp) != NULL ){

    int i, j = 0;

    int stl = strlen(buffer)-1; // 一行の文字列の文字数を数える

    strcpy(buffer2, buffer); // buffer2 にsortする前の文字列を保存する

    insertionsort(buffer, stl); // buffer文字列のsort

    
    for(i=0; i<16; i++){

      if(buffer[j] == table[i]){
	j++;
      }
      
    }
    
    if((j == stl) && (n < stl)){
      printf("%s",buffer2);
      strcpy(answer, buffer2);
      n = stl;
    }
  
  }
  
}

  

int main(){

  if ((fp = fopen("/usr/share/dict/words", "r")) == NULL) { // /usr/share/dict/words
    printf("file open error!!\n");
    exit(EXIT_FAILURE);	/* エラーの場合は通常、異常終了する */
  }

  printf(" 16words 入力してください: ");

  scanf("%s", table);

  int q = strlen(table);

  insertionsort(table, q);

  search();
  
  printf("\n answer is : %s \n", answer);

  fclose(fp);

  return 0;

}
