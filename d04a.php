#!/usr/bin/php
<?php
  $n=1;
  while (strncmp(md5('yzbqklnj'.$n),'00000',5)) $n++;
  echo "5 zeros =$n\n";
  while (strncmp(md5('yzbqklnj'.$n),'000000',6)) $n++;
  echo "6 zeros =$n\n";
?>