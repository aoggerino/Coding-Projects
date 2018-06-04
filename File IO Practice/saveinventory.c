//Alex Oggerino
//Project9
//File IO
//This takes inventory for a company and puts it into a text file until the user enters 0
//This conforms with the assignment requirements which is why a binary file as .txt

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	fp = fopen("inventory.txt", "w");
	int part_number;
	int quantity;
	float price;
	printf("This program stores a business inventory.\n");
	while(1)
	{
		// Scan in a row of data
		printf("Please enter item data (part number, quantity, price):");
		scanf("%d %d %f", &part_number, &quantity, &price);
		// Check if program should continue
		if(part_number != 0)
		{	
		// If not finished, write the row of data to the file			
		fwrite(&part_number, sizeof(int), 1 , fp);
		fwrite(&quantity, sizeof(int), 1 , fp);
		fwrite(&price, sizeof(float), 1 , fp);
		}	
		// Check if program should end
		else if(part_number == 0)
		{
		// If Finished, close file, return 0
			fclose(fp);
			return 0; 	
		}
	// End of Loop			
	}
// End of Program
}