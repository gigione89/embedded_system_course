/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  float median;
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test,SIZE);
  sort_array(test,SIZE);

}

void print_statistics(unsigned char vector[], int size){
	int i, temp, max, min;
	float  avg=0, median=0;
	/*for (i=0;i<size;i++){
		//double temp = strtod(vector[i],NULL);
		temp=vector[i];
  		float ftemp = (float)temp;
  		if (ftemp<min) min=ftemp;
  		if (ftemp>max) max=ftemp;
  		if(size%2==1){
  		 	if(i==(size+1)/2)median=ftemp;
  		 	}
  		else {
  			if(i==size/2){
  				temp = vector[i+1];
  				float ftemp1=(float)temp;
  				median=(ftemp+ftemp1)/2;
  				}
  		}
  		total+=ftemp;	
	}
	avg=total/size;
	*/
	median=find_median(vector, size);
	avg=find_avg(vector,size);
	min=find_min(vector,size);
	max=find_max(vector,size);
	printf("Average is %f, Maximum is %d,  Minimum is %d, Median is %f", avg, max, min, median);
	
}

void print_array(unsigned char arr[],int size)
{
	printf("\nThe array is:\n");
	for(int i=0;i<size;i++){
		printf("%d\t", arr[i]);
	}		
}
void sort_array(unsigned char arr[],int size)
{
	unsigned char temp[size];
	for(int i=0;i<size;i++){
		temp[i]=arr[i];
	}
	quicksort(temp, 0, size - 1);
	print_array(temp,size);
}
void quicksort(unsigned char arr[],int primo,int ultimo)
{
int temp, pivot;
     if(primo<ultimo){
      pivot=primo;
      int i=primo;
      int j=ultimo;     
      
      while(i<j){
         while(arr[i]<=arr[pivot]&&i<ultimo)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){   
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,primo,j-1);
      quicksort(arr,j+1,ultimo);
   }
}

float find_median(unsigned char vector[], int size){
	float median=0;
	if(size%2==1){
		int i=(size+1)/2;
		//double temp = strtod(vector[i],NULL);
  		float ftemp = (float)vector[i];	
	}
	else{
		int i=(size)/2;
		//double temp = strtod(vector[i],NULL);
  		float ftemp = (float)vector[i];
  		//temp = strtod(vector[i+1],NULL);
  		float ftemp1=(float)vector[i+1];
  		median=(ftemp+ftemp1)/2;
	}
	return median;
}

int find_max(unsigned char vector[], int size){
	int max=0;
	int i;
	for (i=0;i<size;i++){
		//double temp = strtod(vector[i],NULL);
  		int ftemp = (int)vector[i];
  		if (ftemp>max) max=ftemp;	
	}
	return max;
}

int find_min(unsigned char vector[], int size){
	int min=0;
	int i;
	for (i=0;i<size;i++){
		//double temp = strtod(vector[i],NULL);
  		int ftemp = (int)vector[i];
  		if (ftemp<min) min=ftemp;
	}
	return min;
}

float find_avg(unsigned char vector[], int size){
	float avg,total=0;
	int i;
	for (i=0;i<size;i++){
		float ftemp = (float)vector[i];
		total+=ftemp;	
	}
	avg=total/size;
	return avg;
}
/* Add other Implementation File Code Here */
