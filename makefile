obj = main.o createInput.o executeOJ.o judgeEqual.o
target = main  
CC = g++

$(target): $(obj)  
	$(CC) $(obj) -o $(target)
	
%.o: %.cpp  
	$(CC) -c $< -o $@ -g

clean: 
	rm *.o main