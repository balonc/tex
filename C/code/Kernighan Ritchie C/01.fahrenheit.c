/* 
    El siguiente programa utiliza la fórmula C=(5/9)(F-32) para imprimir la 
    temperatura Fahrenheit y su equivalente en grados centígrados (Celsius).
*/

#include <stdio.h>

main() 
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
