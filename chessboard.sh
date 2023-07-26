Display_chessboard()
{
	 columns=8
	 rows=8
	for((i=1;i<=rows;i++)); do
		for((j=1;j<columns;j++));do
			if(((i+j)%2==0));then
				printf "0 "
			else
				printf "1 "
			fi
		done
		printf "\n"
	done
}
Display_chessboard
