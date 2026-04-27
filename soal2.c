/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 Structurre and Dynamic Array
 *   Hari dan Tanggal    : Rabu, 22 April 2026
 *   Nama (NIM)          : Muhammad Adnan Habibi Handoyo (13224093)
 *   Nama File           : soal2.c
 *   Deskripsi           : 
 * Program menerima data nama meteor, massa, dan kemurnian kemudian diurutkan
 * berdasarkan kemurnian, massa, dan alfabet
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Meteor{
    char* nama;
    int massa;
    int kemurnian;
}Meteor;

int main(){
    Meteor* arr = NULL;
    int n;

    scanf("%d", &n);
    arr = malloc(n*sizeof(Meteor));
    for(int i=0; i<n; i++){
        arr[i].nama = (char*) malloc(100*sizeof(char));

        scanf("%s %d %d", arr[i].nama,&arr[i].massa, &arr[i].kemurnian);
    };

    Meteor temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j+1].kemurnian > arr[j].kemurnian) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }else if(arr[j+1].kemurnian == arr[j].kemurnian && arr[j+1].massa < arr[j].massa){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }else if(arr[j+1].kemurnian == arr[j].kemurnian && arr[j+1].massa == arr[j].massa && strcmp(arr[j].nama, arr[j+1].nama) > 0){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    if(n<3){
        for(int i=0; i<n;i++){
            printf("%s %d %d\n", arr[i].nama, arr[i].massa, arr[i].kemurnian);
        }
    }else{
        for(int i=0; i<3;i++){
            printf("%s %d %d\n", arr[i].nama, arr[i].massa, arr[i].kemurnian);
        }
    }
    return 0;
}
