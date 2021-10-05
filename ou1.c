//namn = Samuel Kenrick
//cs-id = oi21skk

#include <stdio.h>


int main (void) {
    int choice, loop = 1, leep = 1;
    /*
    choice är användarens val
    och loop är en variabel jag använder för att loopa printf funktionerna för menyn.
    leep är en variabel för while funktionen i andra meny-valet 
    */

    double sekrate = 1; 
    double price;
    double sum;
    //sekrate är vad växlingskursen är. Price är vad produkten kostar. Sum är summan av priserna.

    //säger hej
    printf("Your shopping assistant\n\n");

    while (loop == 1)
    //denna while loop fortsätter repetera ända fram tills personen väljer val 3.
    {
    
    printf("1. Set exchange rate in SEK (current rate: %0.2lf)\n", sekrate);
    printf("2. Read prices in the foreign currency \n");
    printf("3. End\n\n");
    printf("Give your choice (1 - 3): ");
    scanf("%d", &choice);
    printf("\n");
    //meny där man kan mata in en siffra.

    //kollar nedan för de olika svaren.
    switch (choice) {
        
        // om vi väljer val ett så läser vi vad växlingskursen ska vara. 
        case 1:
        printf("Give exchange rate: ");
        scanf("%lf", &sekrate);
        printf("\n");
        //definierar växlingskursen
        break;
        
        /* i fall 2 så ska personen skriva vad produkterna kostar i utländsk valuta och så konverteras
        det enligt angiven växlingskurs */
        case 2:
        leep = 1;
        price = 0;
        sum = 0;
        //nedan while funktion gör så att vi kan mata in flera produkters kostnad.
        while (leep == 1) {
            printf("Give price (finish with < 0): ");
            scanf("%lf", &price);
            //nedan kollar vi om priset är större än noll eftersom vi vill sluta när den är <=0
            if  (price >= 0) {
                sum = sum+price;
                price = 0;
            } else{
                printf("\nSum in foreign currency: %0.2lf\n", sum);
                printf("Sum in SEK: %0.2lf\n\n", sum*sekrate);
                leep = 0;
                //bryter while funktionen med leep = 0
            }
        }
        break;

        /* Avsluta kodprocessen. Om programmet körs genom .exe filen så stängs fönstret.
        Om programmet startades via terminalen så kommer man återgå till att kunna skriva in kommandon */ 
        case 3:
        printf("End of program!\n\n");
        loop = 0;
        
        break;

        //denna återgår till början om någon skriver vad som helst förutom en siffra 1-3. 
        default:
        printf("Not a valid choice!\n\n");
        break;

    }
    }
    return 0;
    
}