//----------------------------------------------youtube----------------------------------------------
// from Youtube video https://www.youtube.com/watch?v=KJgsSFOSQv0

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hello world!\n");

    char characterName[] = "John";
    int characterAge = 35;
    printf("There was a man named %s\n", characterName);   // char ==> %s
    printf("He was %d years old\n", characterAge);   // int ==> %d

    characterAge = 30;
    printf("There was a man named %s\n", characterName);
    printf("He was %d years old\n", characterAge);





    // data type:

    // --> int
    //mutable
    int age = 40;

    // --> float vs double
    // we can just use double for now
    // mutable
    double gpa = 4.0;

    // --> char
    // mutable
    char grade = 'A';  // only ONE character!!!!!! you cannot use "Alison".    single quotation mark.
    // immutable (just add [])
    char moreGrade[] = "AAAA";   // a lot of charactors. double quotation mark






printf("%s", "Hello Alison!");// string
printf("print one character %c", "A");// one character

printf("%d", 500); //int
printf("sdfgh %d", 500);
printf("dsfgdh %s is %d", "number", 500);
printf("%f", 500.324); //float

int favNum = 100;
printf("My favorite %s is %d", "number", favNum);

printf("%f", 5.0 * 4.5);
printf("%d", 5 + 4);
printf("%d", 5 / 4); // it is going to give you 1

    return 0;   // sheldon says this is not necessary
}





// -----------------------------------sheldon helps me write this-----------------------------------
// use control + option + n to run !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>

int main(){
    char a = 'A';
    printf("%c", a);
}







// ----------------------------------------------菜鸟----------------------------------------------

#include <stdio.h>
 
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
 
int main()
{
 
   int area;  
  
   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);    // why does here only use "%c"???? can't even use "%d"?????????/
   // the info of being wrong is:
   /* warning: format specifies type 'char *' but the argument has type 'char' [-Wformat]
   printf("%s", NEWLINE);
           ~~   ^~~~~~~
           %c
 */
   return 0;
}






#include <stdio.h>
int main(){
    const int LENGTH = 10;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;

    area = LENGTH * WIDTH;
    printf("value of area: %d", area);
    printf("%c", NEWLINE);

    return 0;
}








#include <stdio.h>

void func1(void);

static int count = 10;   //global variable 

int main(){
    while (count--){
        func1();
    }
    return 0;
}


void func1(void){
    static int thingy = 5;  // local variable
    thingy++;
    printf(" thingy is %d, count is %d\n", thingy, count);
}
// I do not understand the point of the global here tho
// here the global changes in the main function





//------------------------------ google tutorial --------------------------------------
// from google in English: https://www.learn-c.org/en/Variables_and_Types

// for boolean 
#define BOOL char
#define TRUE 1
#define FALSE 0



// string 
#include <stdio.h>

//char * name = "John Smith";
char name[10] = "John Smith";  
// the num needs to be at least 10 or the array would be too long for it 
// both is alright 

/* 
the square bracket in "char name[]" 
means for the computer to calculate the size of the array automatically

eg: char name[] = "John Smith" is the same as 
    char name[11] = "Johm Smith"
*/ 

int main(){
    printf("%s", name);
}


// string length
strlen(something)



// comparing string
#include <stdio.h>
#include <string.h>

int main(){
    char * name = "Alison";
    if (strncmp(name, "John", 2) == 0) {
        printf("same");
    }else{
        printf("You are not John. Go away.");
    }
}




// string  concatenation
#include <stdio.h>
#include <string.h>

int main(){
    // char dest[20]="Hello";
    // char src[20]="World";
    // strncat(dest,src,3);  // add three digits to the former one
    // printf("%s\n",dest);
    // strncat(dest,src,20);  //dest has been changed already
    // printf("%s\n",dest);

    char first_name[20] = "Alison";  // leave enough room for both 
    char last_name[20] = "Yao";
    strncat(last_name, first_name, 1);  // it can only add the latter to the former one
    printf("%s\n", last_name);
    return 0;
}




// for loop
#include <stdio.h>
/*
For loops give the following functionality:
Initialize the iterator variable using an initial value
Check if the iterator has reached its final value
Increases the iterator
 */


int main(){
    // int i;
    // for (i = 0; i<10; i++){
    //     printf("%d\n", i);

    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = 0;
    int i;

    for (i = 0; i < 10; i++) {
        sum += array[i];
        printf("%d\n", sum);



    }
}



// while loop
int n = 0;
while (n<10){
    n++;
}

while (1) // this is an infinite loop
// how to break?

int n = 0;
while(1){
    n++;
    if (n==10){
        break;
    }
}

int n = 0;
while(n<10){
    n++;
    if (n%2 == 1){
        continue;
    }
    printf("The number %d is even", n);
}





// function
#include <stdio.h>
//int bar = 5;

int foo(int bar){
    
    return bar*2;
}

int main(){
    printf("%d", foo(1));
}


// static is like global 
// the number can change after using "static"
#include<stdio.h>
int runner() {
    static int count = 0;
    count++;
    return count;
}

int main()
{
    printf("%d ", runner());
    printf("%d ", runner());
    return 0;
}

// there is also static function





// pointer
#include <stdio.h>

int main(){
    // int a = 1;
    // int * pointer_to_a = &a;
    // printf("The value a is %d\n", a);
    // printf("The value of a is also %d\n", *pointer_to_a);


    int a = 1;
    int *pointer_to_a = &a;

    /* let's change the variable a */
    a += 1;

    /* we just changed the variable again! */
    //*pointer_to_a += 1;

    /* will print out 3 */
    printf("The value of a is now %d\n", a);
    printf("The value of the pointer is %p\n", pointer_to_a);   // use p for pointer
    return 0;
}




// struct

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[50];
    char major[50];
    int age;
    double gpa;
};


int main(){
    struct Student student1;
    student1.age = 21;
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");
    strcpy(student1.major, "Business");


    struct Student student2;
    student2.age = 22;
    student2.gpa = 4.0;
    strcpy(student2.name, "Alison");
    strcpy(student2.major, "Data Science");

    printf("%f\n", student1.gpa);
    printf("%s\n", student1.name);
}

