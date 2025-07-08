#!/bin/bash
id -Gn $FT_USER | gawk -F " " '{$1=$1}1' OFS=","