#!/bin/bash

awk '{
		{printf "%s ", $1 " " $2 " " $3}; 
		{for (i=4;i<=NF;i++) 
			{ 
				if ($i<60)
					{printf "FX "}
				else if ($i < 70)
					{printf "E "}
				else if ($i < 80)
					{printf "D "}
				else if ($i < 85)
					{printf "C "}
				else if ($i < 95)
					{printf "B "}
				else
					{printf "A "}
			}
		};
		print "";
	}' $1