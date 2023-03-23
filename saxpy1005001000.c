#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>

void get_walltime (double* wcTime){
    struct timeval tp;
    gettimeofday(&tp,NULL);
    *wcTime=(tp.tv_sec+tp.tv_usec/1000000.0);
}

int main (int argc, char* argv[]){
    int i, j, k, n=100,m=500, o=1000;
    int **matrizA100, **matrizB100, **matrizC100,**matrizA500, **matrizB500, **matrizC500,**matrizA1000, **matrizB1000, **matrizC1000;
    double S1,E1;
//------------------------inicio de matrices-------------------------
    matrizA100=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        *(matrizA100+i)=(int *)malloc(n*sizeof(int *));
    }
    matrizB100=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        *(matrizB100+i)=(int *)malloc(n*sizeof(int *));
    }
    matrizC100=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        *(matrizC100+i)=(int *)malloc(n*sizeof(int *));
    }

    matrizA500=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++){
        *(matrizA500+i)=(int *)malloc(m*sizeof(int *));
    }
    matrizB500=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++){
        *(matrizB500+i)=(int *)malloc(m*sizeof(int *));
    }
    matrizC500=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++){
        *(matrizC500+i)=(int *)malloc(m*sizeof(int *));
    }

    matrizA1000=(int **)malloc(o*sizeof(int *));
    for(i=0;i<o;i++){
        *(matrizA1000+i)=(int *)malloc(o*sizeof(int *));
    }
    matrizB1000=(int **)malloc(o*sizeof(int *));
    for(i=0;i<o;i++){
        *(matrizB1000+i)=(int *)malloc(o*sizeof(int *));
    }
    matrizC1000=(int **)malloc(o*sizeof(int *));
    for(i=0;i<o;i++){
        *(matrizC1000+i)=(int *)malloc(o*sizeof(int *));
    }
//-----------------------Llenado de matrices-------------------------
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizA100[i][j]=rand() %6;
        }
    }
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizB100[i][j]=rand() %6;
        }
    }
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizC100[i][j]=0;
        }
    }


    for (i=0;i<m;i++){
        for(j=0;j<m;j++){
            matrizA500[i][j]=rand() %6;
        }
    }
    for (i=0;i<m;i++){
        for(j=0;j<m;j++){
            matrizB500[i][j]=rand() %6;
        }
    }
    for (i=0;i<m;i++){
        for(j=0;j<m;j++){
            matrizC500[i][j]=0;
        }
    }


    for (i=0;i<o;i++){
        for(j=0;j<o;j++){
            matrizA1000[i][j]=rand() %6;
        }
    }
    for (i=0;i<o;i++){
        for(j=0;j<o;j++){
            matrizB1000[i][j]=rand() %6;
        }
    }
    for (i=0;i<o;i++){
        for(j=0;j<o;j++){
            matrizC1000[i][j]=0;
        }
    }
