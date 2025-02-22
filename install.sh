#!/bin/bash

EXECUTABLE="idx"
SRC_FILE="main.c"
INSTALL_DIR="/usr/local/bin"
BASHRC="$HOME/.bashrc"

# Verifica se o código-fonte existe
if [ ! -f "$SRC_FILE" ]; then
    echo "Erro: Arquivo $SRC_FILE não encontrado!"
    exit 1
fi

# Compila o programa
echo "🔧 Compilando $SRC_FILE..."
gcc "$SRC_FILE" -o "$EXECUTABLE"

# Move para /usr/local/bin (precisa de sudo)
echo "📂 Movendo $EXECUTABLE para $INSTALL_DIR..."
sudo mv "$EXECUTABLE" "$INSTALL_DIR/"

# Adiciona alias ao .bashrc se ainda não existir
if ! grep -q "alias idx=" "$BASHRC"; then
    echo "📝 Adicionando alias ao $BASHRC..."
    echo "alias idx=\"$INSTALL_DIR/$EXECUTABLE\"" >> "$BASHRC"
else
    echo "✅ Alias já existe no $BASHRC."
fi

# Recarrega o .bashrc
echo "🔄 Recarregando $BASHRC..."
source "$BASHRC"

echo "🎉 Instalação concluída! Agora você pode rodar o comando 'idx' no terminal."
