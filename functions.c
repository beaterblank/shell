void clearArgs(){
    for(int i=0;i<len;i++){
        strcpy(ARGS[i],"");
    }
}
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
    printf("%s",readText(ARGS[1],findSize(ARGS[1])));
    clearArgs();
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

void _ls(int op_a,int op_l)
{
	struct dirent *d;
	DIR *dh = opendir(CWD);
	if (!dh)
	{
		if (errno = ENOENT)
		{
			perror("Directory doesn't exist");
		}
		else
		{
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while ((d = readdir(dh)) != NULL)
	{
		if (!op_a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if(op_l) printf("\n");
	}
	if(!op_l)
	printf("\n");
}



void date(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%02d / %02d / %04d ",tm.tm_mday,tm.tm_mon+1,tm.tm_year + 1900);
    printf("\n");
}

void makedir(){
    int ret = mkdir(ARGS[1], 0755);
    if (ret == 0)
        printf("Directory created successfully\n");
    else
        printf("Unable to create directory %s\n", ARGS[1]);
}

void removedir(){
    int ret = rmdir(ARGS[1]);
    if (ret == 0)
        printf("Directory delted successfully\n");
    else
        printf("Unable to delete directory %s\n", ARGS[1]);
}