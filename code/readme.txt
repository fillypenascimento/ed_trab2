Execute o comando:
make

Logo em seguida:
./trabalho


Você verá a arvore do primeiro personagem. O programa esperará por um Enter para ir mostrando os próximos
a fim de que você acompanhe a arvore de cada personagem.

O programa não imprime por padrão a figura do personagem. Se quiser vê-la faça os seguintes passos:
1)Abra o arquivo main.c, você vera que estão identificados 2 loops tipo for responsaveis por gerar os personagens.
2)Nos loops está identificada a função que imprime graficamente o personagem: "imprime_personagem(personagem)". Apague
as duas barras ("//") que estão antes da função nos dois loops.
3)Apague o comando "getchar()" que é o ultimo comando do loop.
4)Re-execute o comando make e depois execute ./trabalho


Obs: o programa imprimirá a arvore do personagem e abrirá uma janela com a figura do personagem. O programa só continuará
a execução e mostrará o próximo persogem assim que você fechar a janelad o atualmente mostrado.

ESSE PROGRAMA FOI PRODUZIDO E COMPILADO NA PLATAFORMA LINUX, DISTRIBUIÇÃO UBUNTU 16.04 LTS 64-BIT
COMPILADO COM:
  g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609
  Copyright (C) 2015 Free Software Foundation, Inc.
UTILIZADA A LINGUAGEM C, PADRÃO ANSI

ALÉM DAS BIBLIOTECAS CRIADAS PARA A UTILIZAÇÃO DO CÓDIGO FORAM UTILIZADAS BIBLIOTECAS PADRÃO DO SISTEMA E BIBLIOTECA DA PLAY APC:
-> stdio.h
-> stdlib.h
-> string.h
-> time.h
-> printPersonagem.h
-> arvore.h
-> criador.h
-> lista.h
-> preenchimento.h
