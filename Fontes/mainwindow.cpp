#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <time.h>
#include <QComboBox>
#include <QtWidgets>
#include <QAction>
#include <QApplication>
#include <QtGui>
#include <qapplication.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include<string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include "pilhaq.h"
#include <sys/stat.h>
#include <QMessageBox>


void window_txt(char *txt_name, int op);
void error_window_notcalc(int op);
void arrcpy(int dest[],int src[], int alen);


#define MAXE 10

//Declaração variáveis globais
FILE *arq;								//Ponteiro para um dos arquivos contendo os números em determinada ordem (crescente, decresente ou aleatório)
int vetorsrc[100000], vetor2[100000];	//vetor original e o vetor a ser modificado nos algoritmos
int plotop=0;							//Opção atual do "plotter", zero significa que nada deve ser exibido, 1 para tempo, 2 para trocas e 3 para comparações
char alg1[25], alg2[25], vet[50];		//Nome dos algoritmos a serem comparados e do arquivo a ser aberto
double  x1[MAXE]={10,100, 500, 1000, 5000, 10000, 25000, 50000, 85000, 100000},			//Vetores contendo os pontos a serem plotados no gráfico, x1 é fixo, o restante é modificado durante a execução do algoritmo
        tempo1[MAXE]={0,0,0,0,0,0,0,0,0,0},
        tempo2[MAXE]={0,0,0,0,0,0,0,0,0,0},
        trocas1[MAXE]={0,0,0,0,0,0,0,0,0,0},
        trocas2[MAXE]={0,0,0,0,0,0,0,0,0,0},
        comp1[MAXE]={0,0,0,0,0,0,0,0,0,0},
        comp2[MAXE]={0,0,0,0,0,0,0,0,0,0};

/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/


//INSERTION SORT:
void insertion_sort (int *v, double *tempo, double *trocas, double *comp, int alen){
    int i,j, temp;
    _timeb start, end; // tempo de início e fim
    _ftime(&start); // pega hora inicial


    for(i=1;i<alen;i++){
        temp=v[i];
        j=i;

        while((j>0)&&(temp<v[j-1])){
            v[j]=v[j-1];
            *trocas+=1;	//Executa uma troca
            *comp+=1;	//Deve comparar para executar a troca
            j--;
        }
        v[j]=temp;
        if(v[i]==temp)  //Caso não tenha havido trocas, significa que só houve uma comparação!
            *comp+=1;
        }

    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;
}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/


//BUBBLE SORT:
void bubble_sort (int *v, double *tempo, double *trocas, double *comp, int alen)
{
    int i,j,temp, troca=0;  //variável troca indica se houve ou não uma troca
    _timeb start, end; // tempo de início e fim
    _ftime(&start); // pega hora inicial

    for(i=alen-1;i>0;i--){
        troca=0;
        for(j=0;j<i;j++){
                if(v[j]>v[j+1]){
                    *trocas+=1;
                    temp=v[j];
                    v[j]=v[j+1];
                    v[j+1]=temp;
                    troca=1;    //sinaliza que houve ao menos uma troca
                }
                *comp+=1;   //Sempre executa uma comparação com o próximo elemento
        }
        if(!troca) break;   //Se não houve nenhuma troca no último "loop", significa que já está tudo ordenado, logo se pode terminar o algoritmo
    }
    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;

}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/

//QUICK SORT:
int particao (int v[], double *trocas, double *comp, int i, int f)
{
    int p=i, k=i+1, j=f, temp;
     while(j>k){
             while((v[k]<=v[p])&&(k<f)) {k++; *comp+=1;}    //Sempre compara com o pivô
             while((v[j]>=v[p])&&(j>i)) {j--; *comp+=1;}    //Sempre compara com o pivô
             if((v[k]>v[j])&&(j>k)){
                     temp=v[k];
                     v[k]=v[j];
                     v[j]=temp;
                     *comp+=1;  //Houve comparação
                     *trocas+=1;    //Houve troca
             }

     }
     if(v[j]<v[p]){
         temp=v[j];
         v[j]=v[p];
         v[p]=temp;
         *comp+=1;
         *trocas+=1;
     }
    return j;   //Retorna a posição do pivô
}

