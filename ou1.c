//namn = Samuel Kenrick
//cs-id = oi21skk

#include <stdio.h>
#include <math.h>


int main (void) {
    int choice, loop = 1;
    /*
    choice är användarens val
    och loop är en variabel jag använder för att loopa printf funktionerna för menyn. 
    */

    float sekrate = 1;
    float pris;
    //sekrate är vad växlingskursen är. Pris är vad produkten kostar.
    
    //säger hej
    printf("\n\nShopping assistant Sam. \n\n");

    while (loop == 1)
    //denna while loop fortsätter repetera ända fram tills personen väljer val 3.
    {
    
    printf("\nPlease choose from the options below:\n\n");
    printf("1. Please set your exchange rate in SEK (current rate: %0.2f)\n", sekrate);
    printf("2. Read prices in foreign currencies \n");
    printf("3. Quit\n\n");
    scanf("%d", &choice);
    
    //kollar nu för de olika svaren.
    switch (choice) {
        
        /* om vi väljer val ett så läser vi vad växlingskursen ska vara. 
        Jag använder även abs() från math.h biblioteket för att undvika tecken problem.
        Hade kunnat göra utan den men tycker det ser bättre ut så här */
        case 1:
        printf("Please enter an exchange rate: ");
        scanf("%f", &sekrate);
        sekrate = abs(sekrate);
        break;
        
        /* i fall 2 så ska personen skriva vad produkten kostan i utländsk valuta och så konverteras
        det enligt angiven växlingskurs */
        case 2:
        printf("Please enter the price: ");
        scanf("%f", &pris);
        pris = abs(pris);
        printf("The cost is %0.2f SEK \n", pris*sekrate);
        break;

        /* Avsluta kodprocessen. Om programmet körs genom .exe filen så stängs fönstret.
        Om programmet startades via terminalen så kommer man återgå till att kunna skriva in kommandon */ 
        case 3:
        printf("\nThank you for using this shopping assistant! \n\n");
        loop = 0;
        break;

        //denna återgår till början om någon skriver vad som helst förutom en siffra 1-3. 
        default:
        printf("\nPlease enter a number from 1 to 3");
        break;

    }
    }
    
    
}