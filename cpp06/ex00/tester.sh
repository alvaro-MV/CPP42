#!/bin/bash

# Colores
RED="\033[31m"
GREEN="\033[32m"
CYAN="\033[36m"
RESET="\033[0m"

# Compilar
echo -e "${CYAN}[Tester] -> Running make re...${RESET}"
make -s re
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed. Aborting tester.${RESET}"
    exit 1
fi

BIN=./converter

if [ ! -f "$BIN" ]; then
    echo -e "${RED}Binary '$BIN' not found. Aborting.${RESET}"
    exit 1
fi

# Lista de tests
tests=(
    # CHAR
    "a"
    "Z"
    "?"
    "/"

    # INT
    "0"
    "42"
    "-42"
    "2147483647"
    "-2147483648"
    "2147483648"       # overflow
    "-2147483649"       # overflow

    # DOUBLE
    "4.2"
    "-4.2"
    "+4.2"
    "0.0"
    "00012.340"
    ".42"               # permitido por strtod
    "42."               # permitido también

    # FLOAT
    "4.2f"
    "-4.2f"
    "+4.2f"
    "0.0f"
    "nanf"
    "-inff"
    "+inff"

    # DOUBLE pseudo
    "nan"
    "+inf"
    "-inf"

    # MIX / INVALID
    "42.0ff"
    "4..2"
    "abc"
    "--42"
    "4f2"
    "∞"             # unicode
    ""
)

echo -e "${CYAN}[Tester] -> Running tests...${RESET}"
echo

# Carpeta temporal para diffs
mkdir -p tester_out

test_id=1

for t in "${tests[@]}"; do
    echo -e "${CYAN}===== TEST $test_id =====${RESET}"
    echo -e "Input: \"$t\"\n"

    # Ejecuta el programa y guarda la salida
    echo -e "$BIN \"$t\" > tester_out/out_$test_id.txt"
    $BIN "$t" > tester_out/out_$test_id.txt 2>&1

    # Imprimir salida
    echo -e "${GREEN}--- Output ---${RESET}"
    cat tester_out/out_$test_id.txt
    echo

    # Solo mostrar diff si hay expected file
    exp="expected/$test_id.txt"
    if [ -f "$exp" ]; then
        diff=$(diff -u "$exp" tester_out/out_$test_id.txt)
        if [ "$diff" != "" ]; then
            echo -e "${RED}--- DIFF with expected ---${RESET}"
            echo "$diff"
        else
            echo -e "${GREEN}Output matches expected ✔${RESET}"
        fi
    fi

    echo
    ((test_id++))
done

echo -e "${CYAN}Done.${RESET}"
