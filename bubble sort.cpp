#include <stdio.h>
int main()
{
  int arr[100],n,r,e,swap;
  printf("Enter number of elements\n");
  scanf("%d", &n);
  printf("Enter %d integers\n", n);
  for(r=0;r<n;r++){
    scanf("%d", &arr[r]);
  }
  for(r=0;r<n-1;r++)
  {
    for(e=0;e<n-r-1;e++)
    {
      if (arr[e]>arr[e+1])
      {
        swap= arr[e];
        arr[e]=arr[e+1];
        arr[e+1]=swap;
      }
    }
  }
  printf("Sorted list in ascending order:\n");
  for (r= 0;r< n; r++)
    printf("%d\n", arr[r]);

  return 0;
}
