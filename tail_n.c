#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000
struct line{
    char* data;
    struct line* next;
};
struct line* head=NULL;
struct line* tail=NULL;

int n=10;
void push(char* data){
    struct line* newline=malloc(sizeof(struct line));
    newline->data=data;
    newline->next=NULL;
    if(head==NULL){
        head=newline;
        tail=newline;
    }
    else
    {
        tail->next=newline;
        tail=newline;
    }
}
void pop() {
  if(head==NULL){
    return;
  }
  struct line *prevhead=head;
  head=head->next;
  if(head==NULL){
    tail = NULL;
  }
  free(prevhead->data);
  free(prevhead);
}
void printlast_n(){
  struct line *current=head;
  int i;
  for(i=0;i<n;i++){
    if(current==NULL){
      break;
    }
    printf("%s\n", current->data);
    current=current->next;
  }
}

int main(int argc,char *argv[])
{
    if(argc>2)
    {
        printf("Usage: tail [-n <number of lines>]\n");
        return 1;
    }
    if(argc==2){
        n=atoi(argv[1]);
    }
    char line[MAX_SIZE];
    while(fgets(line,MAX_SIZE,stdin)){
        push(line);
    }
    printlast_n();
}
