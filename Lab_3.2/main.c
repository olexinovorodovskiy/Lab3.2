#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define eps 0.0001


double f(double x);
double chord_method(double x1, double x2);
double half_division_method(double x1, double x2);
int choose_method;
//---------------------------------------
int main()
      {

            int    N;
            double x1, x2, F;
            double root;

                printf(" Choose an odyss from the solution options:");
                printf("\n To solve the chord method, press 1 ");
                printf("\n To solve the half division method, press 2");
                printf("\n Your option: ");
                scanf ("%u", &choose_method);

            while  (choose_method!=1&&choose_method!=2)
                {
                    scanf("%u", &choose_method);
                }

              printf(" Do the following:");
            do {
                    printf("\n Enter a value X1: ");
                    scanf ("%lf", &x1);
                    printf("\n Enter a value X2: ");
                    scanf ("%lf", &x2);
                    printf("\n Enter the number of iterations: ");
                    scanf ("%u", &N);
                    F = f(x1) * f(x2);
                   if (F > 0)
                        printf("\nChoose another arguments\n");
               } while (F > 0);

                 system("cls");

            switch(choose_method)
                  {
                      case 1:
                          {
                             root = chord_method(x1, x2);
                          }
                      break;

                      case 2:
                          {
                             root = half_division_method(x1, x2);
                          }

                      break;
                  }
                   printf ("\nroot=%lf, X1=%.0lf, X2=%.0lf, eps=%lf", root, x1, x2, eps);
            return 0;
      }
//---------------------------------------
double f(double x)
      {
            double y;

                   y = (x - 50)*cos(x/10) - 3*x + 500;

            return y;
      }
//---------------------------------------
double chord_method(double x1, double x2)
      {
            double       xi, xj, delta_t;
            unsigned int choice, const_n, N, n_count;
                         clock_t start, end;

                printf("\n Enter the number of iterations: ");
                scanf("%u", &N);
                const_n=N;

                    start = clock();
            do {
                    n_count++;
                    xj=xi;
                    xi=x2-f(x2)*(x1-x2)/(f(x1)-f(x2));
                    xj=x2;
                    x2=xj;

            if (n_count%N==0);
                 {
                       printf (" Number of completed iterations: %u", n_count);
                       printf ("\n Current X is: %.3lf", xi);
                       printf ("\n Current f(x): %.3lf", f(xi));
                       printf ("\n\n Your next steps?");
                       printf ("\n\t 1. Continue with the same number of iterations");
                       printf ("\n\t 2. Carry out the calculation before obtaining the result");
                       printf ("\n\t 3. Exit end show current result");
                       printf ("\n Enter the following action: ");
                       scanf  ("%u", &choice);
                       printf ("--------------------------------------------------------\n");

                      while (choice!=1&&choice!=2&&choice!=3)
                             {
                                scanf("%u", &choice);
                             }
                      if(choice == 1)
                             {
                                N=N+const_n;
                             }
                      if(choice == 2)
                             {
                                N=N+n_count;
                             }
                      if(choice == 3)
                             {
                                break;
                             }
                 }
               }while(fabs(xi-x2)>eps);

                    end = clock();

                    delta_t = (end - start) / CLOCKS_PER_SEC;

                    printf("\n\ndelta time = %lf", delta_t);
            return xi;
      }
//---------------------------------------
double half_division_method(double x1, double x2)
      {
            double       xi;
            unsigned int choice, const_n, N, n_count, delta_t;
                         clock_t start, end;
                printf("\n Enter the number of iterations: ");
                scanf("%u", &N);
                const_n=N;

                    start = clock();
            do {
                    n_count++;
                    xi = (x1 + x2) / 2;

                if( f(xi) * f(x1) > 0)
                    x1 = xi;
                else
                    x2 = xi;
                if (n_count%N==0)
                  {
                       printf (" Number of completed iterations: %u", n_count);
                       printf ("\n Current X is: %.3lf", xi);
                       printf ("\n Current f(x)= %.3lf", f(xi));
                       printf ("\n\n Your next steps?");
                       printf ("\n\t 1. Continue with the same number of iterations");
                       printf ("\n\t 2. Carry out the calculation before obtaining the result");
                       printf ("\n\t 3. Exit end show current result");
                       printf ("\n Enter the following action: ");
                       scanf  ("%u", &choice);
                       printf ("--------------------------------------------------------\n");
                     while  (choice!=1&&choice!=2&&choice!=3)
                           {
                              scanf("%u", &choice);
                           }
                    if(choice == 1)
                           {
                              N=N+const_n;
                           }
                    if(choice == 2)
                           {
                              N=N+n_count;
                           }
                    if(choice == 3)
                           {
                              break;
                           }
                  }
               }while(fabs(xi-x2)>=eps);
                    end = clock();

                    delta_t =(end - start) / CLOCKS_PER_SEC;

                    printf("\n\ndelta time = %lf", delta_t);

            return xi;
      }



