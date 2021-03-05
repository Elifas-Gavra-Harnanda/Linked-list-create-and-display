#include <stdio.h>
#include <stdlib.h>

struct data{
    int nilai;
    char nilai1;
    struct data *next;
}*head, *tail, *current;

insertKepala(int nilaiMasukkan, char nilaiHuruf){
    current = (struct data*)malloc(sizeof(struct data));
    current->nilai = nilaiMasukkan;
    current->nilai1 = nilaiHuruf;

    if(head==NULL){
        head=tail=current;
    }else{
        current->next = head;
        head=current;
    }
}

insertAkhir(int nilaiMasukkan, char nilaiHuruf){
    current = (struct data*)malloc(sizeof(struct data));
    current->nilai = nilaiMasukkan;
    current->nilai1 = nilaiHuruf;

    if(head==NULL){
        head = tail = current;
    }else{
        tail->next = current;
        tail = current;
    }
    tail->next = NULL;
}

void tampil(){
    current = head;
    while(current!=NULL){
        printf("\nnilainya %i", current->nilai);
        printf("\nnilainya dalam huruf %c", current->nilai1);
        current = current->next;
    }

}

void main(){
    int menu=1;int nilainya;
    while(menu!=0){
        printf("\n1.insert");
        printf("\n2.tampil");
        printf("\n masukkan menu : ");
        scanf("%i", &menu);

        switch(menu){
            case 1:
                    printf("\nmasukkan nilai : ");
                    scanf("%i", &nilainya);
                    if(nilainya>80){
                        insertAkhir(nilainya, 'A');
                    }else if(nilainya>70){
                        insertAkhir(nilainya, 'B');
                    }else{
                        insertAkhir(nilainya, 'E');
                    }
                break;
            case 2: tampil();
                break;
            default : printf("\nmenunya gaaada nih kak");
                break;
        }
    }

}
