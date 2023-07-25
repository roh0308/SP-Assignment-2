#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000
struct line{
    char* data;
    struct line* next;
};
struct line* head=NULL;
struct line* tail=NULL;

int n=3;
void push(char* data){
    /*struct line* newline=malloc(sizeof(struct line));
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
    }*/
    struct line* newline = malloc(sizeof(struct line));
    newline->data = malloc(strlen(data) + 1); // Allocate memory for the string
    strcpy(newline->data, data); // Copy the data into the allocated memory
    newline->next = NULL;

    if (head == NULL) {
        head = newline;
        tail = newline;
    } else {
        tail->next = newline;
        tail = newline;
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
void free_list() {
    struct line* current = head;
    while (current != NULL) {
        struct line* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
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
    if(argc==2){
        n=atoi(argv[1]);
    }
    char line[MAX_SIZE];
    while(fgets(line,MAX_SIZE,stdin)){
        push(line);
    }
    printlast_n();
    free_list();
}
