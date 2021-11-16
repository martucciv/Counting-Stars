//Veronica Martucci
//COP3502 Fall 2021
//09-13-2021
//RP2 Kattis: Counting Stars
//This program counts the number of stars visible in a bitmap image.
#include <stdio.h>
#define MAX 101
#define MOVES 4

const int DX[] = {-1,0,0,1};
const int DY[] = {0,-1,1,0};

//This function fill the region adjacent to (i,j) in the array with newFill
void floodFill(char arr[][MAX], int m, int n, int i, int j, char oldFill, char newFill){

  //check to make sure you're in bounds
  if(i < 0 || i >= m || j < 0 || j >= n){
    return;
  }

  if(arr[i][j] != oldFill){
    return;
  }

  //put new character into this spot
  arr[i][j] = newFill;

  for(int k = 0; k < MOVES; k++){
    floodFill(arr, m, n, i + DX[k], j + DY[k], oldFill, newFill);
  }
}

//This function counts how many stars are in the case
int countStars(char arr[][MAX], int m, int n){

  int count = 0;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){

      if(arr[i][j] == '-'){
        count++;
        //run a floodFill
        floodFill(arr, m, n, i, j, '-', '#');
      }
    }
  }
  return count;
}

int main(){

  int m, n, stars;
  int c = 1;
  char arr[MAX][MAX];

  while(scanf("%d %d", &m, &n) != EOF){

    for(int j = 0; j < m; j++){
      scanf("%s", arr[j]);
    }

    stars = countStars(arr, m, n);

    printf("Case %d: %d\n", c, stars);
    c++;
  }

  return 0;
}
