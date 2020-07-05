#include <stdio.h>
main()
{ char * adr ;
adr = "bonjour" ;
while (*adr)
{ printf ("%c", *adr) ;
adr++ ;
}
}