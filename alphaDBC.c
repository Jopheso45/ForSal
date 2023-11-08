//Author: Joseph Collins Robert Lang
//Goal: Build a large dataset of possible appropriate bids for (electrical) contracting work. Theory is that within a returned list of (currently) 256 different bids resides a golden bid that is pleasing to all parties involved
//Date Last Modified 07-31-2023


#include<stdio.h>

int numberOfItems, licenseFees, permitFees, numberOfEmployees, hoursToComplete, thirdPartyFees, totalAmountOfMaterials, cont;
char materialLabel, licenseLabel, laborLabel, thirdPartyLabel;
double profitPerItem, costPerItem, sum, salarySum, bid;
double employeeSalary[20] = {0.0};
double addAllMaterialCosts[30] = {0.0};
double materialCost[4] = {0.0};
double licenseAndPermitCosts[4] = {0.0};
double laborCost[4] = {0.0};
double thirdPartyCosts[4] = {0.0};


double calcLabor(int hours, double empsal)
{	
	double labor = empsal * hours; //calculates labor by multiplying hours worked by salary(hourly rate) specified
	

	return labor;
}

double calcMaterials(int num, double cpi, double ppi)
{
	double materialValue;
	double materialValueWithProfit;

	materialValue = (num * cpi);  //calculates material value by multiplying number of items of material by the cost per item (cpi)
	materialValueWithProfit = materialValue + (materialValue * ppi); // adds the material value with whatever specified percent profit desired
	


	return materialValueWithProfit;	
}

double calcBid(double mat, double lice, double labor, double third)
{
	double bid = mat + lice + labor + third; // bid is equal to all costs added together

	return bid;
}


