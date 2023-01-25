#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dugum{
	char tag;
	struct dugum *sonraki;
};

typedef struct dugum stack;
stack *top = NULL;


void push(char);
void pop();
void peek();
int bosmu();

void push(char eleman){
	stack *yeni;
	yeni = (struct dugum*)malloc(sizeof(struct dugum));
	yeni -> tag = eleman;
	if(top == NULL)
		yeni -> sonraki = NULL;
	else
		yeni -> sonraki = top;
	top = yeni;
}

void pop(){
	if(top == NULL)
        printf("Stack bos! Stack icinde silinecek eleman yoktur\n");
    else{
        stack *temp = top;
        top = temp -> sonraki;
        free(temp);
    }
}


void peek(){
    if(top == NULL)
        printf("Yigin bos!\n");
    else
        printf("Tepedeki eleman: %s\n", top -> tag);
}

void listele(){
	stack *temp = top;
	while(temp != NULL){
		printf("%s ", temp -> tag);
		temp = temp -> sonraki;
	}
	printf("\n");
}

int bosmu(){
    return top == NULL;
}
	
int main(){
	
	int i;
  char kelime;
	char tag[30][20];
  kelime = tag[30][20];
    
    
	  FILE *dosya;
    dosya = fopen("html.txt","r");
    while (!feof(dosya)){
    	for (i = 0; i <! feof(dosya);i++ ) {
          fscanf(dosya, "%s", &tag);      
    	    if(tag[i][0] == '<'){
    	        if(tag[i][1] != '/'){
                printf("%s tag açıldı stack'e eklendi \n",tag[i]);                
    	        	push(kelime);
				      }
    	        else{
                printf("%s tag kapatıldı stackten eleman çıkarıldı \n",tag[i]);
    	        	pop();
				      }
				  
    	    } 
    	    
		}    
	}
	
  if( bosmu() == 1){
    printf("stack boş tüm tagler kapatılmıştır \n");
  }
	else{
    printf("stack dolu kapatlmamıs tag var hatalı kod \n");
  }
	
  return 0;
}