void quicksort(int *v, double *tempo, double *trocas, double *comp, int i, int f)
{
    int p,y=0;
    pilhaq *stk=NULL; //A pilha só controla a recursão, não tendo nenhuma influência no número de 'trocas'/'comparações'
                      //realizadas. No tempo sim, porém.

    _timeb start, end; // tempo de início e fim
    _ftime(&start); // pega hora inicial

    do{
            if(y!=0)    //y é uma flag dizendo se já é possível desempilhar algo ou não (na primeira passada não, pois está vazia!)
                stk=desempilha(stk, &i, &f);
                p=particao(v, trocas, comp, i, f);
                if(p+1<f)
                    stk=insere_pilha(stk, p+1, f);
                if(p-1>i)
                    stk=insere_pilha(stk, i,p-1);
            if(y==0) y=1;
    }while(stk!=NULL);

    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;
    return;
}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/


//SELECTION SORT:
void selection_sort(int *v, double *tempo, double *trocas, double *comp, int alen){
    int i,j,min,k;

   _timeb start, end; // tempo de início e fim

    _ftime(&start); // pega hora inicial

    for(i=0;i<alen-1;i++){
        min=i;
        for(j=i+1;j<alen;j++){
            if(v[j]<v[min])
                min=j;
                *comp+=1;   //Sempre executa uma comparação!
        }
        if(i!=min){
            k=v[min];
            v[min]=v[i];
            v[i]=k;
            *trocas+=1;     //Troca apenas quando tem certeza do que deve ser trocado.
        }
    }

    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;
}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/


//HEAP SORT:
void heapify (int *v, int i, double *trocas, double *comp, int alen){
    int d=2*i+2, e=2*i+1, maior=i, temp;

    if((e<alen)&&(v[e]>v[maior]))
        maior=e;
    if((d<alen)&&(v[d]>v[maior]))
        maior=d;
    *comp+=2;
    if(maior!=i){
            *comp+=1;
            temp=v[maior];
            v[maior]=v[i];
            v[i]=temp;
            *trocas+=1;
            heapify(v, maior, trocas, comp, alen);
    }
    return;
}

void build_heap (int *v, double *trocas, double *comp, int alen){
    int i=(alen-1)/2;
    for(;i>=0;i--)
        heapify(v, i, trocas, comp, alen);
    return;
}

void heap_sort(int *v, double *tempo, double *trocas, double *comp, int alen){
    int i, temp;
    _timeb start, end; // tempo de início e fim

    _ftime(&start); // pega hora inicial

    build_heap(v, trocas, comp, alen);

    for(i=alen-1;i>=1;i--){
            temp=v[i];
            v[i]=v[0];
            v[0]=temp;
            *trocas+=1;
            alen--;
            heapify(v, 0, trocas, comp, alen);
    }
    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;
    return;
}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/


//MERGESORT:
void mergear(int esq_i, int esq_f, int dir_i, int dir_f, int *v, double *trocas, double *comp)
{
    int esq_size = esq_f - esq_i;
    int dir_size = dir_f - dir_i;

    int esquerda[esq_size];
    int direita[dir_size];

    int d = 0, e = 0, i = 0;

    for (i = esq_i; i < esq_f; i++, e++)
    {
        esquerda[e] = v[i];
    }


    for (i = dir_i; i < dir_f; i++, d++)
    {
        direita[d] = v[i];
    }

    for ( i = esq_i, d = 0, e = 0; e < esq_size && d < dir_size; i++)
    {
        if (esquerda[e] < direita[d]) { v[i] = esquerda[e++]; }
        else { v[i] = direita[d++]; *trocas+=1;}
        *comp+=1;
    }

    //Passa as "sobras"
    for ( ; e < esq_size; i++, e++) { v[i] = esquerda[e]; }
    for ( ; d < dir_size; i++, d++) { v[i] = direita[d]; }
}

