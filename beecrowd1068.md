# [Balanço de Parênteses I](https://judge.beecrowd.com/pt/problems/view/1068)

Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, sem levar em conta o restante da expressão. Por exemplo:  

a+(b*c)-2-a        está correto  
(a+b*(2-c)-2+a)*2  está correto  

enquanto  

(a*b-(2+c)         está incorreto  
2*(3-a))           está incorreto  
)3+b*(2-c)(        está incorreto  

Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.  

**Entrada**  
Como entrada, haverá N expressões (1 <= N <= 10000), cada uma delas com até 1000 caracteres.  

**Saída**  
O arquivo de saída deverá ter a quantidade de linhas correspondente ao arquivo de entrada, cada uma delas contendo as palavras correct ou incorrect de acordo com as regras acima fornecidas.  

**Exemplo de Entrada**

a+(b*c)-2-a  
(a+b*(2-c)-2+a)*2  
(a*b-(2+c)  
2*(3-a))  
)3+b*(2-c)(  

**Exemplo de Saída**  

correct  
correct  
incorrect  
incorrect  
incorrect  

[Clique aqui para a resolução.](beecrowd1068.c)  
