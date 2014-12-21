#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cone(int vol);
void cube(int vol);
void cylinder(int vol);
void sphere(int vol);

int main(int argc, char* argv[]){
   int i;

   for(i=1; i<argc; i++){
      cone(atoi(argv[i]));
      cube(atoi(argv[i]));
      cylinder(atoi(argv[i]));
      sphere(atoi(argv[i]));
   }

   return 0;
}

void cone(int vol){
   double height = pow(cbrt(vol), 2);
   double radius = sqrt((3*vol)/(M_PI * height));

   printf("h: %.2lf, r: %.2lf\n", height, radius);
}

void cube(int vol){
   double root = cbrt(vol);
   printf("l: %.2lf, w: %.2lf, h: %.2lf\n", root, root, root);
}

void cylinder(int vol){
   double height = cbrt(vol);
   double diameter = 2 * sqrt(vol / (M_PI * height));

   printf("h: %.2lf, d: %.2lf\n", height, diameter);
}

void sphere(int vol){
   printf("r: %.2lf\n", cbrt((3*vol)/(4* M_PI)));
}

