cat yyz.sh 
#!/bin/bash
#yyz
usage(){
case $choice in
1)
read -p "please input the old file and the new file : " old_file new_file
./yyz/cp $old_file $new_file
if [ $? -eq 0 ];then
    echo "success!" >&2
fi    
     sleep 2
;;


2)
read -p "please input the file  : " file 
./yyz/cat $file 
if [ $? -eq 0 ] ;then
    echo "success!" >&2
fi    
sleep 2
;;


3)
read -p "please input the file or dir : " filename
./yyz/ls-a $filename
if [ $? -eq 0 ];then
    echo "success!" >&2
fi    
sleep 2
;;


4)
read -p "please input the file or dir : " file
./yyz/ls-l $file
if [ $? -eq 0 ];then
    echo "success!" >&2
fi
sleep 2    
;;

5)
./yyz/pwd $file
if [ $? -eq 0 ];then
    echo "success!" >&2
fi
sleep 2
;;


6)
read -p "please input the directory : " directory
./yyz/mkdir $directory
if [ $? -eq 0 ];then
    echo "success!" >&2
fi
sleep 2
;;

7)
read -p "please input the file or dir : " file
./yyz/rm $file
if [ $? -eq 0 ];then
    echo "success!" >&2
fi
sleep 2
;;

8)
read -p "please input the file name : " file 
./yyz/sort $file
if [ $? -eq 0 ];then
    echo "success!" >&2
fi
sleep 2
;;

9)
read -p "please input the file or dir : " file
./yyz/wc $file
if [ $? -eq 0 ];then
    echo "success!" >&2
fi
sleep 2
;;

10)
read -p "please input : " zzx
./yyz/echo $zzx
if [ $? -eq 0 ];then
    echo "success!" >&2
fi
sleep 2
;;


11)
exit 0
;;

*)
;;




esac

}


while :

do

cat<<EOF
 *************************************
*                MENU                 *

*   1.cp                 2.cat        *

*   3.ls-a               4.ls-l       *

*   5.pwd                6.mkdir      *

*   7.rm                8.sort        *

*   9.wc                10.echo       *

*                 11.exit             *


 *************************************
EOF
 

read -p "please enter your choice : " choice

usage

done
