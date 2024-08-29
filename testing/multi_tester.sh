#!/usr/bin/env bash

function oktest()
{
	if [ $1 != "OK" ]
	then
		echo "FAIL !!!!"
		exit
	fi
}

function mytest10()
{
	echo
	echo "mytest10"
	echo "--------"
	myarg10="1 2 3 4 5 6 7 8 9 10"
	out_push=$(../push_swap $myarg10 | ./checker_linux $myarg10)
	echo -n $out_push ""
	oktest $out_push
	myarg10="2 3 4 6 5 7 8 9 10 11"
	out_push=$(../push_swap $myarg10 | ./checker_linux $myarg10)
	echo -n $out_push
	oktest $out_push
}

function mytest4()
{
	echo
	echo "mytest4"
	echo "-------"
	myarg="4 3 2 1"
	out_push=$(../push_swap $myarg | ./checker_linux $myarg)
	echo -n $out_push ""
	oktest $out_push
	myarg="-1 1 -2 2"
	out_push=$(../push_swap $myarg | ./checker_linux $myarg)
	echo -n $out_push
	oktest $out_push
}

function mytest5()
{
	echo
	echo "mytest5"
	echo "-------"
	myarg="4 1 3 5 2"
	out_push=$(../push_swap $myarg | ./checker_linux $myarg)
	echo -n $out_push ""
	oktest $out_push
}

function test5()
{
	echo
	echo "test5"
	echo "------"
	for i in $(seq 1 100)
	do
		out_test=$(make test5 -C ..)
		out_grep=$(echo $out_test | grep "OK" -)
		if [ $? -eq 1 ]
		then
			echo "FAIL !!!!"
			exit
		fi
		echo -n "$(echo $out_grep | sed 's/.*OK.*/OK/') "
	done
}

function test10()
{
	echo
	echo "test10"
	echo "------"
	for i in $(seq 1 100)
	do
		out_test=$(make test100 -C ..)
		out_grep=$(echo $out_test | grep "OK" -)
		if [ $? -eq 1 ]
		then
			echo "FAIL !!!!"
			exit
		fi
		echo -n "$(echo $out_grep | sed 's/.*OK.*/OK/') "
	done
}

function test100()
{
	echo
	echo "test100"
	echo "------"
	for i in $(seq 1 100)
	do
		out_test=$(make test100 -C ..)
		out_grep=$(echo $out_test | grep "OK" -)
		if [ $? -eq 1 ]
		then
			echo "FAIL !!!!"
			exit
		fi
		echo -n "$(echo $out_grep | sed 's/.*OK.*/OK/') "
	done
}

function test500()
{
	echo
	echo "test500"
	echo "------"
	for i in $(seq 1 100)
	do
		out_test=$(make test500 -C ..)
		out_grep=$(echo $out_test | grep "OK" -)
		if [ $? -eq 1 ]
		then
			echo "FAIL !!!!"
			exit
		fi
		echo -n "$(echo $out_grep | sed 's/.*OK.*/OK/') "
	done
}

mytest4
echo
mytest5
echo
mytest10
echo
test5
echo
test10
echo
test100
echo
test500

