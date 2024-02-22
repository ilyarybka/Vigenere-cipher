#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print80lines(char* text)
{
  int len = strlen(text);
  //char let = 'A';
  for(int i = 0; i < len; i++)
  {
    if(i % 80 == 0)
    {
      printf("\n");
    }
    printf("%c",text[i]);
  }
  
}

void encryptAndPrint(char* key, char* text)
{
  //char* k = key;
  //char* p = text;
  char ct[513];

  for(int i = 0; i < 512; i++)
  {
    //ct[i] = ((key[i] + text[i]) -'a' % 26 + 'a');
    ct[i] = ((key[i] + text[i] - 'a' - 'a') % 26 + 'a');
    ct[i + 1] = '\0';
  }

  //printf("%lu", strlen(ct));
  printf("\n\n\nCiphertext:\n");
  for(int j = 0; j < 512; j++)
  {
    if(j % 80 == 0)
      printf("\n");
    printf("%c", ct[j]);
  }
}

int main(int argc, char** argv) {

  FILE* k;
  FILE* p;
  FILE* w;
  //w = fopen("text.txt", "w");
  k = fopen(argv[argc - 2], "r");
  p = fopen(argv[argc - 1], "r");
  char text[513];
  char key[513];

  if ( k == 0 || p == 0) 
  { 
      printf("Could not open one of the files or both of them.\n"); 
    fclose(k); 
    fclose(p);
    exit(1);
  } 
  else { 
      //printf( "File opened successfully\n" );
  }
  
  //int len_key = strlen(or_key);
  int check;
  int j = 0;
  char c[2000];
  char c1;

  //int x = fread(c, sizeof(char), sizeof(c) - 1, k);
  //c[x - 1]= '\0';
  
  int i = 0;
  while(fscanf(k, "%c", &c1) != EOF)
  {
    if(isalpha(c1) != 0)
    {
   //printf("%c", c1);
   //fprintf(w,"%c", c1);
    c[i] = tolower(c1);
    c[i+1] = '\0';
    i++;
    }
  }
  //printf("%lu", strlen(c));
  printf("\n\nVigenere Key:\n");
  print80lines(c);
  //printf("\n");
  
  int clen = strlen(c);
    for(int i = 0, j = 0; i < 512; i++, j++)
    {
      if(j == clen){
       j = 0;
        }
      key[i] = tolower(c[j]);
      key[i+1] = '\0';
    }

  //printf("%lu", strlen(key));
  //printf("The key:\n\n");
  
  //for(int i1 = 0; i1 < strlen(key); i1++)
    //printf("%c", key[i1]);
  //printf("\n\n");

  
  int i1 = 0;
  
  while(fscanf(p, "%c", &c1) != EOF)
  {
    if(isalpha(c1) != 0)
    {
      c[i1] = c1;
      c[i1 + 1] = '\0';
      i1++;
    }
  }
  clen = strlen(c);
  //printf("Total text:\n\n");
  //printf("%s\n\n", c);

  for(int i = 0, j = 0; i < 512; i++, j++)
  {
    text[i] = tolower(c[j]);
    text[i+1] = '\0';
  }
  int textlen = strlen(text);
  
  if((textlen) < 512)
  {
    //printf("%d\n", textlen);
    for(i = textlen; i < 512; i++)
    {
      text[i] = 'x';
      text[i+1] = '\0';
    }
  }
  printf("\n\n\nPlaintext:\n");
  
  print80lines(text);
  //printf("%s\n\n", text);
  //fgets(c, strlen(c)+1, k);
  //while(fgets(c, strlen(c)+1, k))
  //{
    //fgets(c, strlen(c)+ 1,k);
    //printf("%s", c);
  //}
  encryptAndPrint(key, text);
  printf("\n");

  //int len_text = strlen(or_text);
  
  
    //while(strlen(text) != 512)
    //{
      //text[j] = 'x';
       // j++;
    //}

  for(int i = 0; i < 512; i++)
  {
    //printf("%c", text[i]);
  }
  fclose(k);
  fclose(p);
  //fclose(w);
  return 0;
}