void mergesort(int esq, int dir, int *v, double *tempo, double *trocas, double *comp)
{
    _timeb start, end; // tempo de início e fim
    _ftime(&start); // pega hora inicial

    //dir: posição final
    //esq: posição inicial
    //O final do vetor não pode ser menor que o início
    if (dir-esq<=1)
        return;

    //Divide o array v em duas partes, com seus respectivos "início e fim"
    int esq_i  = esq;
    int esq_f  = (esq+dir)/2;
    int dir_i = esq_f;
    int dir_f   = dir;

    //sort para esquerda
    mergesort( esq_i, esq_f, v, tempo, trocas, comp);
    //sort para direita
    mergesort( dir_i, dir_f, v, tempo, trocas, comp);
    //Une os dois arrays novamente
    mergear(esq_i, esq_f,dir_i, dir_f, v, trocas, comp);

    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;
    return;
}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/


//COUNTING SORT:
//Função necessária para o algoritmo de Counting Sort, pois é necessário descobrir qual o maior valor presente no vetor a ser ordenado
int maior_valor (int *v, int alen){
    int i, maior=v[0];

    for(i=0;i<alen;i++){
            if(v[i]>maior) maior=v[i];
    }
    return maior;
}

void counting_sort (int *v, double *tempo, double *trocas, double *comp, int alen){
    int i,p;
     _timeb start, end; // tempo de início e fim

     _ftime(&start); // pega hora inicial

      p=maior_valor(v, alen);

      int *b=(int*)malloc((alen)*sizeof(int));
      int *c=(int*)malloc((p+1)*sizeof(int));

      for(i=0;i<=p;i++) c[i]=0;

      for(i=0;i<alen;i++) c[v[i]]=c[v[i]]+1;

      for(i=1;i<=p;i++) c[i]+=c[i-1];

      for(i=alen-1;i>=0;i--){
          b[c[v[i]]-1]=v[i];
          c[v[i]]=c[v[i]]-1;

      }
    //Como, pela definição, o vetor 'b' é o vetor de saída, não há nenhuma troca entre os elementos, nem comparações.
    arrcpy(v,b,alen);//Copia os elementos para 'v' apenas para fins de testes depois e de manter a padronização.

    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;
    free(b);
    free(c);
}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/


//BUCKET SORT:
void bucket_sort(int *v, double *tempo, double *trocas, double *comp, int alen){
    int n=alen, i, p=0,k;
    lista *vlist[n];    //O número de buckets é igual ao tamanho do vetor a ser ordenado

    _timeb start, end; // tempo de início e fim

    _ftime(&start); // pega hora inicial

    for(i=0;i<n;i++){
        vlist[i]=NULL;
    }

    //loop que divide os elementos nos 'n' 'buckets'
    for(i=0;i<alen;i++){
        k=(v[i]/100);   /*Apesar de sempre haver 'n' buckets, o que equivale aos 'n' elementos do vetor original,
                        Há casos em que não haverá apenas números de 1,2,...,n-1, por isso se divide cada elemento
                        por 100 e, se o valor 'k' (que define o k-ésimo 'bucket') for maior que 'n', então o número
                        deve ser inserido no último 'bucket', pois é muito grande.
                        Isso pode, porém, causar um problema em casos de vetores que contenham apenas valores muito
                        maiores que 'n', pois neste caso todos os elementos acabariam no último 'bucket', o que levaria
                        o algoritmo a ter o comportamento do 'Insertionsort'.
                        Seria preciso, nestes casos, fazer uma análise prévia dos números contidos, ou obter alguma informação
                        sobre estes, antes de iniciar a ordenação.*/
        if(k>=n) k=n-1;
        //As trocas e as comparações executadas pelo algoritmo de insertionsort quando da inserção de um elemento
        //na lista do "bucket" não são contabilizadas para o algoritmo em questão!
        vlist[k]=inserir_lista_ordenada(v[i],vlist[k]);
    }

    p=0;
    //Concatena os 'buckets' no vetor original, em ordem, assim todo o vetor estará ordenado ao final
    for(i=0;i<n;i++){
        while(vlist[i]!=NULL){
            v[p++]=vlist[i]->chave;
            vlist[i]=vlist[i]->prox;
        }
        free(vlist[i]);
    }
    _ftime(&end); // pega hora final
    *tempo = (end.time - start.time)*1000;
    *tempo=(*tempo+end.millitm-start.millitm)/1000;
}
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------*/

