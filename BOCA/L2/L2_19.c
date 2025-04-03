#include <stdio.h>

int main(){
    int numeroAtleta, numeroDelegacoes, contadorDelegacoes = 1;
    int nota1, nota2, nota3, somaMasculino, somaFeminino, auxiliar;
    int melhorAtletaMasculino, melhorAtletaFeminino, piorAtletaMasculino, piorAtletaFeminino;
    int melhorNotaMasculino1, melhorNotaMasculino2, melhorNotaMasculino3, melhorNotaFeminino1, melhorNotaFeminino2, melhorNotaFeminino3;
    int melhorSomaFeminino = -1, melhorSomaMasculino = -1, melhorDelegacaoMasculino, melhorDelegacaoFeminino;
    int piorNotaMasculino1, piorNotaMasculino2, piorNotaMasculino3, piorNotaFeminino1, piorNotaFeminino2, piorNotaFeminino3;
    char genero;

    scanf("%d", &numeroDelegacoes);

    while(contadorDelegacoes <= numeroDelegacoes){
        melhorNotaMasculino1 = -1, melhorNotaMasculino2 = -1, melhorNotaMasculino3 = -1, melhorNotaFeminino1 = -1, melhorNotaFeminino2 = -1, melhorNotaFeminino3 = -1;
        piorNotaMasculino1 = 11, piorNotaMasculino2 = 11, piorNotaMasculino3 = 11, piorNotaFeminino1 = 11, piorNotaFeminino2 = 11, piorNotaFeminino3 = 11;
        somaMasculino = 0, somaFeminino = 0;

        scanf("%d", &numeroAtleta);

        if(numeroAtleta == -1){
            break;
        }

        while(numeroAtleta != -1){
            scanf("%c", &genero);
            scanf("%d %d %d", &nota1, &nota2, &nota3);

            if(nota1 > nota2){
                auxiliar = nota2;
                nota2 = nota1;
                nota1 = auxiliar;
            }

            if(nota1 > nota3){
                auxiliar = nota3;
                nota3 = nota1;
                nota1 = auxiliar;
            }

            if(nota2 > nota3){
                auxiliar = nota3;
                nota3 = nota2;
                nota2 = auxiliar;
            }

            if(genero == 'M'){
                somaMasculino += nota3;

                if(nota3 >= melhorNotaMasculino3){
					if(nota3 > melhorNotaMasculino3){
						melhorNotaMasculino2 = nota2; 
                        melhorNotaMasculino1 = nota1; 
                        melhorAtletaMasculino = numeroAtleta; 
					}else if(nota2 >= melhorNotaMasculino2){
						if(nota2 > melhorNotaMasculino2 || nota1 > melhorNotaMasculino1 || (nota1 == melhorNotaMasculino1 && numeroAtleta < melhorAtletaMasculino)){ 
							melhorNotaMasculino1 = nota1; 
                            melhorAtletaMasculino = numeroAtleta; 
						} 
						
						melhorNotaMasculino2 = nota2; 
					}
					
					melhorNotaMasculino3 = nota3;
				}

				if(nota3 <= piorNotaMasculino3){
					if(nota3 < piorNotaMasculino3){ 
                        piorNotaMasculino2 = nota2; 
                        piorNotaFeminino1 = nota1; 
                        piorAtletaMasculino = numeroAtleta; 
                    }else if(nota2 <= piorNotaMasculino2){	
                        if (nota2 < piorNotaMasculino2 || nota1 < piorNotaMasculino1 || (nota1 == piorNotaMasculino1 && numeroAtleta > piorAtletaMasculino)){ 
                            piorNotaMasculino1 = nota1; 
                            piorAtletaMasculino = numeroAtleta; 
                        } 
                        piorNotaMasculino2 = nota2; 
                    
                    }
					piorNotaMasculino3 = nota3;
				}	               
            }
              
            if(genero == 'F'){
                somaFeminino += nota3;

				if(nota3 >= melhorNotaFeminino3){
					if(nota3 > melhorNotaFeminino3){
						melhorNotaFeminino2 = nota2;
                        melhorNotaFeminino1 = nota1; 
                        melhorAtletaFeminino = numeroAtleta; 
					}else if(nota2 >= melhorNotaFeminino2){
						if(nota2 > melhorNotaFeminino2 || nota1 > melhorNotaFeminino1 || (nota1 == melhorNotaFeminino1 && numeroAtleta < melhorAtletaFeminino)){ 
							melhorNotaFeminino1 = nota1; melhorAtletaFeminino = numeroAtleta; 
						} 
						
						melhorNotaFeminino2 = nota2; 
					}
					
					melhorNotaFeminino3 = nota3;
				}

				if(nota3 <= piorNotaFeminino3){
					if(nota3 < piorNotaFeminino3){ 
                        piorNotaFeminino2 = nota2;
                        piorNotaFeminino1 = nota1;
                        piorAtletaFeminino = numeroAtleta;
                    }else if(nota2 <= piorNotaFeminino2){	
                        if (nota2 < piorNotaFeminino2 || nota1 < piorNotaFeminino1 || (nota1 == piorNotaFeminino1 && numeroAtleta > piorAtletaFeminino)){ 
                            piorNotaFeminino1 = nota1; piorAtletaFeminino = numeroAtleta; 
                        } 
                        
                        piorNotaFeminino2 = nota2; 
                    }

					piorNotaFeminino3 = nota3;
				}	                
            }

            if(somaFeminino > melhorSomaFeminino){
                melhorDelegacaoFeminino = contadorDelegacoes;
                melhorSomaFeminino = somaFeminino;   
            }

            if(somaMasculino > melhorSomaMasculino){
                melhorDelegacaoMasculino = contadorDelegacoes;
                melhorSomaMasculino = somaMasculino;
            }

            scanf("%d", &numeroAtleta);
        }

        printf("MELHORES ATLETAS DA DELEGACAO %d\n", contadorDelegacoes);
        printf("MASCULINO: %d FEMININO: %d\n", melhorAtletaMasculino, melhorAtletaFeminino);

        printf("PIORES ATLETAS DA DELEGACAO %d\n", contadorDelegacoes);
        printf("MASCULINO: %d FEMININO: %d\n\n", piorAtletaMasculino, piorAtletaFeminino);
        
        if(contadorDelegacoes == numeroDelegacoes){
            printf("DELEGACAO CAMPEA:\n");
            printf("MASCULINO: %d FEMININO: %d\n", melhorDelegacaoMasculino, melhorDelegacaoFeminino);
        }

        contadorDelegacoes++;
    }

    return 0;
}