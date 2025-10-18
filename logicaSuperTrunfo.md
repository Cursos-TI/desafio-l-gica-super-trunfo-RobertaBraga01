# 🃏 Super Trunfo - Nível Aventureiro 🎮
Repositório: **desafio-l-gica-super-trunfo-Biankrvalho**

Projeto desenvolvido para o desafio **Nível Aventureiro** da disciplina de Lógica de Programação em C.  
O objetivo é implementar um jogo **interativo no terminal** que compara atributos de duas cartas utilizando **estruturas condicionais (`if/else`)** e um **menu com `switch`**.

---

## 🧠 Descrição do Projeto

Este projeto é a continuação do nível anterior (Nível Novato).  
Agora, o jogador pode **interagir** com o programa, escolhendo o atributo de comparação entre duas cartas de **cidades reais: São Paulo e Rio de Janeiro**.

O menu é exibido no terminal, e a lógica determina qual carta vence com base no atributo selecionado.

---

## ⚙️ Funcionalidades

✅ Menu interativo com `switch`  
✅ Cálculo automático de **Densidade Demográfica** e **PIB per Capita**  
✅ Comparação de atributos numéricos  
✅ **Desempate aninhado** por pontos turísticos  
✅ Tratamento para entradas inválidas  
✅ Interface simples e intuitiva no terminal  

---

## 📋 Atributos disponíveis para comparação

| Código | Atributo              | Regra de Vitória         |
|:------:|:----------------------|:--------------------------|
| 1 | População | Maior vence |
| 2 | Área (km²) | Maior vence |
| 3 | PIB (bilhões de R$) | Maior vence |
| 4 | Pontos Turísticos | Maior vence |
| 5 | Densidade Demográfica | **Menor vence** |
| 6 | PIB per Capita | Maior vence |
| 0 | Sair | Encerra o jogo |

---

## 🏙️ Cartas cadastradas

### Carta 1 — São Paulo (SP)
- Código: A1  
- População: 12.300.000  
- Área: 1.521 km²  
- PIB: R$ 750 bilhões  
- Pontos Turísticos: 25  
- Densidade: 8.086 hab/km²  
- PIB per capita: R$ 60.975  

### Carta 2 — Rio de Janeiro (RJ)
- Código: B2  
- População: 6.710.000  
- Área: 1.200 km²  
- PIB: R$ 360 bilhões  
- Pontos Turísticos: 20  
- Densidade: 5.591 hab/km²  
- PIB per capita: R$ 53.641  

---

## 🧮 Regras de Comparação

- **Regra geral:** vence a carta com o **maior valor** no atributo escolhido.  
- **Exceção:** para **Densidade Demográfica**, **vence o menor valor**.  
- **Empate:** se os valores forem iguais, o desempate é feito pelo **número de pontos turísticos**.  
  Se continuar empatado, o resultado é **Empate!**.

---

## 🧑‍💻 Como compilar e executar

### 💻 Compilação
No terminal, dentro do seu repositório:
```bash
gcc -Wall -Wextra -O2 logicaSuperTrunfo.c -o supertrunfo

