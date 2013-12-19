#!/usr/bin/env bash

DEFAULT_N=1000
DEFAULT_OUTPUT="test"

if [[ "$N" = "" ]]; then
  N="$DEFAULT_N"
fi

if [[ "$OUTPUT" = "" ]]; then
  OUTPUT="$DEFAULT_OUTPUT"
fi

if [[ "$OUTPUT" = "-" ]]; then
  OUTPUT="/dev/stdout"
fi

I=0

echo -n > "$OUTPUT"

while [ $I -lt $N ]; do
  echo "echo 'test $I' && sleep '1.$RANDOM' && echo 'ok $I'" >> "$OUTPUT"
  let I=I+1
done

