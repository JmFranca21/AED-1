# [Tipos de Triângulos](https://judge.beecrowd.com/pt/problems/view/1045)

Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente, de modo que o lado A representa o maior dos 3 lados. A seguir, determine o tipo de triângulo que estes três lados formam, com base nos seguintes casos, sempre escrevendo uma mensagem adequada:  

- se A ≥ B+C, apresente a mensagem: **NAO FORMA TRIANGULO**  
- se A2 = B2 + C2, apresente a mensagem: **TRIANGULO RETANGULO**  
- se A2 > B2 + C2, apresente a mensagem: **TRIANGULO OBTUSANGULO**  
- se A2 < B2 + C2, apresente a mensagem: **TRIANGULO ACUTANGULO**  
- se os três lados forem iguais, apresente a mensagem: **TRIANGULO EQUILATERO**  
- se apenas dois dos lados forem iguais, apresente a mensagem: **TRIANGULO ISOSCELES**  

**Entrada**  
A entrada contem três valores de ponto flutuante de dupla precisão A (0 < A) , B (0 < B) e C (0 < C).  

**Saída**  
A entrada contem três valores de ponto flutuante de dupla precisão A (0 < A) , B (0 < B) e C (0 < C).  

**Exemplo de Entrada**  

7.0 5.0 7.0  

6.0 6.0 10.0  

6.0 6.0 6.0  

5.0 7.0 2.0  

6.0 8.0 10.0  

**Exemplo de Saída**  

TRIANGULO ACUTANGULO  
TRIANGULO ISOSCELES  

TRIANGULO OBTUSANGULO  
TRIANGULO ISOSCELES  

TRIANGULO ACUTANGULO  
TRIANGULO EQUILATERO  

NAO FORMA TRIANGULO  

TRIANGULO RETANGULO  

[Clique aqui para a resolução.](beecrowd1045.c)  
