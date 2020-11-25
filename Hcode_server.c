#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <windows.h>
#define clear "cls"
#define getcwd _getcwd
char cwd[256];

void getcurrentcwd(){
getcwd(cwd,256);
}
void setcolor(int ForgC){
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
void print_logo(){
  char string_from_file[256];
  FILE *freads = fopen("files\\biologo.txt","r");
  if(freads==NULL){
    printf("error 404\n");
  }
  else{
    while(fgets(string_from_file,256,freads)!=NULL){
      printf("%s",string_from_file);
    }
  }
  printf("\n");
  fclose(freads);
}
void read_file(long long int a){
  char h_code[1000];
  char string_from_file[256];
  sprintf(h_code,"files\\%lld.txt",a);
  FILE *fread = fopen(h_code,"r");
  if(fread==NULL){
    printf("\n\n\nerror 404\n");
  }
  else{
    while(fgets(string_from_file,256,fread)!=NULL){
//stand
      printf("%s",string_from_file);
    }
  }
  printf("\n");
  fclose(fread);
}
void write_file(long long int b){
  char h_code[1000];
  char string_from_file[256];
  sprintf(h_code,"files\\%lld.txt",b);
  FILE *fwrite = fopen(h_code,"a+");
  if(fread==NULL){
    printf("error 404\n");
  }
  else{
    char name[50];
    char surname[50];
    char bloodpre[50];
    int length;
    int weight;
    char heat[50];
    char covid[50];
    char position[50];
    char responsible[50];
    char date[50];
    char loc[50];

    setcolor(10);
    printf("\nDATE [dd.mm.yy] : ");
    setcolor(4);
    scanf("%s",&date);
    setcolor(10);
    setcolor(10);
    printf("\nLOCATION [COUNTRY] : ");
    setcolor(4);
    scanf("%s",&loc);
    setcolor(10);
    printf("\nNAME : ");
    setcolor(4);
    scanf("%s",&name);
    setcolor(10);
    printf("\nSURNAME : ");
    setcolor(4);
    scanf("%s",&surname);
    setcolor(10);
    printf("\nBLOOD PRESSURE : ");
    setcolor(4);
    scanf("%s",&bloodpre);
    setcolor(10);
    printf("\nLENGTH [CM] : ");
    setcolor(4);
    scanf("%d",&length);
    setcolor(10);
    printf("\nWEIGHT [KG] : ");
    setcolor(4);
    scanf("%d",&weight);
    setcolor(10);
    printf("\nHEAT [DEGREE CELSIUS] : ");
    setcolor(4);
    scanf("%s",&heat);
    setcolor(10);
    printf("\nCOVID TEST [NEGATIVE / POSITIVE] : ");
    setcolor(4);
    scanf("%s",&covid);
    setcolor(10);
    printf("\nRESPONSIBLE POSITION [DOC ETC.] : ");
    setcolor(4);
    scanf("%s",&position);
    setcolor(10);
    printf("\nRESPONSIBLE NAME : ");
    setcolor(4);
    scanf(" %[^\t\n]s",&responsible);
    //fgets(responsible,50, stdin);
    //scanf("%[^\n]",&responsible);

    fprintf(fwrite, "--------------------------------------------------------------------------\n");
    fprintf(fwrite, "DATE : %s\n",date);
    fprintf(fwrite, "LOCATION : %s\n",loc);
    fprintf(fwrite, "LOG : \n|\n");
    fprintf(fwrite, "|--->NAME : %s\n",name);
    fprintf(fwrite, "|--->SURNAME : %s\n",surname);
    fprintf(fwrite, "|--->BLOOD PRESSURE : %s mm Hg\n",bloodpre);
    fprintf(fwrite, "|--->LENGTH : %d cm\n",length);
    fprintf(fwrite, "|--->WEIGHT : %d kg\n",weight);
    fprintf(fwrite, "|--->HEAT : %s [degree celsius]\n",heat);
    fprintf(fwrite, "|--->COVID TEST : %s\n",covid);
    fprintf(fwrite, "|--->RESPONSIBLE : [%s] %s\n",position,responsible);
    fprintf(fwrite, "--------------------------------------------------------------------------\n");
    fclose(fwrite);
  }
  printf("\n");
}
int check_id(long long int c){
  char h_code[1000];
  char string_from_file[256];
  sprintf(h_code,"files\\%lld.txt",c);
  FILE *fread = fopen(h_code,"r");
  if(fread==NULL){
    return 0;
    //printf("\n\n\nerror 404\n");
  }
  else{
    return 1;
  }
fclose(fread);
}
//*******************************
int main(){
  system("color 0a");
  int startcount=0;
  while(1){
    int f;
    int choose;
    char command[1000];
    setcolor(6);
    print_logo();
    setcolor(4);
    printf("\n-HEALTH SEARCH SYSTEM [BY TEMPESTAS]-\n");
    setcolor(10);
    FILE *fp = fopen("files\\systemready.vbs","w");
    fprintf(fp, "Dim text, speech\n\nSet speech = CreateObject(\"SAPI.SpVoice\")\ntext = \"Systems are ready\"\nspeech.Speak text");
    fclose(fp);
    getcurrentcwd();
    sprintf(command,"start %s\\files\\systemready.vbs",cwd);
    if(startcount==0)
    system(command);
    setcolor(2);
    printf("Select Option");
    setcolor(13);
    printf("\n1:READ DATA\n2:WRITE DATA\n3:ID QUERY\n");
    setcolor(3);
    printf("Choose : ");
    scanf("%d",&choose);
    setcolor(10);
    switch(choose){
      case 1:
        printf(">ID : ");
        setcolor(4);
        long long int hcode;
        scanf("%lld",&hcode);
        setcolor(10);
        read_file(hcode);
      break;
      case 2:
        setcolor(10);
        printf("-----------");
        setcolor(13);
        printf("\n1:NEW PATIENT\n2:EXISTING PATIENT\n");
        setcolor(3);
        printf("Choose : ");
        scanf("%d",&f);
        setcolor(10);
        switch(f){
          case 1:
          printf(">ID : ");
          setcolor(4);
          long long int hcode_ss;
          scanf("%lld",&hcode_ss);
          setcolor(10);
          write_file(hcode_ss);
            //printf("\n\n\nerror 204\n");
          break;
          case 2:
          printf(">ID : ");
          setcolor(4);
          long long int hcode_s;
          scanf("%lld",&hcode_s);
          setcolor(10);
          write_file(hcode_s);
          break;
        }
      break;
      case 3:
      printf(">ID : ");
      setcolor(4);
      long long int hcode_sss;
      scanf("%lld",&hcode_sss);
      setcolor(10);
      if(check_id(hcode_sss)){
      printf("\n\n\nID IS EXISTING\n");
      }
      else{
      printf("\n\n\nID IS NOT EXISTING\n");
      }
        //printf("\n\n\nerror 204\n");
      break;
    }
    printf("\n\n");
    setcolor(4);
    printf("\nPRESS ANY KEY TO RESTART\n");
    getch();
    startcount++;
    system(clear);
  }
  return 0;
}
