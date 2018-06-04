//Alex Oggerino
//Project9
//This program displays the inventory in inventory.txt, a binary file, with a .txt name

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//declare variables
	int part_number, quantity;
	float price;
	FILE *fp2;

  	// Print Headers after a space for neatness
	printf("\n");
	printf("Below are the items in your inventory:\n");
	printf("Part #\tQuantity\tItem Price\n");

	// Open the file
	fp2 = fopen("inventory.txt", "r"); 

	// Loop until end of file
	while(!feof(fp2))
	{
		// Read in the data, one item at a time
		fread(&part_number, sizeof(part_number), 1, fp2);
		fread(&quantity, sizeof(quantity), 1 , fp2);
		fread(&price, sizeof(price), 1 , fp2);
		
		// Check for end of file 
			if(feof(fp2))
			{
				// End of file, close file, return 0
				fclose(fp2);
				printf("This is the end of the report.\n\n");
				return 0;
			}
		else
				// File provided another row of data
			{
				// Print each item in a single row
				printf("%d", part_number);
				printf("\t%d", quantity);
				printf("\t\t%.2f\n", price);
			}
	}

}