int main(void)
{

	printf("\nPlease enter the number of different materials required to complete this job...\n");
	scanf("%d", &totalAmountOfMaterials);
	
	for(int i = 0; i < totalAmountOfMaterials; i++) // loops through however many different items are specified by the user and then calculates the value of each with profit included
	{
		printf("Enter the number of pieces associated with item #%d...\n", i+1);
		scanf("%d", &numberOfItems);
		printf("Enter your cost per item...\n");
		scanf("%lf", &costPerItem);
		printf("Enter your desired profit per item...\n");
		scanf("%lf", &profitPerItem);
		
		addAllMaterialCosts[i] = calcMaterials(numberOfItems, costPerItem, profitPerItem);
		printf("\n%.2lf\n", addAllMaterialCosts[i]);
	}
	for(int i = 0; i < 30; i++) // sums the cost of all the materials (this is currently hard capped at 30)
	{
		sum = sum + addAllMaterialCosts[i];
	}
	materialCost[0] = sum; // sets the original material cost in the array to the sum from the previous code block
	printf("\nThe total original material cost is equal to: %.2lf\n", materialCost[0]);

	printf("\nPlease enter the total cost of all Licenses and Permits to complete this project...\n");
	scanf("%lf", &licenseAndPermitCosts[0]);
	printf("\nPlease enter the total 3rd party costs (eg homage to the owner)...\n");
	scanf("%lf", &thirdPartyCosts[0]);

	printf("\nPlease enter the total number of employess that will be assigned to this project...\n");
	scanf("%d", &numberOfEmployees);

	for(int i = 0; i < numberOfEmployees; i++)
	{
		printf("\nEnter the salary of employee #%d\n", i+1);
		scanf("%lf", &employeeSalary[i]);
		salarySum = salarySum + employeeSalary[i];
	}

	printf("\nPlease enter your estimated total number of hours you expect this project to take...\n");
	scanf("%d", &hoursToComplete);

	printf("\nThe total original Labor cost is equal to: %.2lf", calcLabor(hoursToComplete, salarySum));
	laborCost[0] = calcLabor(hoursToComplete, salarySum);

	printf("\nenter any number to continue...\n");
	scanf("%d", &cont);

	materialCost[1] = materialCost[0] + (materialCost[0] * .1);
	materialCost[2] = materialCost[0] - (materialCost[0] * .1);
	materialCost[3] = materialCost[0] + (materialCost[0] * .15);

	licenseAndPermitCosts[1] = licenseAndPermitCosts[0] + (licenseAndPermitCosts[0] * .1);
	licenseAndPermitCosts[2] = licenseAndPermitCosts[0] - (licenseAndPermitCosts[0] * .1);
	licenseAndPermitCosts[3] = licenseAndPermitCosts[0] + (licenseAndPermitCosts[0] * .15);

	laborCost[1] = laborCost[0] + (laborCost[0] * .1);
	laborCost[2] = laborCost[0] - (laborCost[0] * .1);
	laborCost[3] = laborCost[0] + (laborCost[0] * .15);

	thirdPartyCosts[1] = thirdPartyCosts[0] + (thirdPartyCosts[0] * .1);
	thirdPartyCosts[2] = thirdPartyCosts[0] - (thirdPartyCosts[0] * .1);
	thirdPartyCosts[3] = thirdPartyCosts[0] + (thirdPartyCosts[0] * .15);
	

	printf("\nMaterial$:\t");
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{materialLabel = 'A';}
		else if(i == 1)
		{materialLabel = 'B';}
		else if(i == 2)
		{materialLabel = 'C';}
		else
		{materialLabel = 'D';}

		printf("\t%c.%.2lf", materialLabel, materialCost[i]);
	}

	printf("\nLicense$:\t");
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{licenseLabel = 'A';}
		else if(i == 1)
		{licenseLabel = 'B';}
		else if(i == 2)
		{licenseLabel = 'C';}
		else
		{licenseLabel = 'D';}

		printf("\t%c.%.2lf", licenseLabel, licenseAndPermitCosts[i]);
	}

	printf("\nLabor$:\t\t");
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{laborLabel = 'A';}
		else if(i == 1)
		{laborLabel = 'B';}
		else if(i == 2)
		{laborLabel = 'C';}
		else
		{laborLabel = 'D';}

		printf("\t%c.%.2lf", laborLabel, laborCost[i]);
	}

	printf("\nThird Party$:\t");
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{thirdPartyLabel = 'A';}
		else if(i == 1)
		{thirdPartyLabel = 'B';}
		else if(i == 2)
		{thirdPartyLabel = 'C';}
		else
		{thirdPartyLabel = 'D';}

		printf("\t%c.%.2lf ", thirdPartyLabel, thirdPartyCosts[i]);
	}	

	printf("\nEnter any number to calculate all possible iterations of each cost...\n");
	scanf("%d", &cont);

	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{materialLabel = 'A';}
		else if (i == 1)
		{materialLabel = 'B';}
		else if (i == 2)
		{materialLabel = 'C';}
		else
		{materialLabel = 'D';}	

		for(int j = 0; j < 4; j++)
		{
			if(j == 0)
			{licenseLabel = 'A';}
			else if (j == 1)
			{licenseLabel = 'B';}
			else if (j == 2)
			{licenseLabel = 'C';}
			else
			{licenseLabel = 'D';}
		

			for(int k = 0; k < 4; k++)
			{
				if(k == 0)
				{laborLabel = 'A';}
				else if (k == 1)
				{laborLabel = 'B';}
				else if (k == 2)
				{laborLabel = 'C';}
				else
				{laborLabel = 'D';}


				for(int l = 0; l < 4; l++)
				{
					if(l == 0)
					{thirdPartyLabel = 'A';}
					else if (l == 1)
					{thirdPartyLabel = 'B';}
					else if (l == 2)
					{thirdPartyLabel = 'C';}
					else
					{thirdPartyLabel = 'D';}


					bid = calcBid(materialCost[i], licenseAndPermitCosts[j], laborCost[k], thirdPartyCosts[l]);
					printf("\nMaterial$ %c. (%.2lf) + License$ %c. (%.2lf) + Labor$ %c. (%.2lf) + 3rd Party$ %c. (%.2lf) = %.2lf (total bid)\n\n", materialLabel, materialCost[i], licenseLabel, licenseAndPermitCosts[j], laborLabel, laborCost[k], thirdPartyLabel, thirdPartyCosts[l], bid);
				}
			}
		}
	}
	

	printf("\n\nEnter any number to exit the program...\n");
	scanf("%d", &cont);
	return 0;
}








