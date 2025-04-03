#include <stdio.h>
#define suspeitoPositivo 30000
#define suspeitoNegativo -30000

int main(){
    int banco, agencia, correntista, maiorBanco = -1, maiorAgencia = -1, maiorCorrentista = -1, segundoBanco = -1, segundoAgencia = -1, segundoCorrentista = -1;
    double transacao, saldoCorrentista, saldoAgencia, saldoBanco, maiorSaldo = -99999999, segundoSaldo = -99999999;

    scanf("%d", &banco);

    while(banco != -1){
        printf("banco %03d\n", banco);
        scanf("%d", &agencia);

        saldoBanco = 0.00;

        while(agencia != -1){
            printf("agencia %04d\n", agencia);

            scanf("%d", &correntista);

            saldoAgencia = 0.00;

            while(correntista != -1){
                scanf("%lf", &transacao);

                saldoCorrentista = 0.00;

                while(transacao != 0.00){
                    saldoCorrentista += transacao;

                    if(transacao > suspeitoPositivo || transacao < suspeitoNegativo){
                        printf("operacao suspeita: correntista %d valor %.2lf\n", correntista, transacao);
                    }

                    scanf("%lf", &transacao);
                }

                saldoAgencia += saldoCorrentista;

                printf("correntista %05d saldo %.2lf\n", correntista, saldoCorrentista);

                if(saldoCorrentista > maiorSaldo){
                    segundoCorrentista = maiorCorrentista;
                    segundoAgencia = maiorAgencia;
                    segundoBanco = maiorBanco;
                    segundoSaldo = maiorSaldo;
                    
                    maiorCorrentista = correntista;
                    maiorAgencia = agencia;
                    maiorBanco = banco;
                    maiorSaldo = saldoCorrentista;
                }

                if(saldoCorrentista > segundoSaldo && correntista != maiorCorrentista){
                    segundoCorrentista = correntista;
                    segundoAgencia = agencia;
                    segundoBanco = banco;
                    segundoSaldo = saldoCorrentista;
                }

                scanf("%d", &correntista);
            }

            printf("saldo agencia %.2lf\n", saldoAgencia);

            saldoBanco += saldoAgencia;

            scanf("%d", &agencia);
        }

        if(saldoBanco < 0){
            printf("saldo banco deficitario: %.2lf\n", saldoBanco);
        }

        scanf("%d", &banco);
    }

    printf("segundo maior correntista: banco %03d agencia %04d correntista %05d saldo %.2lf\n", segundoBanco, segundoAgencia, segundoCorrentista, segundoSaldo);

    printf("maior correntista: banco %03d agencia %04d correntista %05d saldo %.2lf\n", maiorBanco, maiorAgencia, maiorCorrentista, maiorSaldo);

    return 0;
}