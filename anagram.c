#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char table[256]; //入力した文字列を代入
char answer[256]; //答えを入力

char buffer[256];
char buffer2[256];
char buffer3[256];//search で使う


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

 
  while( fgets(buffer3, 256, fp) != NULL ){

    int i, j = 0, t = 0;

    memset(buffer,0,sizeof(buffer));

    int stl = strlen(buffer3)-1; // 一行の文字列の文字数を数える

    strcpy(buffer2, buffer3); // buffer2 にsortする前の文字列を保存する

    for(int k=0; k<= stl; k++){
      if(('A'<= buffer3[k]) && (buffer3[k] <= 'z')){
	buffer[t] = buffer3[k];
	t++;
      }
    }


    insertionsort(buffer, t); // buffer文字列のsort

    for(i=0; i<16; i++){

      if(buffer[j] == table[i]){
	j++;
      }

      if(j == t){
	break;
      }
    }

   

    if((j == t) && (n < t)){
      printf("answer input : %s",buffer2);

      //printf("j:%d, t:%d\n",j,t);
      strcpy(answer, buffer2);
      n = t;
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