//Função que dado um array de destino, um fonte e o tamanho deles, copia destino<-fonte
void arrcpy(int dest[],int src[], int alen){
    int i=0;
    for(i=0;i<alen;i++)
        dest[i]=src[i];

    return;
}


//Algumas inicializações para a construção da 'mainwindow' do programa
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setupUi(this);

    //Configuração inicial do gráfico
    qwtPlot->setCanvasBackground(QColor(Qt::white));
    QwtLegend *legend = new QwtLegend;
    legend->setFrameStyle(QFrame::Box|QFrame::Sunken);
    qwtPlot->insertLegend(legend, QwtPlot::BottomLegend);
    qwtPlot->replot();

    //Conecta as ações do menu às funções que devem realizar
    connect(exitAction_2, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(clearPlot, SIGNAL(triggered()), this, SLOT(clear_Plot()));
    connect(saveastxt, SIGNAL(triggered()), this, SLOT(Save_as_txt()));
    connect(about_2, SIGNAL(triggered()), this, SLOT(about_window_info()));
}


//Função executada sempre que o botão "Comparar" é pressionado, executa os cálculos com os algoritmos e então apresenta o resultado em forma de gráfico
void MainWindow::on_btn_compara_clicked()
{
    int ind1=0,ind2=0, ind3=0,i=0;

    //Limpa o gráfico, permitindo que apenas as curvas do momento sejam vistas
    clear_Plot();

    //Zera os vetores de posições 'y' no gráfico, permitindo utilzar a ferramenta diversas vezes
    for(i=0;i<MAXE;i++){
        trocas1[i]=0;
        trocas2[i]=0;
        comp1[i]=0;
        comp2[i]=0;
        tempo1[i]=0;
        tempo2[i]=0;
    }

    //Pega os índices atuais de cada dropbox que há (alg1, alg2 e tamanho de vetores)
    ind1=alglist_3->currentIndex();
    ind2=alglist_2->currentIndex();
    ind3=vetlist->currentIndex();

    //Se nenhum dos indices dos algoritmos for diferente de zero, nenhum algoritmo foi escolhido para ordenação. Erro!
    if((ind1==0)&&(ind2==0)){
        error_window_notcalc(1);
        return;
    }

    //Define, através do índice da dropbox de vetores, qual o arquivo a ser lido para carregar os valores
    switch(ind3){
        case 0:
             strcpy(vet,".\\vetores\\vetor_ordenado.bin");
             arq = fopen(vet,"rb");
             if(!arq) { window_txt(vet,0); return; }
             break;
        case 1:
             strcpy(vet,".\\vetores\\vetor_desordenado.bin");
             arq = fopen(vet,"rb");
             if(!arq) { window_txt(vet,0); return; }
             break;
        case 2:
            strcpy(vet,".\\vetores\\vetor_aleatorio.bin");
            arq=fopen(vet,"rb");
            if(!arq) { window_txt(vet,0); return; }
             break;
        default: return;
    }


    fread(vetorsrc,sizeof(int), 100000,arq);
    arrcpy(vetor2,vetorsrc,100000);
    fclose(arq);

    switch(ind1){
        case 1: //Bubblesort
                strcpy(alg1, "Bubblesort");
                for(i=0;i<MAXE;i++){
                    bubble_sort(vetor2, &tempo1[i], &trocas1[i], &comp1[i], x1[i]);
                    if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                    progressBar->setValue((i*6)-4);
                }
                break;
        case 2: //Quicksort
                strcpy(alg1, "Quicksort");
                for(i=0;i<MAXE;i++){
                    quicksort(vetor2, &tempo1[i], &trocas1[i], &comp1[i], 0, (x1[i])-1);
                   if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                    progressBar->setValue((i*6)-4);
                }
                break;
       case 3: //Insertionsort
                strcpy(alg1, "Insertionsort");
                for(i=0;i<MAXE;i++){
                    insertion_sort(vetor2, &tempo1[i], &trocas1[i], &comp1[i], x1[i]);
                   if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                    progressBar->setValue((i*6)-4);
                }
                break;
       case 4: //Selectionsort
                strcpy(alg1, "Selectionsort");
                for(i=0;i<MAXE;i++){
                    selection_sort(vetor2, &tempo1[i], &trocas1[i], &comp1[i], x1[i]);
                   if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                    progressBar->setValue((i*6)-4);
                }
                break;
       case 5: //Heapsort
                strcpy(alg1, "Heapsort");
                for(i=0;i<MAXE;i++){
                    heap_sort(vetor2, &tempo1[i], &trocas1[i], &comp1[i], x1[i]);
                    if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                    progressBar->setValue((i*6)-4);
                }
                break;
        case 6:	//Mergesort
                strcpy(alg1, "Mergesort");
                for(i=0;i<MAXE;i++){
                    mergesort(0, x1[i], vetor2, &tempo1[i], &trocas1[i], &comp1[i]);
                    if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                    progressBar->setValue((i*6)-4);
                }
                break;
        case 7:	//Countingsort
                 strcpy(alg1, "Countingsort");
                 for(i=0;i<MAXE;i++){
                     counting_sort(vetor2, &tempo1[i], &trocas1[i], &comp1[i], x1[i]);
                    if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                     progressBar->setValue((i*6)-4);
                 }
                break;
        case 8: //Bucketsort
                 strcpy(alg1, "Bucketsort");
                 for(i=0;i<MAXE;i++){
                     bucket_sort(vetor2, &tempo1[i], &trocas1[i], &comp1[i], x1[i]);
                    if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                     progressBar->setValue((i*6)-4);
                 }
                break;
       case 0:
                alg1[0]=NULL;
                progressBar->setValue(50);
                break;
    default: return;

    }

    //Para fins de testes se os algoritmos estão ordenando corretamente, "descomente" o trecho abaixo:
   /* int j;
    for(i=0;i<99999;i++){
        for(j=i+1;j<100000;j++){
            if(vetor2[i]>vetor2[j]){ printf("Erro!  %i  >  %i\n\n", vetor2[i], vetor2[j]); return;}
        }
       }*/

    arrcpy(vetor2,vetorsrc,100000);

    switch(ind2){
    case 1: //Bubblesort
            strcpy(alg2, "Bubblesort");
            for(i=0;i<MAXE;i++){
                bubble_sort(vetor2, &tempo2[i], &trocas2[i], &comp2[i], x1[i]);
                if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                progressBar->setValue(50+((i*6)-4));
            }
            break;
    case 2: //Quicksort
            strcpy(alg2, "Quicksort");
            for(i=0;i<MAXE;i++){
               quicksort(vetor2, &tempo2[i], &trocas2[i], &comp2[i], 0, (x1[i])-1);
                if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                progressBar->setValue(50+((i*6)-4));
            }
            break;
   case 3: //Insertionsort
            strcpy(alg2, "Insertionsort");
            for(i=0;i<MAXE;i++){
                insertion_sort(vetor2, &tempo2[i], &trocas2[i], &comp2[i], x1[i]);
               if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                progressBar->setValue(50+((i*6)-4));
            }
            break;
   case 4: //Selectionsort
            strcpy(alg2, "Selectionsort");
            for(i=0;i<MAXE;i++){
                selection_sort(vetor2, &tempo2[i], &trocas2[i], &comp2[i], x1[i]);
               if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                progressBar->setValue(50+((i*6)-4));
            }
            break;
    case 5:	//Heapsort
             strcpy(alg2, "Heapsort");
             for(i=0;i<MAXE;i++){
                 heap_sort(vetor2, &tempo2[i], &trocas2[i], &comp2[i], x1[i]);
                if(i!=MAXE-1) arrcpy(vetor2,vetorsrc,x1[i]);
                 progressBar->setValue(50+((i*6)-4));
             }
            break;
    case 6:	//Mergesort
            strcpy(alg2, "Mergesort");
            for(i=0;i<MAXE;i++){
                mergesort(0, x1[i], vetor2, &tempo2[i], &trocas2[i], &comp2[i]);
                if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                progressBar->setValue(50+(i*6)-4);
            }
            break;
    case 7:	//Countingsort
             strcpy(alg2, "Countingsort");
             for(i=0;i<MAXE;i++){
                 counting_sort(vetor2, &tempo2[i], &trocas2[i], &comp2[i], x1[i]);
                 if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                 progressBar->setValue(50+(i*6)-4);
             }
            break;
    case 8:	//Bucketsort
             strcpy(alg2, "Bucketsort");
             for(i=0;i<MAXE;i++){
                 bucket_sort(vetor2, &tempo2[i], &trocas2[i], &comp2[i], x1[i]);
                 if(i!=MAXE-1)arrcpy(vetor2,vetorsrc,x1[i]);
                 progressBar->setValue(50+(i*6)-4);
             }
             break;
   case 0:
            alg2[0]=NULL;
            progressBar->setValue(100);
            break;
    default: return;

    }

    //Para fins de testes se os algoritmos estão ordenando corretamente, "descomente" o trecho abaixo:
    /*
    for(i=0;i<99999;i++){
        for(j=i+1;j<100000;j++){
            if(vetor2[i]>vetor2[j]){ printf("Erro!\n\n"); return;}
        }
       }*/

    //Seleciona a primeira opção do gráfico: "Tempo"
    rtempo->setChecked(true);
    //plotop=1 : tempo!
    plotop=1;
    //Muda o nome do eixo Y para Tempo (s)
    qwtPlot->setAxisTitle(QwtPlot::yLeft, "Tempo (s)");
    //Chama função que desenha o gráfico
    setupPlot(tempo1,tempo2);
    ind1=0;
    ind2=0;
}

