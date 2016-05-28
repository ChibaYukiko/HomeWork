#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char table[16]; // table[0]は番兵として使いたかった

char answer[16]; //答えを入力

char buffer[256];
char buffer2[256];


FILE *fp;


void insertionsort (char *s){ //配列を挿入法で整列する

  int i,j;
  char key;

  
  int last = strlen(s);

  for( i=0; i<last; i++ ){
    s[i] = tolower( s[i] );
  }

  for(i = 1; i < last; i++){

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

void search(){

  
  while( fgets(buffer, 256, fp) != NULL ){

    int stl = strlen(buffer);

    strcpy(buffer2, buffer);

    insertionsort(buffer);

    printf("%s",buffer);

    int ret = strncmp(buffer, table, stl);

    /*printf("%d\n",ret);*/
    
    if( ret == 0 ){

      strcpy(answer, buffer2);
      if(stl == 16){
	printf("16文字一致！");
	break;
      }else{
	printf("%d 文字一致！", stl);
      }
    }else{
      /*printf("一致しません\n");*/
    }
  }

  
}

  

int main(){

  if ((fp = fopen("/usr/share/dict/words", "r")) == NULL) { //まだファイル指定してないよ
    printf("file open error!!\n");
    exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
  }

  printf(" 16words 入力してください: ");

  scanf("%s", table);

  insertionsort(table);

  printf("\n 辞書順に文字を並べました : %s \n", table);

  //  search();

  // printf("\n answer is : %s \n", answer);

  fclose(fp);

  return 0;

}
