#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstdio>
#include <fstream>

using namespace std;

string table;
string answer;

fstream ifs;


void search(){

  std::cout << "search start" << endl;

  int stl, n=0;
  
  string str, str2;

  while(ifs.good()){

    int i,j=0;
    getline(ifs, str);

    stl = str.length();

    str2 = str;

    transform(str.begin(), str.end(), str.begin(), ::tolower); //全部　小文字に

    sort(str.begin(), str.end()); //abc順に

    for(i=0; i<16; i++){
      if(str[j] == table[i]){
	j++;
      }
    }

    if((j==stl) && (n < stl)){
      //cout << str2 << endl;
       answer = str2;
       n = stl;
    }
    
  }

}

int main(){

  ifs.open("/usr/share/dict/words",ios::in);
  if(ifs.fail()){
    std::cerr << "失敗" << std::endl;
    return -1;
  }

  std::cout << "Pleas input 16 words!" << endl;
  
  cin >> table;

  transform(table.begin(), table.end(), table.begin(), ::tolower);

  sort(table.begin(), table.end());

  search();
  
  std::cout << "answer is :" << answer << std::endl;
  
  ifs.close();
   
  
  return 0;
}