//Função que constrói o gráfico a partir de dois vetores y dados (que podem ser: tempo, trocas ou comparações)
void MainWindow::setupPlot(double *y1, double *y2){
    int i;
    qwtPlot->setAutoReplot(false);

    qwtPlot->setAxisTitle(QwtPlot::xBottom, "Nº elementos no vetor"); //nome do eixo 'x'

    //Declara as duas curvas que poderão ser usadas no gráfico
    QwtPlotCurve *curve1 = new QwtPlotCurve(alg1);
    QwtPlotCurve *curve2 = new QwtPlotCurve(alg2);

    curve1->setPen( Qt::red, 1.0 );	//cor da curva1 - vermelho
    curve2->setPen( Qt::black, 1.0 ); //cor da curva2 - preto

    //seta os pontos de cada curva a partir dos dois vetores 'y' recebidos e do vetor de dimensões 'x1'
    curve1->setSamples(x1,y1,MAXE);
    curve2->setSamples(x1,y2,MAXE);

    if(((y1[0]!=-1)&&(y1[3]!=-1))&&(alg1[0]!=NULL))	//Se alguma medição for negativa, significa que houve erro, e a curva não deve ser "plotada" - não há tempo, número de trocas ou comparações negativas!
        curve1->attach(qwtPlot);
    if(((y2[0]!=-1)&&(y2[3]!=-1))&&(alg2[0]!=NULL))
        curve2->attach(qwtPlot);

    //executa um "replot" para atualizar o gráfico com as informações obtidas durante a função
     qwtPlot->replot();
}

