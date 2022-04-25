#include <stdio.h>

typedef struct Item
{
  int id;
  int value;
  int weight;
  float ratio;
} Item;

void sortByRatio (struct Item items[], int n)
{
  int i, j;
  Item temp;

  for (i = 0; i < n - 1; i++)
    {
      for (j = 0; j < (n - 1 - i); j++)
	{
	  if (items[j].ratio < items[j + 1].ratio)
	    {
	      temp = items[j];
	      items[j] = items[j + 1];
	      items[j + 1] = temp;
	    }
	}
    }
}

int main ()
{
  int n, W;
  printf ("Enter the number of activites:");
  scanf ("%d", &n);
  printf ("Enter the maximum capicity of the knapsack");
  scanf ("%d", &W);
  Item items[n];
  for (int i = 0; i < n; i++)
    {
      printf ("Enter the value of Item %d ", i+1);
      scanf ("%d", &items[i].value);
      printf ("Enter the weight of the Item %d ", i+1);
      scanf ("%d", &items[i].weight);
      items[i].id=i+1;
      items[i].ratio = (items[i].value / (float) items[i].weight);
    }
  printf ("\n");
  for (int i = 0; i < n; i++)
    {
      printf ("The value is %d and the weight is %d and the ratio is %f \n",
	      items[i].value, items[i].weight, items[i].ratio);
    }
  printf ("\n");

  sortByRatio (items, n);
    printf("After sorting the ratios\n");
  for (int i = 0; i < n; i++)
    {
      printf ("The sorted by ratio is %f \n", items[i].ratio);
    }

  int current_weight = 0;
  double current_profit = 0;
  //To Store the order of items selected 
  //selected array is used
  double selected[n];
  int k=0; //To store the count of items added in selected array
  for (int i = 0; i < n; i++)
    {

      if (current_weight + items[i].weight <= W)
	{
	  current_profit += items[i].value;
	  current_weight += items[i].weight;
	  selected[k++]=items[i].id;
	}
      else
	{
	  int remaining = W - current_weight;
	  current_profit +=
	    items[i].value * ((double) remaining / (double) items[i].weight);
	   selected[k++]=((double) remaining / (double) items[i].weight);
	   selected[k++]=items[i].id;
	  break;
	}
    }



  printf ("The max profit is %f\n", current_profit);
  printf("The selected items are:");
    for(int i=0;i<k;i++){
        if(i==k-2){
            printf("%.2f part of %.2f is selected",selected[i],selected[i+1]);
            break;
        }
        else{
            
        printf("%.2f,",selected[i]);
        }
    }
  
  return 0;
}
