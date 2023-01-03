#! /usr/bin/bash

test=0

msg_exit() {
    echo "$1"
    exit
}

codefile_define() {
    echo "#include \"$header_file\"" >> $1
    echo "" >> $1
}

header_define() {
    echo "#ifndef $(echo $upper_prefix)_H" >> $1
    echo "#define $(echo $upper_prefix)_H" >> $1
    echo "" >> $1
    echo "" >> $1
    echo "" >> $1
    echo "#endif" >> $1
    echo "" >> $1
}

test_define() {
    echo "#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN" >> $1
    echo "" >> $1
    echo "#include \"doctest.h\"" >> $1
    echo "#include \"$header_file\"" >> $1
    echo "" >> $1
}

echo "Filename entered: '$1'"

if [[ ${#1} -eq 0 ]]; then
    msg_exit "A filename is required."
fi

file_prefix="$1"
upper_prefix=$(echo "$file_prefix" | tr '[:lower:]' '[:upper:]')

# "$file_prefix" | tr '[:lower:]' '[:upper:]'

header_file="$file_prefix.hpp"
code_file="$file_prefix.cpp"
test_file="$file_prefix.test.cpp"

echo "Uppercase Prefix: $upper_prefix"

echo "File names: $header_file $code_file $test_file"
echo -n "Create the following files? [y/n]: "
read -r ans

if [[ $ans == "n" ]]; then
    msg_exit "Exiting."
elif [[ $ans != "y" ]]; then
    msg_exit "$ans is not a valid answer."
fi



if [[ $test -eq 0 ]]; then
    echo "Creating files $header_file $code_file $test_file"
    touch $header_file $code_file $test_file
    test_define $test_file
    header_define $header_file
    codefile_define $code_file

else
    echo "Test - No files created"
    echo "Creating files $header_file $code_file $test_file"
fi