//Função que limpa a tela do gráfico
void MainWindow::clear_Plot(){
    //potop=0 : Nenhuma opção selecionada
    plotop=0;
    //Retira os itens do gráfico (cruvas)
    qwtPlot->detachItems();
    //Atualiza o gráfico
    qwtPlot->replot();
}

//Caso a opção tempo (1) seja selecionada
void MainWindow::on_rtempo_clicked()
{
    if((plotop!=1)&&(plotop!=0)){
        //Limpa o gráfico inicialmente
        qwtPlot->detachItems();
        qwtPlot->replot();
        //Muda o nome do eixo Y
        qwtPlot->setAxisTitle(QwtPlot::yLeft, "Tempo (s)");
        //Seta o gráfico com os novos dados a serem visualizados
        setupPlot(tempo1,tempo2);
        //Seleciona a opção' 'tempo' e mantem as outras como deselecionadas
        rtempo->setChecked(true);
        rtroca->setChecked(false);
        rcomp->setChecked(false);
        //atualiza o gráfico
        qwtPlot->replot();
        plotop = 1;
    }
    return;
}

//Caso a opção trocas (2) seja selecionada
void MainWindow::on_rtroca_clicked()
{
    if((plotop!=2)&&(plotop!=0)){
        //Limpa o gráfico inicialmente
        qwtPlot->detachItems();
        qwtPlot->replot();
        //Muda o nome do eixo Y
        qwtPlot->setAxisTitle(QwtPlot::yLeft, "Nº trocas");
        //Seta o gráfico com os novos dados a serem visualizados
        setupPlot(trocas1,trocas2);
        //Seleciona a opção 'trocas' e mantem as outras como deselecionadas
        rtempo->setChecked(false);
        rtroca->setChecked(true);
        rcomp->setChecked(false);
        //atualiza o gráfico
        qwtPlot->replot();
        plotop = 2;
    }

}

