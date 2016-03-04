//tests.c 

#include "textbuffer.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]) 
{

    char text[]= "usman\nhaidar\nblackbox\ntest\0";
    TB current = newTB(text);

    int number = linesTB(current); 
    assert(number==4);
    assert(number/4==1);
    
    
    char *array = dumpTB(current);
    printf("%s\n",array);
    assert(strcmp(array,"usman\nhaidar\nblackbox\ntest\n")==0);
    free(array);

    swapTB(current,3,2);
    array = dumpTB(current);
    assert(strcmp(array,"usman\nhaidar\ntest\nblackbox\n")==0);
    free(array);

    swapTB(current,1,3);
    array = dumpTB(current);
    assert(strcmp(array,"usman\nblackbox\ntest\nhaidar\n")==0);
    free(array);

    swapTB(current,3,2) ; 
    array= dumpTB(current) ; 
    printf("4th and 3rd lines of current are swapped...\n%s\n",array) ; 
    free(array) ; 
    
    swapTB(current,1,2) ; 
    array = dumpTB(current) ; 
    printf("Back to original string: \n%s\n",array) ; 
    free(array) ;


    array = dumpTB(current);
    assert(array[0] == 'u');
    free(array);
    deleteTB(current,1,2);
    array = dumpTB(current);
    assert(strcmp(array, "usman\ntest\n") == 0);
    free(array); 

    releaseTB(current);
    printf("current is released\n"); 

    char text2[] = "usman\ncomp1927\nsummer\nsemester\n";
    TB anotherOne = newTB(text2);
    swapTB(anotherOne,1,3);
    array = dumpTB(anotherOne);
    printf("%s\n",array);
    assert(strcmp(array,"usman\nsemester\nsummer\ncomp1927\n") == 0);
    free(array); 
    

    deleteTB(anotherOne,1,2);
    array=dumpTB(anotherOne);
    assert(strcmp(array, "usman\ncomp1927\n") == 0); 
    free(array);

    deleteTB(anotherOne,1,1);
    array=dumpTB(anotherOne);
    assert(strcmp(array, "usman\n") == 0); 
    free(array); 
    releaseTB(anotherOne);
    


    char newtext[]= "usman\nhaidar\nsecond\ntest\0";
    TB current2 = newTB(newtext);
    
    deleteTB(current2,0,2);
    array = dumpTB(current2);
    assert(strcmp(array,"test\n") == 0);
    free(array);
    releaseTB(current2);
    




    char str[] = "line 0\n"
                 "line 01\n"
                 "line 02\n"
                 "line 03\n"
                 "line 04\n"
                 "line 05\n";
    TB tbMerge= newTB(str);
    TB merge = newTB("xxxxx\n");
    mergeTB(tbMerge,0,merge);
    array = dumpTB(tbMerge);
    assert(array[0] == 'x'); 
    free(array);



    char str2[] = "line 0\nline 01\nline 02\nline 03\n";
    TB original = newTB(str2);
    TB getsMerged = newTB("usman\n");
    mergeTB(original,3,getsMerged);
    array = dumpTB(original);
    assert(strcmp(array,"line 0\nline 01\nline 02\nusman\nline 03\n") == 0);



    TB tb1 = newTB("usman\nhaidar\ntesting\npaste\n");
    TB tb2 = newTB("gets\npasted\n");
    pasteTB(tb1,1,tb2);  
    char* str3 = dumpTB(tb1);        
    assert(strcmp(str3, "usman\ngets\npasted\nhaidar\ntesting\npaste\n") == 0);
    free(str3) ; 

    releaseTB(tb1);
    releaseTB(tb2);
    

    char newstring[] = "line 01\nline 02\nusman\nhaidar\n";
                 
    tb1 = newTB(newstring);
    
    char *s;
    
    // Cut first 3 lines of tb1
    tb2 = cutTB(tb1, 0, 2);
    s = dumpTB(tb1);
    assert(strcmp(s, "haidar\n") == 0);
    free(s);
    s = dumpTB(tb2);
    assert(strcmp(s, "line 01\nline 02\nusman\n") == 0);
    free(s);
    releaseTB (tb1);
    releaseTB (tb2);
    
    tb1= newTB("usman\nhaidar\ntesting\ncopy\nfunction");
    tb2= copyTB(tb1,1,2);
    array=dumpTB(tb2);
    printf("%s\n",array);
    assert(strcmp(array, "haidar\ntesting\n" ) == 0);
    releaseTB (tb1);
    releaseTB (tb2);
    free(array);

    tb1= newTB("usman\nhaidar\ntesting\nreplace\n");
    array = strdup("usman");
    char replaces[]="comp2";
    replaceText(tb1,array,replaces);
    char *newArray = dumpTB(tb1);
    printf("%s\n",newArray);
    assert(strcmp(newArray, "comp2\nhaidar\ntesting\nreplace\n") == 0);



    printf("all tests passed\n"); 
    return 0; 
} 



