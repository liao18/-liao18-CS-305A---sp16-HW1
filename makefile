hw1: main.o receipt.o retail_item.o
	gcc -o hw1 main.o receipt.o retail_item.o

%.o: %.c %.h
	gcc -c $<

clean:
	/bin/rm -f *.o hm1