//Caso a opção comparações (3) seja selecionada
void MainWindow::on_rcomp_clicked()
{
    if((plotop!=3)&&(plotop!=0)){
        //Limpa o gráfico inicialmente
        qwtPlot->detachItems();
        qwtPlot->replot();
        //Muda o nome do eixo Y
        qwtPlot->setAxisTitle(QwtPlot::yLeft, "Nº comparações");
        //Seta o gráfico com os novos dados a serem visualizados
        setupPlot(comp1,comp2);
        //Seleciona a opção 'comparações' e mantem as outras como deselecionadas
        rtempo->setChecked(false);
        rtroca->setChecked(false);
        rcomp->setChecked(true);
        //atualiza o gráfico
        qwtPlot->replot();
        plotop = 3;
    }

}

//Função que salva os pontos do gráfico em um arquivo .txt, de forma a permitir que os dados sejam utilizados (e melhor visualizados) fora do programa
void MainWindow::Save_as_txt()
{
    FILE *arqs; //arquivo para salvar
    char buff [50], buff2[50], vet2[50];
    time_t rawtime;
    struct tm * timeinfo;
    int i;

    //Se o gráfico ter sido limpo, ou nenhuma computação ter sido realizada, não há o que salvar
    if(((alg1[0]==NULL)&&(alg2[0]==NULL))||(plotop==0))
    {
        error_window_notcalc(0);
        return;
    }
    else if(alg2[0]==NULL)
        sprintf(buff,"%s", alg1);
    else if(alg1[0]==NULL)
        sprintf(buff,"%s", alg2);
    else
        sprintf(buff,"%s x %s", alg1, alg2);

    strcpy(buff2,buff);
    strcat(buff,".txt");

    if(!(arqs=fopen(buff, "at")))
    { //Se houve erro abrindo/criando o arquivo, por qualquer razão que seja
        window_txt (vet, 0);
        return;
    }

    time (&rawtime);
    timeinfo = localtime ( &rawtime );

    if(!(strcmp(vet,".\\vetores\\vetor_ordenado.bin")))
        strcpy(vet2, "Crescente");
    else if(!(strcmp(vet,".\\vetores\\vetor_desordenado.bin")))
        strcpy(vet2, "Decrescente");
    else
        strcpy(vet2, "Aleatório");

    fprintf(arqs,"\t\t\tTeste feito em: %s------ %s ------\nVetor usado: %s\n", asctime (timeinfo), buff2, vet2);
    if(alg1[0]!=NULL){
        fprintf(arqs,"\t-- %s --\n", alg1);
        fprintf(arqs,"no elem.\ttempo\t\ttrocas\t\tcomparações\n");
        for(i=0;i<MAXE;i++){
            fprintf(arqs,"%.0f\t\t%fs\t%.0f\t\t%.0f\n", x1[i], tempo1[i], trocas1[i], comp1[i]);
        }
    }
    if(alg2[0]!=NULL){
        fprintf(arqs,"\n\t-- %s --\n", alg2);
        fprintf(arqs,"no elem.\ttempo\t\ttrocas\t\tcomparações\n");
        for(i=0;i<MAXE;i++){
            fprintf(arqs,"%.0f\t\t%fs\t%.0f\t\t%.0f\n", x1[i], tempo2[i], trocas2[i], comp2[i]);
        }
    }
    fprintf(arqs,"\n\n########################################################################################\n\n");
    fclose(arqs);

    window_txt (buff,1);

}

