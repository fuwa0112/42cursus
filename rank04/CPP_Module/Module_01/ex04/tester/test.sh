#!/bin/bash

EXEC=./replace
RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"

echo "=============================="
echo "Building..."
make re
echo "=============================="

pass() {
    echo -e "${GREEN}PASS${RESET}"
}

fail() {
    echo -e "${RED}FAIL${RESET}"
}

run_test() {
    NAME=$1
    FILE=$2
    S1=$3
    S2=$4
    EXPECTED=$5

    $EXEC "$FILE" "$S1" "$S2" > /dev/null 2>&1

    if diff "$FILE.replace" "$EXPECTED" > /dev/null 2>&1; then
        echo "[$NAME] -> $(pass)"
    else
        echo "[$NAME] -> $(fail)"
        echo "Expected:"
        cat "$EXPECTED"
        echo "Got:"
        cat "$FILE.replace"
    fi
    echo "------------------------------"
}

# -----------------------------
# Test 1: Basic replacement
# -----------------------------
echo -e "hello world\nhello 42" > test1.txt
echo -e "HI world\nHI 42" > expected1.txt
run_test "Basic replace" test1.txt hello HI expected1.txt

# -----------------------------
# Test 2: Multiple occurrences
# -----------------------------
echo "banana" > test2.txt
echo "baNANA" > expected2.txt
run_test "Multiple occurrences" test2.txt na NA expected2.txt

# -----------------------------
# Test 3: Consecutive matches
# -----------------------------
echo "aaaaaa" > test3.txt
echo "XXX" > expected3.txt
run_test "Consecutive matches" test3.txt aa X expected3.txt

# -----------------------------
# Test 4: No match
# -----------------------------
echo "hello world" > test4.txt
echo "hello world" > expected4.txt
run_test "No match" test4.txt zzz YYY expected4.txt

# -----------------------------
# Test 5: Special characters
# -----------------------------
echo "hello. hello? hello!" > test5.txt
echo "HI. HI? HI!" > expected5.txt
run_test "Special characters" test5.txt hello HI expected5.txt

# -----------------------------
# Test 6: Self-growing pattern
# -----------------------------
echo "aaaa" > test6.txt
echo "aaaaaaaa" > expected6.txt
run_test "Self growing pattern" test6.txt a aa expected6.txt

# -----------------------------
# Test 7: Empty file
# -----------------------------
touch test7.txt
touch expected7.txt
run_test "Empty file" test7.txt hello HI expected7.txt

rm -f expected*.txt
rm -f test*.replace
rm -f test*.txt