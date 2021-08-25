#!/usr/bin/env bash
shell="$1"
command="$2"
tmp_own_er="temp_own_er"
tmp_sh_er="temp_sh_er"
tmp_own="temp_own"
tmp_sh="temp_sh"

echo $command | $shell 1> $tmp_own 2> $tmp_own_er
err_status_own=$(echo $?)
echo $command | sh 1> $tmp_sh 2> $tmp_sh_er
err_status_sh=$(echo $?)

echo "STDOUT"
echo -e "\tdiff:\t$(git diff $tmp_own $tmp_sh)"
echo "STDERR"
echo -e "\tdiff:\t$(git diff $tmp_own_er $tmp_sh_er)"
echo "EXIT"
echo -e "\tHSH:$err_status_own \n\tSH:$err_status_sh"

rm -f $tmp_own_er
rm -f $tmp_sh_er
rm -f $tmp_own
rm -f $tmp_sh
