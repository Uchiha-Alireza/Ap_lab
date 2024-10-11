#include "human.h"
#include <iostream>
void deletedn(student*& students, int size){
    for (int i = 0; i < size; ++i){
        delete[] students[i].h.family;
    }
}
void deletedn(human*& humans, int size){
    for (int i = 0; i < size; ++i){
        delete[] humans[i].family;
    }
}
void target_sec(struct human*& New, int n){
    if (n < 2){
        std::cout << "tedad ensanha kafi nist!" << std::endl;
        return;
    }
    int max = New[0].age;
    int second_max = -1; 
    for (int i = 1; i < n; i++){
        if (New[i].age > max){
            second_max = max;
            max = New[i].age;
        }
        else if (New[i].age > second_max && New[i].age < max){
            second_max = New[i].age;
        }
    }
    if (second_max == -1){
        std::cout << "dovomin sen bishtar vojood nadarad." << std::endl;
        return;
    }
    for (int i = 0; i < n; i++){
        if (New[i].age == second_max){
            std::cout << "name va code ensan ba dovomin sen bishtar: " << New[i].name<<" "<<New[i].n_code << std::endl;
            return;
        }
    }
}
void target_sec(struct student*& New, int n){
    if (n < 2){
        std::cout << "tedad danshjooyan kafi nist." << std::endl;
        return;
    }
    double max = New[0].avg;
    double second_max = -1; 
        for (int i = 1; i < n; i++){
        if (New[i].avg > max){
            second_max = max;
            max = New[i].avg;
        }
        else if (New[i].avg > second_max && New[i].avg < max){
            second_max = New[i].avg;
        }
    }
    if (second_max == -1){
        std::cout << "dovomin moadel bishtar vojood nadarad." << std::endl;
        return;
    }
    for (int i = 0; i < n; i++){
        if (New[i].avg == second_max){
            std::cout << "name va code daneshjoo ba dovomin moadele bishtar: " << New[i].h.name<<" "<<New[i].std_no << std::endl;
            return;
        }
    }
}
void target_sec(struct student*& New, int n, int second_max){
    if (n < 2){
        std::cout << "tedad daneshjooyan kafi nist." << std::endl;
        return;
    }
    int max = New[0].h.age;
    second_max = -1; 
    for (int i = 1; i < n; i++){
        if (New[i].h.age > max){
            second_max = max;
            max = New[i].h.age;
        } else if (New[i].h.age > second_max && New[i].h.age < max){
            second_max = New[i].h.age;
        }
    }
    if (second_max == -1){
        std::cout << "dovomin sen bishtar vojood nadarad." << std::endl;
        return;
    }
    for (int i = 0; i < n; i++){
        if (New[i].h.age == second_max){
            std::cout << "name va code danshjoo ba dovomin sen: " << New[i].h.name<<" "<<New[i].std_no << std::endl;
            return;
        }
    }
}
void target_sec(struct student*& New, int n, bool B){
    if (!B){
        int count = 0;
        target_sec(New, n, count);
    }
    else{
        target_sec(New, n);
    }
}