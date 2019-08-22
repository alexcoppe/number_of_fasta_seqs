# number_of_fasta_seqs
#### :microscope: A program to count the number of sequences in a FASTA file

### Compiling the software

Download the software from [github](https://github.com/alexcoppe/number_of_fasta_seqs), enter the directory containg number_of_fasta_seqs.c and compile it with:
```
make
```


### Getting help

To obtain the usage help just launch the program with the -h option:

```
./number_of_fasta_seqs -h
Usage program [OPTION]... FASTA_FILE.
  -d	show only description lines
  -h	show help options
```

### Counting the number of sequences in a FASTA file

To obtain the number of sequences in a FASTA file:

```
./number_of_fasta_seqs sequences.fasta
3
```

### Obtaining description lines

To get the description lines from a FASTA file use the -d option:

```
./number_of_fasta_seqs -d sequences.fasta
>ENST00000269305.8 (TP53) length=393
>ENST00000345146.6 (IDH1) length=414
>ENST00000376701.4 (WAS) length=502
```