//--------------------MULTIPLICACIONES en 100*100-------------------------
    //Multiplicación de matrices ijk
    get_walltime(&S1);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                matrizC100[i][j]+=matrizA100[i][k]*matrizB100[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método ijk en 100*100: %f s\n", (E1-S1));
    //Multiplicación de matrices ikj
    get_walltime(&S1);
    for(i=0;i<n;i++){
        for(k=0;k<n;k++){
            for(j=0;j<n;j++){
                matrizC100[i][j]+=matrizA100[i][k]*matrizB100[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método ikj en 100*100: %f s\n", (E1-S1));

    //Multiplicación de matrices jik
    get_walltime(&S1);
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            for(k=0;k<n;k++){
                matrizC100[i][j]+=matrizA100[i][k]*matrizB100[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método jik en 100*100: %f s\n", (E1-S1));

    //Multiplicación de matrices jki
    get_walltime(&S1);
    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                matrizC100[i][j]+=matrizA100[i][k]*matrizB100[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método jki en 100*100: %f s\n", (E1-S1));

    //Multiplicación de matrices kij
    get_walltime(&S1);
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                matrizC100[i][j]+=matrizA100[i][k]*matrizB100[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método kij en 100*100: %f s\n", (E1-S1));

    //Multiplicación de matrices kji
    get_walltime(&S1);
    for(k=0;k<n;k++){
        for(j=0;j<n;j++){
            for(i=0;i<n;i++){
                matrizC100[i][j]+=matrizA100[i][k]*matrizB100[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método kji en 100*100: %f s\n", (E1-S1));



//--------------------MULTIPLICACIONES en 500*500-------------------------
    //Multiplicación de matrices ijk
    get_walltime(&S1);
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            for(k=0;k<m;k++){
                matrizC500[i][j]+=matrizA500[i][k]*matrizB500[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método ijk en 500*500: %f s\n", (E1-S1));
    //Multiplicación de matrices ikj
    get_walltime(&S1);
    for(i=0;i<m;i++){
        for(k=0;k<m;k++){
            for(j=0;j<m;j++){
                matrizC500[i][j]+=matrizA500[i][k]*matrizB500[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método ikj en 500*500: %f s\n", (E1-S1));

    //Multiplicación de matrices jik
    get_walltime(&S1);
    for(j=0;j<m;j++){
        for(i=0;i<m;i++){
            for(k=0;k<m;k++){
                matrizC500[i][j]+=matrizA500[i][k]*matrizB500[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método jik en 500*500: %f s\n", (E1-S1));

    //Multiplicación de matrices jki
    get_walltime(&S1);
    for(j=0;j<m;j++){
        for(k=0;k<m;k++){
            for(i=0;i<m;i++){
                matrizC500[i][j]+=matrizA500[i][k]*matrizB500[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método jki en 500*500: %f s\n", (E1-S1));

    //Multiplicación de matrices kij
    get_walltime(&S1);
    for(k=0;k<m;k++){
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                matrizC500[i][j]+=matrizA500[i][k]*matrizB500[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método kij en 500*500: %f s\n", (E1-S1));

    //Multiplicación de matrices kji
    get_walltime(&S1);
    for(k=0;k<m;k++){
        for(j=0;j<m;j++){
            for(i=0;i<m;i++){
                matrizC500[i][j]+=matrizA500[i][k]*matrizB500[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método kji en 500*500: %f s\n", (E1-S1));


//--------------------MULTIPLICACIONES en 1000*1000-------------------------
    //Multiplicación de matrices ijk
    get_walltime(&S1);
    for(i=0;i<o;i++){
        for(j=0;j<o;j++){
            for(k=0;k<o;k++){
                matrizC1000[i][j]+=matrizA1000[i][k]*matrizB1000[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método ijk en 1000*1000: %f s\n", (E1-S1));
    //Multiplicación de matrices ikj
    get_walltime(&S1);
    for(i=0;i<o;i++){
        for(k=0;k<o;k++){
            for(j=0;j<o;j++){
                matrizC1000[i][j]+=matrizA1000[i][k]*matrizB1000[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método ikj en 1000*1000: %f s\n", (E1-S1));

    //Multiplicación de matrices jik
    get_walltime(&S1);
    for(j=0;j<o;j++){
        for(i=0;i<o;i++){
            for(k=0;k<o;k++){
                matrizC1000[i][j]+=matrizA1000[i][k]*matrizB1000[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método jik en 1000*1000: %f s\n", (E1-S1));

    //Multiplicación de matrices jki
    get_walltime(&S1);
    for(j=0;j<o;j++){
        for(k=0;k<o;k++){
            for(i=0;i<o;i++){
                matrizC1000[i][j]+=matrizA1000[i][k]*matrizB1000[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método jki en 1000*1000: %f s\n", (E1-S1));

    //Multiplicación de matrices kij
    get_walltime(&S1);
    for(k=0;k<o;k++){
        for(i=0;i<o;i++){
            for(j=0;j<o;j++){
                matrizC1000[i][j]+=matrizA1000[i][k]*matrizB1000[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método kij en 1000*1000: %f s\n", (E1-S1));

    //Multiplicación de matrices kji
    get_walltime(&S1);
    for(k=0;k<o;k++){
        for(j=0;j<o;j++){
            for(i=0;i<o;i++){
                matrizC1000[i][j]+=matrizA1000[i][k]*matrizB1000[k][j];
            }
        }
    }
    get_walltime(&E1);
    printf("Tiempo método kji en 1000*1000: %f s\n", (E1-S1));

//---------------------Impresión de matrices para comprobación (CAMBIAR CUANDO SE USEN N GRANDES-----------------
/*
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%i " ,matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%i " ,matrizB[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%i " ,matrizC[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    return 0;
}