//Função que apresenta uma mensagem ao usuário caso o arquivo txt tenha sido salvo com sucesso, ou caso tenha ocorrido algum erro ao abri-lo
void window_txt (char *txt_name, int op){
    char buff[100];
    QMessageBox messageBox;
    if(!op){
        sprintf(buff,"Erro ao tentar abrir/criar o arquivo '%s'.\nVerifique a existência do arquivo ou do diretório 'vetores'.",txt_name);

        messageBox.critical(0,"Erro na leitura",buff);
        messageBox.setFixedSize(500,200);
        return;
    }
    else{
        sprintf(buff,"Arquivo '%s' salvo com sucesso.",txt_name);
        messageBox.information(0,"Arquivo Salvo", buff);
        messageBox.setFixedSize(500,200);
        return;
    }

}

//Função que apresenta uma mensagem de erro em relação a computação do algoritmo
//tratando casos em que nenhum algoritmo foi selecionado para ser comparado, ou caso o gráfico tenha sido limpo e houve a tentativa de salvar os dados deste em txt
void error_window_notcalc(int op){
    QMessageBox messageBox;
    if(!op)
        messageBox.critical(0,"Erro ao salvar","Gráfico em branco, não há dados a serem salvos.\nEscolha os algoritmos que deseja comparar e então pressione \"Comparar\".");
    else
        messageBox.critical(0,"Erro ao computar","Nenhum algoritmo foi selecionado da lista de algoritmos 1 e 2.\nSelecione pelo menos um e pressione \"Comparar\".");
    messageBox.setFixedSize(500,200);
    return;
}

//Função que apresenta uma mensagem de informação do programa ao usuário
void MainWindow::about_window_info(){
    QMessageBox messageBox;
    messageBox.information(0,"LET Especial #0","UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL\nINSTITUTO DE INFORMÁTICA\n\nINF01124 - Classificação e Pesquisa de Dados\n2013/2 - Turma B\nProfessor: Leandro Krug Wives\nTrabalho: LET especial #0\n->Comparador de Algoritmos com Gráfico\n\nAluno: Carlo Sulzbach Sartori\nID: 218326\nData: 19/10/2013\n\nv1.0.0");
    messageBox.setFixedSize(500,200);
}

