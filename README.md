# 🛡️ Intrusion Detection System (IDS) – Hash Tables em C

Projeto desenvolvido em **C** que simula um **Sistema de Detecção de Intrusão em Rede (IDS)** utilizando **estruturas de dados fundamentais**, como **Tabelas Hash com Chaining e Linear Probing**.

O sistema registra **eventos de segurança**, armazena **tipos de ataque detectados** e permite **consultar, visualizar e remover logs de eventos** através de um menu interativo no terminal.

Este projeto demonstra a aplicação prática de **Estruturas de Dados** em um cenário inspirado em **Cyber Security**.

---

# 🎯 Objetivo

Simular um sistema simples de monitoramento de segurança de rede capaz de:

* Registrar eventos suspeitos
* Armazenar logs de segurança
* Classificar tipos de ataques
* Permitir busca e remoção de eventos

---

# 🧠 Estruturas de Dados Utilizadas

## 🔗 Tabela Hash com Chaining

Utilizada para armazenar **eventos de segurança detectados na rede**.

Cada posição da tabela possui uma **lista encadeada**, permitindo armazenar múltiplos eventos que geram **colisão na função hash**.

Exemplo de eventos:

* login suspeito
* port scan detectado
* sql injection
* tráfego anormal
* acesso não autorizado

Estrutura utilizada:

```c
typedef struct Nodo {
    char valor[50];
    struct Nodo* proximo;
} Nodo;
```

---

## 📍 Tabela Hash com Linear Probing

Utilizada para armazenar **tipos de ataques detectados**.

Neste método, quando ocorre colisão, o algoritmo procura **a próxima posição livre na tabela**.

Exemplos de ataques:

* brute force
* ddos
* sql injection
* reconnaissance
* phishing

Estrutura utilizada:

```c
typedef struct {
    char valor[50];
    int ocupado;
} Entrada;
```

---

# ⚙️ Funcionalidades do Sistema

O sistema possui um **menu interativo no terminal**.

### 1️⃣ Visualizar logs de eventos

Mostra todos os eventos registrados na **tabela hash com chaining**.

Exemplo:

```
=== LOG DE EVENTOS DE SEGURANCA ===

[0]: login suspeito -> trafego anormal -> NULL
[1]: NULL
[2]: port scan detectado -> NULL
```

---

### 2️⃣ Visualizar tipos de ataque

Mostra todos os ataques armazenados na **tabela hash com linear probing**.

Exemplo:

```
=== TIPOS DE ATAQUE DETECTADOS ===

[0]: brute force
[1]: ddos
[2]: <livre>
[3]: sql injection
```

---

### 3️⃣ Buscar evento

Permite procurar um evento específico dentro do log de segurança.

Exemplo:

```
Digite o evento: login suspeito
Evento encontrado no log.
```

---

### 4️⃣ Remover evento

Permite remover um evento registrado.

Exemplo:

```
Digite evento para remover: sql injection
Evento 'sql injection' removido do log.
```

---

### 5️⃣ Encerrar sistema

Finaliza a execução do IDS.

---

# 🔑 Função Hash

A função hash utilizada soma os valores ASCII dos caracteres da string e aplica **módulo pelo tamanho da tabela**.

```c
int funcao_hash(const char* chave) {
    int soma = 0;

    for (int i = 0; chave[i] != '\0'; i++){
        soma += chave[i];
    }

    return soma % TAMANHO_TABELA;
}
```

---

# ▶️ Como executar o projeto

### 1️⃣ Compilar o programa

```bash
gcc ids.c -o ids
```

### 2️⃣ Executar

```bash
./ids
```

---

# 📌 Exemplo de execução

```
==============================
 SISTEMA DE DETECCAO DE INTRUSAO
==============================

1 - Mostrar logs de eventos
2 - Mostrar tipos de ataque
3 - Buscar evento
4 - Remover evento
5 - Sair
```

---

# 🚀 Conceitos aplicados

Este projeto demonstra conceitos importantes de **Estruturas de Dados e Programação em C**:

* Tabelas Hash
* Chaining (listas encadeadas)
* Linear Probing
* Funções Hash
* Manipulação de Strings
* Alocação dinâmica de memória
* Estruturas (`struct`)
* Ponteiros
* Busca e remoção em estruturas de dados

---

# 💼 Aplicação prática

Sistemas de monitoramento semelhantes são utilizados em:

* Sistemas de **Cyber Security**
* **Análise de logs de rede**
* Sistemas **SIEM**
* Monitoramento de **tráfego suspeito**
* Detecção de **ataques em servidores**

---

# 👩‍💻 Autor

**Nicolly Góes Bastos**

Estudante nas áreas de **Ciência da Computação, Ciência e Tecnologia e Engenharia da Informação**.

Interesses:

* Estruturas de Dados
* Sistemas
* Cyber Security
* Desenvolvimento de Software
