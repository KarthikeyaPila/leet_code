int mod(int x) {
  if(x < 0){
    return x*-1;
  }

  return x;
}

// max = yi + yj + |xi - xj|
// |xi - xj| <= k
int findMaxValueOfEquation(int **points, int pointsSize, int *pointsColSize,
                           int k) {
  int abs_max = 0;

  for (int i = 0; i < pointsSize-1; i++) {
    int total = 0;
    int val = points[i][0] - points[i+1][0];
    int val_mod = mod(val);

    if (val_mod <= k) {
      total = points[i][1] + points[i+1][1] + val_mod;
    }

    if (total > abs_max) {
      abs_max = total;
    }
  }

  return abs_max;
}
