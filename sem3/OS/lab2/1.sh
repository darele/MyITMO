ps axu | awk -v user=$USER '{ if ($1 == user) print $2":"$NF; }' > tempfile.txt
cat tempfile.txt | wc -l > darelesprocess.txt
cat tempfile.txt >> "$USER"process.txt
rm tempfile.txt