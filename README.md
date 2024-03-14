# Trabalho I - Métodos Numéricos
## Prof. João B. Oliveira

Seu primeiro trabalho nesta disciplina consiste em explorar o padrão IEEE-754. Você deve implementar um programa que cumpra as seguintes tarefas:

1. Ele recebe pela linha de comando uma expressão no formato `val1 op val2` onde op é uma operação (+,−, ∗,/) e val1 e val2 são dois valores em ponto flutuante, NaN ou ±∞.
2. Depois de receber a expressão seu programa deve realizar a operação op e mostrar o resultado dela;
3. Seu programa também deve mostrar a configuração de bits das duas variáveis e do resultado. Tome cuidado com a `endianness` do seu proessador para que a saída seja apresentada corretamente;
4. Seu programa também deve informar se alguma exceção do padrão IEEE-754 foi sinalizada quando a operação foi feita. Use o registrador de status!

Por exemplo, seu programa poderia funcionar assim:

```
> python3 aluleitor.py 21 / -0

Recebi 21.000000 / -0.000000 e resultado deu -inf
val1 = 0 10000011 01010000000000000000000 = 21
val2 = 1 00000000 00000000000000000000000 = -0
res = 1 11111111 00000000000000000000000 = -inf
Exceção FE_INEXACT: 0
Exceção FE_DIVBYZERO: 1
Exceção FE_UNDERFLOW: 0
Exceção FE_OVERFLOW: 0
Exceção FE_INVALID: 0
```

*Atenção:* faça este trabalho em C. Não faça em Python, não faça em Java. Aqui estão (apenas alguns) motivos:
Da espeicificação da máquina virtual java:
The floating-point operations of the Java Virtual Mahine do not throw
exeptions, trap, or otherwise signal the IEEE 754 exeptional conditions
of invalid operation, division by zero, overflow, underflow, or inexat.
The Java Virtual Mahine has no signaling NaN value.`
Sobre Python: voê pode ter alguma esperança usando numpy e numpy.seterr, mas vai estar correndo riscos. A responsabilidade é toda sua e a chance de arrependimento é alta.

