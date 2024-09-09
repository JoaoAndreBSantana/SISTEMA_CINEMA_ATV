# SISTEMA_CINEMA_ATV

Esse sistema simula um controle de cinema que permite ao usuário escolher salas, filmes, sessões e assentos, além de calcular o total a pagar com base na idade do cliente. 

 - O sistema apresenta duas salas com horários e filmes diferentes, com restrição de idade para filmes exibidos na segunda sala(porem esqueci de imprimir essa informacao de inicio, mas n é tão relevante)
 - 
 - O cliente seleciona uma sala, depois escolhe entre dois filmes disponíveis na sala escolhida e a sessão.(achei mais facil de manipular sendo apenas 2 filmes)
 - 
 - Em seguida é exibido os assentos disponíveis e permite que o usuário escolha um assento livre. Assentos já reservados são indicados como indisponíveis.(são 3 assentos cada sala)
 - 
 - Depois é exxibido as informações sobre o filme, a sessão e o assento escolhido, além de calcular o valor do ingresso com base na idade do cliente (meia para menores de 18 anos).
 - STRUCTS:
 - INFO_FILME: Armazena informações sobre o filme escolhido, a sessão e o assento selecionado pelo usuário.
 - FILME: Guarda os detalhes de cada filme, incluindo título, gênero e o nome do ator principal.
 - SALA: Representa cada sala do cinema com sua capacidade, classificação indicativa e os filmes disponíveis
UTILIZEI STRCPY PARA COPIAR AS STRINGS DE FILME PARA A STRUCT DE INFO_FILME


