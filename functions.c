
void print(){
    for(int i=1;i<len;i++){
        printf("%s%c",ARGS[i],DELIMETER);
    }
    printf("\n");
}
void add(){
    printf("%d\n",atoi(ARGS[1])+atoi(ARGS[2]));
}
void sub(){
    printf("%d\n",atoi(ARGS[1])-atoi(ARGS[2]));
}
void divide(){
    if(atoi(ARGS[2])==0){printf("! zero division !\n");return;}
    printf("%d\n",atoi(ARGS[1])/atoi(ARGS[2]));
}
void mul(){
    printf("%d\n",atoi(ARGS[1])*atoi(ARGS[2]));
}
void newTxt(){
    fopen(ARGS[1],"wb");
}
//returns number of charecters in a text file
long int findSize(char* fname)
{
    FILE* iter = fopen(fname,"rb"); ;
    fseek(iter, 0L, SEEK_END);
    long int res = ftell(iter);
    fclose(iter);
    return res;
}
//reads the text in a text file
char* readText(char* fname,long int size){
    FILE* iter= fopen(fname,"rb");
    char *buffer = (char*)malloc(sizeof(char)*(int)size);
    if(iter==NULL)return buffer;
    fread(buffer,sizeof(buffer),1,iter);
    fclose(iter);
    return buffer;
}
void readTxt(){
    printf("%s\n",readText(ARGS[1],findSize(ARGS[1])));
}
void changeDir(){
    if(chdir(ARGS[1])){
        printf("please enter a valid dir\n");
    }
}
void delete(){
    if(remove(ARGS[1])){
        printf("pleast enter a valid file\n");
    }
}
void copy(){
   char ch;
   FILE *source, *target;
   source = fopen(ARGS[1], "r");
   if (source == NULL) {
      printf("cannot read source file");
      return;
   }
   target = fopen(ARGS[2], "w");
   if (target == NULL) {
      fclose(source);
      printf("cannot open target file");
      return;
   }
   while ((ch = fgetc(source)) != EOF)fputc(ch, target);
   printf("File copied successfully.\n");
   fclose(target);
   fclose(source);

}

void pwd(){
    getcwd(CWD, sizeof(CWD));
    printf("%s\n",CWD);
}