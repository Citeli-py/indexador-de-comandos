# Indexador de Comandos (idx)

## 📌 Sobre o Projeto

O **idx** é um indexador de comandos que permite criar atalhos (alias) personalizados para comandos complexos no terminal. Com ele, você pode salvar, listar, executar e remover alias de forma prática, facilitando o uso diário de comandos longos.

## 🚀 Funcionalidades

- Criar alias para comandos personalizados
- Listar os alias salvos
- Executar comandos através dos alias
- Remover alias desnecessários
- Persistência dos alias em um arquivo binário

## 🛠️ Como Instalar

1. Clone este repositório:
   ```bash
   git clone https://github.com/Citeli-py/indexador-de-comandos.git
   cd indexador-de-comandos
   ```
2. Instale o programa no sistema:
   ```bash
   chmod +x install_idx.sh
   ./install_idx.sh
   ```
3. Reinicie o terminal ou rode:
   ```bash
   source ~/.bashrc
   ```

## 💻 Como Usar

### Criar um Alias:

```bash
idx add <nome_do_alias> "<comando>"
```

Exemplo:

```bash
idx add api "cd ~/meu_projeto && npm start"
```

### Listar Alias:

```bash
idx list
```

Listar mostrando os comandos
```bash
idx list -c
```

### Executar um Alias:

```bash
idx run <nome_do_alias>
```

Exemplo:

```bash
idx run api
```

### Remover um Alias:

```bash
idx rm <nome_do_alias>
```

Exemplo:

```bash
idx rm api
```

## 🔄 Atualizações Futuras

- Implementação de **autocompletar comandos** (ex.: `idx li<TAB>` ➝ `idx list`)
- Interface interativa para gerenciamento dos alias

## 🤝 Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request.

## 📝 Licença

Este projeto está sob a licença GPL3. Sinta-se livre para usá-lo e modificá-lo!

---

Feito com ❤️ por Citeli-py

