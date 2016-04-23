#!/usr/bin/perl
#hex to decimal

for($i=0;$i < @ARGV; $i++) {
	$HexVal = hex($ARGV[$i]);
	printf("0x%x\t=\t %d\n",$HexVal,$HexVal);
}
