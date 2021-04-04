#include <stdio.h>
#include "konyv.h"

int main(){
Date a;
setDate(&a,2018,1,1);
Book* book = createBook("A Keplet","Barabasi Albert Laszlo","Hungarian","Self Improvement",&a,0,2,0);
showBook(book);
return 0;
}
