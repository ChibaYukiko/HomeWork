#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char input[256]; //入力した文字列を代入
char answer[256]; //答えを入力

char buffer[256];
char buffer2[256]; //search で使う


FILE *fp;


void insertionsort (char *s, int last){ //配列を挿入法で整列する

  int i,j;
  char key;

  for( i=0; i<last; i++ ){
    s[i] = tolower( s[i] );
  }

  for(i = 0; i < last; i++){

    key = s[i];

    //table[0] = key; 番兵
    
    j = i - 1;
    
    while(j>=0 && key<s[j]){ //key<table[j]
      s[j+1] = s[j];
      j--;
    }
    s[j+1] = key;
  }

  
}

void search(char *table, int m){

  int n = 0;

  
  while( fgets(buffer, 256, fp) != NULL ){

    int stl = strlen(buffer)-1; // 一行の文字列の文字数を数える

    strcpy(buffer2, buffer); // buffer2 にsortする前の文字列を保存する

    insertionsort(buffer, stl); // 文字列のsort

    int ret = strncmp(buffer, table, stl); 
   
    if( ret == 0 ){ //文字列が一致した時

      if(stl == m){ //16文字一致したものを見つけたら
	strcpy(answer, buffer2);
	break;
      }else if (n < stl){ //前に見つけたものよりも、文字列が長かったら
	strcpy(answer, buffer2);
	n = stl;
	printf("%d 文字一致！\n", stl);
      }else{
	//どうしよう
      }
    }else{
      /*printf("一致しません\n");*/
    }
  }

  
}

  

int main(){

  if ((fp = fopen("/usr/share/dict/words", "r")) == NULL) {
    printf("file open error!!\n");
    exit(EXIT_FAILURE);	/* エラーの場合は通常、異常終了する */
  }

  printf(" 16words 入力してください: ");

  scanf("%s", input);

  int q = strlen(input);

  insertionsort(input, q);

  printf("\n 辞書順に文字を並べました : %s \n", table);

  for(q; q>0 ; q--){
    
    search(input,q);

  }
  
  printf("\n answer is : %s \n", answer);

  fclose(fp);

  return 0;

}
