# 🐍 Jogo da Cobrinha (Snake Game) no Terminal

Uma recriação do clássico jogo da cobrinha (Snake) desenvolvida inteiramente em **C** para rodar no terminal. 

Este projeto foi construído durante a graduação em Ciência da Computação (UNESP) com o objetivo de aplicar conceitos de matrizes, laços de repetição, manipulação de interface textual e lógica de jogos (Game Loop).

## 🎮 Funcionalidades e Regras

* **Movimentação Clássica:** Navegue pelo cenário usando as setinhas para comer as "frutinhas" e aumentar o tamanho da cobra.
* **Game Over:** O jogo termina se a cobra bater nas paredes do cenário ou se colidir com o próprio corpo.
* **Condição de Vitória:** O jogador vence ao preencher a tela/atingir o tamanho máximo.
* **Sistema de Pausa:** É possível pausar o jogo a qualquer momento.

## 🧠 A Lógica por trás (Matriz de Coordenadas)

O "motor" do jogo funciona através do mapeamento do terminal usando uma **Matriz Bidimensional**. 
Em vez de apenas desenhar caracteres soltos, o cenário é uma matriz onde:
* `1` representa os segmentos que compõem o corpo da cobra.
* `0` representa os espaços vazios do cenário.

A cada "frame" (ciclo do game loop), a lógica atualiza as posições da matriz, empurrando o corpo da cobra para a próxima coordenada e redesenhando a interface na tela, criando a ilusão de movimento.

## 🥚 Easter Egg: "Corbinha"

Para adicionar um pouco de humor ao desenvolvimento, implementamos um *easter egg*: toda vez que o jogo é aberto, existe **10% de chance** do título principal em ASCII Art aparecer escrito como **"Corbinha"** em vez de "Cobrinha". Quando essa condição é ativada no código, vários textos e mensagens de interação dentro do jogo também mudam!

## 🚀 Como compilar e executar

Certifique-se de ter um compilador C (como o `gcc`) instalado no seu sistema.

**Passo 1:** Clone o repositório
```bash
git clone https://github.com/Brugo24/Jogo-da-cobrinha.git
cd Jogo-da-cobrinha
```

**Passo 2:** Compile e execute de acordo com o seu SO:

**🐧 No Linux ou macOS:**
```bash
# Para compilar:
gcc Cobrinha.c -o jogo_cobrinha

# Para executar:
./jogo_cobrinha
```

**🪟 No Windows:**
```cmd
# Para compilar:
gcc Cobrinha.c -o jogo_cobrinha.exe

# Para executar:
jogo_cobrinha.exe
```

## 📸 Demonstração

<img width="765" height="652" alt="image" src="https://github.com/user-attachments/assets/1cedc3de-b4ad-47a0-abd4-ccd0fe3b4786" />


---
*Desenvolvido por [Bruno de Oliveira Monchelato](https://www.linkedin.com/in/bruno-monchelato-23a870387/) e [Davi Bandeca Schwingel](https://www.linkedin.com/in/davi-bandeca-schwingel/)*
