#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contador(int decimal, int base)
{
    int contador = 0;

    if(decimal ==0)
    {
        contador = 1;
        return contador;
    }
    else
    {
        while(decimal>=base)
        {
            decimal = decimal/base;
            contador += 1;
        }
    }
    contador +=1;

    return contador;
}

int* converter(int numero, int base)
{
    int* a = (int*)(malloc(contador(numero,base)*sizeof(int*)));

    int b = contador(numero,base);
    int num = numero;

    for(int i = b-1; i>=0; i--)
    {
        a[i] = num%base;
        num = num/base;
    }
    return a;  // NÃO ACHEI UM JEITO DE RETORNAR A SEM USAR FREE(A) DEPOIS DO RETURN.
    free(a);
}

int main() {
    while(1==1)
    {
        printf("\nDigite o numero decimal a ser convertido e a base de destino:  ");
        int decimal, basenova;
        scanf("%i", &decimal);
        getchar();
        scanf("%i", &basenova);

        for(int j=0; j<contador(decimal,basenova);j++)
        {
            printf("%i", converter(decimal,basenova)[j]);
        }
    }
    return 0;
}
